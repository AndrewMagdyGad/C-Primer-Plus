/*
 * Exercise09_10.c
 *
 *  Created on: Mar 30, 2020
 *      Author: andrew
 */
#include <stdio.h>

void to_base_n(int number, int base);

int main(void)
{
	int number, base, flag;

	printf("Enter a positive integer (invalid value to quit): ");
	fflush(stdout);
	fflush(stdin);
	while (scanf("%d", &number) == 1 && number > 0)
	{
		printf("Enter number base (2-10): ");
		fflush(stdout);
		fflush(stdin);
		while (((flag = scanf("%d", &base)) == 1 && (base < 2 || base > 10)) || flag != 1)
		{
			printf("Base should be in the range 2-10: ");
			fflush(stdout);
			fflush(stdin);
		}

		printf("Base %d equivalent: ", base);
		to_base_n(number, base);
		putchar('\n');
		printf("Enter a positive integer (invalid value to quit): ");
		fflush(stdout);
		fflush(stdin);
	}
	printf("Bye!\n");
	return 0;
}

void to_base_n(int number, int base)
{
	int r;
	r = number % base;
	if (number >= base)
		to_base_n(number / base, base);
	putchar('0' + r);
}
