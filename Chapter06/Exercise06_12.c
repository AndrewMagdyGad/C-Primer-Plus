/*
 * Exercise06_12.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	long limit, index, sign;
	double series1, series2;
	printf("Enter a number of terms to sum (enter zero or negative value to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%ld", &limit) != 1) {
		while (getchar() != '\n')
			continue;
		printf("Invalid input, please enter an integer value: ");
		fflush(stdout);
		fflush(stdin);
	}
	while (limit > 0) {
		sign = 1;
		series1 = 0;
		series2 = 0;
		for (index = 1; index <= limit; index++) {
			series1 += 1.0 / index;
			series2 += 1.0 / index * sign;
			sign = -1 * sign;
		}
		printf("The %ldth partial sum for series 1 is: %.5f\n", limit, series1);
		printf("The %ldth partial sum for series 2 is: %.5f\n", limit, series2);
		printf("Enter a number of terms to sum (enter zero or negative value to quit): ");
		fflush(stdout);
		fflush(stdin);
		while (scanf("%ld", &limit) != 1) {
			while (getchar() != '\n')
				continue;
			printf("Invalid input, please enter an integer value: ");
			fflush(stdout);
			fflush(stdin);
		}
	}
	printf("Done.\n");
	// Answer: Series 1 has no limit. Series 2 appears to be bounded above
	return 0;
}
