#include <stdio.h>
#include <stdlib.h>
#include "separate.h"

List_Of_Numbers create_list_of_numbers(Numbers numbers, u_short count)
{
  List_Of_Numbers list_of_numbers;
  list_of_numbers.numbers = (Numbers)malloc(sizeof(int) * count);
  list_of_numbers.count = 0;

  for(u_short i = 0; i < count; i++)
  {
    list_of_numbers.numbers[list_of_numbers.count++] = numbers[i];
  }

  return list_of_numbers;
}

Belong compare(int number, int start, int end)
{
  if(number < start)
  {
    return Below;
  }

  if(number > end)
  {
    return Above;
  }

  return In;
}

Array_Of_List_Of_Numbers separate(Numbers numbers, u_short count, int start, int end)
{
  int separated[3][count];
  int counts[] = {0, 0, 0};

  for(u_short i = 0; i < count; i++)
  {
    int number = numbers[i];
    Belong belong = compare(number, start, end);
    separated[belong][counts[belong]++] = number;
  }

  Array_Of_List_Of_Numbers dynamic_separated = (Array_Of_List_Of_Numbers)malloc(sizeof(List_Of_Numbers) * 3);

  dynamic_separated[Below] = create_list_of_numbers(separated[Below], counts[Below]);
  dynamic_separated[In] = create_list_of_numbers(separated[In], counts[In]);
  dynamic_separated[Above] = create_list_of_numbers(separated[Above], counts[Above]);

  return dynamic_separated;
}

void print_list_of_numbers(Array_Of_List_Of_Numbers array_of_list_of_numbers, u_short count)
{
  for(u_short i = 0; i < count; i++)
  {
    for(u_short j = 0; j < array_of_list_of_numbers[i].count; j++)
    {
      printf("%d ", array_of_list_of_numbers[i].numbers[j]);
    }
    printf("\n");
  }
}
