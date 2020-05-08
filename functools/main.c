#include <stdio.h>
#include <limits.h>
#include "functools.h"

int square(int);
int add(int, int);
int gerater(int, int);
Bool is_even(int);
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

Bool is_even(int number)
{
  return number % 2 == 0 ? 1 : 0;
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

  List_Ptr square_list = int_map(&square, array, 5);
  printf("Squares\n");
  display_int_array(square_list->array, square_list->count);

  int sum = int_reduce(&add, array, 5, 0);
  printf("Sum = %d\n", sum);
  printf("Big = %d\n", int_reduce(&greater, array, 5, INT_MIN));

  List_Ptr even_list = int_filter(&is_even, array, 5);
  printf("Evens\n");
  display_int_array(even_list->array, even_list->count);

  return 0;
}
