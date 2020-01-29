/*
 * Exercise05_07.c
 *
 *  Created on: Sep 7, 2019
 *      Author: andrew
 */
#include <stdio.h>

void showCube(double number);

int main(void)
{
	double number;
	printf("Enter a floating-point value: ");
	fflush(stdout);
	scanf("%lf", &number);
	showCube(number);

	return 0;
}

void showCube(double number)
{
	printf("The cube of %e is %e.\n", number, number * number * number);
}
