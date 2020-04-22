#include "separate.h"

int main(void)
{
  int list[] = {3, 1, 7, 4, 6, 5, 8, 2};

  Array_Of_List_Of_Numbers separated = separate(list, 8, 4, 7);

  print_list_of_numbers(separated, 3);

  return 0;
}
