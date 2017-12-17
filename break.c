#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void brute_force(int n) {
	int p, q;
	for (p = 2; p < n; p++) {
		for (q = 2; q < n; q++) {
			if (p * q == n) {
			    printf("Primes for %d are : %d and %d\n", n, p, q);
				return;
			}
		}
	}
}

int main(int argc, char** argv) {
	if (argc!=2) {
		printf("Please enter n.\n");
		return EXIT_FAILURE;
	}
	clock_t begin = clock();
	int n;
	n = atoi(argv[1]);
	brute_force(n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nExecution time in seconds : %f\n", time_spent);
	return EXIT_SUCCESS;
}
