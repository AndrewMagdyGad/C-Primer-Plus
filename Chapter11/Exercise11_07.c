/*
 * Exercise11_07.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#define LIMIT 51

char *mystrncpy(char *target, const char *source, int n);
char *s_gets(char *s, int n);
void clear_string(char *string, int n);

int main(void)
{
    char source[LIMIT];
    char target[LIMIT];
    char *input_check;
    int n;

    printf("Enter a string to copy (empty line to quit): ");
    input_check = s_gets(source, LIMIT);
    while (source[0] != '\0' && input_check)
    {
        printf("How many characters do you want to copy? (maximum %d) ", LIMIT - 1);
        scanf("%d", &n);

        while (getchar() != '\n')
            continue;

        if (n > LIMIT)
            n = LIMIT;

        printf("Original string: %s\n", source);
        mystrncpy(target, source, n);
        printf("Copy: %s\n", target);

        clear_string(target, LIMIT);

        printf("Enter a string to copy (empty line to quit): ");
        input_check = s_gets(source, LIMIT);
    }
    puts("Done.");

    return 0;
}

char *mystrncpy(char *target, const char *source, int n)
{
    int i = 0;

    while (i < n && source[i] != '\0')
    {
        target[i] = source[i];
        i++;
    }

    while (i < n)
    {
        target[i] = '\0';
        i++;
    }

    return target;
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

void clear_string(char *string, int n)
{
    int i;
    for (i = 0; i < n; i++)
        string[i] = '\0';
}
