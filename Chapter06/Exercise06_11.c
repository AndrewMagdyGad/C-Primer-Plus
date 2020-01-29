/*
 * Exercise06_11.c
 *
 *  Created on: Jan 28, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	long array[8];
	long index;
	printf("Enter eight integers: ");
	fflush(stdout);
	fflush(stdin);
	for (index = 0; index < 8; index++) {
		while (scanf("%ld", &array[index]) != 1) {
			while (getchar() != '\n')
				continue;
			printf("Invalid input, please enter an integer value: ");
			fflush(stdout);
			fflush(stdin);
		}
	}

	printf("The values you have entered in a reverse order:\n");
	fflush(stdout);
	fflush(stdin);
	for (index = 7; index >= 0; index--)
		printf("%ld\n", array[index]);

	return 0;
}
