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

int main(void)
{
  test_add_to_end();
  return 0;
}