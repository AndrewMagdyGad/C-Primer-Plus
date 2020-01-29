/*
 * Exercise04_03.c
 *
 *  Created on: Aug 1, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void) {
	double number;
	printf("Enter a floating-point number: ");
	fflush(stdout);
	scanf("%lf", &number);
	printf("The input is %0.1f or %0.1e.\n", number, number);
	printf("The input is %+0.3f or %0.3E.\n", number, number);
	return 0;
}
