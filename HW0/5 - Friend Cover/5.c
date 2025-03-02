#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "5.h"

int deleteFriends(Friends *friends, int size, int value)
{
    int newSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (friends[i].a != value && friends[i].b != value)
        {
            friends[newSize] = friends[i];
            newSize = newSize + 1;
        }
    }
    return newSize;
}

void findSubset(Friends *friends, int total, int upperBound)
{
    while (total)
    {
        int freq[20] = {0};

        for (int i = 0; i < total; i++)
        {
            freq[friends[i].a]++;
            freq[friends[i].b]++;
        }

        int maxFreq = 0, mostFrequentValue = -1;
        for (int i = 0; i < upperBound; i++)
        {
            if (freq[i] > maxFreq)
            {
                maxFreq = freq[i];
                mostFrequentValue = i;
            }
        }

        total = deleteFriends(friends, total, mostFrequentValue);
        printf("%d\n", mostFrequentValue);
    }
}

int main()
{
    int n, m;
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
