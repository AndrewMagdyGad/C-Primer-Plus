/*
 * Exercise08_01.c
 *
 *  Created on: Feb 28, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	unsigned count = 0;
	while (getchar() != EOF)
		count++;
	printf("The number of characters you have entered: %u\n", count);
	return 0;
}
