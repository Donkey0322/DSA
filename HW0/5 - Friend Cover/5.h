#ifndef FRIEND_H
#define FRIEND_H

typedef struct friends
{
    int a;
    int b;
} Friends;

void findSubset(Friends *friends, int total, int upperBound);

#endif