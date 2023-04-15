#include <stdio.h>

#include "include/doubly_linked_list.h"

void dll_init(node **list) {
  *list = NULL;
}

void dll_free(node **list) {
  if (!list) {
    return;
  }

  node *curr = *list;
  while (curr) {
    node *temp = curr;
    curr = curr->next;
    free(temp);
  }

  *list = NULL;
}

void dll_print_asc(node *list) {
  node *curr = list;
  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
}

void dll_print_desc(node *list) {
  node *curr = list;
  while (curr->next) {
    curr = curr->next;
  }

  while (curr) {
    printf("%d ", curr->data);
    curr = curr->prev;
  }
}

bool dll_empty(node *list) {
  return list == NULL;
}

bool dll_insert_front(node **list, int data) {
  if (!list) {
    return false;
  }

  node *new_node = (node *)malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;
  new_node->next = *list;
  new_node->prev = NULL;

  if (*list) {
    (*list)->prev = new_node;
  }

  *list = new_node;

  return true;
}

bool dll_insert_back(node **list, int data) {
  if (!list) {
    return false;
  }

  node *new_node = (node *)malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;
  new_node->next = NULL;

  if (!(*list)) {
    new_node->prev = NULL;
    *list = new_node;

    return true;
  }

  node *curr = *list;
  while (curr->next) {
    curr = curr->next;
  }

  curr->next = new_node;
  new_node->prev = curr;

  return true;
}

bool dll_insert_after(node **list, int target, int data) {
  if (!list) {
    return false;
  }

  node *new_node = (node *)malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;

  node *curr = *list;
  while (curr && curr->data != target) {
    curr = curr->next;
  }

  if (!curr) {
    // target not found
    return false;
  }

  new_node->next = curr->next;
  new_node->prev = curr;

  if (curr->next) {
    curr->next->prev = new_node;
  }

  curr->next = new_node;

  return true;
}

bool dll_remove_front(node **list) {
  if (!list || !(*list)) {
    return false;
  }

  node *temp = *list;
  *list = (*list)->next;

  if (*list) {
    (*list)->prev = NULL;
  }

  free(temp);

  return true;
}

bool dll_remove_back(node **list) {
  if (!list || !(*list)) {
    return false;
  }

  node *curr = *list;
  while (curr->next) {
    curr = curr->next;
  }

  if (curr->prev) {
    curr->prev->next = NULL;
  }
  else {
    *list = NULL;
  }

  free(curr);

  return true;
}