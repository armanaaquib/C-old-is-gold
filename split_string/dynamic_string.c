#include <stdio.h>
#include <stdlib.h>
#include "dynamic_string.h"

u_short get_no_of_occurrance(String string, u_short length, char c)
{
  u_short no_of_occurrance = 0;
  ITERATE(0, length)
  {
    if(string[i] == c)
    {
      no_of_occurrance += 1;
    }
  }
  return no_of_occurrance;
}

String create_string(String string, u_short length)
{
  String new_stirng = malloc(sizeof(char) * length);
  ITERATE(0, length)
  {
    new_stirng[i] = string[i];
  }
  return new_stirng;
}

String copy_string(String string, u_short length)
{
  String copy_string = malloc(sizeof(char) * length);
  ITERATE(0, length)
  {
    copy_string[i] = string[i];
  }
  return copy_string;
}

void print_strings(String *strings, u_short length)
{
  ITERATE(0, length)
  {
    printf("'%s',", strings[i]);
  }
  printf("\n");
}
