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
String *copy_strings(String *, u_short);
String copy_string(String, u_short);
void print_strings(String *, u_short);
