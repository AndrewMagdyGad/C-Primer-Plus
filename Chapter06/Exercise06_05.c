/*
 * Exercise06_05.c
 *
 *  Created on: Jan 25, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	char rows, i;
	char input;
	printf("Enter an upper case letter: ");
	fflush(stdout);
	fflush(stdin);
	while (!(scanf(" %c", &input) == 1 && input >= 'A' && input <= 'Z'))
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid input, please enter an upper case letter: ");
		fflush(stdout);
		fflush(stdin);
	}

	for (rows = 0; rows <= (input - 'A'); rows++)
	{
		for (i = (input - 'A'); i > rows; i--)
			printf(" ");
		for (i = 'A'; i - 'A' <= rows; i++)
			printf("%c", i);
		for (i = 'A' + rows - 1; i >= 'A'; i--)
			printf("%c", i);
		printf("\n");
	}
	return 0;
}
