#include <stdio.h>
#include <stdlib.h>

#include "include/linked_list.h"

void ll_init(node **list) {
  *list = NULL;
}

void ll_free(node **list) {
  node *curr = *list;
  node *next;

  while (curr) {
    next = curr->next;

    free(curr);

    curr = next;
  }

  *list = NULL;
}

void ll_print(node *list) {
  while (list) {
    printf("%d ", list->data);
    list = list->next;
  }
}

bool ll_empty(node *list) {
  return list == NULL;
}

bool ll_contains(node *list, int data) {
  while (list && list->data == data) {
    if (list->data == data) {
      return true;
    }

    list = list->next;
  }

  return false;
}

bool ll_insert_front(node **list, int data) {
  if (!list) {
    return false;
  }

  node *new_node = malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;
  new_node->next = *list;

  *list = new_node;

  return true;
}

bool ll_insert_back(node **list, int data) {
  if (!list) {
    return false;
  }

  node *new_node = malloc(sizeof(node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;
  new_node->next = NULL;

  if (ll_empty(*list)) {
    *list = new_node;
  }
  else {
    node *last = *list;
    while (last->next) {
      last = last->next;
    }

    last->next = new_node;
  }

  return true;
}

bool ll_insert_after(node **list, int target, int data) {
  if (!list || ll_empty(*list)) {
    return false;
  }

  node *curr = *list;
  while (curr) {
    if (curr->data == target) {
      node *new_node = malloc(sizeof(node));
      if (!new_node) {
        return false;
      }

      new_node->data = data;
      new_node->next = curr->next;

      curr->next = new_node;

      return true;
    }

    curr = curr->next;
  }

  return false;
}

bool ll_remove_front(node **list) {
  if (!list || ll_empty(*list)) {
    return false;
  }

  node *first = *list;
  *list = first->next;

  free(first);

  return true;
}

bool ll_remove_back(node **list) {
  if (!list || ll_empty(*list)) {
    return false;
  }

  node *last_prev = NULL;
  node *last = *list;

  while (last->next) {
    last_prev = last;
    last = last->next;
  }

  if (last_prev) {
    last_prev->next = NULL;
  }
  else {
    *list = NULL;
  }

  free(last);

  return true;
}