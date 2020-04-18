#include "dynamic_numbers.h"

#ifndef __HEAP_EVEN_FILTER_H_
#define __HEAP_EVEN_FILTER_H_

typedef unsigned char u_char;
typedef unsigned short u_short;

#ifndef ITERATE
#define ITERATE(start, end) for(u_short i = start; i < end; i++)
#endif


Dynamic_Numbers filter_even(Numbers, u_short);
u_char is_even(int);

#endif