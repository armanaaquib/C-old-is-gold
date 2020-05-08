#include <stdio.h>
#include "list.h"

#define TERMINATION_VALUE -99

void take_inputs(List_Ptr);
int ask_search_value(void);

void take_inputs(List_Ptr list)
{
  int value;

  printf("Please enter a number:\n");
  scanf("%d", &value);

  while(value != TERMINATION_VALUE)
  {
		insert_value(list, value);
		
    printf("Please enter a number:\n");
    scanf("%d", &value);
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

	int value = ask_search_value();
	
  while(value != TERMINATION_VALUE)
  {
    short position = find_position(list, value);

    if(position != -1)
    {
      printf("%d is present in the list at position %d\n", value, position);
    }
    else
    {
      printf("%d is not present in the list\n", value);
    }
    
		value = ask_search_value();
  }

  free_list(list);
  
  return 0;
}
