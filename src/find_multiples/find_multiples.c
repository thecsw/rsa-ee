#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void not()
{
}

int main(int argc, char **argv)
{
	printf("\n\tProgram to find multiples of n\n\n");
	(argc != 2) ? printf("\tExiting...\n"), abort() : not();
	clock_t begin = clock();
	int i, k = 0;
	int n = atoi(1 [argv]);
	for (i = 1; i <= n; i++)
		(n % i == 0) ? k++,
			printf("\t%d is an %d th multiple of %d\n", i, k, n) :
			       not();
	printf("\n\tThere are %d multiples of %d\n", k, n);
	(k == 2) ? printf("\t%d is a prime!\n", n) : not();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\tExecution time in seconds : %f\n", time_spent);
	return EXIT_SUCCESS;
}
