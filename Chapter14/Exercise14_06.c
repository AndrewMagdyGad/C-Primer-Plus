/*
 * Exercise14_06.c
 *
 *  Created on: Feb 21, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 12
#define ROSTERSIZE 19
#define MXLINE 40

struct Player
{
    char first[NAMELEN];
    char last[NAMELEN];
    unsigned int atbats, hits, walks, rbis;
    double batting_average;
};

void getbattingaverage(struct Player *p);
void showteamdata(const struct Player *p, int size);

int main(void)
{
    struct Player players[ROSTERSIZE];
    for (int i = 0; i < ROSTERSIZE; i++)
        players[i] = (struct Player){"", "", 0, 0, 0, 0, 0};

    FILE *fp;
    int number;
    char first[NAMELEN];
    char last[NAMELEN];
    unsigned int atbats;
    unsigned int hits;
    unsigned int walks;
    unsigned int rbis;

    if ((fp = fopen("roster.txt", "r")) == NULL)
    {
        fprintf(stderr, "Could not open file 'roster.txt'.\n");
        exit(EXIT_FAILURE);
    }

    // read data from roster.txt
    while (fscanf(fp, "%d %11s %11s %u %u %u %u", &number, first, last, &atbats, &hits, &walks, &rbis) == 7)
    {
        if (players[number].first[0] == '\0')
        {
            strncpy(players[number].first, first, NAMELEN);
            strncpy(players[number].last, last, NAMELEN);
        }
        players[number].atbats += atbats;
        players[number].hits += hits;
        players[number].walks += walks;
        players[number].rbis += rbis;
    }

    for (int i = 0; i < ROSTERSIZE; i++)
        getbattingaverage(&players[i]);

    showteamdata(players, ROSTERSIZE);

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}

void getbattingaverage(struct Player *player)
{
    if (player->atbats > 0)
        player->batting_average = player->hits / (double)player->atbats;
}

void showteamdata(const struct Player *player, int size)
{
    unsigned int atbats = 0, hits = 0, walks = 0, rbis = 0;

    printf("Team statistics (number, first, last, at bats, hits, walks, rbis, average):\n");
    for (int i = 0; i < size; i++, player++)
    {
        printf("%2d ", i);
        printf("%*s %*s %u %u %u %u %.3f\n", NAMELEN, player->first, NAMELEN,
               player->last, player->atbats, player->hits, player->walks,
               player->rbis, player->batting_average);

        atbats += player->atbats;
        hits += player->hits;
        walks += player->walks;
        rbis += player->rbis;
    }
    printf("Combined stats: %u %u %u %u %.3f\n", atbats, hits, walks, rbis, hits / (double)atbats);
}
