/*
 * Exercise08_02.c
 *
 *  Created on: Feb 28, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int ch;
	unsigned count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= ' ')
			printf("\'%c\': %d", ch, ch);
		else if (ch == '\n')
			printf("\'\\n\': %d", ch);
		else if (ch == '\t')
			printf("\'\\t\': %d", ch);
		else
			printf("\'^%c\': %d", ch + 64, ch);

		count++;
		if (count % 10 == 0)
			printf("\n");
		else
			printf(" ");
	}
	printf("\n");
	return 0;
}
