#ifndef __LIST_H_
#define __LIST_H_

typedef unsigned short u_short;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef struct
{
  Node *start;
  Node *end;
  u_short count;
} List;

typedef Node * Node_Ptr;
typedef List * List_Ptr;

List_Ptr create_list(void);
Node_Ptr create_node(int);
void insert_value(List_Ptr, int);
short find_position(List_Ptr, int value);

#endif