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

List *create_list(void);
Node *create_node(int);
void insert_value(List *, int);

#endif