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

Array_Of_List_Of_Numbers separate(Numbers numbers, u_short count, int start, int end)
{
  int below_numbers[count];
  u_short below_Numbers_count = 0;

  int in_numbers[count];
  u_short in_numbers_count = 0;

  int above_numbers[count];
  u_short above_numbers_count = 0;

  for(u_short i = 0; i < count; i++)
  {
    int number = numbers[i];  

    if(number < start){
      below_numbers[below_Numbers_count++] = number;
    }

    if(number >= start && number <= end){
      in_numbers[in_numbers_count++] = number;
    }

    if(number > end)
    {
      above_numbers[above_numbers_count++] = number;
    }
  }

  Array_Of_List_Of_Numbers separated = (Array_Of_List_Of_Numbers)malloc(sizeof(List_Of_Numbers) * 3);

  separated[0] = create_list_of_numbers(below_numbers, below_Numbers_count);
  separated[1] = create_list_of_numbers(in_numbers, in_numbers_count);
  separated[2] = create_list_of_numbers(above_numbers, above_numbers_count);

  return separated;
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
