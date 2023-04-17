#ifndef DS_STACK
#define DS_STACK

#include <stdbool.h>

typedef struct node {
  float data;
  struct node *next;
} Node;

void stack_init(Node **stack);

void stack_destroy(Node **stack);

bool stack_is_empty(Node *stack);

bool stack_push(Node **stack, int data);

int stack_pop(Node **stack);

#endif