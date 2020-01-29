/*
 * Exercise06_18.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define DUNBAR_NUMBER 150

int main(void)
{
	long index = 0, number_of_friends = 5;
	while (number_of_friends < DUNBAR_NUMBER) {
		printf("The number of friends for week %ld is %ld.\n", index, number_of_friends);
		index++;
		number_of_friends -= index;
		number_of_friends *= 2;
	}
	return 0;
}
