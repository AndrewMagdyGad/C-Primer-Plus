/*
 * Exercise09_09.c
 *
 *  Created on: Mar 30, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h> /* to use the abs() function */

double power(double base, int exponent);

int main(void)
{
	double base, result;
	int exponent;

	printf("Enter a number and the integer power to which\n"
			"the number will be raised. (enter invalid value to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf %d", &base, &exponent) == 2)
	{
		result = power(base, exponent);
		printf("%.3g to the power %d is %.5g\n", base, exponent, result);
		printf("Enter next pair of numbers or any invalid value to quit: ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Hope you enjoyed this power trip -- bye!\n");
	return 0;
}

double power(double base, int exponent)
{
	double result;

	if (exponent == 0)
	{
		if (base == 0)
			printf("0 to the 0 undefined; using 1 as the value\n");
		return 1.0;
	}
	else if (base == 0)
		return 0.0;

	result = base * power(base, abs(exponent) - 1);
	if (exponent < 0) result = 1 / result;

	return result;
}
