#include <stdio.h>
#include "split.h"

int main(void)
{
  char string[] = "this is cool";
  Strings split_string;

  split_string = split(string, 12, '\0');
  print_strings(split_string.strings, split_string.length);

  split_string = split(string, 12, ' ');
  print_strings(split_string.strings, split_string.length);

  split_string = split(string, 12, 'i');
  print_strings(split_string.strings, split_string.length);

  return 0;
}
