#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void not(){}
void find_primes(int* arr, int size) {
	int i = 0;
	for (i = 0; i < size; i++) arr[i] = i;
	for (i = 2; i < size; i++) {
		if (arr[i] != 0) {
			int j = i;
			while (j + arr[i] < size) arr[j += arr[i]] = 0;
		}
	}
}

int count(int* arr, int size) {
	int i, k = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] != 0) k++;
	}
	return k;
}

void primes(int* arr, int size, int k, int* arg) {
	int i, l = 0;
	int j = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] != 0) {
			arg[j++] = arr[i];
		}
	}
}

void brute_force(int n) {
	int p, q, i = 0;
	int* arr = (int*)malloc(sizeof(int)*n);
	find_primes(arr, n);
	int s = count(arr, n);
	int* arg = (int*)malloc(sizeof(int)*s);
	primes(arr, n, s, arg);
	free(arr);
	for (p = 0; p < s; p++) {
		for (q = 0; q < s; q++) {
			if (arg[p] * arg[q] == n) {
				printf("Primes are : %d and %d", arg[p], arg[q]);
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
	int n;
	n = atoi(argv[1]);
	double secs = (pow(n/log(n), 2)) / CLOCKS_PER_SEC;
	int years = ceil(secs / (3600 * 24 * 365));
	printf("In worst-case scenario, it will take %f seconds or %d years\n", secs, years);
	brute_force(n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nExecution time in seconds : %f\n", time_spent);
	return EXIT_SUCCESS;
}
