#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "include/circular_linked_list.h"

int main(void) {
  node *list = NULL;

  cll_init(&list);
  assert(list == NULL);

  for (int i = 0; i < 10; i++) {
    if (!cll_insert(&list, i)) {
      printf("err: couldn't insert data.");
      exit(EXIT_FAILURE);
    }
  }

  for (int i = -1; i >= -9; i--) {
    if (!cll_insert(&list, i)) {
      printf("err: couldn't insert data.");
      exit(EXIT_FAILURE);
    }
  }

  cll_remove(&list, 4);
  cll_remove(&list, 5);
  cll_remove(&list, 6);

  assert(!cll_contains(list, 4));
  assert(!cll_contains(list, 5));
  assert(!cll_contains(list, 6));
  assert(cll_contains(list, 0));
  assert(cll_contains(list, 1));
  assert(cll_contains(list, -9));

  cll_print(list);

  cll_free(&list);
  assert(list == NULL);

  return EXIT_SUCCESS;
}