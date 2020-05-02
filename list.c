#include<stdio.h>
#include<stdlib.h>
#include"list.h"

Node_ptr create_node(value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  } 
  else 
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->last = new_node;
  }
  else
  {
    new_node->next = list->head;
  }
  list->head = new_node;
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  Node_ptr new_node = create_node(value);
  if (position == 0)
  {
    new_node->next = list->head;
    list->head = new_node;
    list->last = new_node;
    list->count++;
    return Success;
  }

  Node_ptr p_walk = list->head;
  int count = 0;
  
  while (p_walk != NULL)
  {
    if (position - 1 == count)
    {
      new_node->next = p_walk->next;
      p_walk->next = new_node;
      list->count++;
      break;
    }
    p_walk = p_walk->next;
    count++;
  }
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  Node_ptr p_walk = list->head;
  if (list->head == NULL)
  {
    list->head = new_node;
    list->last = new_node;
    list->count++;
  }
  while (p_walk != NULL && p_walk->value != value)
  {
    if (p_walk->next == NULL)
    {
      p_walk->next = new_node;
      list->count++;
    }
    p_walk = p_walk->next;
  }
  return Success;
}

Status remove_from_start(List_ptr list)
{
  if (list->head != NULL)
  {
    Node_ptr new_node = list->head;
    list->head = new_node->next;
    free(new_node);
    list->count--;
  }
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node_ptr p_walk = list->head;
  if (list->count == 1)
  {
    list->head = NULL;
    list->last = NULL;
    list->count--;
  }
  
  while (p_walk->next != NULL)
  {
    if (p_walk->next->next == NULL)
    {
      list->last = p_walk;
      free(p_walk->next);
      p_walk->next = NULL;
      list->count--;
      break;
    }
    p_walk = p_walk->next;
  }
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (position > list->count - 1 || position < 0)
  {
    return Failure;
  }
  
  if (position == 0)
  {
    Node_ptr previous = list->head;
    list->head = list->head->next;
    free(previous);
    list->count--;
    return Success;
  }

  Node_ptr p_walk = list->head;
  int count = 0;

  while (p_walk->next != NULL)
  {
    if (count - 1 == position)
    {
      Node_ptr next = p_walk->next->next;
      free(p_walk);
      p_walk->next = next;
      list->count--;
      break;
    }
    count++;
  }
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;

  if (list->head->value == value)
  {
    Node_ptr previous = list->head;
    list->head = list->head->next;
    free(previous);
    list->count--;
    return Success;
  }
  
  while (p_walk != NULL)
  {
    if (p_walk->next->value == value)
    {
      Node_ptr next = p_walk->next->next;
      free(p_walk->next);
      p_walk->next = next;
      list->count--;
      break;
    }
    p_walk = p_walk->next;
  }
  return Success;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;

  if (list->count == 1 && list->head->value == value)
  {
    Node_ptr previous = list->head;
    list->head = list->head->next;
    free(previous);
    list->count--;
    return Success;
  }
  
  while (p_walk->value == value)
  {
    Node_ptr previous = list->head;
    list->head = list->head->next;
    free(previous);
    p_walk = list->head;
  }
  
  while (p_walk->next != NULL )
  {
    if (p_walk->next->value == value)
    {
      Node_ptr next = p_walk->next->next;
      free(p_walk->next);
      p_walk->next = next;
      list->count--;
    }
    else
    {
      p_walk = p_walk->next;
    }
  }
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  printf("List is:\n");
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}