/*
 * Exercise07_04.c
 *
 *  Created on: Feb 10, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	unsigned count1 = 0, count2 = 0;
	printf("Enter input (%c to stop):\n", STOP);
	fflush(stdout);
	fflush(stdin);
	while ((ch = getchar()) != STOP)
	{
		if (ch == '.')
		{
			printf("!");
			count1++;
		}
		else if (ch == '!')
		{
			printf("!!");
			count2++;
		}
		else
			printf("%c", ch);
		fflush(stdout);
	}
	printf("\n");
	printf("%u replacement(s) of . with !\n", count1);
	printf("%u replacement(s) of ! with !!\n", count2);
	return 0;
}
