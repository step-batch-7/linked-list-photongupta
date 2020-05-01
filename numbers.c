#include<stdio.h>
#include "list.h"

void display(List_ptr list)
{
  printf("Elements of the list are : ");
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
  int value,position;
  Status status = Success;
  List_ptr list = create_list();
  display_menu();
  scanf("%c",&operation);
  while((getchar()) != '\n');

  while(NOT_EXIT)
  {
    switch (operation){

    case 'a':
      printf("Enter the number you want to add at the end of the list : ");
      scanf("%d",&value); 
      while((getchar()) != '\n');
      status = add_to_end(list,value);
      break;
      
    case 'b':
      printf("Enter the number you want to add at the start of the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      status = add_to_start(list,value);
      break;

    case 'c':
      printf("Enter the number you want to insert in the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      printf("Enter the position where you want to insert the number : ");
      scanf("%d",&position);
      while((getchar()) != '\n');
      status = insert_at(list,value,position);
      break;

    case 'd':
      printf("Enter the unique number you want to add in the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      status = add_unique(list,value);
      break;

    case 'e':
      status = remove_from_start(list);
      break;

    case 'f':
      status = remove_from_end(list);
      break;

    case 'k':
      printf("Enter the number to check if it is present in the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      if(is_present(list,value))
        printf("%d is present in the list.",value);
      else 
        printf("%d is not in the list.",value);
      NEW_LINE;
      break;

    case 'l':
      display(list);
      break;
      
    }
    
    if(status)
      printf("Done");
    else
      printf("Something went wrong...");

    display_menu();
    scanf("%c",&operation);
    while((getchar()) != '\n');

  }
  
  return 0;
}