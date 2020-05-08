#ifndef __FUNCTOOLS_H
#define __FUNCTOOLS_H

typedef int *Int_Array;

typedef struct
{
  Int_Array array;
  unsigned count;
} List;

typedef List *List_Ptr;

typedef enum
{
  False,
  True
} Bool;

typedef int (*Int_Mapper)(int);
typedef int (*Int_Reducer)(int, int);
typedef Bool (*Int_Predicate)(int);

List_Ptr int_map(Int_Mapper, Int_Array, unsigned);
int int_reduce(Int_Reducer, Int_Array, unsigned, int);
List_Ptr int_filter(Int_Predicate, Int_Array, unsigned);

#endif
