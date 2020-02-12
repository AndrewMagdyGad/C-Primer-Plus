/*
 * Exercise07_11.c
 *
 *  Created on: Feb 12, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>

#define ARTICHOKE_PRICE_PER_LB 2.05
#define BEET_PRICE_PER_LB 1.15
#define CARROT_PRICE_PER_LB 1.09

#define SHIPPING_5LB 6.50
#define SHIPPING_20LB 14.00
#define SHIPPING_OVER_20LB_RATE 0.5

#define DISCOUNT_RATE 0.05

int main(void)
{
	double artichoke_weight = 0, beet_weight = 0, carrot_weight = 0, total_weight;
	double artichoke_price, beet_price, carrot_price, subtotal, discount, shipping, total;
	double weight;
	char option;
	printf("ABC Mail Order Grocery\n");
	printf("What would you like to order?\n");
	printf("a) artichokes  b) beets  c) carrots  q) quit\n");
	fflush(stdout);
	fflush(stdin);
	while ((option = tolower(getchar())) && option != 'q')
	{
		while (getchar() != '\n')
			continue;
		switch (option)
		{
			case 'a':
				printf("Enter pounds of artichokes: ");
				fflush(stdout);
				fflush(stdin);
				if (scanf("%lf", &weight) == 1 && weight >= 0)
					artichoke_weight += weight;
				else
					printf("Invalid Input, please enter a positive number.\n");
				break;
			case 'b':
				printf("Enter pounds of beets: ");
				fflush(stdout);
				fflush(stdin);
				if (scanf("%lf", &weight) == 1 && weight >= 0)
					beet_weight += weight;
				else
					printf("Invalid Input, please enter a positive number.\n");
				break;
			case 'c':
				printf("Enter pounds of carrots: ");
				fflush(stdout);
				fflush(stdin);
				if (scanf("%lf", &weight) == 1 && weight >= 0)
					carrot_weight += weight;
				else
					printf("Invalid Input, please enter a positive number.\n");
				break;
			default:
				if (isprint(option))
					printf("%c is not a valid choice.\n", option);
				else
					printf("non-printing character is not a valid choice.\n");
		}
		printf("What would you like to order?\n");
		printf("a) artichokes  b) beets  c) carrots  q) quit\n");
		fflush(stdout);
		fflush(stdin);
	}
	artichoke_price = artichoke_weight * ARTICHOKE_PRICE_PER_LB;
	beet_price = beet_weight * BEET_PRICE_PER_LB;
	carrot_price = carrot_weight * CARROT_PRICE_PER_LB;
	subtotal = artichoke_price + beet_price + carrot_price;
	total_weight = artichoke_weight + beet_weight + carrot_weight;

	// calculate the shipping price
	if (total_weight <= 0)
		shipping = 0;
	else if (total_weight <= 5)
		shipping = SHIPPING_5LB;
	else if (total_weight < 20)
		shipping = SHIPPING_20LB;
	else
		shipping = 14 + SHIPPING_OVER_20LB_RATE * total_weight;

	// calculate the discount
	discount = (subtotal >= 100)? DISCOUNT_RATE * subtotal : 0;

	// calculate the total price
	total = subtotal + shipping - discount;

	printf("Your order:\n");
	printf("%.2f lbs of artichokes at $%.2f per pound:$ %.2f\n",
			artichoke_weight, ARTICHOKE_PRICE_PER_LB, artichoke_price);
	printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
			beet_weight, BEET_PRICE_PER_LB, beet_price);
	printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
			carrot_weight, CARROT_PRICE_PER_LB, carrot_price);
	printf("Total cost of vegetables: $%.2f\n", subtotal);
	if (subtotal >= 100)
		printf("Volume discount: $%.2f\n", discount);
	printf("Shipping: $%.2f\n", shipping);
	printf("Total charges: $%.2f\n", total);

	return 0;
}
