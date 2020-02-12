/*
 * Exercise07_02.c
 *
 *  Created on: Feb 10, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define STOP '#'

#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'
#define BACKSPACE '\b'

int main(void)
{
	char ch;
	unsigned count = 0;
	printf("ASCII Character Codes\n");
	printf("Enter input (%c to stop):\n", STOP);
	fflush(stdout);
	fflush(stdin);
	while ((ch = getchar()) != STOP)
	{
		switch (ch)
		{
			case SPACE:
				printf("(space, %3d) ", ch);
				break;
			case TAB:
				printf("(tab, %3d) ", ch);
				break;
			case NEWLINE:
				printf("(newline, %3d) ", ch);
				break;
			case BACKSPACE:
				printf("(backspace, %3d) ", ch);
				break;
			default:
				printf("(%c, %3d) ", ch, ch);
		}
		fflush(stdout);
		count++;
		if (count % 8 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;
}
