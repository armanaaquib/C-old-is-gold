#include<stdio.h>
#include<stdlib.h>

typedef unsigned short u_short;
typedef char * String;
#define ITERATE(start, end) for(u_short i = start; i < end; i++)

typedef struct
{
  String *strings;
  u_short length;
} Strings;

Strings split(String, u_short, char);
char *create_string(String, u_short);
String *copy_string(String *, u_short);
void print_strings(String *, u_short);

char *create_string(String string, u_short length)
{
  char *new_stirng = malloc(sizeof(char *) * length);
  ITERATE(0, length)
  {
    new_stirng[i] = string[i];
  }
  return new_stirng;
}

String *copy_strings(String *strings, u_short length)
{
  String *cp_strings = malloc(sizeof(char) * length);
  ITERATE(0, length)
  {
    cp_strings[i] = strings[i];
  }
  return cp_strings;
}

Strings split(String string, u_short length, char c)
{ 
  char temp_string[length];
  String temp_strings[length];
  Strings strings;
  strings.strings = NULL;
  strings.length = 0;
  if(c == '\0')
  {
    ITERATE(0, length)
    {
      temp_string[0] = string[i];
      temp_string[1] = '\0';
      temp_strings[strings.length] = create_string(temp_string, 2);
      strings.length++;
    }
    strings.strings = copy_strings(temp_strings, strings.length);
    return strings;
  }
  u_short temp_length = 0;
  ITERATE(0, length + 1)
  {  
    if(string[i] == c || i == length)
    {
      temp_string[temp_length++] = '\0';
      temp_strings[strings.length] = create_string(temp_string, temp_length);
      strings.length++;
      temp_length = 0;
      continue;
    }
    temp_string[temp_length++] = string[i];
  }
  strings.strings = copy_strings(temp_strings, strings.length);
  return strings;
}

void print_strings(String *strings, u_short length)
{
  ITERATE(0, length)
  {
    printf("'%s',", strings[i]);
  }
  printf("\n");
}

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
