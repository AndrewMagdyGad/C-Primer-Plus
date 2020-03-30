/*
 * Exercise09_05.c
 *
 *  Created on: Mar 27, 2020
 *      Author: andrew
 */
#include <stdio.h>

void larger_of(double * x, double * y);

int main(void)
{
	double x, y;

	printf("Enter two numbers (non-number to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("Before calling larger_of() the two numbers are %f and %f\n", x, y);
		larger_of(&x, &y);
		printf("After calling larger_of() the two numbers are %f and %f\n", x, y);
		printf("Enter two numbers (non-number to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

void larger_of(double * x, double * y)
{
	if (*x > *y)
		*y = *x;
	else
		*x = *y;
}
