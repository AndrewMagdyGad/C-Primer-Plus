/*
 * Exercise07_06.c
 *
 *  Created on: Feb 10, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '#'

int main(void)
{
	char ch;
	unsigned count = 0;
	bool e_flag = false;

	printf("This program reads input and counts the number of times the\n"
			   "sequence 'ei' occurs (case insensitive).\n");
	printf("Enter input (%c to stop):\n", STOP);
	fflush(stdout);
	fflush(stdin);
	while ((ch = getchar()) != STOP)
	{
		ch = tolower(ch);
		if (ch == 'e')
			e_flag = true;
		else if (ch == 'i')
		{
			if (e_flag)
				count++;
			e_flag = false;
		}
		else
			e_flag = false;
	}
	printf("\nThe sequence 'ei' occurs %u times.\n", count);
	return 0;
}
