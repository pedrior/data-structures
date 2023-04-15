#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "include/doubly_linked_list.h"

int main(void) {
  node *list;

  dll_init(&list);
  assert(list == NULL);

  for (int i = 0; i < 10; i++) {
    if (!dll_insert_front(&list, i)) {
      printf("err: couldn't insert data.");
      exit(EXIT_FAILURE);
    }
  }

  for (int i = -1; i >= -9; i--) {
    if (!dll_insert_back(&list, i)) {
      printf("err: couldn't insert data.");
      exit(EXIT_FAILURE);
    }
  }

  dll_insert_after(&list, -9, -10);
  dll_insert_after(&list, -10, -11);

  dll_remove_front(&list);
  dll_remove_front(&list);

  dll_print_asc(list);
  printf("\n");
  dll_print_desc(list);

  dll_free(&list);
  assert(list == NULL);

  return EXIT_SUCCESS;
}