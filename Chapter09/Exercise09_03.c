/*
 * Exercise09_03.c
 *
 *  Created on: Mar 24, 2020
 *      Author: andrew
 */
#include <stdio.h>

void print_grid(char ch, unsigned rows, unsigned columns);

int main(void)
{
	char ch;
	unsigned rows, columns;

	printf("Enter a character, number of rows and number of columns: ");
	fflush(stdout);
	fflush(stdin);
	while (scanf(" %c %u %u", &ch, &rows, &columns) == 3)
	{
		print_grid(ch, rows, columns);
		printf("Enter a character, number of rows and number of columns: ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

void print_grid(char ch, unsigned rows, unsigned columns)
{
	unsigned i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			putchar(ch);
		putchar('\n');
	}
}
