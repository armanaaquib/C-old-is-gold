#include <stdlib.h>
#include "dynamic_string.h"
#include "split.h"

Strings split_every_char(String string, u_short length)
{
  Strings split_strings;
  split_strings.strings = malloc(sizeof(char *) * length);
  split_strings.length = 0;
  ITERATE(0, length)
  {
    char sub_string[2];
    sub_string[0] = string[i];
    sub_string[1] = '\0';
    split_strings.strings[split_strings.length++] = create_string(sub_string, 2);
  }
  return split_strings;
}

Strings split(String string, u_short length, char c)
{ 
  if(c == '\0')
  {
    return split_every_char(string, length);
  }

  Strings split_string;
  u_short count = get_no_of_occurrance(string, length, c) + 1;
  split_string.strings = malloc(sizeof(char *) * count);

  String heap_copy_string = copy_string(string, length);
  split_string.strings[0] = heap_copy_string;
  split_string.length = 1;
  ITERATE(0, length)
  {
    if(string[i] == c)
    {
      heap_copy_string[i] = '\0';
      split_string.strings[split_string.length++] = heap_copy_string + i + 1;
    }
  }
  return split_string;
}
