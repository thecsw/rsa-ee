#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	unsigned long long i, j, n;
	if (argc!=2) {
		printf("Please enter n.\n");
		return 0;
	}
	n = atol(argv[1]);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (j * i == n) {
				printf("Primes for n are : %llu and %llu\n", i, j);
			}
		}
		//printf("Progress: %llu\%\n", i);
	}
	return 0;
}
