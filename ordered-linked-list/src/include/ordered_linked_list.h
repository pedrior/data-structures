#ifndef DS_ORDERED_LINKED_LIST
#define DS_ORDERED_LINKED_LIST

#include <stdbool.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

void oll_init(node **list);

void oll_free(node **list);

void oll_print(node *list);

bool oll_empty(node *list);

bool oll_contains(node *list, int data);

bool oll_insert(node **list, int data);

bool oll_remove(node **list, int data);

#endif