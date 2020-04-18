#include <stdio.h>
#include "dynamic_numbers.h"

void print_numbers(Numbers numbers, u_short length)
{
  ITERATE(0, length)
  {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

void input_numbers(Numbers numbers, u_short length)
{
  printf("Enter %d numbers: ", length);
  ITERATE(0, length)
  {
    scanf("%d,", &numbers[i]);
  }
}
