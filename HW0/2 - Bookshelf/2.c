#include "2.h"

unsigned long long binaryToInt(int *arr, int size)
{
    unsigned long long value = 0;

    for (int i = 0; i < size; i++)
    {
        value = (value << 8) | arr[i];
    }

    return value;
}