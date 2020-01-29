/*
 * Exercise06_17.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	const double CHUCKIE_BASE = 1e6;
	const double INTEREST = 0.08;
	const double WITHDRAWAL_AMOUNT = 1e5;
	double balance = CHUCKIE_BASE;
	int years = 0;
	while (balance > 0) {
		balance -= WITHDRAWAL_AMOUNT;
		balance += INTEREST * balance;
		years++;
	}
	printf("After %d years, Chuckie`s balance will be $%.3f\n", years, balance);
	return 0;
}
