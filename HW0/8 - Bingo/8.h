#ifndef PLAYER_H
#define PLAYER_H

typedef struct player
{
    char name[64];
    int numbers[256][256];
    int bingo[256][256];
} Player;

void bingo(Player *players, int n, int m);
#endif