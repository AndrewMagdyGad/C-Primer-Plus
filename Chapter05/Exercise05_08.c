/*
 * Exercise05_08.c
 *
 *  Created on: Sep 7, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	int first_operand, second_operand;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	fflush(stdout);
	scanf("%d", &second_operand);
	printf("Now enter the first operand: ");
	fflush(stdout);
	scanf("%d", &first_operand);
	while (first_operand > 0)
	{
		printf("%d %% %d is %d\n", first_operand, second_operand, first_operand % second_operand);
		printf("Enter next number for first operand (<= 0 to quit): ");
		fflush(stdout);
		scanf("%d", &first_operand);
	}
	printf("Done\n");

	return 0;
}
