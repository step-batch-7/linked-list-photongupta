#include "test.h"
#include <stdio.h>

void run_tests()
{
  test_create_node();
  test_create_list();
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
  test_is_present();
}

int main(void)
{
  printf("Testing start.............");
  NEW_LINE;
  run_tests();
  printf(".............Testing end");
  return 0;
}
