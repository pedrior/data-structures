#ifndef DS_STACK
#define DS_STACK

#include <stdbool.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

void st_init(Node **stack);

void st_free(Node **stack);

bool st_empty(Node *stack);

bool st_push(Node **stack, int data);

int st_pop(Node **stack);

int st_peek(Node *stack);

#endif