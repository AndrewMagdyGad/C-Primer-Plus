/*
 * Exercise11_13.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("Error: at least one command-line argument required.\n");
        return 1;
    }
    else
        for (i = argc - 1; i > 0; i--)
            printf("%s ", argv[i]);
    puts("");
    return 0;
}
