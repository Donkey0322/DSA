#include "3.h"

#include <stdio.h>
#include <string.h>

void common(Food *food1, Food *food2, char answer[640])
{
  answer[0] = '\0';
  int isFirst = 1;

  for (int i = 0; i < 10; i++)
  {
    if (food1->ingredient[i][0] == '\0')
      continue;

    for (int j = 0; j < 10; j++)
    {
      if (food2->ingredient[j][0] == '\0')
        continue;

      if (strcmp(food1->ingredient[i], food2->ingredient[j]) == 0)
      {
        if (!isFirst)
        {
          strncat(answer, " ", 640 - strlen(answer) - 1);
        }
        strncat(answer, food1->ingredient[i], 640 - strlen(answer) - 1);
        isFirst = 0;
      }
    }
  }

  if (answer[0] == '\0')
  {
    strcpy(answer, "nothing");
  }
}