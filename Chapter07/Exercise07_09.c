/*
 * Exercise07_09.c
 *
 *  Created on: Feb 12, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdbool.h>

int get_limit(void);

int main(void)
{
	int number, divisor;
	bool isPrime;
	int limit = get_limit();
	while (limit != 0)
	{
		if (limit > 1)
			printf("Here are the prime numbers up through %d\n", limit);
		else
			printf("No primes.\n");
		for (number = 2; number <= limit; number++)
		{
			for (divisor = 2, isPrime = true; divisor * divisor <= number; divisor++)
			{
				if (number % divisor == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				printf("%d is prime.\n", number);
		}
		limit = get_limit();
	}
	printf("Done.\n");
	return 0;
}

int get_limit(void)
{
	int limit;
	printf("Enter a positive integer (0 to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%d", &limit) != 1 || limit < 0)
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid Input, please enter a positive integer (0 to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	return limit;
}
