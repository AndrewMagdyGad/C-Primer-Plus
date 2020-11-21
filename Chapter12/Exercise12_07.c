/*
 * Exercise12_07.c
 *
 *  Created on: Nov 21, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include "Exercise12_07.h"

int main(void)
{
    int sets, dice, sides;

    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        dice = sides = -1;
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        while (dice < 0 || sides < 0)
        {
            while (getchar() != '\n')
                ;
            puts("Invalid input. Positive integers only.");
            puts("How many sides and how many dice? ");
            scanf("%d %d", &sides, &dice);
        }

        dicerolls(sets, dice, sides);

        printf("How many sets? Enter q to stop: ");
    }

    return 0;
}
