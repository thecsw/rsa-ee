#include <stdio.h>
#include <string.h>
#include "gmp.h"

int main(int argc, char** argv) {
  if (argc != 3) {
	printf("Please enter values of p and q. FILE [] []\nExiting...\n");
	return 0;
  }
  mpz_t p, q, n, lam, e, d;
  mpz_init(p);
  mpz_set_str(p, argv[1], 10);
  gmp_printf("%Zd\n", p);
  return 0;
}
