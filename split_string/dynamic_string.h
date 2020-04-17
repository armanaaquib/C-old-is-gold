#ifndef __DYNAMIC_STRING_H_
#define __DYNAMIC_STRING_H_

typedef unsigned short u_short;
typedef char * String;

typedef struct
{
  String *strings;
  u_short length;
} Strings;

#define ITERATE(start, end) for(u_short i = start; i < end; i++)

char *create_string(String, u_short);
String *copy_strings(String *, u_short);
String copy_string(String, u_short);
void print_strings(String *, u_short);

#endif
