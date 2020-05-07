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
  if(new_node == NULL)
  {
    return Failure;
  }

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
  if(new_node == NULL)
  {
    return Failure;
  }

  if(list->head == NULL)
  {
    list->last = new_node;
  }
  new_node->next = list->head;
  list->head = new_node;
  list->count++;
  return Success;
}

Status is_valid_position(int position, int count)
{
  if (position > count || position < 0)
  {
    return Failure;
  }
  return Success;
}  

Status insert_at(List_ptr list, int value, int position)
{ 
  int valid = is_valid_position(position, list->count);
  if (!valid) return Failure;
  
  if (position == 0)
  {
    return add_to_start(list, value); 
  }
  if (list->count == position)
  {
    return add_to_end(list, value);
  }
  
  Node_ptr new_node = create_node(value);
  if(new_node == NULL)
  {
    return Failure;
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
    return Success;
  }
  while (p_walk != NULL && p_walk->value != value)
  {
    if (p_walk->next == NULL)
    {
      p_walk->next = new_node;
      list->count++;
      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
}

Status remove_from_start(List_ptr list)
{
  if (list->count == 0) return Failure;
  Node *first_node = list->head;
  list->head = first_node->next;
  free(first_node);
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node_ptr p_walk = list->head;

  if(list->count == 0)
  {
    return Failure;
  }

  if (list->count == 1)
  {
    clear_list(list);
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
  int valid = is_valid_position(position, list->count - 1);
  if (!valid) return Failure;
  if (position == 0)
  {
    return remove_from_start(list);
  }

  if (position == list->count - 1)
  {
    return remove_from_end(list);
  }
  
  Node_ptr p_walk = list->head;
  int count = 0;
  while (count < position - 1)
  {
    p_walk = p_walk->next;
    count++;
  }

  Node_ptr next = p_walk->next->next;
  free(p_walk->next);
  p_walk->next = next;
  list->count--;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int position = 0;
  Status status = Failure;
  while (p_walk != NULL)
  {
    if (p_walk->value == value) 
    {
      return remove_at(list, position);
    }
    p_walk = p_walk->next;
    position++;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int position = 0;
  Status status = Failure;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      remove_at(list, position);
      status = Success;
      position--;
    }
    p_walk = p_walk->next;
    position++;
  }
  return status;
}

Status clear_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    Node_ptr next = p_walk->next;
    free(p_walk);
    p_walk = next;
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}

Status is_present(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
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