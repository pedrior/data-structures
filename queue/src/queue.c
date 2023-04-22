#include <stdio.h>
#include <stdlib.h>

#include "include/queue.h"

void queue_init(Queue *queue) {
  queue->head = NULL;
  queue->tail = NULL;
}

bool queue_empty(Queue *queue) {
  return queue && !queue->head && !queue->tail;
}

void queue_enqueue(Queue *queue, int data) {
  if (!queue) {
    printf("err: null queue pointer\n");
    exit(EXIT_FAILURE);
  }

  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    printf("err: stack overflow\n");
    exit(EXIT_FAILURE);
  }

  new_node->data = data;
  new_node->next = NULL;

  if (queue_empty(queue)) {
    queue->head = new_node;
    queue->tail = new_node;
  }
  else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
}

int queue_dequeue(Queue *queue) {
  if (!queue) {
    printf("err: null queue pointer\n");
    exit(EXIT_FAILURE);
  }

  if (queue_empty(queue)) {
    printf("err: queue is empty\n");
    exit(EXIT_FAILURE);
  }

  Node *front = queue->head;

  if (queue->head == queue->tail) {
    queue->head = NULL;
    queue->tail = NULL;
  }
  else {
    queue->head = front->next;
  }

  int data = front->data;

  free(front);

  return data;
}