/*
 * Exercise04_02.c
 *
 *  Created on: Aug 1, 2019
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>

int main(void) {
	char first_name[40];
	printf("Enter your first name: ");
	fflush(stdout);
	scanf("%s", first_name);
	printf("\"%s\"\n", first_name);
	printf("\"%20s\"\n", first_name);
	printf("\"%-20s\"\n", first_name);
	printf("\"%*s\"\n", strlen(first_name) + 3, first_name);
	return 0;
}
