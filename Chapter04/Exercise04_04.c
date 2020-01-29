/*
 * Exercise04_04.c
 *
 *  Created on: Aug 1, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void) {
	const float INCHES_PER_FEET = 12;
	float height;
	char name[40];
	printf("Enter your name: ");
	fflush(stdout);
	scanf("%s", name);
	printf("Enter your height in inches: ");
	fflush(stdout);
	scanf("%f", &height);
	printf("%s, you are %0.3f feet tall\n", name, height / INCHES_PER_FEET);
	return 0;
}
