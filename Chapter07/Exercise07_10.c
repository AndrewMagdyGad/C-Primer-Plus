/*
 * Exercise07_10.c
 *
 *  Created on: Feb 12, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define SINGLE 1
#define HEAD_OF_HOUSEHOLD 2
#define MARRIED_JOINT 3
#define MARRIED_SEPARATE 4
#define EXIT 5
#define RATE1 0.15
#define RATE2 0.28
#define AMOUNT1 17850.0
#define AMOUNT2 23900.0
#define AMOUNT3 29750.0
#define AMOUNT4 14875.0

void print_menu(void);
int get_valid_input(void);
double get_taxable_income(void);

int main(void)
{
	double base_amount, income, taxes;
	int input = get_valid_input();
	while (input != 5)
	{
		switch (input)
		{
			case SINGLE:
				base_amount = AMOUNT1;
				break;
			case HEAD_OF_HOUSEHOLD:
				base_amount = AMOUNT2;
				break;
			case MARRIED_JOINT:
				base_amount = AMOUNT3;
				break;
			case MARRIED_SEPARATE:
				base_amount = AMOUNT4;
		}

		income = get_taxable_income();
		if (income > base_amount)
			taxes = base_amount * RATE1 + (income - base_amount) * RATE2;
		else
			taxes = income * RATE1;
		printf("taxes: $%.2f\n\n", taxes);
		input = get_valid_input();
	}
	printf("Done.\n");

	return 0;
}

void print_menu(void)
{
	printf("*****************************************************************\n");
	printf("Enter your tax category (1-4) or 5 to quit:\n");
	printf("1) Single   				2) Head of Household\n");
	printf("3) Married, Joint 			4) Married, Separate\n");
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

double get_taxable_income(void)
{
	double income;
	printf("Enter your taxable income: ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%lf", &income) != 1 || income < 0)
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid Input, please enter a positive number: ");
		fflush(stdout);
		fflush(stdin);
	}
	return income;
}
