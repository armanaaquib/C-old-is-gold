#include <stdio.h>
#include <stdlib.h>
#include "heap_filter_even.h"

unsigned char is_even(int number){
  return number % 2 == 0;
}

Evens *filter_even(int *numbers, unsigned count)
{
  int temp_evens[count];
  Evens *evens = malloc(sizeof(int) + sizeof(int *));

  evens->length = 0;
  evens->numbers = NULL;

  ITERATE(0, count)
  {
    int number = numbers[index];

    if(is_even(number))
    {
      temp_evens[evens->length] = number;
      evens->length += 1;
    }
  }

  evens->numbers = malloc(sizeof(int) * evens->length);

  ITERATE(0, evens->length)
  {
    evens->numbers[index] = temp_evens[index];
  }

  return evens;
}

void print_numbers(int *array, unsigned length)
{
  ITERATE(0, length)
  {
    printf("%d ", array[index]);
  }
  printf("\n");
}

void input_numbers(int *array, unsigned length)
{
  printf("Enter %d numbers: ", length);
  ITERATE(0, length)
  {
    scanf("%d,", &array[index]);
  }
}
