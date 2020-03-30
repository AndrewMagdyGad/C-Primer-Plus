/*
 * Exercise09_06.c
 *
 *  Created on: Mar 27, 2020
 *      Author: andrew
 */
#include <stdio.h>

void sort(double * x, double * y, double * z);

int main(void)
{
	double x, y, z;

	printf("Enter three numbers (non-number to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf %lf %lf", &x, &y, &z) == 3)
	{
		printf("Before calling sort() the three numbers are %f, %f, and %f\n", x, y, z);
		sort(&x, &y, &z);
		printf("After calling sort() the three numbers are %f, %f, and %f\n", x, y, z);
		printf("Enter three numbers (non-number to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

void sort(double * x, double * y, double * z)
{
	double temp;
	if (*x > *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
	}

	if (*y > *z)
	{
		temp = *y;
		*y = *z;
		*z = temp;

		if (*x > *y)
		{
			temp = *x;
			*x = *y;
			*y = temp;
		}
	}
}
