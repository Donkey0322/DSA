#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "4.h"

#define MAX_COMMANDS 5001

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

int main()
{
    char input[100];
    char temp[MAX_COMMANDS] = "";
    char answer[MAX_COMMANDS] = "";

    char action[100], direction[100], newWord[100];

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0)
        {
            if (answer[0] == '\0')
            {
                break;
            }
            findLongestConsecutiveSequence(answer, strlen(answer));
            answer[0] = '\0';
        }
        else
        {
            sscanf(input, "%s %s %s", action, direction, newWord);
            if (strcmp(action, "insert") == 0)
            {
                if (strcmp(direction, "left") == 0)
                {
                    strcpy(temp, answer);
                    answer[0] = '\0';
                    strcat(answer, newWord);
                    strcat(answer, temp);
                }
                else if (strcmp(direction, "right") == 0)
                {
                    strcat(answer, newWord);
                }
                else
                {
                    int position = atoi(direction) - 1;
                    strncpy(temp, answer, position);
                    answer[0] = '\0';
                    temp[position] = '\0';
                    strcat(temp, newWord);
                    strcat(temp, answer + position);
                    strcpy(answer, temp);
                }
            }
            else
            {
                if (strcmp(direction, "left") == 0)
                {
                    strcpy(answer, answer + 1);
                }
                else if (strcmp(direction, "right") == 0)
                {
                    int length = strlen(answer);
                    if (length > 0)
                    {
                        answer[length - 1] = '\0';
                    }
                }
                else
                {
                    int position = atoi(direction) - 1;
                    strncpy(temp, answer, position);
                    answer[0] = '\0';
                    temp[position] = '\0';
                    strcat(temp, answer + position + 1);
                    strcpy(answer, temp);
                }
            }
        }
    }
    return 0;
}