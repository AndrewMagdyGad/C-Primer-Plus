/*
 * Exercise05_02.c
 *
 *  Created on: Sep 2, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int input;
	int counter = 0;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &input);

	while (counter <= 10)
	{
		printf("%d\n", input + counter);
		counter++;
	}
	return 0;
}
