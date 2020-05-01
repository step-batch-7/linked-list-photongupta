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
  int value,result,position;
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
      result = add_to_end(list,value);
      break;
      
    case 'b':
      printf("Enter the number you want to add at the start of the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      result = add_to_start(list,value);
      break;

    case 'c':
      printf("Enter the number you want to insert in the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      printf("Enter the position where you want to insert the number : ");
      scanf("%d",&position);
      while((getchar()) != '\n');
      result = insert_at(list,value,position);
      break;

    case 'd':
      printf("Enter the unique number you want to add in the list : ");
      scanf("%d",&value);
      while((getchar()) != '\n');
      result = add_unique(list,value);
      break;

    case 'e':
      result = remove_from_start(list);
      break;

    case 'f':
      result = remove_from_end(list);
      break;

    case 'l':
      display(list);
      result = Success;
      break;
      
    }
    
    if(result)
      printf("Done");
    else
      printf("Something went wrong...");

    display_menu();
    scanf("%c",&operation);
    while((getchar()) != '\n');

  }
  
  return 0;
}