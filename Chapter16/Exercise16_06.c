/*
 * Exercise16_06.c
 *
 *  Created on: Aug 19, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct
{
    char first[40];
    char last[40];
} NAME;

void show_array(const NAME arr[], int n);
int mycomp(const void *p1, const void *p2);

int main(void)
{
    NAME arr[SIZE] = {{"Rebecca", "Ryan"},
                      {"Penelope", "Briggs"},
                      {"Holly", "Sinclair"},
                      {"Rose", "Howard"},
                      {"Paige", "Roberts"},
                      {"Hanna", "Donnelly"},
                      {"Irene", "Deleon"},
                      {"Lily", "Grant"},
                      {"Emilia", "Miller"},
                      {"Yasmin", "Seymour"},
                      {"Maya", "Mcdonald"},
                      {"Bonnie", "Padilla"},
                      {"Hattie", "Wilkes"},
                      {"Kelly", "Carroll"},
                      {"Kate", "Hale"},
                      {"Eloise", "Morales"},
                      {"Liberty", "Atherton"},
                      {"Elise", "Ali"},
                      {"Erica", "Guerrero"},
                      {"Josie", "Norris"}};

    puts("Here is the list of names:\n");
    show_array(arr, SIZE);
    puts("\n");

    qsort(arr, SIZE, sizeof(NAME), mycomp);

    puts("Here is the sorted list of names:\n");
    show_array(arr, SIZE);

    return 0;
}

void show_array(const NAME arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s, %s\n", arr[i].last, arr[i].first);
    }
}

int mycomp(const void *p1, const void *p2)
{
    const NAME *a1 = (const NAME *)p1;
    const NAME *a2 = (const NAME *)p2;

    int res = strcmp(a1->last, a2->last);

    if (res != 0)
        return res;
    else
        return strcmp(a1->first, a2->first);
}
