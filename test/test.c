#include "../list.h"
#include <stdio.h>

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
  int result = status == Success && list->count == previous_length + 1;
  print_result(result);
  destroy_list(list);
}

void test_add_to_end()
{
  List_ptr list = create_list();
  int previous_length = list->count;
  printf("should add the number at the end of the list : ");
  Status status = add_to_end(list, 5);
  int result = status == Success && list->count == previous_length + 1;
  print_result(result);
  destroy_list(list);
}

void run_tests()
{
  test_add_to_end();
  test_add_to_start();
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
