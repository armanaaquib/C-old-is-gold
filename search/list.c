#include <stdlib.h>
#include "list.h"

List_Ptr create_list(void)
{
  List_Ptr list = (List_Ptr )malloc(sizeof(List));

  list->start = NULL;
  list->end = NULL;
  list->count = 0;

  return list;
}

Node_Ptr create_node(int value)
{
  Node_Ptr node = (Node_Ptr )malloc(sizeof(Node));

  node->value = value;
  node->next = NULL;

  return node;
}

void insert_value(List_Ptr list, int value)
{
  Node_Ptr new_node = create_node(value);

  if(list->start == NULL)
  {
    list->start = new_node;
  }
  else
  {
    list->end->next = new_node;
  }
  
  list->end = new_node;
  list->count++;
}

short find_position(List_Ptr list, int value)
{
  Node_Ptr p_walk = list->start;
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
