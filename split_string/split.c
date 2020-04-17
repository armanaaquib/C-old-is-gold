#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  char **strings;
  unsigned length;
} Strings;

char *create_string(char *string, unsigned length)
{
  char *new_stirng = malloc(sizeof(char *) * length);
  for(int i = 0; i < length; i++){
    new_stirng[i] = string[i];
  }
  return new_stirng;
}

Strings split(char *string, unsigned length, char c)
{ 
  char temp_string[length];
  unsigned temp_length = 0;
  Strings strings;
  strings.strings = malloc(sizeof(char *));
  strings.length = 0;
  for(unsigned i = 0; i <= length; i++)
  {     
    if(string[i] == c || i == length)
    {
      strings.length++;
      temp_string[temp_length] = '\0';
      strings.strings = realloc(strings.strings, sizeof(char *) * strings.length);
      strings.strings[strings.length - 1] = create_string(temp_string, temp_length);
      temp_length = 0;
      continue;
    }
    temp_string[temp_length++] = string[i];
  }
  return strings;
}

int main(void)
{
  char string[] = "this is cool";
  Strings split_string;
  split_string = split(string, 12, ' ');
  for(int i = 0; i < split_string.length; i++)
  {
    printf("%s,", split_string.strings[i]);
  }
  printf("\n");
  return 0;
}
