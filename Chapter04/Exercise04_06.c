/*
 * Exercise04_06.c
 *
 *  Created on: Aug 1, 2019
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>

int main(void) {
	char first_name[40], last_name[40];
	printf("Enter your first name: ");
	fflush(stdout);
	scanf("%s", first_name);
	printf("Enter your last name: ");
	fflush(stdout);
	scanf("%s", last_name);
	printf("%s %s\n%*u %*u\n", first_name, last_name,
			strlen(first_name), strlen(first_name),
			strlen(last_name), strlen(last_name));
	printf("%s %s\n%-*u %-*u\n", first_name, last_name,
			strlen(first_name), strlen(first_name),
			strlen(last_name), strlen(last_name));
	return 0;
}
