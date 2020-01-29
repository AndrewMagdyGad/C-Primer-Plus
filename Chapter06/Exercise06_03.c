/*
 * Exercise06_03.c
 *
 *  Created on: Jan 25, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int rows, columns;
	for (rows = 0; rows < 6; rows++) {
		for (columns = 0; columns <= rows; columns++)
			printf("%c", 'F' - columns);
		printf("\n");
	}
	return 0;
}
