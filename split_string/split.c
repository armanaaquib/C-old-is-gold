#include <stdlib.h>
#include "dynamic_string.h"
#include "split.h"

Strings split(String string, u_short length, char c)
{ 
  String temp_strings[length];
  Strings strings;

  strings.strings = NULL;
  strings.length = 0;

  if(c == '\0')
  {
    ITERATE(0, length)
    {
      char temp_string[2];
      temp_string[0] = string[i];
      temp_string[1] = '\0';
      temp_strings[strings.length] = create_string(temp_string, 2);
      strings.length++;
    }
    strings.strings = copy_strings(temp_strings, strings.length);
    return strings;
  }


  String heap_copy_string = copy_string(string, length);
  temp_strings[0] = heap_copy_string;
  ITERATE(0, length)
  {  
    if(string[i] == c)
    {
      heap_copy_string[i] = '\0';
      temp_strings[++strings.length] = heap_copy_string + i + 1;
    }
  }
  strings.length++;
  strings.strings = copy_strings(temp_strings, strings.length);
  return strings;
}
