/*
 * Exercise09_02.c
 *
 *  Created on: Mar 24, 2020
 *      Author: andrew
 */
#include <stdio.h>

void chline(char ch, unsigned int i, unsigned int j);

int main(void)
{
	char ch;
	unsigned int i, j;

	printf("Enter a character and two non-negative integers: ");
	fflush(stdout);
	fflush(stdin);
	while (scanf(" %c %u %u", &ch, &i, &j) == 3)
	{
		if (i > j)
			printf("The first integer should be smaller than or equal to the second integer\n");
		else
			chline(ch, i, j);
		printf("Enter a character and two non-negative integers: ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

void chline(char ch, unsigned int i, unsigned int j)
{
	unsigned int column = 1;
	while (column <= j)
	{
		if (column < i)
			putchar(' ');
		else
			putchar(ch);
		column++;
	}
	putchar('\n');
}
