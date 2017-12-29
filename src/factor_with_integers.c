#include<stdio.h>
#include<time.h>
#include <stdlib.h>
voidnot(){}
int find_val(int* arr, int size, int val) {
	int i = 0;
	for(i = 0; i < size; i++) if(arr[i] == val) return 1;
	return 0;
}

void brute_force(int n) {
	int p, q, i = 0;
	int arr[100];
	for(p = 2; p < n; p++) for(q = 2; q < n; q++) if ((p * q == n) && (find_val(arr, i, p) == 0)) {
				printf("Primes for %d are : %d and %d\n", n, p, q);
				arr[i++] = p;
				arr[i++] = q;
			}
}

int main(int argc, char** argv) {
	if(argc != 2) {
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
