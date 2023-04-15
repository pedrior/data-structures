#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "include/linked_list.h"

int main(void) {
  node *list;

  ll_init(&list);
  assert(list == NULL);

  for (int i = 0; i < 10; i++) {
    if (!ll_insert_front(&list, i)) {
      printf("err: couldn't insert data.");
      exit(EXIT_FAILURE);
    }
  }

  for (int i = -1; i >= -9; i--) {
    if (!ll_insert_back(&list, i)) {
      printf("err: couldn't insert data.");
      exit(EXIT_FAILURE);
    }
  }

  ll_insert_after(&list, -9, -10);
  ll_insert_after(&list, -10, -11);

  ll_remove_front(&list);
  ll_remove_front(&list);

  ll_print(list);

  ll_free(&list);
  assert(list == NULL);

  return EXIT_SUCCESS;
}