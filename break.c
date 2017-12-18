#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void not(){}
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

int count(unsigned int* arr, unsigned int size) {
	unsigned int i, k = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] != 0) k++;
	}
	return k;
}

void primes(unsigned int* arr, unsigned int size, unsigned int k, unsigned int* arg) {
	unsigned int i, l = 0;
	unsigned int j = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] != 0) {
			arg[j++] = arr[i];
		}
	}
}

void brute_force(unsigned int n) {
	unsigned int p, q, i, j = 0;
	unsigned int* arr = (unsigned int*)malloc(sizeof(unsigned int)*n);
	find_primes(arr, n);
	unsigned int s = count(arr, n);
	unsigned int* arg = (unsigned int*)malloc(sizeof(unsigned int)*s);
	primes(arr, n, s, arg);
	free(arr);
	for (p = 0; p < s; p++) {
		for (q = 0; q < s; q++) {
			if (arg[p] * arg[q] == n) {
				printf("Primes are : %u and %u", arg[p], arg[q]);
				free(arg);
				return;
			}
		}
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Please enter n.\n");
		return EXIT_FAILURE;
	}
	clock_t begin = clock();
	unsigned int n = atoi(argv[1]);;
	double secs = (pow(n/log(n), 2)) / CLOCKS_PER_SEC;
	int days = ceil(secs / (3600 * 24));
	(secs < 3600 * 24) ? days = 0 : not();
	printf("In worst-case scenario, it will take %f seconds or %d day(s)\n", secs, days);
	brute_force(n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nExecution time in seconds : %f\n", time_spent);
	return EXIT_SUCCESS;
}
