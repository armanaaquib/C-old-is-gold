#include <stdio.h>
#include "list.h"

#define TERMINATION_VALUE -99

void take_inputs(List_Ptr);
int ask_search_value(void);

void take_inputs(List_Ptr list)
{
  int value;

  while(1)
  {
    printf("Please enter a number:\n");
    scanf("%d", &value);

    if(value == TERMINATION_VALUE)
    {
      break;
    }

    insert_value(list, value);
  }

}

int ask_search_value(void)
{
  int value;

  printf("What number would you like to search for?\n");
  scanf("%d", &value);

  return value;
}

int main(void)
{
  List_Ptr list = create_list();

  take_inputs(list);

  while(1)
  {
    int value = ask_search_value();

    if(value == TERMINATION_VALUE)
    {
      break;
    }

    short position = find_position(list, value);

    if(position != -1)
    {
      printf("%d is present in the list at position %d\n", value, position);
    }
    else
    {
      printf("%d is not present in the list\n", value);
    }
    
  }

  free_list(list);

  return 0;
}
