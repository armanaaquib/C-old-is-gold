#include <stdlib.h>
#include "functools.h"

Int_Array int_map(Int_Mapper mapper, Int_Array array, unsigned length)
{
  Int_Array mapped_array = (Int_Array)malloc(sizeof(int) * length);

  for(unsigned i = 0; i < length; i++)
  {
    mapped_array[i] = (*mapper)(array[i]);
  }

  return mapped_array;
}

int int_reduce(Int_Reducer reducer, Int_Array array, unsigned length, int initial_value)
{
  int result = initial_value;

  for(unsigned i = 0; i < length; i++)
  {
    result = (*reducer)(result, array[i]);
  }

  return result;
}
