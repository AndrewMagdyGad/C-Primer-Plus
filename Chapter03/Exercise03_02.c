/*
 * Exercise03_02.c
 *
 *  Created on: Jul 2, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int ascii;
	printf("Enter an ASCII code: ");
	fflush(stdout);
	scanf("%d", &ascii);
	printf("%d is the ASCII code for %c.\n", ascii, ascii);
	return 0;
}
