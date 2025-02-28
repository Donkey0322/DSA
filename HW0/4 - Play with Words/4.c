
#include "4.h"

#include <stdio.h>
#include <string.h>

void findLongestConsecutiveSequence(const char *str, int size)
{
    int maxCount = 0;
    char currentChar = '\0';
    int currentCount = 0;

    char answers[26] = "";
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] == currentChar)
        {
            currentCount++;
        }
        else
        {
            currentChar = str[i];
            currentCount = 1;
        }

        if (currentCount == maxCount)
        {
            if (strchr(answers, currentChar) == NULL)
            {
                answers[counter] = currentChar;
                counter = counter + 1;
            }
        }
        else if (currentCount > maxCount)
        {
            maxCount = currentCount;
            answers[0] = '\0';
            counter = 0;
            answers[counter] = currentChar;
            counter = 1;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        printf("%c ", answers[i]);
    }
    printf("%d\n", maxCount);
}
