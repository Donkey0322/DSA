#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "2.h"

int MAX_LENGTH = 1000002;

unsigned long long binaryToInt(int *arr, int size)
{
    unsigned long long value = 0;

    for (int i = 0; i < size; i++)
    {
        value = (value << 8) | arr[i];
    }

    return value;
}

int main()
{
    int n, m, id, total, format;
    int read;
    Book *B = (Book *)malloc(MAX_LENGTH * sizeof(Book));
    Book *head, *tail, *current, *last;

    while (scanf("%d", &n) == 1)
    {
        // 初始化
        for (int i = 0; i < MAX_LENGTH - 1; i++)
        {
            B[i].id = 0;
            B[i].next = &B[i + 1];
        }
        head = B;
        tail = B;
        total = 0;
        int booksId[8] = {0};

        // 看書
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            if (m == 1)
            {
                read = 0;
                scanf("%d", &id);
                current = head;
                last = head;
                for (int j = 0; j < total; j++)
                {
                    if (current->id == id)
                    {
                        if (current != head)
                        {
                            last->next = current->next;
                        }
                        else
                        {
                            head = head->next;
                        }
                        read = 1;
                        break;
                    }
                    last = current;
                    current = current->next;
                }
                if (!read)
                {
                    if (total < 8)
                    {
                        total = total + 1;
                    }
                    else
                    {
                        head = head->next;
                    }
                }
                tail->id = id;
                tail->next = tail + 1;
                tail = tail->next;
            }
            else if (m == 2)
            {
                scanf("%d", &format);
                current = head;
                for (int j = 0; j < 8 - total; j++)
                {
                    booksId[j] = 0;
                }
                for (int j = 8 - total; j < 8; j++)
                {
                    booksId[j] = current->id;
                    current = current->next;
                }
                if (format == 1)
                {
                    printf("%llu\n", binaryToInt(booksId, 8));
                }
                else
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (j == 7)
                        {
                            printf("%d\n", booksId[j]);
                        }
                        else
                        {
                            printf("%d ", booksId[j]);
                        }
                    }
                }
            }
        }
    }
    free(B);
    return 0;
}