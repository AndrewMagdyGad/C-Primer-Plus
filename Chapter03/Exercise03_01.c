/*
 * Exercise03_01.c
 *
 *  Created on: Jul 2, 2019
 *      Author: andrew
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	int int_overflow;
	float flt_overflow, flt_underflow;

	int_overflow = INT_MAX + 1;
	flt_overflow = FLT_MAX * 2.;
	flt_underflow = FLT_MIN / 2.;

	printf("Max integer: %d \tMax integer + 1: %d\n", INT_MAX, int_overflow);
	printf("Max float: %f \tMax float * 2: %f\n", FLT_MAX, flt_overflow);
	printf("Min float: %f \tMin float / 2: %f\n", FLT_MIN, flt_underflow);

	return 0;
}
