#ifndef __DYNAMIC_NUMBERS_H_
#define __DYNAMIC_NUMBERS_H_

typedef unsigned short u_short;
typedef int * Numbers;
typedef struct 
{
  Numbers numbers;
  u_short length;
} Dynamic_Numbers;

#ifndef ITERATE
#define ITERATE(start, end) for(u_short i = start; i < end; i++)
#endif

void print_numbers(Numbers, u_short);
void input_numbers(Numbers, u_short);

#endif