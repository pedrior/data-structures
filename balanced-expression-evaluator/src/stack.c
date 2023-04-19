#include <stdlib.h>
#include <stdio.h>

#include "include/stack.h"

void stack_init(Node **stack) {
  if (!stack) {
    printf("err: null stack pointer");
    exit(EXIT_FAILURE);
  }

  *stack = NULL;
}

bool stack_is_empty(Node *stack) {
  return stack == NULL;
}

bool stack_push(Node **stack, char data) {
  if (!stack) {
    printf("err: null stack pointer");
    exit(EXIT_FAILURE);
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

bool stack_pop(Node **stack, char *data) {
  if (!stack) {
    printf("err: null stack pointer");
    exit(EXIT_FAILURE);
  }

  if (stack_is_empty(*stack)) {
    return false;
  }

  Node *top = *stack;
  *data = top->data;

  *stack = top->next;

  free(top);

  return true;
}