#include<stdio.h>
#include "list.h"

int enter_number(void)
{
  int value;
  scanf("%d",&value);
  while((getchar()) != '\n');
  return value; 
}

int main(void)
{
  char operation;
  int value,position;
  Status status;
  List_ptr list = create_list();
  display_menu();
  operation = getchar();
  while((getchar()) != '\n');

  while(operation != EXIT)
  {
    switch (operation){

    case 'a':
      printf("Enter the number you want to add at the end of the list : ");
      value = enter_number();
      status = add_to_end(list,value);
      break;
      
    case 'b':
      printf("Enter the number you want to add at the start of the list : ");
      value = enter_number();
      status = add_to_start(list,value);
      break;

    case 'c':
      printf("Enter the number you want to insert in the list : ");
      value = enter_number();
      printf("Enter the position where you want to insert the number : ");
      position = enter_number();
      status = insert_at(list,value,position);
      break;

    case 'd':
      printf("Enter the unique number you want to add in the list : ");
      value = enter_number();
      status = add_unique(list,value);
      break;

    case 'e':
      status = remove_from_start(list);
      break;

    case 'f':
      status = remove_from_end(list);
      break;

    case 'g':
      printf("Enter the position which you want to remove from the list : ");
      position = enter_number();
      status = remove_at(list,position);
      break;

    case 'h':
      printf("Enter the number you want to remove from the list : ");
      value = enter_number();
      status = remove_first_occurrence(list,value);
      break;

    case 'i':
      printf("Enter the number you want to remove from the list : ");
      value = enter_number();
      status = remove_all_occurrences(list,value);
      break;

    case 'j':
      status = clear_list(list);
      break;

    case 'k':
      printf("Enter the number to check if it is present in the list : ");
      value = enter_number();
      if(is_present(list,value))
        printf("%d is present in the list.",value);
      else 
        printf("%d is not in the list.",value);
      NEW_LINE;
      status = Success;
      break;

    case 'l':
      display_list(list);
      status = Success;
      break;
    }
    
    display_status(status);
    display_menu();
    operation = getchar();
    while((getchar()) != '\n');

  }
  
  return 0;
}
