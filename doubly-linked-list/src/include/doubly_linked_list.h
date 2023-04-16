#ifndef DS_DOUBLY_LINKED_LIST
#define DS_DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node node;

void dll_init(node **list);

void dll_free(node **list);

void dll_print_asc(node *list);

void dll_print_desc(node *list);

bool dll_empty(node *list);

bool dll_insert_front(node **list, int data);

bool dll_insert_back(node **list, int data);

bool dll_insert_after(node **list, int target, int data);

bool dll_remove_front(node **list);

bool dll_remove_back(node **list);

#endif