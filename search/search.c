#include <stdio.h>
#include "list.h"

short find_position(List *, int value);

short find_position(List *list, int value)
{
  Node *p_walk = list->start;
  short position = 0;

  while(p_walk != NULL)
  {
    if(p_walk->value == value)
    {
      return position;
    }

    position++;
    p_walk = p_walk->next;
  }

  return -1;
}

int main(void)
{
  List *list = create_list();
  int value;

  while(1)
  {
    printf("Please enter a number:\n");
    scanf("%d", &value);

    if(value == -99)
    {
      break;
    }

    insert_value(list, value);
  }

  while(1)
  {
    printf("What number would you like to search for?\n");
    scanf("%d", &value);

    if(value == -99)
    {
      break;
    }

    short pos = find_position(list, value);

    if(pos != -1)
    {
      printf("%d is present in the list at position %d\n", value, pos);
    }
    else
    {
      printf("%d is not present in the list\n", value);
    }
    
  }

  return 0;
}
