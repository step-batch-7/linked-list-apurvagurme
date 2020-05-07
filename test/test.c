#include<stdio.h>
#include<stdlib.h>
#include"../list.h"

Status assert(List_ptr list, char msg[], int actual_status, int count, int expected_list_values[], Status expected_status)
{
  Status status = Failure;
  int counter = 0;
  if (actual_status == expected_status && list->count == count)
  {
    status = Success;
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
  char *sign = status == Success ? "✅ " : "❌ ";
  printf("%s %s", sign, msg);
}

void add_to_end_in_empty_list(List_ptr list)
{
  int result = add_to_end(list, 1);
  char msg[] = "Should add add to the end of empty list\n";
  int expected_values[1] = {1};
  Status status = assert(list, msg, result, 1, expected_values, Success);
  print_result(status, msg);
}

void add_to_end_in_list_of_1_number(List_ptr list)
{
  int result = add_to_end(list, 2);
  char msg[] = "Should add to the end of list having one number\n";
  int expected_values[2] = {1, 2};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void add_to_end_in_list_of_having_more_than_one_numbers(List_ptr list)
{
  int result = add_to_end(list, 3);
  char msg[] = "Should add add to the end of list having more than one number\n";
  int expected_values[3] = {1, 2, 3};
  Status status = assert(list, msg, result, 3, expected_values, Success);
  print_result(status, msg);
}

void test_add_to_end(void)
{
  List_ptr list = create_list();
  printf("\n#add_to_end\n");
  add_to_end_in_empty_list(list);
  add_to_end_in_list_of_1_number(list);
  add_to_end_in_list_of_having_more_than_one_numbers(list);
}

void add_to_start_in_empty_list(List_ptr list)
{
  int result = add_to_start(list, 1);
  char msg[] = "Should add add to the start of empty list\n";
  int expected_values[1] = {1};
  Status status = assert(list, msg, result, 1, expected_values, Success);
  print_result(status, msg);
}

void add_to_start_in_list_of_1_number(List_ptr list)
{
  int result = add_to_start(list, 2);
  char msg[] = "Should add to the start of list having one number\n";
  int expected_values[2] = {2, 1};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void add_to_start_in_list_of_having_more_than_one_numbers(List_ptr list)
{
  int result = add_to_start(list, 3);
  char msg[] = "Should add add to the start of list having more than one number\n";
  int expected_values[3] = {3, 2, 1};
  Status status = assert(list, msg, result, 3, expected_values, Success);
  print_result(status, msg);
}

void test_add_to_start(void)
{
  List_ptr list = create_list();
  printf("\n#add_to_start\n");
  add_to_start_in_empty_list(list);
  add_to_start_in_list_of_1_number(list);
  add_to_start_in_list_of_having_more_than_one_numbers(list);
}

void insert_at_the_0th_position_of_empty_list(List_ptr list)
{
  int result = insert_at(list, 0, 0);
  char msg[] = "Should insert at the 0th position of an empty list\n";
  int expected_values[1] = {0};
  Status status = assert(list, msg, result, 1, expected_values, Success);
  print_result(status, msg);
}

void insert_at_the_0th_position_of_list_having_one_element(List_ptr list)
{
  int result = insert_at(list, 1, 0);
  char msg[] = "Should insert at the 0th position of list having one element\n";
  int expected_values[2] = {1, 0};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void insert_at_the_1st_position_or_middle_of_list_having_two_element(List_ptr list)
{
  int result = insert_at(list, 2, 1);
  char msg[] = "Should insert at the 1st position of list having two element\n";
  int expected_values[3] = {1, 2, 0};
  Status status = assert(list, msg, result, 3, expected_values, Success);
  print_result(status, msg);
}

void insert_at_the_last_position_of_list(List_ptr list)
{
  int result = insert_at(list, 4, list->count);
  char msg[] = "Should insert at the last position of list\n";
  int expected_values[4] = {1, 2, 0, 4};
  Status status = assert(list, msg, result, 4, expected_values, Success);
  print_result(status, msg);
}

void insert_at_the_invalid_position(List_ptr list)
{
  int result = insert_at(list, 4, 10);
  char msg[] = "Should not insert if the position is invalid\n";
  int expected_values[4] = {1, 2, 0, 4};
  Status status = assert(list, msg, result, 4, expected_values, Failure);
  print_result(status, msg);
}

void test_insert_at(void)
{
  List_ptr list = create_list();
  printf("\n#insert_at\n");
  insert_at_the_0th_position_of_empty_list(list);
  insert_at_the_0th_position_of_list_having_one_element(list);
  insert_at_the_1st_position_or_middle_of_list_having_two_element(list);
  insert_at_the_last_position_of_list(list);
  insert_at_the_invalid_position(list);
}

void add_unique_if_list_is_empty(List_ptr list)
{
  int result = add_unique(list, 0);
  char msg[] = "Should add at end of an empty list\n";
  int expected_values[1] = {0};
  Status status = assert(list, msg, result, 1, expected_values, Success);
  print_result(status, msg);
}

void add_unique_if_list_is_not_empty(List_ptr list)
{
  int result = add_unique(list, 1);
  char msg[] = "Should add unique number at end of list\n";
  int expected_values[2] = {0, 1};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void add_unique_if_number_is_not_unique(List_ptr list)
{
  int result = add_unique(list, 1);
  char msg[] = "Should not add if number is not unique\n";
  int expected_values[2] = {0, 1};
  Status status = assert(list, msg, result, 2, expected_values, Failure);
  print_result(status, msg);
}

void test_add_unique(void)
{
  List_ptr list = create_list();
  printf("\n#add_unique\n");
  add_unique_if_list_is_empty(list);
  add_unique_if_list_is_not_empty(list);
  add_unique_if_number_is_not_unique(list);
}

void remove_from_start_if_list_is_empty(List_ptr list)
{
  int result = remove_from_start(list);
  char msg[] = "Should not remove from start if the list is empty\n";
  int expected_values[0] = {};
  Status status = assert(list, msg, result, 0, expected_values, Failure);
  print_result(status, msg);
}

void remove_from_start_if_list_is_not_empty(List_ptr list)
{
  add_to_start(list, 1);
  int result = remove_from_start(list);
  char msg[] = "Should remove from start if the list has one element\n";
  int expected_values[0] = {};
  Status status = assert(list, msg, result, 0, expected_values, Success);
  print_result(status, msg);
}

void remove_from_start_if_list_has_more_than_one_elements(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);
  int result = remove_from_start(list);
  char msg[] = "Should remove from start if the list has more than one elements\n";
  int expected_values[1] = {2};
  Status status = assert(list, msg, result, 1, expected_values, Success);
  print_result(status, msg);
}

void test_remove_from_start(void)
{
  List_ptr list = create_list();
  printf("\n#remove_from_start\n");
  remove_from_start_if_list_is_empty(list);
  remove_from_start_if_list_is_not_empty(list);
  remove_from_start_if_list_has_more_than_one_elements(list);
}

void remove_from_end_if_list_is_empty(List_ptr list)
{
  int result = remove_from_end(list);
  char msg[] = "Should not remove from end if the list is empty\n";
  int expected_values[0] = {};
  Status status = assert(list, msg, result, 0, expected_values, Failure);
  print_result(status, msg);
}

void remove_from_end_if_list_is_not_empty(List_ptr list)
{
  add_to_start(list, 1);
  int result = remove_from_end(list);
  char msg[] = "Should remove from end if the list has one element\n";
  int expected_values[0] = {};
  Status status = assert(list, msg, result, 0, expected_values, Success);
  print_result(status, msg);
}

void remove_from_end_if_list_has_more_than_one_elements(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);
  int result = remove_from_end(list);
  char msg[] = "Should remove from end if the list has more than one elements\n";
  int expected_values[1] = {1};
  Status status = assert(list, msg, result, 1, expected_values, Success);
  print_result(status, msg);
}

void test_remove_from_end(void)
{
  List_ptr list = create_list();
  printf("\n#remove_from_end\n");
  remove_from_end_if_list_is_empty(list);
  remove_from_end_if_list_is_not_empty(list);
  remove_from_end_if_list_has_more_than_one_elements(list);
}

void remove_at_from_end_if_list_is_empty(List_ptr list)
{
  int result = remove_at(list, 1);
  char msg[] = "Should not remove from end if the list is empty\n";
  int expected_values[0] = {};
  Status status = assert(list, msg, result, 0, expected_values, Failure);
  print_result(status, msg);
}

void remove_at_from_start_if_list_is_empty(List_ptr list)
{
  int result = remove_at(list, 0);
  char msg[] = "Should not remove from end if the list is empty\n";
  int expected_values[0] = {};
  Status status = assert(list, msg, result, 0, expected_values, Failure);
  print_result(status, msg);
}

void remove_at_from_start_if_list_is_not_empty(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  int result = remove_at(list, 0);
  char msg[] = "Should remove from start of the list\n";
  int expected_values[2] = {2, 3};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void remove_at_from_end_if_list_is_not_empty(List_ptr list)
{
  add_to_start(list, 1);
  int result = remove_at(list, 2);
  char msg[] = "Should remove from end of the list\n";
  int expected_values[2] = {1, 2};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void remove_from_middle(List_ptr list)
{
  add_to_end(list, 3);
  int result = remove_at(list, 1);
  char msg[] = "Should remove from middle of the list\n";
  int expected_values[2] = {1, 3};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void test_remove_at(void)
{
  List_ptr list = create_list();
  printf("\n#remove_at\n");
  remove_at_from_end_if_list_is_empty(list);
  remove_at_from_start_if_list_is_empty(list);
  remove_at_from_start_if_list_is_not_empty(list);
  remove_at_from_end_if_list_is_not_empty(list);
  remove_from_middle(list);
}

void remove_first_occurrence_in_empty_list(List_ptr list)
{
  int result = remove_first_occurrence(list, 1);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {};
  Status status = assert(list, msg, result, 0, expected_values, Failure);
  print_result(status, msg);
}

void remove_first_occurrence_one_element_list(List_ptr list)
{
  add_to_end(list, 0);
  int result = remove_first_occurrence(list, 0);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {};
  Status status = assert(list, msg, result, 0, expected_values, Success);
  print_result(status, msg);
}

void remove_first_occurrence_from_end_more_than_one_element_list(List_ptr list)
{
  add_to_end(list, 0);
  add_to_end(list, 1);
  add_to_end(list, 2);
  int result = remove_first_occurrence(list, 2);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {0, 1};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void remove_first_occurrence_from_start_more_than_one_element_list(List_ptr list)
{
  add_to_end(list, 2);
  int result = remove_first_occurrence(list, 0);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {1, 2};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void remove_first_occurrence_from_medium_more_than_one_element_list(List_ptr list)
{
  add_to_start(list, 0);
  int result = remove_first_occurrence(list, 1);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {0, 2};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void remove_first_occurrence_when_more_occurrences_in_list(List_ptr list)
{
  add_to_start(list, 2);
  int result = remove_first_occurrence(list, 2);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {0, 2};
  Status status = assert(list, msg, result, 2, expected_values, Success);
  print_result(status, msg);
}

void remove_first_occurrence_if_no_occurrences_in_list(List_ptr list)
{
  int result = remove_first_occurrence(list, 1);
  char msg[] = "Should not remove from an empty list\n";
  int expected_values[] = {0, 2};
  Status status = assert(list, msg, result, 2, expected_values, Failure);
  print_result(status, msg);
}

void test_remove_first_occurrence(void)
{
  List_ptr list = create_list();
  printf("\n#remove_first_occurrence\n");
  remove_first_occurrence_in_empty_list(list);
  remove_first_occurrence_one_element_list(list);
  remove_first_occurrence_from_end_more_than_one_element_list(list);
  remove_first_occurrence_from_start_more_than_one_element_list(list);
  remove_first_occurrence_from_medium_more_than_one_element_list(list);
  remove_first_occurrence_when_more_occurrences_in_list(list);
  remove_first_occurrence_if_no_occurrences_in_list(list);
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  return 0;
}