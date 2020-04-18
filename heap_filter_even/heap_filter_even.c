#include <stdio.h>
#include <stdlib.h>
#include "dynamic_numbers.h"
#include "heap_filter_even.h"

u_char is_even(int number){
  return number % 2 == 0;
}

Dynamic_Numbers filter_even(Numbers numbers, u_short count)
{
  int temp_evens[count];
  Dynamic_Numbers evens;

  evens.length = 0;
  evens.numbers = NULL;

  ITERATE(0, count)
  {
    int number = numbers[i];

    if(is_even(number))
    {
      temp_evens[evens.length++] = number;
    }
  }

  evens.numbers = malloc(sizeof(int) * evens.length);

  ITERATE(0, evens.length)
  {
    evens.numbers[i] = temp_evens[i];
  }

  return evens;
}
