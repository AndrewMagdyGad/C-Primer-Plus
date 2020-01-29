/*
 * Exercise06_02.c
 *
 *  Created on: Jan 25, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int rows, columns;
	for (rows = 0; rows < 5; rows++) {
		for (columns = 0; columns <= rows; columns++)
			printf("$");
		printf("\n");
	}
	return 0;
}
