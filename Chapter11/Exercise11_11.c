/*
 * Exercise11_11.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define COUNT 10
#define LIMIT 50

void sort_ASCII(char *strings[], int n);
void sort_length(char *strings[], int n);
int firstword_length(char *string);
void sort_firstword_length(char *strings[], int n);
void print_menu(void);
char *s_gets(char *s, int n);
void reset_ptrs(char (*strings)[LIMIT], char *strptrs[], int n);

int main(void)
{
    char strings[COUNT][LIMIT];
    char *strptrs[COUNT];
    char *input_check;
    int ch, i, n = 0;

    printf("Enter up to %d strings (EOF to stop): \n", COUNT);
    for (i = 0; i < COUNT; i++)
    {
        printf("%d: ", i + 1);
        input_check = s_gets(strings[i], LIMIT);

        if (!input_check)
            break;
        n++;
    }
    printf("\n");

    reset_ptrs(strings, strptrs, n);
    print_menu();
    while ((ch = getchar()) != 'q')
    {
        if (ch != '\n')
            while (getchar() != '\n')
                continue;

        switch (ch)
        {
        case 'a':
            break;
        case 'b':
            sort_ASCII(strptrs, n);
            break;
        case 'c':
            sort_length(strptrs, n);
            break;
        case 'd':
            sort_firstword_length(strptrs, n);
            break;
        default:
            printf("Invalid input. Try again.\n\n");
            print_menu();
            continue;
        }

        puts("Result:");
        for (i = 0; i < n; i++)
            puts(strptrs[i]);

        puts("");
        reset_ptrs(strings, strptrs, n);
        print_menu();
    }
    puts("Done.");

    return 0;
}

void reset_ptrs(char (*strings)[LIMIT], char *strptrs[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        strptrs[i] = strings[i];
}

void print_menu(void)
{
    puts("Choose an option:");
    puts("(a) Print strings in original order.");
    puts("(b) Print strings in ASCII collating sequence.");
    puts("(c) Print strings ordered by length.");
    puts("(d) Print strings ordered by length of the first word.");
    puts("(q) Quit.\n");
    printf("Enter a character: ");
}

void sort_ASCII(char *strings[], int n)
{
    char *tmp;
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
}

void sort_length(char *strings[], int n)
{
    char *tmp;
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (strlen(strings[i]) > strlen(strings[j]))
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
}

int firstword_length(char *string)
{
    int length = 0;

    while (isspace(*string))
        string++;

    while (!isspace(*string) && *string)
    {
        length++;
        string++;
    }

    return length;
}

void sort_firstword_length(char *strings[], int n)
{
    char *tmp;
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (firstword_length(strings[i]) > firstword_length(strings[j]))
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        find = strchr(s, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
