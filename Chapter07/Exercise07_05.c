/*
 * Exercise07_05.c
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
		switch (ch)
		{
			case '.':
				printf("!");
				count1++;
				break;
			case '!':
				printf("!!");
				count2++;
				break;
			default:
				printf("%c", ch);
		}
		fflush(stdout);
	}
	printf("\n");
	printf("%u replacement(s) of . with !\n", count1);
	printf("%u replacement(s) of ! with !!\n", count2);
	return 0;
}

