/*
 * Exercise14_04.c
 *
 *  Created on: Jan 21, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>
#define LEN 5
#define MAXNAME 20

struct fullname
{
    char first[MAXNAME];
    char middle[MAXNAME];
    char last[MAXNAME];
};

struct person
{
    int ssn;
    struct fullname name;
};

void print_by_address(struct person *pp);
void print_by_value(struct person p);

int main(void)
{
    struct person people[LEN] = {
        {123456789, {"Marvin", "The", "Martian"}},
        {987654321, {"Scrooge", "Mc", "Duck"}},
        {888777666, {"Mantis", "Froggy", "Tobogan"}},
        {123432467, {.first = "Night", .last = "Man"}},
        {354257623, {.first = "Day", .last = "Man"}}};

    // part a -- pass by address
    for (int i = 0; i < LEN; i++)
        print_by_address(&people[i]);
    puts("\n");

    // part b -- pass by value
    for (int i = 0; i < LEN; i++)
        print_by_value(people[i]);

    return 0;
}

void print_by_address(struct person *pp)
{
    printf("%s, %s ", pp->name.last, pp->name.first);
    if (pp->name.middle[0] != '\0')
        printf("%c. ", toupper(pp->name.middle[0]));
    printf("--- %d\n", pp->ssn);
}

void print_by_value(struct person p)
{
    printf("%s, %s ", p.name.last, p.name.first);
    if (p.name.middle[0] != '\0')
        printf("%c. ", toupper(p.name.middle[0]));
    printf("--- %d\n", p.ssn);
}
