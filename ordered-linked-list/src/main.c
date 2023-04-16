#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "include/ordered_linked_list.h"

int main(void) {
  srand(time(NULL));

  node *list;

  oll_init(&list);
  assert(list == NULL);

  int last_data = 0;

  for (int i = 0; i < 10; i++) {
    last_data = rand() % 100;
    oll_insert(&list, last_data);
  }

  oll_print(list);

  printf("\nRemoving %d:\n", last_data);

  assert(oll_remove(&list, last_data));

  printf("\n");

  oll_print(list);

  oll_free(&list);
  assert(list == NULL);

  return EXIT_SUCCESS;
}