#include <stdlib.h>
#include "list.h"

List *create_list(void)
{
  List *list = (List *)malloc(sizeof(List));

  list->start = NULL;
  list->end = NULL;
  list->count = 0;

  return list;
}

Node *create_node(int value)
{
  Node *node = (Node *)malloc(sizeof(Node));

  node->value = value;
  node->next = NULL;

  return node;
}

void insert_value(List *list, int value)
{
  Node *new_node = create_node(value);

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
