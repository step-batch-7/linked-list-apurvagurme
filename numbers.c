#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(void)
{
  int number, number2, number3, number4, number5, number6, position;
  char operation_alphabet;
  List *list = create_list();

  printf("Please enter an operation alphabet from a to m to perform operation\n");
  scanf("%c", &operation_alphabet);

  while (operation_alphabet != 'm')
  {
    switch (operation_alphabet)
    {
      case 'a': printf("Please enter a number to add to end of the list\n");
                scanf("%d", &number);
                add_to_end(list, number);
                break;

      case 'b': printf("Please enter a number to add to start of the list\n");
                scanf("%d", &number);
                add_to_start(list, number);
                break;

      case 'c': printf("Please enter a number and position where to add it in the list\n");
                scanf("%d %d", &number, &position);
                insert_at(list, number, position);
                break;

      case 'd': printf("Please enter a number to add it in the list if not present\n");
                scanf("%d", &number);
                add_unique(list, number);
                break;

      case 'e': printf("Removing a number from the beginning of the list\n");
                remove_from_start(list);
                break;
      
      case 'f': printf("Removing a number from the end of the list\n");
                remove_from_end(list);
                break;

      case 'g': printf("Please enter a position to remove a number of that position from list\n");
                scanf("%d", &position);
                remove_at(list, position);
                break;

      case 'h': printf("Please enter a number to remove it's first occurrence from the list\n");
                scanf("%d", &number);
                remove_first_occurrence(list, number);
                break;

      case 'i': printf("Please enter a number to remove all occurrences from the list\n");
                scanf("%d", &number);
                remove_all_occurrences(list, number);
                break;

      case 'j': printf("Clearing whole list\n");
                clear_list(list);
                break;

      case 'k': printf("Enter a number which you want to check whether it's present in list or not\n");
                scanf("%d", &number);
                is_present(list, number);
                break;
      
      case 'l': display(list);
                break;

      default:
                break;
    }
    
    printf("Please enter an operation alphabet from a to m to perform operation\n");
    scanf("%c", &operation_alphabet);
  }

  return 0;
}