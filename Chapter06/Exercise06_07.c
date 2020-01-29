/*
 * Exercise06_07.c
 *
 *  Created on: Jan 27, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
	int index;
	char str[50];
	printf("Enter a string: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", str);
	for (index = strlen(str) - 1; index >= 0; index--)
		printf("%c", str[index]);
	printf("\n");
	return 0;
}
