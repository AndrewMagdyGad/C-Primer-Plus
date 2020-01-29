/*
 * Exercise05_01.c
 *
 *  Created on: Aug 31, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	const int MIN_PER_HOUR = 60;
	int total_minutes, hours, minutes;

	printf("Enter the number of minutes to convert: ");
	fflush(stdout);
	scanf("%d", &total_minutes);
	while (total_minutes > 0)
	{
		hours = total_minutes / MIN_PER_HOUR;
		minutes = total_minutes % MIN_PER_HOUR;
		printf("%d minute(s) is equal to %d hour(s) and %d minute(s)\n", total_minutes, hours, minutes);
		printf("Enter next minutes value (0 or less to quit): ");
		fflush(stdout);
		scanf("%d", &total_minutes);
	}
	printf("Bye\n");

	return 0;
}
