#include <stdio.h>
#include <stdlib.h>

#include "include/circular_linked_list.h"

void cll_init(node **list) {
  *list = NULL;
}

void cll_free(node **list) {
  node *curr = *list;
  node *next;

  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  *list = NULL;
}

void cll_print(node *list) {
  if (cll_empty(list)) {
    return;
  }

  node *curr = list;

  do {
    printf("%d ", curr->data);
    curr = curr->next;
  } while (curr != list);
}

bool cll_empty(node *list) {
  return list == NULL;
}

bool cll_contains(node *list, int data) {
  if (cll_empty(list)) {
    return false;
  }

  node *curr = list;

  do {
    if (curr->data == data) {
      return true;
    }

    curr = curr->next;
  } while (curr != list);

  return false;
}

bool cll_insert(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;

  if (cll_empty(*list)) {
    new_node->next = new_node;
    *list = new_node;

    return true;
  }

  node *last = *list;

  // Find the last node
  while (last->next != *list) {
    last = last->next;
  }

  new_node->next = *list;
  last->next = new_node;

  return true;
}

bool cll_remove(node **list, int data) {
  if (!list || cll_empty(*list)) {
    return false;
  }

  node *curr = *list;
  node *prev = NULL;

  // Find the node to remove
  do {
    if (curr->data == data) {
      break;
    }

    prev = curr;
    curr = curr->next;
  } while (curr != *list);

  // Check if the node was found
  if (curr->data != data) {
    return false;
  }

  // Removing the first node
  if (curr == *list) {
    prev = *list;
    while (prev->next != *list) {
      prev = prev->next;
    }
    *list = (*list)->next;
    prev->next = *list;
  }
  // Removing any other node
  else {
    prev->next = curr->next;
  }

  free(curr);

  return true;
}
