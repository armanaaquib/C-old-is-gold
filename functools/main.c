#include <stdio.h>
#include <limits.h>
#include "functools.h"

int square(int);
int add(int, int);
int gerater(int, int);
void display_int_array(Int_Array, unsigned);

int square(int number)
{
  return number * number;
}

int add(int number_1, int number_2)
{
  return number_1 + number_2;
}

int greater(int number_1, int number_2)
{
  return number_1 >= number_2 ? number_1 : number_2;
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
  int array[] = {1, 2, -3, 4, 5};

  display_int_array(array, 5);

  Int_Array squares = int_map(&square, array, 5);
  printf("Squares\n");
  display_int_array(squares, 5);

  int sum = int_reduce(&add, array, 5, 0);
  printf("Sum = %d\n", sum);
  printf("Big = %d\n", int_reduce(&greater, array, 5, INT_MIN));

  return 0;
}
