#include <stdio.h>
#include <stdlib.h>

#include "include/stack.h"

void st_init(Node **stack) {
  *stack = NULL;
}

void st_free(Node **stack) {
  Node *curr = *stack;

  while (curr) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }

  *stack = NULL;
}

bool st_empty(Node *stack) {
  return stack == NULL;
}

bool st_push(Node **stack, int data) {
  if (!stack) {
    return false;
  }

  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    return false;
  }

  new_node->data = data;
  new_node->next = *stack;

  *stack = new_node;

  return true;
}

int st_pop(Node **stack) {
  if (!stack || st_empty(*stack)) {
    printf("err: stack underflow\n");
    exit(EXIT_FAILURE);
  }

  Node *top = *stack;
  int data = top->data;

  *stack = top->next;
  free(top);

  return data;
}

int st_peek(Node *stack) {
  if (st_empty(stack)) {
    printf("err: stack underflow\n");
    exit(EXIT_FAILURE);
  }

  return stack->data;
}