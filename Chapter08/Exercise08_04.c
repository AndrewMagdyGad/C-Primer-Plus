/*
 * Exercise08_04.c
 *
 *  Created on: Feb 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	bool in_word = false;
	int ch;
	unsigned long word_count = 0, letter_count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			letter_count++;
			if (!in_word)
			{
				in_word = true;
				word_count++;
			}
		}
		else
			in_word = false;
	}
	printf("words count: %lu\n", word_count);
	printf("letters count: %lu\n", letter_count);
	printf("Average letters per word: %.2f\n", (word_count > 0)? (float) letter_count / word_count : 0);
	return 0;
}
