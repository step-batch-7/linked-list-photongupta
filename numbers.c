#include<stdio.h>
#include "list.h"


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
      
    NEW_LINE;
    display_menu();
    scanf("%c",&operation);
  }
  
  return 0;
}