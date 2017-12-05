#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "gmp.h"

int main(int argc, char** argv) {

  // We need exactly 5 variables. If not, abort.
  if (argc != 5) {
	printf("Please enter values of n, e and d, also the message.\nExiting...\n");
	abort();
  }

  // Declaring varibles, ned is obvious, while:
  // m is the original converted message
  // c is the original converted message that is encrypted
  // mt is the decrypted original converted message that was encrypted 
  mpz_t n, e, d, m, c, mt;

  // Initializing variables, thus allocating memery for them
  mpz_init(m);
  mpz_init(c);
  mpz_init(mt);

  // Initializing and setting variables with values from the terminal input
  mpz_init_set_str(n, argv[1], 10);
  mpz_init_set_str(e, argv[2], 10);
  mpz_init_set_str(d, argv[3], 10);
  mpz_import(m, strlen(argv[4]), 1, 1, 0, 0, argv[4]);

  // If the converted message's value is bigger than n, abort.
  if (mpz_cmp(m, n) > 0) {
	printf("The text value is bigger than modulo parameter.\nExiting...");
	abort();
  }
  
  // Encrypting the message
  mpz_powm(c, m, e, n); // c = pow(m, e) % n

  // Trying to make the cypher into a text
  char enc[64];
  mpz_export(enc, NULL, 1, 1, 0, 0, c);

  // Decrypting the message
  mpz_powm(mt, c, d, n); // mt = pow(c, d) % n

  // Converting the message from digits to characters
  char text[64];
  mpz_export(text, NULL, 1, 1, 0, 0, mt);

  // Print out all the necessary data 
  printf("\nInitial settings:\n");
  gmp_printf("\tThe n value: %Zd\n", n);
  gmp_printf("\tThe e value: %Zd\n", e);
  gmp_printf("\tThe d value: %Zd\n", d);

  printf("\nAll following data will be shown as hexadecimal values.");
  printf("\nIt's easier to present in this way than decimal.\n");
  
  printf("\nRSA keys:\n");
  gmp_printf("\tPublic key  :   (%#Zx, \n\t\t\t %#Zx)\n", e, n);
  gmp_printf("\tPrivate key :   (%#Zx, \n\t\t\t %#Zx)\n", d, n);
  
  printf("\nThe results:\n");
  printf("\tInput text :     %s\n", argv[4]);
  gmp_printf("\tConverted text : %Zx\n", m);
  gmp_printf("\tEncrypted text : %Zx\n", c);
  printf("\tEncrypted text : %s\n", enc);
  gmp_printf("\tDecrypted text : %Zx\n", mt);
  printf("\tOutput text :    %s\n", text);

  // Clearing the memory and resetting it to NULL
  mpz_clears(n, e, d, m, c, mt, NULL);
  
  printf("\nThank you for using rsa-ee!\nExiting...\n");
  return 0;
}
