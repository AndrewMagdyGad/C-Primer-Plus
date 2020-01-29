/*
 * Exercise06_10.c
 *
 *  Created on: Jan 27, 2020
 *      Author: andrew
 */
#include <stdio.h>

long long sum_of_squares(long long lower, long long upper);

int main(void)
{
	long long lower, upper;
	printf("Enter lower and upper integer limits: ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lld %lld", &lower, &upper) == 2 && lower < upper) {
		printf("The sums of the squares from %lld to %lld is %lld\n",
				lower * lower, upper * upper, sum_of_squares(lower, upper));
		printf("Enter next set of limits: ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Done.\n");
	return 0;
}

long long sum_of_squares(long long lower, long long upper)
{
	long long index, sum = 0;
	for (index = lower; index <= upper; index++) {
		sum += index * index;
	}
	return sum;
}
