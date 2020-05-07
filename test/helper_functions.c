#include "test.h"
#include <stdio.h>

void describe(Char_ptr message)
{
  NEW_LINE;
  printf("%s", message);
  NEW_LINE;
}

void it(Char_ptr message)
{
  NEW_LINE;
  printf("%s", message);
}

void print_status(int status, Test_report_ptr test_watcher)
{
  if (status)
  {
    test_watcher->passed++;
    printf("✅ ");
  }
  else
  {
    test_watcher->failed++;
    printf("❌ ");
  }
  test_watcher->total++;
}

void assert_int(int actual, int expected, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status(actual == expected, test_watcher);
  printf("%s", message);
}

void assert_ok(int value, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status(value, test_watcher);
  printf("%s", message);
}

void assert_is_null(Node_ptr value, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status(value == NULL, test_watcher);
  printf("%s", message);
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

float percentage(int total, int value)
{
  return (100 * value) / total;
}