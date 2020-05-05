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
  NEW_LINE;
  printf("# add_to_start");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should add the number at the start if the list is empty : ");
  Status status = add_to_start(list, 1);
  int result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 0, 1);
  print_result(result);

  previous_length = list->count;
  printf("should add the number at the start of the list : ");
  status = add_to_start(list, 2);
  result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 0, 2);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_add_to_end()
{
  printf("# add_to_end");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should add the number at the end if the list is empty : ");
  Status status = add_to_end(list, 1);
  int result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 0, 1);
  print_result(result);

  previous_length = list->count;
  printf("should add the number at the end of the list : ");
  status = add_to_end(list, 2);
  result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 1, 2);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_insert_at()
{
  printf("# insert_at");
  NEW_LINE;
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  int previous_length = list->count;
  printf("should insert at 0th position in the list : ");
  Status status = insert_at(list, 3, 0);
  int result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 0, 3);
  print_result(result);

  previous_length = list->count;
  printf("should insert at last position in the list : ");
  status = insert_at(list, 4, 3);
  result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 3, 4);
  print_result(result);

  previous_length = list->count;
  printf("should insert at given position in the list : ");
  status = insert_at(list, 5, 2);
  result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 2, 5);
  print_result(result);

  previous_length = list->count;
  printf("should not insert if the given position is invalid : ");
  status = insert_at(list, 6, 10);
  result = status == Failure && list->count == previous_length && !is_number_present_at(list, 10, 6);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_add_unique()
{
  printf("# add_unique");
  NEW_LINE;
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  int previous_length = list->count;
  printf("should not add if number is in the list : ");
  Status status = add_unique(list, 1);
  int result = status == Failure && list->count == previous_length && !is_number_present_at(list, 2, 1);
  print_result(result);

  previous_length = list->count;
  printf("should add if number is not present in the list : ");
  status = add_unique(list, 5);
  result = status == Success && list->count == previous_length + 1 && is_number_present_at(list, 2, 5);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_remove_from_start()
{
  printf("# remove_from_start");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should not remove if the list is empty : ");
  Status status = remove_from_start(list);
  int result = status == Failure && list->count == previous_length;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  previous_length = list->count;
  printf("should remove the number from start of the list : ");
  status = remove_from_start(list);
  result = status == Success && list->count == previous_length - 1 && is_number_present_at(list, 0, 2);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_remove_from_end()
{
  printf("# remove_from_end");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should not remove if the list is empty : ");
  Status status = remove_from_end(list);
  int result = status == Failure && list->count == previous_length;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  previous_length = list->count;
  printf("should remove the number from end of the list : ");
  status = remove_from_end(list);
  result = status == Success && list->count == previous_length - 1 && !is_number_present_at(list, 1, 2);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_remove_at()
{
  printf("# remove_at");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should not remove if the list is empty: ");
  Status status = remove_at(list, 2);
  int result = status == Failure && list->count == previous_length;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);
  previous_length = list->count;
  printf("should remove from the last position of the list: ");
  status = remove_at(list, 4);
  result = status == Success && list->count == previous_length - 1 && !is_number_present_at(list, 4, 5);
  print_result(result);

  previous_length = list->count;
  printf("should remove from the 0th position of the list: ");
  status = remove_at(list, 0);
  result = status == Success && list->count == previous_length - 1 && !is_number_present_at(list, 0, 1);
  print_result(result);

  previous_length = list->count;
  printf("should remove from the given position of the list: ");
  status = remove_at(list, 1);
  result = status == Success && list->count == previous_length - 1 && !is_number_present_at(list, 1, 3);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_remove_first_occurrence()
{
  printf("# remove_first_occurrence");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should not remove if the list is empty : ");
  Status status = remove_first_occurrence(list, 1);
  int result = status == Failure && list->count == previous_length;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 2);
  previous_length = list->count;
  printf("should remove the first occurrence of the given number from list : ");
  status = remove_first_occurrence(list, 2);
  result = status == Success && list->count == previous_length - 1 && !is_number_present_at(list, 1, 2);
  print_result(result);

  previous_length = list->count;
  printf("should not remove if the list doesn't contain the given number : ");
  status = remove_first_occurrence(list, 5);
  result = status == Failure && list->count == previous_length;
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_remove_all_occurrences()
{
  printf("# remove_all_occurrences");
  NEW_LINE;
  List_ptr list = create_list();

  int previous_length = list->count;
  printf("should not remove if the list is empty : ");
  Status status = remove_all_occurrences(list, 1);
  int result = status == Failure && list->count == previous_length;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 2);
  previous_length = list->count;
  printf("should remove all occurrences of the given number from list : ");
  status = remove_all_occurrences(list, 2);
  result = status == Success &&
           list->count == previous_length - 2 &&
           !is_number_present_at(list, 1, 2) &&
           !is_number_present_at(list, 3, 2);
  print_result(result);

  previous_length = list->count;
  printf("should not remove if the list doesn't contain the given number : ");
  status = remove_all_occurrences(list, 5);
  result = status == Failure && list->count == previous_length;
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void test_clear_list()
{
  printf("# clear_list");
  NEW_LINE;
  List_ptr list = create_list();

  printf("should clear the empty list : ");
  Status status = clear_list(list);
  int result = status == Success && list->count == 0;
  print_result(result);

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  printf("should remove all the elements present in the list : ");
  status = clear_list(list);
  result = status == Success &&
           list->count == 0 &&
           !is_number_present_at(list, 0, 1) &&
           !is_number_present_at(list, 1, 2) &&
           !is_number_present_at(list, 2, 3);
  print_result(result);

  destroy_list(list);
  NEW_LINE;
}

void run_tests()
{
  test_add_to_start();
  test_add_to_end();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_clear_list();
}

int main(void)
{
  printf("Testing start.............");
  NEW_LINE;
  run_tests();
  printf(".............Testing end");
  return 0;
}
