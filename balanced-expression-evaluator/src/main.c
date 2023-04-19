#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "include/stack.h"

#define EXP_BUFFER_SIZE 40

bool evaluate_expression(char *exp);

int main(void) {
  char exp[EXP_BUFFER_SIZE];

  printf("Enter the expression: ");
  scanf("%s", exp);

  printf("The expression '%s' is ", exp);
  printf(evaluate_expression(exp) ? "balanced!" : "not balanced!");

  return EXIT_SUCCESS;
}

bool evaluate_expression(char *exp) {
  if (!exp) {
    return false;
  }

  Node *stack;
  stack_init(&stack);

  int pos = 0;
  while (exp[pos]) {
    char cur_sym = exp[pos];

    if (cur_sym == '(' || cur_sym == '[' || cur_sym == '{') {
      if (!stack_push(&stack, cur_sym)) {
        printf("err: failed to push on stack");
        exit(EXIT_FAILURE);
      }
    }
    else  if (cur_sym == ')' || cur_sym == ']' || cur_sym == '}') {
      // In case of ending brackets without a pair
      if (stack_is_empty(stack)) {
        return false;
      }

      char top_sym;
      if (!stack_pop(&stack, &top_sym)) {
        printf("err: failed to pop from stack");
        exit(EXIT_FAILURE);
      }

      // printf("'%c %c'\n", top_sym, cur_sym);

      if (top_sym == '(' && cur_sym != ')') return false;
      if (top_sym == '[' && cur_sym != ']') return false;
      if (top_sym == '{' && cur_sym != '}') return false;
    }

    pos++;
  }

  return stack_is_empty(stack);
}