#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "7.h"
#define MINE_NUM 9

int main()
{
    int N[MINE_NUM][MINE_NUM] = {0};
    int M[MINE_NUM][MINE_NUM];
    Mine A[MINE_NUM][MINE_NUM];

    int update = 1;

    for (int i = 0; i < MINE_NUM; i++)
    {
        for (int j = 0; j < MINE_NUM; j++)
        {
            scanf("%d", &N[i][j]);
            M[i][j] = -1;
        }
    }

    for (int i = 0; i < MINE_NUM; i++)
    {
        for (int j = 0; j < MINE_NUM; j++)
        {
            A[i][j].remains = N[i][j];
            A[i][j].bomb = &M[i][j];

            if (i == 0)
            {
                A[i][j].left = NULL;
            }
            else
            {
                A[i][j].left = &A[i - 1][j];
            }

            if (i == MINE_NUM - 1)
            {
                A[i][j].right = NULL;
            }
            else
            {
                A[i][j].right = &A[i + 1][j];
            }

            if (j == 0)
            {
                A[i][j].top = NULL;
            }
            else
            {
                A[i][j].top = &A[i][j - 1];
            }

            if (j == MINE_NUM - 1)
            {
                A[i][j].bottom = NULL;
            }
            else
            {
                A[i][j].bottom = &A[i][j + 1];
            }
        }
    }

    while (update)
    {
        update = 0;
        for (int i = 0; i < MINE_NUM; i++)
        {
            for (int j = 0; j < MINE_NUM; j++)
            {
                int bomb = 0;
                int undefine = 0;

                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        if (0 <= (i + x) && (i + x) < MINE_NUM && 0 <= (j + y) && (j + y) < MINE_NUM)
                        {
                            switch (M[i + x][j + y])
                            {
                            case -1:
                                A[i][j].undefines[undefine][0] = i + x;
                                A[i][j].undefines[undefine][1] = j + y;
                                undefine = undefine + 1;
                                break;
                            case 1:
                                bomb = bomb + 1;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
                A[i][j].remains = N[i][j] - bomb;
                A[i][j].undefine = undefine;
                if (undefine)
                {
                    if (N[i][j] == bomb)
                    {
                        for (int u = 0; u < undefine; u++)
                        {
                            int ux = A[i][j].undefines[u][0];
                            int uy = A[i][j].undefines[u][1];
                            M[ux][uy] = 0;
                            update = 1;
                        }
                    }
                    else if (N[i][j] - bomb == undefine)
                    {
                        for (int u = 0; u < undefine; u++)
                        {
                            int ux = A[i][j].undefines[u][0];
                            int uy = A[i][j].undefines[u][1];
                            M[ux][uy] = 1;
                            update = 1;
                        }
                    }
                }
                // if (debug)
                // {
                //     printf("===============\n");
                //     for (int m = 0; m < MINE_NUM; m++)
                //     {
                //         for (int n = 0; n < MINE_NUM; n++)
                //         {
                //             printf("%d ", A[m][n].remains);
                //         }
                //         printf("\n");
                //     }
                // }
            }
        }
        if (!update)
        {
            for (int i = 0; i < MINE_NUM; i++)
            {
                if (update)
                {
                    break;
                }
                for (int j = 0; j < MINE_NUM; j++)
                {
                    if ((A[i][j].remains == 2 || A[i][j].remains == 1) && A[i][j].undefine == 3)
                    {
                        Mine *compare;
                        if (A[i][j].left != NULL && A[i][j].left->remains == 1 && A[i][j].left->undefine == 2)
                        {
                            compare = A[i][j].left;
                        }
                        else if (A[i][j].right != NULL && A[i][j].right->remains == 1 && A[i][j].right->undefine == 2)
                        {
                            compare = A[i][j].right;
                        }
                        else if (A[i][j].top != NULL && A[i][j].top->remains == 1 && A[i][j].top->undefine == 2)
                        {
                            compare = A[i][j].top;
                        }
                        else if (A[i][j].bottom != NULL && A[i][j].bottom->remains == 1 && A[i][j].bottom->undefine == 2)
                        {
                            compare = A[i][j].bottom;
                        }

                        for (int u = 0; u < A[i][j].undefine; u++)
                        {
                            int found = 0;

                            int x = A[i][j].undefines[u][0];
                            int y = A[i][j].undefines[u][1];

                            for (int uc = 0; uc < compare->undefine; uc++)
                            {
                                if (compare->undefines[uc][0] == x && compare->undefines[uc][1] == y)
                                {
                                    found = 1;
                                }
                            }

                            if (!found && *(A[x][y].bomb) == -1)
                            {
                                *(A[x][y].bomb) = A[i][j].remains - compare->remains;
                                update = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int solution = 1;
    // printf("===============\n");
    // for (int m = 0; m < MINE_NUM; m++)
    // {
    //     for (int n = 0; n < MINE_NUM; n++)
    //     {
    //         printf("%d ", A[m][n].remains);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < MINE_NUM; i++)
    {
        if (!solution)
        {
            break;
        }
        for (int j = 0; j < MINE_NUM; j++)
        {
            if (M[i][j] == -1)
            {
                solution = 0;
                break;
            }
        }
    }

    if (solution)
    {
        for (int i = 0; i < MINE_NUM; i++)
        {
            printf("%d", M[i][0]);
            for (int j = 1; j < MINE_NUM; j++)
            {
                printf(" %d", M[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("no solution\n");
    }
    return 0;
}
