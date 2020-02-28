/*
 * Exercise08_08.c
 *
 *  Created on: Feb 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>

void print_menu(void);
int get_first(void);
float get_number(void);

int main(void)
{
	int operation;
	float num1, num2;

	print_menu();
	while ((operation = get_first()) != 'q')
	{
		printf("Enter first number: ");
		fflush(stdout);
		fflush(stdin);
		num1 = get_number();
		printf("Enter second number: ");
		fflush(stdout);
		fflush(stdin);
		num2 = get_number();

		switch (operation)
		{
			case 'a':
				printf("%.3f + %.3f = %.3f\n", num1, num2, num1 + num2);
				break;
			case 's':
				printf("%.3f - %.3f = %.3f\n", num1, num2, num1 - num2);
				break;
			case 'm':
				printf("%.3f * %.3f = %.3f\n", num1, num2, num1 * num2);
				break;
			case 'd':
				while (num2 == 0)
				{
					printf("Enter a number other than 0: ");
					fflush(stdout);
					fflush(stdin);
					num2 = get_number();
				}
				printf("%.3f / %.3f = %.3f\n", num1, num2, num1 / num2);
				break;
			default :
				printf("I do not recognize that input. Try again.\n");
		}
		print_menu();
	}
	printf("Done.\n");
	return 0;
}

void print_menu(void)
{
	printf("Enter the operation of your choice:\n");
	printf("a. add            s. subtract\n");
	printf("m. multiply       d. divide\n");
	printf("q. quit\n");
	fflush(stdout);
	fflush(stdin);
}

int get_first(void)
{
	int ch;
	do
		ch = tolower(getchar());
	while (isspace(ch));

	while (getchar() != '\n')
		continue;

	return ch;
}

float get_number(void)
{
	int ch;
	float num;

	while (scanf("%f", &num) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);

		printf(" is not a number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
		fflush(stdout);
		fflush(stdin);
	}

	return num;
}
