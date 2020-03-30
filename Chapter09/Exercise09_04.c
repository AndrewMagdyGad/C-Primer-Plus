/*
 * Exercise09_04.c
 *
 *  Created on: Mar 27, 2020
 *      Author: andrew
 */
#include <stdio.h>

double harmonic_mean(double a, double b);

int main(void)
{
	double a, b;
	printf("Harmonic means\n");
	printf("Enter two numbers (non-number to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf %lf", &a, &b) == 2)
	{
		printf("The harmonic mean between %f and %f is %f\n", a, b, harmonic_mean(a, b));
		printf("Enter two numbers (non-number to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

double harmonic_mean(double a, double b)
{
	return 2 / (1 / a + 1 / b);
}
