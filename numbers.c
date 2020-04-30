#include<stdio.h>
#include "list.h"

List_ptr enter_numbers()
{
  List_ptr user_data = create_list();
  int number;

  printf("Please enter numbers(Enter -99 for stop entering) :");
  NEW_LINE;
  scanf("%d", &number);

  while (number != -99)
  {
    add_to_end(user_data, number);
    scanf("%d", &number);
  }
  return user_data;
}

int main(void)
{
  char operation;
  List_ptr list;
  int value,result;
  display_menu();
  scanf("%c",&operation);
  
  while(NOT_EXIT)
  {
    switch (operation){

    case 'a':
      list = enter_numbers();
      printf("Enter the number you want to add at the end of your list : ");
      scanf("%d",&value);
      result = add_to_end(list,value);
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