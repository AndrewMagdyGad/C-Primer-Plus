/*
 * Exercise05_06.c
 *
 *  Created on: Sep 7, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int count = 0, sum = 0;
	int number;
	printf("Enter the upper limit: ");
	fflush(stdout);
	scanf("%d", &number);

	while (count++ < number)
	{
		sum += count * count;
	}
	printf("The sum of the first %d squares is: %d\n", number, sum);
	return 0;
}
