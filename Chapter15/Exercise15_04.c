/*
 * Exercise15_04.c
 *
 *  Created on: May 26, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <limits.h>

char *itobs(int n, char *str);
int checkbit(int n, int position);

int main(int argc, char **argv)
{
    int number, position;
    char binary_str[CHAR_BIT * sizeof(int) + 1];

    printf("Enter an integer and a bit position (q to quit): ");
    while (scanf("%d %d", &number, &position) == 2 && position >= 0 && position < 32)
    {
        while (getchar() != '\n')
            continue;
        printf("Position %d of %d (%s) is %d\n", position, number, itobs(number, binary_str), checkbit(number, position));
        printf("Next integer and a bit position (q to quit): ");
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

int checkbit(int n, int position)
{
    return (n >> position) & 01;
}
