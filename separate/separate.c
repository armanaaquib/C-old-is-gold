#include <stdio.h>
#include <stdlib.h>
#include "separate.h"

Array_Of_List_Of_Numbers create_array_of_list_of_numbers(Numbers *numbers, u_short length, Numbers counts)
{
  Array_Of_List_Of_Numbers array_of_list_of_numbers = (Array_Of_List_Of_Numbers)malloc(sizeof(List_Of_Numbers) * length);

  for(u_short i = 0; i < length; i++)
  {
    Numbers nums = (Numbers)malloc(sizeof(int) * counts[i]);
    u_short count = 0;

    for(u_short j = 0; j < counts[i]; j++)
    {
      nums[count++] = numbers[i][j];
    }

    array_of_list_of_numbers[i].numbers = nums;
    array_of_list_of_numbers[i].count = count;
  }

  return array_of_list_of_numbers;
}

u_char compare(int number, int start, int end)
{
  if(number < start)
  {
    return 0;
  }

  if(number > end)
  {
    return 2;
  }

  return 1;
}

Array_Of_List_Of_Numbers separate(Numbers numbers, u_short count, int start, int end)
{
  int below_numbers[count];
  int in_numbers[count];
  int above_numbers[count];
  Numbers separated[] = {below_numbers, in_numbers, above_numbers};
  int counts[] = {0, 0, 0};

  for(u_short i = 0; i < count; i++)
  {
    int number = numbers[i];
    u_short index = compare(number, start, end);
    separated[index][counts[index]++] = number;
  }

  return create_array_of_list_of_numbers(separated, 3, counts);
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
