/*
 * Exercise06_16.c
 *
 *  Created on: Jan 29, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	const double DAPHNE_BASE = 100.0;
	const double DEIRDRE_BASE = 100.0;
	const double DAPHNE_INTEREST = 0.1;
	const double DEIRDRE_INTEREST = 0.05;
	int years = 0;
	double daphne_balance = DEIRDRE_BASE;
	double deirdre_balance = DEIRDRE_BASE;

	while (deirdre_balance <= daphne_balance) {
		daphne_balance += DAPHNE_INTEREST * DAPHNE_BASE;
		deirdre_balance += DEIRDRE_INTEREST * deirdre_balance;
		years++;
	}
	printf("Investment values after %d years:\n", years);
	printf("Daphne: $%.2f\n", daphne_balance);
	printf("Deirdre: $%.2f\n", deirdre_balance);

	return 0;
}
