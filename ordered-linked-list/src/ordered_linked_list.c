#include <stdio.h>
#include <stdlib.h>

#include "include/ordered_linked_list.h"

void oll_init(node **list) {
  *list = NULL;
}

void oll_free(node **list) {
  node *curr = *list;
  node *next;

  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  *list = NULL;
}

void oll_print(node *list) {
  while (list) {
    printf("%d ", list->data);
    list = list->next;
  }
}

bool oll_empty(node *list) {
  return list == NULL;
}

bool oll_contains(node *list, int data) {
  while (list) {
    if (list->data == data) {
      return true;
    }

    list = list->next;
  }

  return false;
}

bool oll_insert(node **list, int data) {
  if (!list) {
    return false;
  }

  node *new_node = malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;

  // Insert at the beginning
  if (oll_empty(*list) || (*list)->data > data) {
    new_node->next = *list;
    *list = new_node;

    return true;
  }

  node *curr = *list;

  // Insert in the middle or at the end
  while (curr->next && curr->next->data < data) {
    curr = curr->next;
  }

  new_node->next = curr->next;
  curr->next = new_node;

  return true;
}

bool oll_remove(node **list, int data) {
  if (!list || oll_empty(*list)) {
    return false;
  }

  node *curr = *list;
  node *prev = NULL;

  // Find the node to remove
  while (curr && curr->data < data) {
    prev = curr;
    curr = curr->next;
  }

  // The node to remove is not in the list
  if (!curr || curr->data != data) {
    return false;
  }

  // The node to remove is in the middle or at the end
  if (prev) {
    prev->next = curr->next;
  }
  else {
    *list = curr->next;
  }

  free(curr);

  return true;
}