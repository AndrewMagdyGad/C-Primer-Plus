/*
 * Exercise07_03.c
 *
 *  Created on: Feb 10, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define STOP 0

int main(void)
{
	long input;
	long even_sum = 0, even_count = 0, odd_sum = 0, odd_count = 0;
	printf("Enter integers (0 to stop):\n");
	fflush(stdout);
	fflush(stdin);
	while ((scanf("%ld", &input) == 1) && input != STOP)
	{
		if (input % 2 == 0)
		{
			even_sum += input;
			even_count++;
		}
		else {
			odd_sum += input;
			odd_count++;
		}
	}
	printf("Number of even integers: %ld\n", even_count);
	if (even_count > 0)
		printf("Average value of even integers: %.2f\n", (double) even_sum / even_count);
	printf("Number of odd integers: %ld\n", odd_count);
	if (odd_count > 0)
		printf("Average value of odd integers: %.2f\n", (double) odd_sum / odd_count);

	return 0;
}
