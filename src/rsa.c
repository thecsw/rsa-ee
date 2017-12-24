#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "gmp.h"

int main(int argc, char** argv) {
	gmp_printf("\nProgram to demonstrate the work of RSA encryption algorithm.\n\n");
	gmp_printf("Checking for the terminal input... ");
	// We need exactly 5 variables. If not, abort.
	char nc[64], ec[64], dc[64], mc[64];
	if (argc != 5) {
		printf("Please enter values of n, e and d, also the message.\nExiting...\n");
	    printf("Please enter the value of modulo in decimal : ");
		scanf("%s", nc);
		printf("Please enter the value of public exponent in decimal : ");
		scanf("%s", ec);
		printf("Please enter the value of private exponent in decimal : ");
		scanf("%s", dc);
		printf("Please enter your message in ASCII : ");
		scanf("%s", mc);
		printf("Thank you for the input.\n");
	} else {
		strcpy(nc, argv[1]);
		strcpy(ec, argv[2]);
		strcpy(dc, argv[3]);
		strcpy(mc, argv[4]);
	}
	gmp_printf("Success.\n");
	
	// Declaring varibles, ned is obvious, while:
	// m is the original converted message
	// c is the original converted message that is encrypted
	// mt is the decrypted original converted message that was encrypted 
	gmp_printf("Creating local variables... ");
	mpz_t n, e, d, m, c, mt;
	gmp_printf("Success.\n");
	
	// Initializing variables, thus allocating memery for them
	gmp_printf("Initializing local variables... ");
	mpz_init(m);
	mpz_init(c);
	mpz_init(mt);
	gmp_printf("Success.\n");
	
	// Initializing and setting variables with values from the terminal input
	gmp_printf("Initializing and setting up local variables... ");
	mpz_init_set_str(n, nc, 10);
	mpz_init_set_str(e, ec, 10);
	mpz_init_set_str(d, dc, 10);
	gmp_printf("Success.\n");
	
	// Converting text into hexadecimal
	gmp_printf("Converting text into hexadecimal... ");
	mpz_import(m, strlen(mc), 1, 1, 0, 0, mc);
	gmp_printf("Success.\n");
  
	// If the converted message's value is bigger than n, abort.
	gmp_printf("Checking if text value is bigger than the modulo... ");
	if (mpz_cmp(m, n) > 0) {
		printf("The text value is bigger than modulo parameter.\nExiting...\n");
		return EXIT_FAILURE;
	}
	gmp_printf("Success.\n");
	
	// Encrypting the message
	gmp_printf("Encrypting the message... ");
	mpz_powm(c, m, e, n); // c = pow(m, e) % n
	gmp_printf("Success.\n");
	
	// Trying to make the cypher into a text
	gmp_printf("Trying to directly translate the encrypted text... ");
	char enc[256];
	mpz_export(enc, NULL, 1, 1, 0, 0, c);
	gmp_printf("Success.\n");
	
	// Decrypting the message
	gmp_printf("Decrypting the message... ");
	mpz_powm(mt, c, d, n); // mt = pow(c, d) % n
	gmp_printf("Success.\n");
	
	// Converting the message from digits to characters
	gmp_printf("Translating the decypted text into string... ");
	char text[256];
	mpz_export(text, NULL, 1, 1, 0, 0, mt);
	gmp_printf("Success.\n");
	
	// Print out all the necessary data 
	gmp_printf("\nInitial settings:\n");
	gmp_printf("\tThe n value: %Zd\n", n);
	gmp_printf("\tThe e value: %Zd\n", e);
	gmp_printf("\tThe d value: %Zd\n", d);
	
	gmp_printf("\nAll following data will be shown as hexadecimal values.");
	gmp_printf("\nIt's easier to present in this way than decimal.\n");
	
	gmp_printf("\nRSA keys:\n");
	gmp_printf("\tPublic key  :   (%#Zx, \n\t\t\t %#Zx)\n", e, n);
	gmp_printf("\tPrivate key :   (%#Zx, \n\t\t\t %#Zx)\n", d, n);
	
	gmp_printf("\nThe results:\n");
	gmp_printf("\tInput text            : %s\n", mc);
	gmp_printf("\tConverted text        : %Zx\n", m);
	gmp_printf("\tAttempt of decrypting : %Zx\n", c);
	gmp_printf("\tEncrypted text        : %s\n", enc);
	gmp_printf("\tDecrypted text        : %Zx\n", mt);
	gmp_printf("\tOutput text           : %s\n", text);
	
	// Clearing the memory and resetting it to NULL
	mpz_clears(n, e, d, m, c, mt, NULL);
	
	printf("\nThank you for using rsa-ee!\nExiting...\n");
	return EXIT_SUCCESS;
}
