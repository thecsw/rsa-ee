#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(int argc,
	 char **argv)
{
		gmp_printf("\nProgram to demonstrate the work of RSA encryption algorithm.\n\n");
		gmp_printf("Checking for the terminal input... ");
		char n_char[512], e_char[512], d_char[512], m_char[512];
		if (argc != 5) { /* We need exactly 5 arguments to proceed. If they are not
							provided, ask. */
				printf("Please enter values of n, e and d, also the "
					   "message.\n");
				printf("Please enter the value of modulo in decimal : ");
				scanf("%s", n_char);
				printf("Please enter the value of public exponent in decimal : ");
				scanf("%s", e_char);
				printf("Please enter the value of private exponent in decimal : ");
				scanf("%s", d_char);
				printf("Please enter your message in ASCII : ");
				scanf("%s", m_char);
				printf("Thank you for the input.\n");
		} else {
				strcpy(n_char, argv[1]);
				strcpy(e_char, argv[2]);
				strcpy(d_char, argv[3]);
				strcpy(m_char, argv[4]);
		}
		gmp_printf("Success.\n");
		
		/*---------------------------------------------------------------
		  Declaring varibles, ned is obvious, while:
		  m is the original converted message
		  c is the original converted message that is encrypted
		  mt is the decrypted original converted message that was encrypted
		  ----------------------------------------------------------------*/
		
		gmp_printf("Creating local variables... ");
		mpz_t n, e, d, converted_message, encrypted_message, decrypted_message;
		gmp_printf("Success.\n");
		
		/* Initializing variables, thus allocating memery for them */
		gmp_printf("Initializing local variables... ");
		mpz_init(converted_message);
		mpz_init(encrypted_message);
		mpz_init(decrypted_message);
		gmp_printf("Success.\n");
		
		// Initializing and setting variables with values from the terminal input
		gmp_printf("Initializing and setting up local variables... ");
		mpz_init_set_str(n, n_char, 10);
		mpz_init_set_str(e, e_char, 10);
		mpz_init_set_str(d, d_char, 10);
		gmp_printf("Success.\n");
		
		// Converting text into hexadecimal
		gmp_printf("Converting text into hexadecimal... ");
		mpz_import(converted_message, strlen(m_char), 1, 1, 0, 0, m_char);
		gmp_printf("Success.\n");
		
		// If the converted message's value is bigger than n, abort.
		gmp_printf("Checking if text value is bigger than the modulo... ");
		if (mpz_cmp(converted_message, n) > 0) {
				printf("The text value is bigger than modulo parameter.\nExiting...\n");
				return EXIT_FAILURE;
		}
		gmp_printf("Success.\n");
		
		// Encrypting the message
		gmp_printf("Encrypting the message... ");
		mpz_powm(encrypted_message, converted_message, e,
				 n); // encrypted_message = pow(m, e) % n
		gmp_printf("Success.\n");
		
		// Trying to make the cypher into a text
		gmp_printf("Trying to directly translate the encrypted text... ");
		char attempted_decryption[256];
		mpz_export(attempted_decryption, NULL, 1, 1, 0, 0, encrypted_message);
		gmp_printf("Success.\n");
		
		// Decrypting the message
		gmp_printf("Decrypting the message... ");
		mpz_powm(decrypted_message, encrypted_message, d, n);
		// decrypted_message = pow(encrypted_message, d) % n
		gmp_printf("Success.\n");
		
		// Converting the message from digits to characters
		gmp_printf("Translating the decypted text into string... ");
		char decrypted_final_text[256];
		mpz_export(decrypted_final_text, NULL, 1, 1, 0, 0, decrypted_message);
		gmp_printf("Success.\n");
		
		// Print out all the necessary data
		gmp_printf("\nInitial settings:\n");
		gmp_printf("\tThe n value: %Zd\n", n);
		gmp_printf("\tThe e value: %Zd\n", e);
		gmp_printf("\tThe d value: %Zd\n", d);
		
		gmp_printf("\nAll following data will be shown as hexadecimal values.");
		gmp_printf("\nIt is easier to present in this way than decimal.\n");
		
		gmp_printf("\nRSA keys:\n");
		gmp_printf("\tPublic key  :   (%#Zx, \n\t\t\t %#Zx)\n", e, n);
		gmp_printf("\tPrivate key :   (%#Zx, \n\t\t\t %#Zx)\n", d, n);
		
		gmp_printf("\nThe results:\n");
		gmp_printf("\tInput text            : %s\n", m_char);
		gmp_printf("\tConverted text        : %Zx\n", converted_message);
		gmp_printf("\tAttempt of decrypting : %Zx\n", encrypted_message);
		gmp_printf("\tEncrypted text        : %s\n", attempted_decryption);
		gmp_printf("\tDecrypted text        : %Zx\n", decrypted_message);
		gmp_printf("\tOutput text           : %s\n", decrypted_final_text);
		
		// Clearing the memory and resetting it to NULL
		mpz_clears(n, e, d, converted_message, encrypted_message, decrypted_message, NULL);
		
		printf("\nThank you for using rsa-ee!\nExiting...\n");
		return EXIT_SUCCESS;
}
