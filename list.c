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