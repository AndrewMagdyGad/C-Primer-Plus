/*
 * Exercise09_01.c
 *
 *  Created on: Mar 24, 2020
 *      Author: andrew
 */
#include <stdio.h>

double min(double x, double y);

int main(void)
{
	double x, y;

	printf("Enter two numbers (non-number input to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The smaller number is %f.\n", min(x, y));
		printf("Next two values (non-number input to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

double min(double x, double y)
{
	return x < y ? x : y;
}
