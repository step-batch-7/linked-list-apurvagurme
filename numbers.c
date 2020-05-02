#include<stdio.h>
#include<stdlib.h>
#include"list.h"

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
                add_to_end(list, number);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'b': printf("Please enter a number to add to start of the list\n");
                scanf("%d", &number);
                add_to_start(list, number);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'c': printf("Please enter a number and position where to add it in the list\n");
                scanf("%d %d", &number, &position);
                insert_at(list, number, position);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'd': printf("Please enter a number to add it in the list if not present\n");
                scanf("%d", &number);
                add_unique(list, number);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'e': success = remove_from_start(list);
                if (!success)
                {
                  printf("Removing a number from the beginning of the list is not possible\n");
                }
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;
      
      case 'f': success = remove_from_end(list);
                if (!success)
                {
                  printf("Removing a number from the end of the list is not possible\n");
                }
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'g': printf("Please enter a position to remove a number of that position from list\n");
                scanf("%d", &position);
                success = remove_at(list, position);
                if (!success)
                {
                  printf("Removing a number from the given position of the list is not possible\n");
                }
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'h': printf("Please enter a number to remove it's first occurrence from the list\n");
                scanf("%d", &number);
                success = remove_first_occurrence(list, number);
                if (!success)
                {
                  printf("Removing a number from the given position of the list is not possible\n");
                }
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'i': printf("Please enter a number to remove all occurrences from the list\n");
                scanf("%d", &number);
                remove_all_occurrences(list, number);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'j': printf("Cleared whole list\n");
                clear_list(list);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      case 'k': printf("Enter a number which you want to check whether it's present in list or not\n");
                scanf("%d", &number);
                present = is_present(list, number);
                if (!present)
                {
                  printf("Number is not present\n");
                }else
                {
                  printf("Number is not present\n");
                }
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;
      
      case 'l': display(list);
                printf("\nPlease enter an option from a to m to perform operation\n");
                break;

      default:
                break;
    }
    
    scanf("%c", &option);
  }

  return 0;
}