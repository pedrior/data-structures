#ifndef DS_CIRCULAR_LINKED_LIST
#define DS_CIRCULAR_LINKED_LIST

#include <stdbool.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

void cll_init(node **list);

void cll_free(node **list);

void cll_print(node *list);

bool cll_empty(node *list);

bool cll_contains(node *list, int data);

bool cll_insert(node **list, int data);

bool cll_remove(node **list, int data);

#endif