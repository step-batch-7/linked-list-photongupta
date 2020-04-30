#include<stdio.h>
#include "list.h"

void display(List_ptr list)
{
  NEW_LINE;
  printf("Updated list is given below : ");
  NEW_LINE;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d ",p_walk->value);
    p_walk = p_walk->next;
  }
  NEW_LINE;
}


int main(void)
{
  char operation;
  int value,result;
  List_ptr list = create_list();
  display_menu();
  scanf("%c",&operation);
  
  while(NOT_EXIT)
  {
    switch (operation){

    case 'a':
      printf("Enter the number you want to add at the end of the list : ");
      scanf("%d",&value);
      result = add_to_end(list,value);
      break;
      
    case 'b':
      printf("Enter the number you want to add at the start of the list : ");
      scanf("%d",&value);
      result = add_to_start(list,value);
      break;
      
    }
    
    if(result)
      printf("Done");
    else
      printf("Something went wrong...");

    display(list);
    display_menu();
    scanf("%c",&operation);
  }
  
  return 0;
}