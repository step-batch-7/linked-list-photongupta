#include "test.h"
#include <stdio.h>

void test_create_node()
{
  NEW_LINE;
  describe("# create_node");
  Node_ptr node = create_node(1);

  it("Should create a node with given value: ");
  assert_int(node->value, 1);
  assert_is_null(node->next);
  NEW_LINE;
}

void test_create_list()
{
  NEW_LINE;
  describe("# create_node");
  List_ptr list = create_list();

  it("Should create list with count 0: ");
  assert_int(list->count, 0);
  assert_is_null(list->head);
  assert_is_null(list->last);
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_add_to_start()
{
  describe("# add_to_start");
  List_ptr list = create_list();

  it("Should add the number at the start if the list is empty : ");
  assert_int(add_to_start(list, 1), Success);
  assert_int(list->count, 1);
  assert_ok(is_number_present_at(list, 0, 1));
  NEW_LINE;

  it("Should add the number at the start of the list : ");
  assert_int(add_to_start(list, 2), Success);
  assert_int(list->count, 2);
  assert_ok(is_number_present_at(list, 0, 2));
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_add_to_end()
{
  describe("# add_to_end");
  List_ptr list = create_list();

  it("Should add the number at the end if the list is empty : ");
  assert_int(add_to_end(list, 1), Success);
  assert_int(list->count, 1);
  assert_ok(is_number_present_at(list, 0, 1));
  NEW_LINE;

  it("Should add the number at the end of the list : ");
  assert_int(add_to_end(list, 2), Success);
  assert_int(list->count, 2);
  assert_ok(is_number_present_at(list, 1, 2));
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_insert_at()
{
  describe("# insert_at");
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  it("Should insert at 0th position in the list : ");
  assert_int(insert_at(list, 3, 0), Success);
  assert_int(list->count, 3);
  assert_ok(is_number_present_at(list, 0, 3));
  NEW_LINE;

  it("Should insert at last position in the list : ");
  assert_int(insert_at(list, 4, 3), Success);
  assert_int(list->count, 4);
  assert_ok(is_number_present_at(list, 3, 4));
  NEW_LINE;

  it("Should insert at given position in the list : ");
  assert_int(insert_at(list, 5, 2), Success);
  assert_int(list->count, 5);
  assert_ok(is_number_present_at(list, 2, 5));
  NEW_LINE;

  it("Should not insert if the given position is invalid : ");
  assert_int(insert_at(list, 6, 10), Failure);
  assert_int(list->count, 5);
  assert_ok(!is_number_present_at(list, 10, 6));
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_add_unique()
{
  describe("# add_unique");
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  it("Should not add if number is in the list : ");
  assert_int(add_unique(list, 1), Failure);
  assert_int(list->count, 2);
  assert_ok(!is_number_present_at(list, 2, 1));
  NEW_LINE;

  it("Should add if number is not present in the list : ");
  assert_int(add_unique(list, 3), Success);
  assert_int(list->count, 3);
  assert_ok(is_number_present_at(list, 2, 3));
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_remove_from_start()
{
  describe("# remove_from_start");
  List_ptr list = create_list();

  it("Should not remove if the list is empty : ");
  assert_int(remove_from_start(list), Failure);
  assert_int(list->count, 0);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  it("Should remove the number from start of the list : ");
  assert_int(remove_from_start(list), Success);
  assert_int(list->count, 1);
  assert_ok(is_number_present_at(list, 0, 2));
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_remove_from_end()
{
  describe("# remove_from_end");
  List_ptr list = create_list();

  it("Should not remove if the list is empty : ");
  assert_int(remove_from_end(list), Failure);
  assert_int(list->count, 0);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  it("Should remove the number from end of the list : ");
  assert_int(remove_from_end(list), Success);
  assert_int(list->count, 1);
  assert_ok(!is_number_present_at(list, 1, 2));
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_remove_at()
{
  describe("# remove_at");
  List_ptr list = create_list();

  it("Should not remove if the list is empty: ");
  assert_int(remove_at(list, 1), Failure);
  assert_int(list->count, 0);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);
  it("Should remove from the last position of the list: ");
  assert_int(remove_at(list, 4), Success);
  assert_int(list->count, 4);
  assert_ok(!is_number_present_at(list, 4, 5));
  NEW_LINE;

  it("Should remove from the 0th position of the list: ");
  assert_int(remove_at(list, 0), Success);
  assert_int(list->count, 3);
  assert_ok(!is_number_present_at(list, 0, 1));
  NEW_LINE;

  it("Should remove from the given position of the list: ");
  assert_int(remove_at(list, 1), Success);
  assert_int(list->count, 2);
  assert_ok(!is_number_present_at(list, 1, 3));
  NEW_LINE;

  it("Should not remove if given position is invalid : ");
  assert_int(remove_at(list, 10), Failure);
  assert_int(list->count, 2);
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_remove_first_occurrence()
{
  describe("# remove_first_occurrence");
  List_ptr list = create_list();

  int previous_length = list->count;
  it("Should not remove if the list is empty : ");
  assert_int(remove_first_occurrence(list, 1), Failure);
  assert_int(list->count, 0);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 2);
  it("Should remove the first occurrence of the given number from list : ");
  assert_int(remove_first_occurrence(list, 2), Success);
  assert_int(list->count, 3);
  assert_ok(!is_number_present_at(list, 1, 2));
  NEW_LINE;

  it("Should not remove if the list doesn't contain the given number : ");
  assert_int(remove_first_occurrence(list, 5), Failure);
  assert_int(list->count, 3);
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_remove_all_occurrences()
{
  describe("# remove_all_occurrences");
  List_ptr list = create_list();

  it("Should not remove if the list is empty : ");
  assert_int(remove_all_occurrences(list, 1), Failure);
  assert_int(list->count, 0);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 2);
  it("Should remove all occurrences of the given number from list : ");
  assert_int(remove_all_occurrences(list, 2), Success);
  assert_int(list->count, 2);
  NEW_LINE;

  it("Should not remove if the list doesn't contain the given number : ");
  assert_int(remove_all_occurrences(list, 5), Failure);
  assert_int(list->count, 2);
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_clear_list()
{
  describe("# clear_list");
  List_ptr list = create_list();

  it("Should clear the empty list : ");
  assert_int(clear_list(list), Success);
  assert_int(list->count, 0);
  NEW_LINE;

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  it("Should remove all the elements present in the list : ");
  assert_int(clear_list(list), Success);
  assert_int(list->count, 0);
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}

void test_is_present()
{
  describe("# is_present");
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);

  it("Should not validate if the given number isn't in the list : ");
  assert_int(is_present(list, 5), Failure);
  assert_int(list->count, 2);
  NEW_LINE;

  it("Should validate if the given number is present in the list : ");
  assert_int(is_present(list, 1), Success);
  assert_int(list->count, 2);
  NEW_LINE;

  destroy_list(list);
  NEW_LINE;
}
