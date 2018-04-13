#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* FUNCTION PROTOTYPES */
void
not();

unsigned int
performance();

int
count(unsigned int *arr,
	  unsigned int size);

void
brute_force(unsigned int n,
			unsigned int speed);

void
find_primes(unsigned int *arr,
			unsigned int size);

void
primes(unsigned int *arr,
	   unsigned int size,
	   unsigned int *arg);
	
/* MAIN FUNCTION */
int
main(int argc,
		 char **argv)
{
		unsigned int n;
		
		if (argc != 2) {
				printf("Please enter n : ");
				scanf(" %u", &n);
		} else if (argc == 2)
				n = atoi(argv[1]);
		else {
				printf("Please recheck your input.\nExiting...\n");
				return EXIT_FAILURE;
		}
		
		char performance_test;
		printf("\nThis is a program to factorize input n.\nIf you receive "
			   "Segmentation error when executing, it means that you don\'t have "
			   "enough RAM capacity to hold prime numbers\n");
		printf("\nBefore starting the factorization, the system performance test "
			   "shoukd be performed.\n");
		printf("It is necessary for accurate approximations of runtime.\n");
		printf("However if you don't want to run the performance test, it\'s up to "
			   "you. Run it? (Y/n) ");
		
		scanf(" %c", &performance_test);
		unsigned int SPEED;
		char reliability[15] = "";
		if (performance_test == 'Y') {
				printf("Starting the performance test...\n");
				SPEED = performance();
				printf("Finished successfully.\n");
				printf("Operations per second for your computer : %d.\n", SPEED);
		} else {
				SPEED = 400000000;
				strcat(reliability, "(UNRELIABLE!)");
		}
		
		clock_t begin = clock();
		double secs = (pow(n / log(n), 2)) / SPEED;
		int days = ceil(secs / (3600 * 24));
		(secs < 3600 * 24) ? days = 0 : not();
		printf("\nExpectations: %s\n", reliability);
		printf("\tApproximation : \n\t\tIn worst-case scenario, it will take %f "
			   "seconds or %d day(s)\n",
			   secs, days);
		
		brute_force(n, SPEED);
		
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\nExecution time in seconds : %f\n", time_spent);
		return EXIT_SUCCESS;
}

void
not()
{
}

unsigned int
performance()
{
		unsigned int i = 0;
		clock_t begin = clock();
		
		while (i < pow(10, 9))
				i++;
		clock_t end = clock();
		double time = (double)(end - begin) / CLOCKS_PER_SEC;
		return pow(10, 9) / time;
}

// By using sieve of eratosthenes, all non-primes in array arr are turned to 0
void
find_primes(unsigned int *arr,
			unsigned int size)
{
		unsigned int i, j = 0;
		
		for (i = 0; i < size; i++)
				arr[i] = i;
		
		for (i = 2; i < size; i++)
				if (arr[i] != 0) {
						j = i;
						while (j + arr[i] < size)
								arr[j += arr[i]] = 0;
				}
}

// Counting number of non-zero values in array arr
int
count(unsigned int *arr,
	  unsigned int size)
{
		unsigned int i, k = 0;
		
		for (i = 0; i < size; i++)
				if (arr[i] != 0)
						k++;
		return k;
}

// Copies all primes from array arr to new array arg
void
primes(unsigned int *arr,
	   unsigned int size,
	   unsigned int *arg)
{
		unsigned int i = 0;
		unsigned int j = 0;
		
		for (i = 0; i < size; i++)
				if (arr[i] != 0)
						arg[j++] = arr[i];
}

// Brute
void
brute_force(unsigned int n,
			unsigned int speed)
{
		unsigned int p, q = 0;
		unsigned int *arr = (unsigned int *)malloc(sizeof(unsigned int) * n);
		
		find_primes(arr, n);
		
		unsigned int s = count(arr, n);
		double secs = pow(s, 2) / speed;
		int days = ceil(secs / (3600 * 24));
		(secs < 3600 * 24) ? days = 0 : not();
		printf("\tIn reality : \n\t\tIn worst-case scenario, it will take %f seconds "
			   "or %d day(s)\n",
			   secs, days);
		
		unsigned int *arg = (unsigned int *)malloc(sizeof(unsigned int) * s);
		primes(arr, n, arg);
		free(arr);
		for (p = 0; p < s; p++)
				for (q = 0; q < s; q++)
						if ((arg[p] * arg[q] == n) && (n / arg[p] == arg[q])) {
								printf("\nPrimes are : %u and %u\n", arg[p], arg[q]);
								printf("\nThe results and additional data :\n");
								printf("\tNumber of primes generated to factorize %u : %u\n", n, s);
								printf("\tPrime index of p (%u) : %u\n", arg[p], p);
								printf("\tPrime index of q (%u) : %u\n", arg[q], q);
								free(arg);
								return;
						}
		
		printf("\nThe entered modulo cannot be factorized!(Bad modulo)\n");
}
