#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "include/queue.h"

int main(void) {
  Queue queue;
  queue_init(&queue);
  assert(queue_empty(&queue));

  for (int i = 0; i < 10; i++) {
    queue_enqueue(&queue, i);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", queue_dequeue(&queue));
  }

  assert(queue_empty(&queue));

  return EXIT_SUCCESS;
}