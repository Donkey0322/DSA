#include "1.h"

int findBoss(Employee *employee1, Employee *employee2, int reverse)
{
    if (employee1->boss == employee1)
    {
        return 0;
    }
    else if (employee1->boss == employee2)
    {
        return 1 + reverse;
    }
    else if (employee1->boss == employee2->boss)
    {
        return 3;
    }
    else
    {
        return findBoss(employee1->boss, employee2, reverse);
    }
}

int relation(Employee *employee1, Employee *employee2)
{
    int x = findBoss(employee1, employee2, 0);
    if (x)
    {
        return x;
    }
    int y = findBoss(employee2, employee1, 1);
    if (y)
    {
        return y;
    }
    return 4;
}