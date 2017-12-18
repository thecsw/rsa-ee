#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SPEED 2528000000
void not(){}
// By using sieve of eratosthenes, all non-primes in array arr are turned to 0
void find_primes(unsigned int* arr, unsigned int size) {
	unsigned int i = 0;
	for (i = 0; i < size; i++) arr[i] = i;
	for (i = 2; i < size; i++) {
		if (arr[i] != 0) {
			unsigned int j = i;
			while (j + arr[i] < size) arr[j += arr[i]] = 0;
		}
	}
}
// Counting number of non-zero values in array arr
int count(unsigned int* arr, unsigned int size) {
	unsigned int i, k = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] != 0) k++;
	}
	return k;
}
// Copies all primes from array arr to new array arg
void primes(unsigned int* arr, unsigned int size, unsigned int k, unsigned int* arg) {
	unsigned int i, l = 0;
	unsigned int j = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] != 0) {
			arg[j++] = arr[i];
		}
	}
}
// Brute 
void brute_force(unsigned int n) {
	unsigned int p, q, i, j = 0;
	unsigned int* arr = (unsigned int*)malloc(sizeof(unsigned int)*n);

	find_primes(arr, n);
	unsigned int s = count(arr, n);

	double secs = pow(s, 2) / SPEED;
	int days = ceil(secs / (3600 * 24));
	(secs < 3600 * 24) ? days = 0 : not();
	printf("\tIn reality : \n\t\tIn worst-case scenario, it will take %f seconds or %d day(s)\n", secs, days);
	unsigned int* arg = (unsigned int*)malloc(sizeof(unsigned int)*s);

	primes(arr, n, s, arg);

	free(arr);

	short int found = 0;
	int a, b = 0;
	for (p = 0; p < s; p++) {
		for (q = 0; q < s; q++) {
			if ((arg[p] * arg[q] == n) && (n / arg[p] == arg[q])) {
				printf("\nPrimes are : %u and %u\n", arg[p], arg[q]);
				found = 1;
				printf("\nThe results and additional data :\n");
				printf("\tNumber of primes generated to factorize %u : %u\n", n, s);
				printf("\tPrime index of p (%u) : %u\n", arg[p], p);
				printf("\tPrime index of q (%u) : %u\n", arg[q], q);
				free(arg);
				return;
			}
		}
	}
	(!found) ? printf("\nThe entered modulo cannot be factorized!(Bad modulo)\n") : not();
}

int main(int argc, char** argv) {
	unsigned int n;
	if (argc != 2) {
		printf("Please enter n : ");
		scanf("%u", &n);
	} else if (argc == 2) {
		n = atoi(argv[1]);
	} else {
		printf("Please recheck your input.\nExiting...\n");
		return EXIT_FAILURE;
	}
	printf("\nThis is a program to factorize input n.\nIf you receive Segmentation error when executing, it means that you don\'t have enough RAM capacity to hold prime numbers\n");
	clock_t begin = clock();
	double secs = (pow(n/log(n), 2)) / SPEED;
	int days = ceil(secs / (3600 * 24));
	(secs < 3600 * 24) ? days = 0 : not();
	printf("\nExpectations:\n");
	printf("\tApproximation : \n\t\tIn worst-case scenario, it will take %f seconds or %d day(s)\n", secs, days);
	brute_force(n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nExecution time in seconds : %f\n", time_spent);
	return EXIT_SUCCESS;
}
