#ifndef DS_LINKED_LIST
#define DS_LINKED_LIST

#include <stdbool.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

void ll_init(node **list);

void ll_free(node **list);

void ll_print(node *list);

bool ll_empty(node *list);

bool ll_contains(node *list, int data);

bool ll_insert_front(node **list, int data);

bool ll_insert_back(node **list, int data);

bool ll_insert_after(node **list, int target, int data);

bool ll_remove_front(node **list);

bool ll_remove_back(node **list);

#endif