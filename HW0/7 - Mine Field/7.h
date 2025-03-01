#ifndef MINE_H
#define MINE_H

typedef struct mine
{
    int remains;
    int *bomb;
    int undefines[9][2];
    int undefine;
    struct mine *top;
    struct mine *bottom;
    struct mine *left;
    struct mine *right;
} Mine;

int sweep(Mine *mines);
#endif