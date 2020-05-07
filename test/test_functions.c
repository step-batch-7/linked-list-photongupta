#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void test_create_node(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CREATE_NODE");
  Node_ptr node = create_node(1);

  it("Should create a node with given value: ");
  assert_int(node->value, 1, "should pass the value", test_watcher);
  assert_is_null(node->next, "next should be null", test_watcher);

  free(node);
  NEW_LINE;
}

void test_create_list(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CREATE_LIST");
  List_ptr list = create_list();

  it("Should create list with count 0: ");
  assert_int(list->count, 0, "count should be 0", test_watcher);
  assert_is_null(list->head, "head should be null", test_watcher);
  assert_is_null(list->last, "last should be null", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_add_to_start(Test_report_ptr test_watcher)
{
  describe("# ADD_TO_START");
  List_ptr list = create_list();

  it("Should add the number at the start of the list : ");
  assert_int(add_to_start(list, 1), Success, "should add the number", test_watcher);
  assert_int(list->count, 1, "count should increase by one", test_watcher);
  assert_ok(is_number_present_at(list, 0, 1), "number should be present at first position", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_add_to_end(Test_report_ptr test_watcher)
{
  describe("# ADD_TO_END");
  List_ptr list = create_list();

  it("Should add the number at the end of the list :");
  assert_int(add_to_end(list, 1), Success, "should add the number", test_watcher);
  assert_int(list->count, 1, "count should increase by one", test_watcher);
  assert_ok(is_number_present_at(list, 0, 1), "number should be present at last position", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_insert_at(Test_report_ptr test_watcher)
{
  describe("# INSERT_AT");
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  it("Should insert at 0th position in the list : ");
  assert_int(insert_at(list, 3, 0), Success, "should add the number", test_watcher);
  assert_int(list->count, 3, "count should increase by one", test_watcher);
  assert_ok(is_number_present_at(list, 0, 3), "number should be present at first position", test_watcher);
  NEW_LINE;

  it("Should insert at last position in the list : ");
  assert_int(insert_at(list, 4, 3), Success, "should add the number", test_watcher);
  assert_int(list->count, 4, "count should increase by one", test_watcher);
  assert_ok(is_number_present_at(list, 3, 4), "number should be present at last position", test_watcher);
  NEW_LINE;

  it("Should insert at given position in the list : ");
  assert_int(insert_at(list, 5, 2), Success, "should add the number", test_watcher);
  assert_int(list->count, 5, "count should increase by one", test_watcher);
  assert_ok(is_number_present_at(list, 2, 5), "number should be present at given position", test_watcher);
  NEW_LINE;

  it("Should not insert if the given position is invalid : ");
  assert_int(insert_at(list, 6, 10), Failure, "should not add the number", test_watcher);
  assert_int(list->count, 5, "count should remain same", test_watcher);
  assert_ok(!is_number_present_at(list, 10, 6), "number should not be present at the given position", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_add_unique(Test_report_ptr test_watcher)
{
  describe("# ADD_UNIQUE");
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  it("Should not add if number is in the list : ");
  assert_int(add_unique(list, 1), Failure, "should not add the number", test_watcher);
  assert_int(list->count, 2, "count should remain same", test_watcher);
  assert_ok(!is_number_present_at(list, 2, 1), "number should not be present at the given position", test_watcher);
  NEW_LINE;

  it("Should add if number is not present in the list : ");
  assert_int(add_unique(list, 3), Success, "should add the number", test_watcher);
  assert_int(list->count, 3, "count should increase by one", test_watcher);
  assert_ok(is_number_present_at(list, 2, 3), "number should be present at last position", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_remove_from_start(Test_report_ptr test_watcher)
{
  describe("# REMOVE_FROM_START");
  List_ptr list = create_list();

  it("Should not remove if the list is empty : ");
  assert_int(remove_from_start(list), Failure, "should not remove", test_watcher);
  assert_int(list->count, 0, "count should be 0", test_watcher);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  it("Should remove the number from start of the list : ");
  assert_int(remove_from_start(list), Success, "should remove the first number", test_watcher);
  assert_int(list->count, 1, "count should be decreased by one", test_watcher);
  assert_ok(is_number_present_at(list, 0, 2), "first position should not contain that number", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_remove_from_end(Test_report_ptr test_watcher)
{
  describe("# REMOVE_FROM_END");
  List_ptr list = create_list();

  it("Should not remove if the list is empty : ");
  assert_int(remove_from_end(list), Failure, "should not remove", test_watcher);
  assert_int(list->count, 0, "count should be 0", test_watcher);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  it("Should remove the number from end of the list : ");
  assert_int(remove_from_end(list), Success, "should remove the last number", test_watcher);
  assert_int(list->count, 1, "count should be decreased by one", test_watcher);
  assert_ok(!is_number_present_at(list, 1, 2), "last position should not contain the number", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_remove_at(Test_report_ptr test_watcher)
{
  describe("# REMOVE_AT");
  List_ptr list = create_list();

  it("Should not remove if the list is empty: ");
  assert_int(remove_at(list, 1), Failure, "should not remove", test_watcher);
  assert_int(list->count, 0, "count should be 0", test_watcher);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);
  it("Should remove from the last position of the list: ");
  assert_int(remove_at(list, 4), Success, "should remove the last number", test_watcher);
  assert_int(list->count, 4, "count should be decreased by one", test_watcher);
  assert_ok(!is_number_present_at(list, 4, 5), "first position should not contain that number", test_watcher);
  NEW_LINE;

  it("Should remove from the 0th position of the list: ");
  assert_int(remove_at(list, 0), Success, "should remove the first number", test_watcher);
  assert_int(list->count, 3, "count should be decreased by one", test_watcher);
  assert_ok(!is_number_present_at(list, 0, 1), "last position should not contain that number", test_watcher);
  NEW_LINE;

  it("Should remove from the given position of the list: ");
  assert_int(remove_at(list, 1), Success, "should remove the number at given position", test_watcher);
  assert_int(list->count, 2, "count should be decreased by one", test_watcher);
  assert_ok(!is_number_present_at(list, 1, 3), "given position should not contain that number", test_watcher);
  NEW_LINE;

  it("Should not remove if given position is invalid : ");
  assert_int(remove_at(list, 10), Failure, "should not remove", test_watcher);
  assert_int(list->count, 2, "count should be remain same", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_remove_first_occurrence(Test_report_ptr test_watcher)
{
  describe("# REMOVE_FIRST_OCCURRENCE");
  List_ptr list = create_list();

  int previous_length = list->count;
  it("Should not remove if the list is empty : ");
  assert_int(remove_first_occurrence(list, 1), Failure, "should not remove", test_watcher);
  assert_int(list->count, 0, "count should be 0", test_watcher);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 2);
  it("Should remove the first occurrence of the given number from list : ");
  assert_int(remove_first_occurrence(list, 2), Success, "should remove the first occurrence", test_watcher);
  assert_int(list->count, 3, "count should be decrease by 1", test_watcher);
  assert_ok(!is_number_present_at(list, 1, 2), "number shouldn't be present at its position", test_watcher);
  NEW_LINE;

  it("Should not remove if the list doesn't contain the given number : ");
  assert_int(remove_first_occurrence(list, 5), Failure, "should not remove", test_watcher);
  assert_int(list->count, 3, "count should remain same", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_remove_all_occurrences(Test_report_ptr test_watcher)
{
  describe("# REMOVE_ALL_OCCURRENCES");
  List_ptr list = create_list();

  it("Should not remove if the list is empty : ");
  assert_int(remove_all_occurrences(list, 1), Failure, "should not remove", test_watcher);
  assert_int(list->count, 0, "count should be 0", test_watcher);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 2);
  it("Should remove all occurrences of the given number from list : ");
  assert_int(remove_all_occurrences(list, 2), Success, "should remove all the occurrences ", test_watcher);
  assert_int(list->count, 2, "count should be decrease according to the number of occurrence", test_watcher);
  assert_ok(!is_present(list, 2), "list should not contain that number", test_watcher);
  NEW_LINE;

  it("Should not remove if the list doesn't contain the given number : ");
  assert_int(remove_all_occurrences(list, 5), Failure, "should not remove", test_watcher);
  assert_int(list->count, 2, "count should be remain same", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_clear_list(Test_report_ptr test_watcher)
{
  describe("# CLEAR_LIST");
  List_ptr list = create_list();

  it("Should clear the empty list : ");
  assert_int(clear_list(list), Success, "should clear the list", test_watcher);
  assert_int(list->count, 0, "count should remain 0", test_watcher);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  it("Should remove all the elements present in the list : ");
  assert_int(clear_list(list), Success, "should clear the list", test_watcher);
  assert_int(list->count, 0, "count should be reduced to 0", test_watcher);
  NEW_LINE;

  destroy_list(list);
}

void test_is_present(Test_report_ptr test_watcher)
{
  describe("# IS_PRESENT");
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  it("Should not validate if the given number isn't in the list : ");
  assert_int(is_present(list, 5), Failure, "should return false", test_watcher);
  assert_int(list->count, 2, "count should remain same", test_watcher);
  NEW_LINE;

  it("Should validate if the given number is present in the list : ");
  assert_int(is_present(list, 1), Success, "should return true", test_watcher);
  assert_int(list->count, 2, "count should remain same", test_watcher);
  NEW_LINE;

  destroy_list(list);
}
