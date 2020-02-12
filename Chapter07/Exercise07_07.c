/*
 * Exercise07_07.c
 *
 *  Created on: Feb 11, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define BASIC_RATE 10.0
#define WEEKLY_HOURS 40.0
#define OVERTIME 1.5
#define AMOUNT1 300.0
#define AMOUNT2 150.0
#define TAX_RATE1 0.15
#define TAX_RATE2 0.2
#define TAX_RATE3 0.25

int main(void)
{
	double hours, gross, net, taxes;
	printf("Enter the number of hours worked this week: ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf", &hours) != 1)
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid Input, please enter the number of hours worked this week: ");
		fflush(stdout);
		fflush(stdin);
	}
	if (hours > WEEKLY_HOURS)
		gross = WEEKLY_HOURS * BASIC_RATE + (hours - WEEKLY_HOURS) * BASIC_RATE * OVERTIME;
	else
		gross = hours * BASIC_RATE;

	if (gross <= AMOUNT1)
		taxes = gross * TAX_RATE1;
	else if (gross <= AMOUNT1 + AMOUNT2)
		taxes = AMOUNT1 * TAX_RATE1 + (gross - AMOUNT1) * TAX_RATE2;
	else
		taxes = AMOUNT1 * TAX_RATE1 + AMOUNT2 * TAX_RATE2 + (gross - AMOUNT1 - AMOUNT2) * TAX_RATE3;

	net = gross - taxes;
	printf("gross: $%.2f, taxes: $%.2f, net: $%.2f\n", gross, taxes, net);

	return 0;
}
