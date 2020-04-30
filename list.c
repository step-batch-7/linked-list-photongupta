#include "list.h"
#include <stdlib.h>

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
  Status status;
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
    list->head = new_node;
  else
    list->last->next = new_node;
  list->last = new_node;
  list->count += 1;
  status = Success;
  return status;
}

Status add_to_start(List_ptr list, int value)
{ 
  Status status;
  Node_ptr new_node = create_node(value);
  Node_ptr previous_first_node = list->head;
  list->head = new_node;
  new_node->next = previous_first_node;
  list->count += 1;
  status = Success;
  return status;
}

Status insert_at(List_ptr list, int value, int position)
{
  Status status = Failure;
  if(position > list->count + 1)
    return status;

  int count=1;
  Node_ptr p_walk = list->head;
  count++;
  while(count<position)
  {
    p_walk = p_walk->next;
    count++;
  }
  Node_ptr new_node = create_node(value);
  Node_ptr temp_node =p_walk->next;
  p_walk->next = new_node;
  new_node->next = temp_node;
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