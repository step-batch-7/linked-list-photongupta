#include "test.h"
#include <stdio.h>

void describe(Char_ptr message)
{
  printf("%s", message);
  NEW_LINE;
}

void it(Char_ptr message)
{
  printf("%s", message);
}

void print_status(int status)
{
  if (status)
    printf("✅");
  else
    printf("❌");
}

void assert_int(int actual, int expected)
{
  print_status(actual == expected);
}

void assert_ok(int value)
{
  print_status(value);
}

int is_number_present_at(List_ptr list, int position, int value)
{
  if (position > list->count - 1 || position < 0)
    return 0;

  Node_ptr p_walk = list->head;
  for (int count = 0; count != position; count++)
    p_walk = p_walk->next;

  return p_walk->value == value;
}