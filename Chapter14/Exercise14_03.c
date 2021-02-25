/*
 * Exercise14_03.c
 *
 *  Created on: Jan 20, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
#define EPS 1e-8

int sort_by_title(const void *b1, const void *b2);
int sort_by_value(const void *b1, const void *b2);
char *s_gets(char *string, int n);

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue; /* clear input line */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books in the original order:\n\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        puts("\n");

        // sorted by title
        printf("Here is the list of your books alphabetized by title:\n\n");
        qsort(library, count, sizeof(struct book), sort_by_title);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        puts("\n");

        // sorted by value
        printf("Here is the list of your books ordered by value:\n\n");
        qsort(library, count, sizeof(struct book), sort_by_value);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

int sort_by_title(const void *b1, const void *b2)
{
    struct book *book1 = (struct book *)b1;
    struct book *book2 = (struct book *)b2;
    return strcmp(book1->title, book2->title);
}

int sort_by_value(const void *b1, const void *b2)
{
    struct book *book1 = (struct book *)b1;
    struct book *book2 = (struct book *)b2;
    float diff = book1->value - book2->value;

    if (fabs(diff) <= EPS)
        return 0;
    else if (diff < 0)
        return -1;
    else
        return 1;
}

char *s_gets(char *string, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(string, n, stdin);
    if (ret_val)
    {
        find = strchr(string, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
