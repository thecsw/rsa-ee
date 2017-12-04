#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gmp.h"

int main(int argc, char** argv) {
  if (argc != 5) {
	printf("Please enter values of n, e and d, also the message.\nExiting...\n");
	abort();
  }
  mpz_t n, e, d, m, c, mt;
  mpz_init(m);
  mpz_init(c);
  mpz_init(mt);
  mpz_init_set_str(n, argv[1], 10);
  mpz_init_set_str(e, argv[2], 10);
  mpz_init_set_str(d, argv[3], 10);
  mpz_import(m, strlen(argv[4]), 1, 1, 0, 0, argv[4]);
  mpz_powm(c, m, e, n);

  if (mpz_cmp(m, n) > 0) {
	printf("The text value is bigger than modulo parameter.\nExiting...");
	abort();
  }

  mpz_powm(mt, c, d, n);
  char text[64];
  mpz_export(text, NULL, 1, 1, 0, 0, mt);
  printf("\nInitial settings:\n");
  gmp_printf("\tThe n value: %Zd\n", n);
  gmp_printf("\tThe e value: %Zd\n", e);
  gmp_printf("\tThe d value: %Zd\n", d);
  printf("\nThe results:\n");
  printf("\tInput text : %s\n", argv[4]);
  gmp_printf("\tConverted text : %Zd\n", m);
  gmp_printf("\tEncrypted text : %Zd\n", c);
  gmp_printf("\tDecrypted text : %Zd\n", mt);
  printf("\tOutput text : %s\n", text);


  return 0;
}
