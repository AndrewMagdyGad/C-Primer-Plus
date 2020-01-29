/*
 * Exercise03_04.c
 *
 *  Created on: Jul 2, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	float number;
	printf("Enter a floating-point value: ");
	fflush(stdout);
	scanf("%f", &number);
	printf("fixed-point notation: %f\n", number);
	printf("exponential notation: %e\n", number);
	printf("p notation: %a\n", number);
	return 0;
}
