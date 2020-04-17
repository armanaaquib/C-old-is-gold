#include <stdio.h>
#include <stdlib.h>
#include "dynamic_string.h"

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

void print_strings(String *strings, u_short length)
{
  ITERATE(0, length)
  {
    printf("'%s',", strings[i]);
  }
  printf("\n");
}
