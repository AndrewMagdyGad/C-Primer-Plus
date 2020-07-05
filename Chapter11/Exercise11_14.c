/*
 * Exercise11_14.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double base;
    long power;
    char *end;

    if (argc != 3)
    {
        puts("Usage: <program_name> <arg1 base:double> <arg2 power:int>");
        return 1;
    }

    base = strtod(argv[1], &end);
    if (*end)
    {
        puts("Usage: <program_name> <arg1 base:double> <arg2 power:int>");
        return 1;
    }

    power = strtol(argv[2], &end, 10);
    if (*end)
    {
        puts("Usage: <program_name> <arg1 base:double> <arg2 power:int>");
        return 1;
    }

    printf("%g ^ %ld = %lf\n", base, power, pow(base, power));

    return 0;
}
