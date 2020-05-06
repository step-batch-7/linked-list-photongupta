#include "test.h"
#include <stdio.h>

Test_report_ptr run_tests(Test_report_ptr test_watcher)
{
  test_create_node(test_watcher);
  test_create_list(test_watcher);
  test_add_to_start(test_watcher);
  test_add_to_end(test_watcher);
  test_insert_at(test_watcher);
  test_add_unique(test_watcher);
  test_remove_from_start(test_watcher);
  test_remove_from_end(test_watcher);
  test_remove_at(test_watcher);
  test_remove_first_occurrence(test_watcher);
  test_remove_all_occurrences(test_watcher);
  test_clear_list(test_watcher);
  test_is_present(test_watcher);
  return test_watcher;
}

void print(Test_report_ptr test_report)
{
  printf("\n__________REPORT_________\n");
  printf("\nTotal tests : %d\n", test_report->total);
  printf("✅ Passed : %d\n", test_report->passed);
  printf("❌ Failed : %d\n", test_report->failed);
}

int main(void)
{
  Test_report_ptr test_watcher, test_report;
  test_watcher->failed = 0;
  test_watcher->passed = 0;
  test_watcher->total = 0;

  printf("Testing start.............\n");
  test_report = run_tests(test_watcher);
  printf(".............Testing end\n");

  print(test_report);
  return 0;
}
