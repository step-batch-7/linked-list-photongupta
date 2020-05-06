#ifndef __TEST_H
#define __TEST_H

#include "../list.h"
typedef char *Char_ptr;

void it(Char_ptr);
void describe(Char_ptr);
void assert_int(int,int,Char_ptr);
void assert_ok(int,Char_ptr);
void assert_is_null(Node_ptr,Char_ptr);
int is_number_present_at(List_ptr, int, int);

void test_create_node();
void test_create_list();
void test_add_to_start();
void test_add_to_start();
void test_add_to_end();
void test_insert_at();
void test_add_unique();
void test_remove_from_start();
void test_remove_from_end();
void test_remove_at();
void test_remove_first_occurrence();
void test_remove_all_occurrences();
void test_clear_list();
void test_is_present();
void run_tests();

#endif
