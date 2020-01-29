/*
 * Exercise03_08.c
 *
 *  Created on: Jul 3, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	/*
	 * If the number of cups is not an even whole number, then the number of
	 * pints will not be a whole number.
	 * So, a floating-point type make more sense for this application than
	 * an integer type.
	 */
	float PINTS_PER_CUP = 0.5;
	float OUNCES_PER_CUP = 8;
	float TABLESPOONS_PER_CUP = 2 * OUNCES_PER_CUP;
	float TEASPOONS_PER_CUP = 3 * TABLESPOONS_PER_CUP;
	float cups;
	printf("Enter an amount in cups: ");
	fflush(stdout);
	scanf("%f", &cups);
	printf("%f cups are equivalent to:\n", cups);
	printf("%f pints\n", cups * PINTS_PER_CUP);
	printf("%f ounces\n", cups * OUNCES_PER_CUP);
	printf("%f tablespoons\n", cups * TABLESPOONS_PER_CUP);
	printf("%f teaspoons\n", cups * TEASPOONS_PER_CUP);
	return 0;
}
