/*
 * Exercise12_08.c
 *
 *  Created on: Nov 21, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);

        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}

int *make_array(int elem, int val)
{
    int *array = (int *)malloc(elem * sizeof(int));
    if (array)
        for (int i = 0; i < elem; i++)
            array[i] = val;
    return array;
}

void show_array(const int ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
        if ((i + 1) % 8 == 0)
            putchar('\n');
    }
    if (i % 8 != 0)
        putchar('\n');
}
