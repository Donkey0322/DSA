#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "8.h"

void bingo(Player *players, int n, int m)
{
    int win = 0;          // 勝利數字
    int winner = 0;       // 贏家有幾個
    char winners[n][256]; // 贏家名單

    int number;
    int bang[m * 2 + 2];

    for (int i = 0; i < m * m; i++)
    {
        scanf("%d", &number);

        for (int j = 0; j < n; j++)
        {
            if (win && win != number)
            {
                break;
            }
            for (int b = 0; b < m * 2 + 2; b++)
            {
                bang[b] = 1;
            }

            for (int k = 0; k < m; k++)
            {
                for (int x = k; x < m; x++)
                {

                    if (players[j].numbers[k][x] == number)
                    {
                        players[j].bingo[k][x] = 1;
                    }
                    else if (players[j].numbers[x][k] == number)
                    {
                        players[j].bingo[x][k] = 1;
                    }

                    if (k == x && !players[j].bingo[k][k])
                    {
                        bang[2 * m] = 0;
                        bang[k] = 0;
                        bang[k + m] = 0;
                    }
                    else
                    {
                        if (!players[j].bingo[k][x])
                        {
                            bang[k] = 0;
                            bang[x + m] = 0;

                            if (k + x == m - 1)
                            {
                                bang[2 * m + 1] = 0;
                            }
                        }
                        if (!players[j].bingo[x][k])
                        {
                            bang[x] = 0;
                            bang[k + m] = 0;

                            if (k + x == m - 1)
                            {
                                bang[2 * m + 1] = 0;
                            }
                        }
                    }
                }
            }
            int sum = 0;
            for (int b = 0; b < m * 2 + 2; b++)
            {
                sum = sum + bang[b];
            }
            if (sum && !win)
            {
                win = number;
            }
            if (sum && win == number)
            {
                strcpy(winners[winner], players[j].name);
                winner++;
            }
        }
    }
    printf("%d", win);
    for (int i = 0; i < winner; i++)
    {
        printf(" %s", winners[i]);
    }
}

int main()
{
    int n, m;
    Player A[10];

    while (scanf("%d %d", &n, &m) == 2)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", A[i].name);
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    scanf("%d", &A[i].numbers[j][k]);
                    A[i].bingo[j][k] = 0;
                }
            }
        }
        bingo(A, n, m);
    }
    return 0;
}