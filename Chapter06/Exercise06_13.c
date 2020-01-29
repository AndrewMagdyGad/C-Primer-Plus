/*
 * Exercise06_13.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define SIZE 8

int main(void)
{
	long power, index, array[SIZE];
	power = 1;
	for (index = 0; index < SIZE; index++) {
		array[index] = power;
		power *= 2;
	}
	printf("The first eight powers of 2 (starting from 0): ");
	index = 0;
	do
		printf("%ld ", array[index++]);
	while (index < SIZE);
	printf("\n");

	return 0;
}
