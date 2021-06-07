/*
 * Exercise15_06.c
 *
 *  Created on: June 7, 2021
 *      Author: andrew
 */
#include <stdio.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OFF 0
#define ON 1

typedef struct
{
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
} Font;

void display_font(Font *);
void print_menu(void);
void set_font(Font *);
void set_size(Font *);
void set_alignment(Font *);
void toggle_bold(Font *);
void toggle_italic(Font *);
void toggle_underline(Font *);
void clear_input(void);
char *is_on(int);
char *alignment_text(int);

int main(void)
{
    Font font = {1, 12, 0, 0, 0, 0};

    while (1)
    {
        display_font(&font);
        print_menu();
        int ch = getchar();
        if (ch != '\n')
            clear_input();

        if (ch == EOF || ch == 'q')
            break;
        else if (ch == 'f')
            set_font(&font);
        else if (ch == 's')
            set_size(&font);
        else if (ch == 'a')
            set_alignment(&font);
        else if (ch == 'b')
            toggle_bold(&font);
        else if (ch == 'i')
            toggle_italic(&font);
        else if (ch == 'u')
            toggle_underline(&font);
        else
            puts("Sorry, I don't understand that input. Try again.");
    }

    puts("Bye.");
    return 0;
}

char *is_on(int status)
{
    return status == 0 ? "off" : "on";
}

char *alignment_text(int alignment)
{
    if (alignment == 0)
        return "left";
    else if (alignment == 1)
        return "center";
    else
        return "right";
}

void clear_input(void)
{
    while (getchar() != '\n')
        continue;
}

void display_font(Font *font)
{
    puts("");
    puts("ID  SIZE ALIGNMENT  B   I   U ");
    printf("%-3u %-4u %-9s %3s %3s %3s\n", font->id, font->size,
           alignment_text(font->alignment), is_on(font->bold), is_on(font->italic),
           is_on(font->underline));
    puts("");
}

void print_menu(void)
{
    puts("f)change fonts	s)change size 	 a)change alignment");
    puts("b)toggle bold 	i)toggle italic  u)toggle underline");
    puts("q)quit");
}

void set_font(Font *font)
{
    unsigned int id;
    printf("Enter font id (0 - 255): ");
    while (scanf("%u", &id) != 1 || id < 0 || id > 255)
    {
        clear_input();
        puts("Invalid input. Try again.");
        printf("Enter font id (0 - 255): ");
    }
    font->id = id;
    clear_input();
}

void set_size(Font *font)
{
    unsigned int size;
    printf("Enter font size (0 - 127): ");
    while (scanf("%u", &size) != 1 || size < 0 || size > 127)
    {
        clear_input();
        puts("Invalid input. Try again.");
        printf("Enter font size (0 - 127): ");
    }
    font->size = size;
    clear_input();
}

void set_alignment(Font *font)
{
    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    int ch;
    while (!((ch = getchar()) == 'l' || ch == 'c' || ch == 'r'))
    {
        clear_input();
        puts("That is not a valid option. Try again.");
        puts("Select alignment:");
        puts("l)left   c)center   r)right");
    }

    if (ch == 'l')
        font->alignment = LEFT;
    else if (ch == 'c')
        font->alignment = CENTER;
    else if (ch == 'r')
        font->alignment = RIGHT;

    clear_input();
}

void toggle_bold(Font *font)
{
    font->bold = font->bold ? OFF : ON;
}

void toggle_italic(Font *font)
{
    font->italic = font->italic ? OFF : ON;
}

void toggle_underline(Font *font)
{
    font->underline = font->underline ? OFF : ON;
}
