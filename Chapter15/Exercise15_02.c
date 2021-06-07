/*
 * Exercise15_02.c
 *
 *  Created on: May 23, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int binary_to_decimal(const char *str);
char *itobs(int n, char *str);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number1 = binary_to_decimal(argv[1]);
    int number2 = binary_to_decimal(argv[2]);
    char binary_string[sizeof(int) * CHAR_BIT + 1];

    printf("~%s = %s\n", argv[1], itobs(~number1, binary_string));
    printf("~%s = %s\n", argv[2], itobs(~number2, binary_string));
    printf("%s & %s= %s\n", argv[1], argv[2], itobs(number1 & number2, binary_string));
    printf("%s | %s= %s\n", argv[1], argv[2], itobs(number1 | number2, binary_string));
    printf("%s ^ %s= %s\n", argv[1], argv[2], itobs(number1 ^ number2, binary_string));

    puts("Done");
    return 0;
}

int binary_to_decimal(const char *str)
{
    int value = 0;
    while (*str)
    {
        if (*str != '1' && *str != '0')
        {
            fprintf(stderr, "Error: input string is not binary.\n");
            exit(EXIT_FAILURE);
        }
        value = value * 2 + (*str++ - '0');
    }
    return value;
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
