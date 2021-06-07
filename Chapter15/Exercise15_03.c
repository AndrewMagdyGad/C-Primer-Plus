/*
 * Exercise15_03.c
 *
 *  Created on: May 26, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <limits.h>

char *itobs(int n, char *str);
int onbits(int n);

int main(int argc, char **argv)
{
    int number;
    char binary_str[CHAR_BIT * sizeof(int) + 1];

    printf("Enter an integer (q to quit): ");
    while ((scanf("%d", &number) == 1))
    {
        while (getchar() != '\n')
            continue;

        printf("%d (%s) has %d bit(s) on.\n", number, itobs(number, binary_str), onbits(number));
        printf("Next value (q to quit): ");
    }

    puts("Done");
    return 0;
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

int onbits(int n)
{
    int count = 0;
    int size = CHAR_BIT * sizeof(int);
    int i;

    for (i = 0; i < size; i++, n >>= 1)
    {
        if ((n & 01) == 1)
            count++;
    }

    return count;
}
