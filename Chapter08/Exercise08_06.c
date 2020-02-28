/*
 * Exercise08_06.c
 *
 *  Created on: Feb 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>

int get_first(void);

int main(void)
{
	int ch;
	printf("Test program for get_first():\n");
	printf("You should see the first non-whitespace\n");
	printf("character echoed in the terminal:\n");
	printf("Enter a line: ");
	fflush(stdout);
	fflush(stdin);

	ch = get_first();
	printf("%c\n", ch);

	return 0;
}

int get_first(void)
{
	int ch;
	do
		ch = getchar();
	while(isspace(ch));
	fflush(stdin);
	return ch;
}
