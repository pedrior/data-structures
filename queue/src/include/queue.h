#ifndef _QUEUE_
#define _QUEUE_

#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct queue {
  Node *head;
  Node *tail;
} Queue;

void queue_init(Queue *queue);

bool queue_empty(Queue *queue);

void queue_enqueue(Queue *queue, int data);

int queue_dequeue(Queue *queue);

#endif