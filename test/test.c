#include "../list.h"
#include <stdio.h>

int is_number_present_at(List_ptr list, int position, int value)
{
  if (position > list->count - 1 || position < 0)
    return 0;

  Node_ptr p_walk = list->head;
  for (int count = 0; count != position; count++)
    p_walk = p_walk->next;

  return p_walk->value == value;
}

void print_result(int result)
{
  if (result)
    printf("✅");
  else
    printf("❌");
  NEW_LINE;
}

void test_add_to_start()
{
  List_ptr list = create_list();
  int previous_length = list->count;
  printf("should add the number at the start of the list : ");
  Status status = add_to_start(list, 5);
  int result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 0, 5);
  print_result(result);
  destroy_list(list);
}

void test_add_to_end()
{
  List_ptr list = create_list();
  int previous_length = list->count;
  printf("should add the number at the end of the empty list : ");
  Status status = add_to_end(list, 5);
  int result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 0, 5);
  print_result(result);
  destroy_list(list);
}

void test_remove_from_start()
{
  List_ptr list = create_list();

  printf("should return failure for empty list : ");
  Status status = remove_from_start(list);
  int result = status == Failure;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  int previous_length = list->count;
  printf("should remove the number from end of the list : ");
  status = remove_from_start(list);
  result = status == Success && list->count == previous_length - 1 && is_number_present_at(list, 0, 2);
  print_result(result);
  destroy_list(list);
}

void run_tests()
{
  test_add_to_end();
  test_add_to_start();
  test_remove_from_start();
}

int main(void)
{
  printf("Testing start");
  NEW_LINE;
  printf(".............");
  NEW_LINE;
  run_tests();
  printf(".............");
  NEW_LINE;
  printf("Testing end");

  return 0;
}
