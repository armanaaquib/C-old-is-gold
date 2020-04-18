#include <stdio.h>
#include <stdlib.h>
#include "dynamic_numbers.h"
#include "heap_filter_even.h"

u_char is_even(int number){
  return number % 2 == 0;
}

Dynamic_Numbers filter_even(Numbers numbers, u_short count)
{
  Dynamic_Numbers evens;

  evens.numbers = malloc(sizeof(int) * count);
  evens.length = 0;

  ITERATE(0, count)
  {
    int number = numbers[i];

    if(is_even(number))
    {
      evens.numbers[evens.length++] = number;
    }
  }

  evens.numbers = realloc(evens.numbers, sizeof(int) * evens.length);

  return evens;
}
