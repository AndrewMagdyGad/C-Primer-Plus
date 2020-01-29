/*
 * Exercise06_06.c
 *
 *  Created on: Jan 27, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	long long lower = 1, upper = 0, index;
	do {
		printf("Enter the lower and upper limits for the table: ");
		fflush(stdout);
		fflush(stdin);
		if (scanf("%lld %lld", &lower, &upper) != 2)
			while (getchar() != '\n')
				continue;
	} while (lower > upper);

	printf("Integer        | Square        | Cube          \n");
	printf("---------------|---------------|---------------\n");
	for (index = lower; index <= upper; index++)
	{
		printf("%-15lld| %-14lld| %-14lld", index, index * index, index * index * index);
		printf("\n");
	}
	return 0;
}
