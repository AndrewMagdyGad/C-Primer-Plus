/*
 * Exercise06_15.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define SIZE 255

int main(void)
{
	char array[SIZE];
	int index = 0;
	printf("Enter a line to reverse (no more than 255 characters): ");
	fflush(stdout);
	fflush(stdin);
	while (index < SIZE && scanf("%c", &array[index]) && array[index] != '\n')
		index++;
	printf("The reversed line: ");
	for (index = index - 1; index >= 0; index--)
		printf("%c", array[index]);
	printf("\n");
	return 0;
}
