#include <stdlib.h>
#include "dynamic_string.h"
#include "split.h"

Strings split_every_char(String string, u_short length)
{
  Strings split_strings;
  split_strings.strings = malloc(sizeof(String) * length);
  split_strings.length = 0;
  ITERATE(0, length)
  {
    char sub_string[] = {string[i], END_OF_STRING}; 
    split_strings.strings[split_strings.length++] = create_string(sub_string, 2);
  }
  return split_strings;
}

Strings split(String string, u_short length, char c)
{ 
  if(c == END_OF_STRING)
  {
    return split_every_char(string, length);
  }

  Strings split_string;
  String heap_copy_string = copy_string(string, length);
  u_short count = get_no_of_occurrance(string, length, c) + 1;

  split_string.strings = malloc(sizeof(String) * count);
  split_string.strings[0] = heap_copy_string;
  split_string.length = 1;

  ITERATE(0, length)
  {
    if(string[i] == c)
    {
      heap_copy_string[i] = END_OF_STRING;
      split_string.strings[split_string.length++] = heap_copy_string + i + 1;
    }
  }
  return split_string;
}
