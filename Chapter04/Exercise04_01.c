/*
 * Exercise04_01.c
 *
 *  Created on: Jul 30, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void) {
	char first_name[40], last_name[40];
	printf("Enter your first name: ");
	fflush(stdout);
	scanf("%s", first_name);
	printf("Enter your last name: ");
	fflush(stdout);
	scanf("%s", last_name);
	printf("%s, %s\n", last_name, first_name);
	return 0;
}
