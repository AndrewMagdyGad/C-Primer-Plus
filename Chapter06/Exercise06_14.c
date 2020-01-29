/*
 * Exercise06_14.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define SIZE 8

int main(void)
{
	int index;
	double array1[SIZE], array2[SIZE], sum = 0;
	printf("Enter %d floating-point values: ", SIZE);
	fflush(stdout);
	fflush(stdin);
	for (index = 0; index < SIZE; index++) {
		while (scanf("%lf", &array1[index]) != 1) {
			while (getchar() != '\n')
				continue;
			printf("Invalid input, please enter a floating-point value: ");
			fflush(stdout);
			fflush(stdin);
		}
		sum += array1[index];
		array2[index] = sum;
	}
	printf("The values you have entered:\n");
	for (index = 0; index < SIZE; index++)
		printf("%12.4f ", array1[index]);
	printf("\nCumulative sum:\n");
	for (index = 0; index < SIZE; index++)
		printf("%12.4f ", array2[index]);
	printf("\n");
	return 0;
}
