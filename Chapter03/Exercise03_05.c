/*
 * Exercise03_05.c
 *
 *  Created on: Jul 3, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	unsigned int SECONDS_PER_YEAR = 31560000;
	unsigned int age;
	printf("What is your age (in years)?: ");
	fflush(stdout);
	scanf("%u", &age);
	printf("You are %u seconds old!\n", SECONDS_PER_YEAR * age);
	return 0;
}
