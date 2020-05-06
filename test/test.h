#ifndef __TEST_H
#define __TEST_H

#include "../list.h"
typedef char *Char_ptr;

typedef struct   Test_report{
 int passed;
 int failed;
 int total;
}   Test_report;

typedef   Test_report *  Test_report_ptr;

void it(Char_ptr);
void describe(Char_ptr);
void assert_int(int,int,Char_ptr,  Test_report_ptr);
void assert_ok(int,Char_ptr,  Test_report_ptr);
void assert_is_null(Node_ptr,Char_ptr,  Test_report_ptr);
int is_number_present_at(List_ptr, int, int);

void test_create_node(  Test_report_ptr);
void test_create_list(  Test_report_ptr);
void test_add_to_start(  Test_report_ptr);
void test_add_to_start(  Test_report_ptr);
void test_add_to_end(  Test_report_ptr);
void test_insert_at(  Test_report_ptr);
void test_add_unique(  Test_report_ptr);
void test_remove_from_start(  Test_report_ptr);
void test_remove_from_end(  Test_report_ptr);
void test_remove_at(  Test_report_ptr);
void test_remove_first_occurrence(  Test_report_ptr);
void test_remove_all_occurrences(  Test_report_ptr);
void test_clear_list(  Test_report_ptr);
void test_is_present(  Test_report_ptr);
  Test_report_ptr run_tests(  Test_report_ptr);

#endif
