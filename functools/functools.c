#include <stdlib.h>
#include "functools.h"

Int_Array create_int_array(Int_Array, unsigned);

Int_Array create_int_array(Int_Array array, unsigned length)
{
  Int_Array new_array = (Int_Array)malloc(sizeof(int) * length);

  for(unsigned i = 0; i < length; i++)
  {
    new_array[i] = array[i];
  }

  return new_array;
}

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

List_Ptr int_filter(Int_Predicate predicate, Int_Array array, unsigned length)
{
  List_Ptr list = (List_Ptr)malloc(sizeof(List));
  list->count = 0;

  int temp_array[length];

  for(unsigned i = 0; i < length; i++)
  {
    int integer = array[i];

    if((*predicate)(integer))
    {
      temp_array[list->count++] = integer;
    }
  }

  list->array = create_int_array(temp_array, list->count);

  return list;
}
