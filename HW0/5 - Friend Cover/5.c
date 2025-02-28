#include "5.h"

#include <stdio.h>
#include <string.h>

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