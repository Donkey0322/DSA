#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "8.h"

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
