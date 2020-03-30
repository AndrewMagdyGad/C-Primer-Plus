/*
 * Exercise09_11.c
 *
 *  Created on: Mar 30, 2020
 *      Author: andrew
 */
#include <stdio.h>

long fibonacci(long n);

int main(void)
{
	long number;

	printf("Enter a positive integer (invalid value to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%ld", &number) == 1 && number > 0)
	{
		printf("Fibonacci #%ld = %ld\n", number, fibonacci(number));
		printf("Enter a positive integer (invalid value to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

long fibonacci(long n)
{
	long index, result = 1, number1 = 0, number2 = 0;

	if (n == 1) return 0;
	if (n == 2) return 1;

	for (index = 3; index <= n; index++)
	{
		number1 = number2;
		number2 = result;
		result = number1 + number2;
	}

	return result;
}
