#include<stdio.h>
#include<stdlib.h>
#include"list.h"

Node *create_node(value)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void)
{
  List *list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node *new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  } 
  else 
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node *new_node = create_node(value);
  if (list->head == NULL)
  {
    list->last = new_node;
  }
  else
  {
    new_node->next = list->head;
  }
  list->head = new_node;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  Node *new_node = create_node(value);
  Node *p_walk = list->head;
  int count = 0;
  if (position == 0)
  {
    new_node->next = list->head;
    list->head = new_node;
    return Success;
  }
  while (p_walk != NULL)
  {
    if (position - 1 == count)
    {
      new_node->next = p_walk->next;
      p_walk->next = new_node;
      break;
    }
    p_walk = p_walk->next;
    count++;
  }
  return Success;
}

void display(List_ptr list)
{
  Node *p_walk = list->head;
  printf("List is:\n");
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}