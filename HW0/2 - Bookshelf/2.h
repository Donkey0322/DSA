#ifndef BOOK_H
#define BOOK_H

typedef struct Book
{
    int id;
    struct Book *next;
} Book;

unsigned long long binaryToInt(int *arr, int size);

#endif