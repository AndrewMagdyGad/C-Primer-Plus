/*
 * Exercise05_04.c
 *
 *  Created on: Sep 2, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void)
{
	const double CENTIMETERS_PER_INCH = 2.54;
	const int INCHES_PER_FOOT = 12;
	double centimeters, height_in, inches;
	int feet;

	printf("Enter a height in centimeters: ");
	fflush(stdout);
	scanf("%lf", &centimeters);

	while (centimeters > 0)
	{
		height_in = centimeters / CENTIMETERS_PER_INCH;
		feet = (int) height_in / INCHES_PER_FOOT;
		inches = height_in - feet * INCHES_PER_FOOT;
		printf("%.1f cm = %d feet, %.1f inches\n", centimeters, feet, inches);
		printf("Enter a height in centimeters (<=0 to quit): ");
		fflush(stdout);
		scanf("%lf", &centimeters);
	}
	printf("bye\n");

	return 0;
}
