/*
 * Exercise06_08.c
 *
 *  Created on: Jan 27, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	double number1, number2;
	printf("Enter two numbers (enter non-numeric value to terminate the program): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf %lf", &number1, &number2) == 2) {
		printf("(%.3f - %.3f) / (%.3f * %.3f) = %.3f\n", number1, number2, number1, number2, (number1 - number2) / (number1 * number2));
		printf("Enter next two numbers (enter  non-numeric value to terminate the program): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Done.\n");
	return 0;
}
