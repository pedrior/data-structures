#include <stdio.h>
#include <stdlib.h>

#include "include/stack.h"

void stack_init(Node **stack) {
  *stack = NULL;
}

void stack_destroy(Node **stack) {
  if (!*stack) {
    return;
  }

  stack_destroy(&(*stack)->next);
  free(*stack);

  *stack = NULL;
}

bool stack_is_empty(Node *stack) {
  return stack == NULL;
}

bool stack_push(Node **stack, int data) {
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

int stack_pop(Node **stack) {
  if (!stack || stack_is_empty(*stack)) {
    printf("err: stack underflow\n");
    exit(EXIT_FAILURE);
  }

  Node *top = *stack;
  int data = top->data;

  *stack = top->next;

  free(top);

  return data;
}