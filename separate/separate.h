#ifndef __SEPARATE_H_
#define __SEPARATE_H_

typedef unsigned short u_short;
typedef int * Numbers;

typedef struct
{
  Numbers numbers;
  u_short count;
} List_Of_Numbers;

typedef List_Of_Numbers * Array_Of_List_Of_Numbers;

Array_Of_List_Of_Numbers separate(Numbers, u_short, int, int);
List_Of_Numbers create_list_of_numbers(Numbers, u_short);
void print_list_of_numbers(Array_Of_List_Of_Numbers, u_short);

#endif
