#ifndef _STACK_
#define _STACK_

#include <stdbool.h>

typedef struct node {
  char data;
  struct node *next;
} Node;

void stack_init(Node **stack);

bool stack_is_empty(Node *stack);

bool stack_push(Node **stack, char data);

bool stack_pop(Node **stack, char *data);

#endif