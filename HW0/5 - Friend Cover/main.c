#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "5.h"

int main()
{
    int n, m;
    Friends A[200] = {0};

    while (scanf("%d", &n) == 1)
    {
        Friends A[100] = {0};
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &A[i].a);
            scanf("%d", &A[i].b);
        }
        findSubset(A, m, n);
    }
    return 0;
}
