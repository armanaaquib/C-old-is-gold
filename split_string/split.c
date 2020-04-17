#include <stdio.h>
#include <stdlib.h>
#include "split.h"

char *create_string(String string, u_short length)
{
  char *new_stirng = malloc(sizeof(char) * length);
  ITERATE(0, length)
  {
    new_stirng[i] = string[i];
  }
  return new_stirng;
}

String *copy_strings(String *strings, u_short length)
{
  String *cp_strings = malloc(sizeof(char *) * length);
  ITERATE(0, length)
  {
    cp_strings[i] = strings[i];
  }
  return cp_strings;
}

String copy_string(String string, u_short length)
{
  String cp_string = malloc(sizeof(char) * length);
  ITERATE(0, length)
  {
    cp_string[i] = string[i];
  }
  return cp_string;
}

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

void print_strings(String *strings, u_short length)
{
  ITERATE(0, length)
  {
    printf("'%s',", strings[i]);
  }
  printf("\n");
}
