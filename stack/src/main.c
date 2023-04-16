#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "include/stack.h"

void print_stack(Node *stack);

int main(void) {
  Node *stack;

  st_init(&stack);
  assert(stack == NULL);

  for (int i = 0; i < 10; i++) {
    st_push(&stack, i);
  }

  print_stack(stack);

  st_free(&stack);
  assert(stack == NULL);

  return EXIT_SUCCESS;
}

void print_stack(Node *stack) {
  if (st_empty(stack)) {
    return;
  }

  printf("%d ", stack->data);
  print_stack(stack->next);
}