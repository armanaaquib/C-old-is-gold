#include <stdio.h>
#include <stdlib.h>
#include "dynamic_numbers.h"
#include "heap_filter_even.h"

int main(void)
{
  u_short length;
  Numbers numbers;

  printf("Enter length: ");
  scanf("%hu", &length);

  numbers = malloc(sizeof(int) * length);

  input_numbers(numbers, length);

  Dynamic_Numbers evens = filter_even(numbers, length);

  printf("Even Numbers: ");
  print_numbers(evens.numbers, evens.length);

  return 0;
}
