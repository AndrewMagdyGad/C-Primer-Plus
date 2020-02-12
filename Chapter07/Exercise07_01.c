/*
 * Exercise07_01.c
 *
 *  Created on: Feb 9, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	unsigned int space_characters = 0, newline_characters = 0, other_characters = 0;
	printf("Enter input (%c to stop):\n", STOP);
	fflush(stdout);
	fflush(stdin);
	while ((ch = getchar()) != STOP)
	{
		if (ch == ' ')
			space_characters++;
		else if (ch == '\n')
			newline_characters++;
		else
			other_characters++;
	}
	printf("\nYou have entered %u spaces, %u newlines, and %u others\n",
			space_characters, newline_characters, other_characters);

	return 0;
}
