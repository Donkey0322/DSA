#ifndef FOOD_H
#define FOOD_H

typedef struct food
{
    char name[64];
    char ingredient[10][64];
} Food;

void common(Food *food1, Food *food2, char answer[640]);

#endif