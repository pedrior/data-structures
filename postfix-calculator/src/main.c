#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/stack.h"

int main(void) {
  Node *stack;
  stack_init(&stack);

  char exp[100];

  printf("Enter the expression: \n");
  scanf_s("%s", exp);

  for (int i = 0; exp[i] != '\0'; i++) {
    if (isdigit(exp[i])) {
      stack_push(&stack, exp[i] - '0');
    }
    else {
      int op1 = stack_pop(&stack);
      int op2 = stack_pop(&stack);

      switch (exp[i]) {
      case '+':
        stack_push(&stack, op1 + op2);
        break;
      case '-':
        stack_push(&stack, op2 - op1);
        break;
      case '*':
        stack_push(&stack, op1 * op2);
        break;
      case '/':
        if (op1 == 0) {
          printf("err: division by zero\n");
          return EXIT_FAILURE;
        }

        stack_push(&stack, op2 / op1);
        break;
      default:
        printf("err: invalid operator '%c'\n", exp[i]);
        return EXIT_FAILURE;
      }
    }
  }

  int result = stack_pop(&stack);
  if (!stack_is_empty(stack)) {
    printf("err: invalid expression");
    return EXIT_FAILURE;
  }

  printf("\nResult: %d\n", result);

  stack_destroy(&stack);

  return EXIT_SUCCESS;
}