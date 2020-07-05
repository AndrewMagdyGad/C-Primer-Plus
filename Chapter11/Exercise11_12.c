/*
 * Exercise11_12.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int words = 0, uppercase_letters = 0, lowercase_letters = 0, punctuation_characters = 0, digits = 0;
    bool inword = false;
    int ch;

    printf("Enter text to be analyzed (EOF to terminate): ");
    while ((ch = getchar()) != EOF)
    {

        if (isupper(ch))
            uppercase_letters++;
        else if (islower(ch))
            lowercase_letters++;
        else if (ispunct(ch))
            punctuation_characters++;
        else if (isdigit(ch))
            digits++;

        if (!isspace(ch) && !inword)
        {
            inword = true;
            words++;
        }
        if (isspace(ch) && inword)
            inword = false;
    }
    printf("Number of words: %d\n", words);
    printf("Number of uppercase letters: %d\n", uppercase_letters);
    printf("Number of lowercase letters: %d\n", lowercase_letters);
    printf("Number of punctuation characters: %d\n", punctuation_characters);
    printf("Number of digits: %d\n", digits);

    return 0;
}