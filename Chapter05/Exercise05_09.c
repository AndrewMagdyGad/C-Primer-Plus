/*
 * Exercise05_09.c
 *
 *  Created on: Sep 7, 2019
 *      Author: andrew
 */
#include <stdio.h>

void Temperatures(double fahrenheit);

int main(void)
{
	double fahrenheit;
	printf("This program converts fahrenheit to celsius and kelvin.\n");
	printf("Enter a temperature in degrees fahrenheit (q to quit): ");
	fflush(stdout);
	while(scanf("%lf", &fahrenheit) == 1)
	{
		Temperatures(fahrenheit);
		printf("Enter a temperature in degrees fahrenheit (q to quit): ");
		fflush(stdout);
	}
	printf("Done\n");

	return 0;
}

void Temperatures(double fahrenheit)
{
	const double FAHR_TO_CEL_SCALE = 5.0 / 9.0;
	const double FAHR_TO_CEL_OFFSET = -32.0;
	const double CEL_TO_KEL_OFFSET = 273.16;

	double celsius = FAHR_TO_CEL_SCALE * (fahrenheit + FAHR_TO_CEL_OFFSET);
	double kelvin = celsius + CEL_TO_KEL_OFFSET;

	printf("%.2f degrees fahrenheit is %.2f degrees celsius or %.2f degrees kelvin.\n",
			fahrenheit, celsius, kelvin);
}
