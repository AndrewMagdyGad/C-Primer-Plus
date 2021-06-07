/*
 * Exercise15_05.c
 *
 *  Created on: May 26, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <limits.h>

unsigned int rotate_left(unsigned int n, unsigned int places);
char *itobs(int n, char *str);

int main(int argc, char **argv)
{
    unsigned int number, places, rotated_number;
    char binary_str1[CHAR_BIT * sizeof(int) + 1];
    char binary_str2[CHAR_BIT * sizeof(int) + 1];

    printf("Enter an integer (q to quit): ");
    while (scanf("%ud", &number))
    {
        while (getchar() != '\n')
            continue;

        printf("Enter the number of bits to be rotated: ");
        if (scanf("%ud", &places) != 1)
            break;
        while (getchar() != '\n')
            continue;
        rotated_number = rotate_left(number, places);
        itobs(number, binary_str1);
        itobs(rotated_number, binary_str2);
        printf("%u rotated is %u.\n", number, rotated_number);
        printf("%s rotated is %s.\n", binary_str1, binary_str2);
        printf("Next value: ");
    }

    puts("Done");
    return 0;
}

unsigned int rotate_left(unsigned int n, unsigned int places)
{
    int size = CHAR_BIT * sizeof(int);
    unsigned int overflow;
    places %= size;

    overflow = n >> (size - places);
    return (n << places) | overflow;
}

char *itobs(int n, char *str)
{
    int i;
    int size = sizeof(int) * CHAR_BIT;
    for (i = size - 1; i >= 0; i--, n >>= 1)
    {
        str[i] = (n & 01) + '0';
    }
    str[size] = '\0';
    return str;
}
