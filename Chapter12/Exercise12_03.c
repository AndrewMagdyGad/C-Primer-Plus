/*
 * Exercise12_03.c
 *
 *  Created on: Nov 21, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include "Exercise12_03.h"

int main(void)
{
    int mode = 0;
    double distance, fuel;

    set_mode(&mode);
    while (mode >= 0)
    {
        get_info(mode, &distance, &fuel);
        show_info(mode, distance, fuel);
        set_mode(&mode);
    }

    printf("Done.\n");
    return 0;
}
