/*
 * Exercise11_15.c
 *
 *  Created on: Jul 05, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>

int my_atoi(const char *s);

int main(int argc, char *argv[])
{
    int input;

    if (argc != 2)
    {
        puts("Usage: <program_name> <arg_1>");
    }
    else
    {
        input = my_atoi(argv[1]);
        printf("%d + 5 = %d\n", input, input + 5);
        printf("%d / 2 = %d\n", input, input / 2);
        printf("%d %% 3 = %d\n", input, input % 3);
    }

    return 0;
}

int my_atoi(const char *s)
{
    int total = 0;
    while (*s != '\0')
    {
        if (!isdigit(*s))
            return 0;
        else
        {
            total *= 10;
            total += *s - '0';
        }

        s++;
    }

    return total;
}
