#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "3.h"

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
    Food A[100] = {0};

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
