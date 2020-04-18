#include <stdio.h>
#include <stdlib.h>
#include "heap_filter_even.h"

int main(void)
{
  unsigned length;
  int *numbers;

  printf("Enter length: ");
  scanf("%d", &length);

  numbers = malloc(sizeof(int) * length);

  input_numbers(numbers, length);

  Evens * evens = filter_even(numbers, length);

  printf("Even Numbers: ");
  print_numbers(evens->numbers, evens->length);

  return 0;
}
