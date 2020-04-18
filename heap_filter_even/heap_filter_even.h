#ifndef __HEAP_EVEN_FILTER_H_
#define __HEAP_EVEN_FILTER_H_

#define ITERATE(start, end) for(unsigned index = start; index < end; index++)

typedef struct
{
  int length;
  int *numbers;
} Evens;


Evens *filter_even(int *, unsigned);
unsigned char is_even(int);
void print_numbers(int *, unsigned);
void input_numbers(int *, unsigned);

#endif