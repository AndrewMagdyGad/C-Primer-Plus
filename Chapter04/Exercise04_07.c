/*
 * Exercise04_07.c
 *
 *  Created on: Aug 4, 2019
 *      Author: andrew
 */
#include <stdio.h>
#include <float.h>

int main(void) {
	double double_variable = 1.0 / 3.0;
	float float_variable = 1.0 / 3.0;
	printf("%0.4f %0.4f\n", double_variable, float_variable);
	printf("%0.12f %0.12f\n", double_variable, float_variable);
	printf("%0.16f %0.16f\n", double_variable, float_variable);
	printf("DBL_DIG: %d\n", DBL_DIG);
	printf("FLT_DIG: %d\n", FLT_DIG);
	return 0;
}
