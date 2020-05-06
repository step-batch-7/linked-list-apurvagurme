#include<stdio.h>
#include<stdlib.h>
#include"../list.h"

Status assert(List_ptr list, char msg[], int result, int count, int expected_list_values[])
{
  Status status = Success;
  int counter = 0;
  if (result == Success && list->count == count)
  {
    Node_ptr p_walk = list->head;
    while (p_walk != NULL)
    {
      if (p_walk->value != expected_list_values[counter])
      {
        status = Failure;
        break;
      }
      counter++;
      p_walk = p_walk->next;
    }
  }
  return status;
}

void print_result(Status status, char msg[])
{
  char *sign = status == Success ? "✅ " : "❎ ";
  printf("%s %s", sign, msg);
}

void add_to_end_in_empty_list(List_ptr list)
{
  int result = add_to_end(list, 1);
  char msg[] = "Should add add to the end of empty list\n";
  int expected_values[1] = {1};
  Status status = assert(list, msg, result, 1, expected_values);
  print_result(status, msg);
}

void add_to_end_in_list_of_1_number(List_ptr list)
{
  int result = add_to_end(list, 2);
  char msg[] = "Should add to the end of list having one number\n";
  int expected_values[2] = {1, 2};
  Status status = assert(list, msg, result, 2, expected_values);
  print_result(status, msg);
}

void add_to_end_in_list_of_having_more_than_one_numbers(List_ptr list)
{
  int result = add_to_end(list, 3);
  char msg[] = "Should add add to the end of list having more than one number\n";
  int expected_values[3] = {1, 2, 3};
  Status status = assert(list, msg, result, 3, expected_values);
  print_result(status, msg);
}

void test_add_to_end(void)
{
  List_ptr list = create_list();
  add_to_end_in_empty_list(list);
  add_to_end_in_list_of_1_number(list);
  add_to_end_in_list_of_having_more_than_one_numbers(list);
}

void add_to_start_in_empty_list(List_ptr list)
{
  int result = add_to_start(list, 1);
  char msg[] = "Should add add to the start of empty list\n";
  int expected_values[1] = {1};
  Status status = assert(list, msg, result, 1, expected_values);
  print_result(status, msg);
}

void add_to_start_in_list_of_1_number(List_ptr list)
{
  int result = add_to_start(list, 2);
  char msg[] = "Should add to the start of list having one number\n";
  int expected_values[2] = {2, 1};
  Status status = assert(list, msg, result, 2, expected_values);
  print_result(status, msg);
}

void add_to_start_in_list_of_having_more_than_one_numbers(List_ptr list)
{
  int result = add_to_start(list, 3);
  char msg[] = "Should add add to the start of list having more than one number\n";
  int expected_values[3] = {3, 2, 1};
  Status status = assert(list, msg, result, 3, expected_values);
  print_result(status, msg);
}

void test_add_to_start(void)
{
  List_ptr list = create_list();
  add_to_start_in_empty_list(list);
  add_to_start_in_list_of_1_number(list);
  add_to_start_in_list_of_having_more_than_one_numbers(list);
}

void insert_at_the_0th_position_of_empty_list(List_ptr list)
{
  int result = insert_at(list, 0, 0);
  char msg[] = "Should insert at the 0th position of an empty list\n";
  int expected_values[1] = {0};
  Status status = assert(list, msg, result, 1, expected_values);
  print_result(status, msg);
}

void insert_at_the_0th_position_of_list_having_one_element(List_ptr list)
{
  int result = insert_at(list, 1, 0);
  char msg[] = "Should insert at the 0th position of list having one element\n";
  int expected_values[2] = {1, 0};
  Status status = assert(list, msg, result, 2, expected_values);
  print_result(status, msg);
}

void insert_at_the_1st_position_or_middle_of_list_having_two_element(List_ptr list)
{
  int result = insert_at(list, 2, 1);
  char msg[] = "Should insert at the 1st position of list having two element\n";
  int expected_values[3] = {1, 2, 0};
  Status status = assert(list, msg, result, 3, expected_values);
  print_result(status, msg);
}

void insert_at_the_last_position_of_list(List_ptr list)
{
  int result = insert_at(list, 4, list->count);
  char msg[] = "Should insert at the last position of list\n";
  int expected_values[4] = {1, 2, 0, 4};
  Status status = assert(list, msg, result, 4, expected_values);
  print_result(status, msg);
}

void test_insert_at(void)
{
  List_ptr list = create_list();
  insert_at_the_0th_position_of_empty_list(list);
  insert_at_the_0th_position_of_list_having_one_element(list);
  insert_at_the_1st_position_or_middle_of_list_having_two_element(list);
  insert_at_the_last_position_of_list(list);
}

void add_unique_if_list_is_empty(List_ptr list)
{
  int result = add_unique(list, 0);
  char msg[] = "Should add at end of an empty list\n";
  int expected_values[1] = {0};
  Status status = assert(list, msg, result, 1, expected_values);
  print_result(status, msg);
}

void test_add_unique(void)
{
  List_ptr list = create_list();
  add_unique_if_list_is_empty(list);
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  return 0;
}