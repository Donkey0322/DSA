#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "3.h"

void common(Food *food1, Food *food2, char answer[640])
{
    answer[0] = '\0';
    int isFirst = 1;

    for (int i = 0; i < 10; i++)
    {
        if (food1->ingredient[i][0] == '\0')
            continue;

        for (int j = 0; j < 10; j++)
        {
            if (food2->ingredient[j][0] == '\0')
                continue;

            if (strcmp(food1->ingredient[i], food2->ingredient[j]) == 0)
            {
                if (!isFirst)
                {
                    strncat(answer, " ", 640 - strlen(answer) - 1);
                }
                strncat(answer, food1->ingredient[i], 640 - strlen(answer) - 1);
                isFirst = 0;
            }
        }
    }

    if (answer[0] == '\0')
    {
        strcpy(answer, "nothing");
    }
}

int nameToIndex(Food *e, Food A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(A[i].name, e->name))
            return i;
    }
    return -1;
}

int main()
{
    int n, q;
    int i;
    char answer[660] = {0};

    while (scanf("%d", &n) == 1)
    {
        Food A[100] = {0};
        for (int j = 0; j < n; j++)
        {
            scanf("%s", A[j].name);
            scanf("%d", &i);
            for (int k = 0; k < i; k++)
            {
                scanf("%s", A[j].ingredient[k]);
            }
        }
        scanf("%d", &q);
        Food x, y;
        for (int j = 0; j < q; j++)
        {
            scanf("%s", x.name);
            scanf("%s", y.name);
            int ix = nameToIndex(&x, A, n), iy = nameToIndex(&y, A, n);
            assert(ix != -1);
            assert(iy != -1);

            common(&A[ix], &A[iy], answer);
            printf("%s\n", answer);
        }
    }
    return 0;
}