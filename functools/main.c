#include <stdio.h>
#include "functools.h"

int square(int);
void display_int_array(Int_Array, unsigned);

int square(int number)
{
  return number * number;
}

void display_int_array(Int_Array array, unsigned length)
{
  for(unsigned i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(void)
{
  int array[] = {1, 2, 3, 4, 5};

  Int_Array squares = int_map(&square, array, 5);

  display_int_array(squares, 5);

  return 0;
}