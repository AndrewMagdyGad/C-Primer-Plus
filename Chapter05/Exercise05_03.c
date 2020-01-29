/*
 * Exercise05_03.c
 *
 *  Created on: Sep 2, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	const int DAYS_PER_WEEK = 7;
	int total_days, weeks, days;

	printf("Enter the number of days: ");
	fflush(stdout);
	scanf("%d", &total_days);

	while (total_days > 0)
	{
		weeks = total_days / DAYS_PER_WEEK;
		days = total_days % DAYS_PER_WEEK;
		printf("%d day(s) are %d week(s), %d day(s).\n", total_days, weeks, days);
		printf("Enter the number of days (0 or less to end): ");
		fflush(stdout);
		scanf("%d", &total_days);
	}
	printf("Done!\n");

	return 0;
}
