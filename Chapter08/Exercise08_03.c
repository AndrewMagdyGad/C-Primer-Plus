/*
 * Exercise08_03.c
 *
 *  Created on: Feb 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	unsigned long lowercase_letters = 0, uppercase_letters = 0, other_letters = 0;
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			uppercase_letters++;
		else if (islower(ch))
			lowercase_letters++;
		else
			other_letters++;
	}

	printf("Character Counts:\n");
	printf("%lu uppercase characters read\n", uppercase_letters);
	printf("%lu lowercase characters read\n", lowercase_letters);
	printf("%lu other characters read\n", other_letters);
	return 0;
}
