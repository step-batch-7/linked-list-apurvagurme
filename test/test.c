#include<stdio.h>
#include<stdlib.h>
#include"../list.h"

void add_to_end_in_empty_list(List_ptr list)
{
  int result = add_to_end(list, 1);
  char msg[] = "Should add add to the end of empty list\n";
  char *sign = "❎ ";
  
  if (result == Success && list->count == 1 && list->head->value == 1 && list->last->value == 1)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
}

void add_to_end_in_list_of_1_number(List_ptr list)
{
  int result = add_to_end(list, 2);
  char msg[] = "Should add to the end of list having one number\n";
  char *sign = "❎ ";

  if (result == Success && list->count == 2 && list->head->value == 1 && list->last->value == 2)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
}

void add_to_end_in_list_of_having_more_than_one_numbers(List_ptr list)
{
  int result = add_to_end(list, 3);
  char msg[] = "Should add add to the end of list having more than one number\n";
  char *sign = "❎ ";
  
  if (result == Success && list->count == 3 && list->head->value == 1 && list->last->value == 3)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
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
  char *sign = "❎ ";
  
  if (result == Success && list->count == 1 && list->head->value == 1 && list->last->value == 1)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
}

void add_to_start_in_list_of_1_number(List_ptr list)
{
  int result = add_to_start(list, 2);
  char msg[] = "Should add to the start of list having one number\n";
  char *sign = "❎ ";

  if (result == Success && list->count == 2 && list->head->value == 2 && list->last->value == 1)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
}

void add_to_start_in_list_of_having_more_than_one_numbers(List_ptr list)
{
  int result = add_to_start(list, 3);
  char msg[] = "Should add add to the start of list having more than one number\n";
  char *sign = "❎ ";
  
  if (result == Success && list->count == 3 && list->head->value == 3 && list->last->value == 1)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
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
  char *sign = "❎ ";
  
  if (result == Success && list->count == 1 && list->head->value == 0 && list->last->value == 0)
  {
    sign = "✅ ";
  }
  printf("%s %s", sign, msg);
}

void test_insert_at(void)
{
  List_ptr list = create_list();
  insert_at_the_0th_position_of_empty_list(list);
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  return 0;
}