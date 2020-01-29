/*
 * Exercise03_07.c
 *
 *  Created on: Jul 3, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	float CENTI_PRT_INCH = 2.54;
	float height;
	printf("Enter your height (in inches): ");
	fflush(stdout);
	scanf("%f", &height);
	printf("You are %f centimeters tall.\n", height * CENTI_PRT_INCH);
	return 0;
}
