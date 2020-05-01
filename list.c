#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Node_ptr create_node(int value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{ 
  Status status = Success;
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
    list->head = new_node;
  else
    list->last->next = new_node;
  list->last = new_node;
  list->count += 1;
  return status;
}

Status add_to_start(List_ptr list, int value)
{ 
  Status status = Success;
  Node_ptr new_node = create_node(value);
  Node_ptr previous_first_node = list->head;
  list->head = new_node;
  new_node->next = previous_first_node;
  list->count += 1;
  return status;
}

Status insert_at(List_ptr list, int value, int position)
{
  Status status = Failure;
  if(position > list->count + 1)
    return status;

  if(position == 1)
    return add_to_start(list, value);

  Node_ptr p_walk = list->head;
  for(int count = 1; count < position - 1; count++)
  {
    p_walk = p_walk->next;
  }
  Node_ptr new_node = create_node(value);
  new_node->next =p_walk->next;
  p_walk->next = new_node;
  list->count += 1;
  status = Success;
  return status;
}

Status add_unique(List_ptr list, int value)
{ 
  Status status = Success;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if(p_walk->value == value)
      return status;
    p_walk = p_walk->next;
  }
  add_to_end(list,value);
  return status;
}

Status remove_from_start(List_ptr list)
{ 
  Status status = Failure;
  if(EMPTY_LIST)
    return status;
  Node_ptr first_node = list->head;
  list->head = first_node->next;
  free(first_node);
  list->count -= 1;
  status = Success;
  return status;
}

Status remove_from_end(List_ptr list)
{ 
  Status status = Failure;
  if(EMPTY_LIST)
    return status;
  Node_ptr temp = NULL;
  Node_ptr p_walk = list->head;

  while (p_walk->next!=NULL)
  {
    temp = p_walk;
    p_walk = p_walk->next;
  }
  free(p_walk);
  list->last= temp;
  if(temp != NULL)
    temp->next = NULL;
  else
    list->head = temp;
  list->count -= 1;
  status = Success;
  return status;
}

Status is_present(List_ptr list, int value)
{
  Status status = Failure;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if(p_walk->value == value){
      status = Success;
      return status;
    }
    p_walk = p_walk->next;
  }
  return status;
}

Status remove_at(List_ptr list, int position)
{
  Status status = Failure;
  if(position>list->count)
    return status;
    
  if(position == 1)
    return remove_from_start(list);

  if(position == list->count)
    return remove_from_end(list);
    
  Node_ptr temp_node;
  Node_ptr p_walk = list->head;
  for(int count = 1; count < position; count++)
  {
    temp_node = p_walk;
    p_walk = p_walk->next;
  }
  temp_node->next =p_walk->next;
  free(p_walk);
  list->count -= 1;
  status = Success;
  return status;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Status status = Failure;
  if(!is_present(list,value))
    return status;
  Node_ptr p_walk = list->head;
  int postion = 1;
  while(p_walk->value != value)
  {
     p_walk = p_walk->next;
     postion++;
  }
  remove_at(list,postion);
  status = Success;
  return status;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Status status = Failure;
  if(!is_present(list,value))
    return status;

  Node_ptr p_walk = list->head;
  for(int position = 1; p_walk!=NULL; position++)
  {
    if(p_walk->value == value)
    {
      remove_at(list,position);
      position-=1;
    }
    p_walk = p_walk->next;
  }
  status = Success;
  return status;
}

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

void destroy_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    Node_ptr next = p_walk->next;
    free(p_walk);
    p_walk = next;
  }
  free(list);
}