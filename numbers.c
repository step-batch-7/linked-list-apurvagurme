#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void clear_buffer(void)
{
  while ((getchar()) != '\n'); 
}

int main(void)
{
  int number, position, success, present;
  char option;
  List *list = create_list();

  printf("Please enter an option from a to m to perform operation\n");
  scanf("%c", &option);

  while (option != 'm')
  {
    switch (option)
    {
      case 'a': printf("Please enter a number to add to end of the list\n");
                scanf("%d", &number);
                clear_buffer();
                add_to_end(list, number);
                break;

      case 'b': printf("Please enter a number to add to start of the list\n");
                scanf("%d", &number);
                clear_buffer();
                add_to_start(list, number);
                break;

      case 'c': printf("Please enter a number and position where to add it in the list\n");
                scanf("%d %d", &number, &position);
                clear_buffer();
                success = insert_at(list, number, position);
                if (!success)
                {
                  printf("Inserting a number in the list at given position is not possible\n");
                }
                break;

      case 'd': printf("Please enter a number to add it in the list if not present\n");
                scanf("%d", &number);
                clear_buffer();
                add_unique(list, number);
                break;

      case 'e': success = remove_from_start(list);
                if (!success)
                {
                  printf("Removing a number from the beginning of the list is not possible\n");
                }
                break;
      
      case 'f': success = remove_from_end(list);
                if (!success)
                {
                  printf("Removing a number from the end of the list is not possible\n");
                }
                break;

      case 'g': printf("Please enter a position to remove a number of that position from list\n");
                scanf("%d", &position);
                clear_buffer();
                success = remove_at(list, position);
                if (!success)
                {
                  printf("Removing a number from the given position of the list is not possible\n");
                }
                break;

      case 'h': printf("Please enter a number to remove it's first occurrence from the list\n");
                scanf("%d", &number);
                clear_buffer();
                success = remove_first_occurrence(list, number);
                if (!success)
                {
                  printf("Removing a number from the given position of the list is not possible\n");
                }
                break;

      case 'i': printf("Please enter a number to remove all occurrences from the list\n");
                scanf("%d", &number);
                clear_buffer();
                remove_all_occurrences(list, number);
                break;

      case 'j': printf("Cleared whole list\n");
                clear_list(list);
                break;

      case 'k': printf("Enter a number which you want to check whether it's present in list or not\n");
                scanf("%d", &number);
                clear_buffer();
                present = is_present(list, number);
                if (!present)
                {
                  printf("Number is not present\n");
                }else
                {
                  printf("Number is not present\n");
                }
                break;
      
      case 'l': clear_buffer();
                display(list);
                break;

      default:
                break;
    }
    printf("\nPlease enter an option from a to m to perform operation\n");
    scanf("%c", &option);
  }

  return 0;
}