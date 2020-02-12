/*
 * Exercise07_08.c
 *
 *  Created on: Feb 11, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define BASIC_RATE1 8.75
#define BASIC_RATE2 9.33
#define BASIC_RATE3 10.00
#define BASIC_RATE4 11.20
#define WEEKLY_HOURS 40.0
#define OVERTIME 1.5
#define AMOUNT1 300.0
#define AMOUNT2 150.0
#define TAX_RATE1 0.15
#define TAX_RATE2 0.2
#define TAX_RATE3 0.25

void print_menu(void);
int get_valid_input(void);
double get_weekly_hours(void);

int main(void)
{
	double rate, hours, gross, net, taxes;
	int input = get_valid_input();
	while (input != 5)
	{
		switch (input)
		{
			case 1:
				rate = BASIC_RATE1;
				break;
			case 2:
				rate = BASIC_RATE2;
				break;
			case 3:
				rate = BASIC_RATE3;
				break;
			case 4:
				rate = BASIC_RATE4;
		}

		hours = get_weekly_hours();
		if (hours > WEEKLY_HOURS)
			gross = WEEKLY_HOURS * rate + (hours - WEEKLY_HOURS) * rate * OVERTIME;
		else
			gross = hours * rate;

		if (gross <= AMOUNT1)
			taxes = gross * TAX_RATE1;
		else if (gross <= AMOUNT1 + AMOUNT2)
			taxes = AMOUNT1 * TAX_RATE1 + (gross - AMOUNT1) * TAX_RATE2;
		else
			taxes = AMOUNT1 * TAX_RATE1 + AMOUNT2 * TAX_RATE2 + (gross - AMOUNT1 - AMOUNT2) * TAX_RATE3;

		net = gross - taxes;
		printf("gross: $%.2f, taxes: $%.2f, net: $%.2f\n\n", gross, taxes, net);
		input = get_valid_input();
	}
	printf("Done.\n");

	return 0;
}

void print_menu(void)
{
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $%.2f/hr 				2) $%.2f/hr\n", BASIC_RATE1, BASIC_RATE2);
	printf("3) $%.2f/hr 				4) $%.2f/hr\n", BASIC_RATE3, BASIC_RATE4);
	printf("5) quit \n");
	printf("*****************************************************************\n");
	fflush(stdout);
	fflush(stdin);
}

int get_valid_input(void)
{
	int input;
	print_menu();
	while (scanf("%d", &input) != 1 || input < 1 || input > 5)
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid Input, please enter an integer value between 1 and 5.\n");
		printf("Here is the main menu again\n");
		print_menu();
	}
	return input;
}

double get_weekly_hours(void)
{
	double hours;
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
	return hours;
}
