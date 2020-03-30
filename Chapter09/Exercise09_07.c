/*
 * Exercise09_07.c
 *
 *  Created on: Mar 27, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>

int letter_location(char ch);

int main(void)
{
	char ch;
	int location;

	printf("Enter characters (end-of-file to quit): ");
	fflush(stdout);
	fflush(stdin);
	while ((ch = getchar()) != EOF)
	{
		location = letter_location(ch);
		if (location == -1)
			printf("%c is not a letter\n", ch);
		else
			printf("%c is a letter: location = %d\n", ch, location);
		fflush(stdout);
	}
	printf("Bye!\n");
	return 0;
}

int letter_location(char ch)
{
	if (isalpha(ch))
	{
		ch = tolower(ch);
		return ch - 'a' + 1;
	}
	return -1;
}
