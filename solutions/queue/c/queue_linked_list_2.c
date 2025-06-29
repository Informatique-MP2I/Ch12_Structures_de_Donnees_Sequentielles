#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/* Structure of the queue */
typedef struct node {
  int value;
  struct node *next;
} node_s;

typedef struct {
  int size;
  node_s *first;
  node_s *last;
} queue_s;

node_s *node_create(int value) {
  node_s *new_node = (node_s *)malloc(sizeof(node_s));
  assert(new_node != NULL); 
  new_node->value = value;
  new_node->next = NULL;
  return new_node; 
}

queue_s *queue_create() {
  queue_s *new_queue = (queue_s *)malloc(sizeof(queue_s));
  assert(new_queue != NULL);
  new_queue->size = 0;
  new_queue->first = NULL;
  new_queue->last = NULL;
  return new_queue; 
}

int queue_size(queue_s *queue) {
  assert(queue != NULL);
  return queue->size;
}

bool queue_empty(queue_s *queue) {
  assert(queue != NULL);
  return queue->size == 0;
}

queue_s* queue_enqueue(int value, queue_s *queue) {
  assert(queue != NULL);
  node_s *new_node = node_create(value);
  assert(new_node != NULL);
  if (queue_empty(queue)) {
    queue->first = new_node;
    queue->last = new_node;
  } else {  
    queue->last->next = new_node;
    queue->last = new_node;
  }
  queue->size += 1;
  return queue;
}

int queue_peek(queue_s *queue) {
  assert(!queue_empty(queue));
  return queue->first->value;
}

queue_s *queue_dequeue(queue_s *queue) {
  assert(!queue_empty(queue));
  node_s *temp = queue->first;
  queue->first = queue->first->next;
  if (queue->first == NULL) {
    queue->last = NULL;
  }
  free(temp);
  queue->size -= 1;
  return queue;
}

void queue_print(queue_s *queue) {
  assert(queue!=NULL);
  if (queue_empty(queue)) {
    printf("[]");
    return;
  }
  printf("[");
  node_s *current = queue->first;
  while (current != NULL) {
    printf("%d", current->value);
    if (current->next != NULL) {
      printf(", ");
    }
    current = current->next;
  }
  printf("]");  
  return;
}

void queue_delete(queue_s *queue) {
  assert(queue!=NULL);
  node_s *current = queue->first;
  while (current != NULL) {
    node_s *temp = current;
    current = current->next;
    free(temp);
  }
  free(queue);
  return;
}
