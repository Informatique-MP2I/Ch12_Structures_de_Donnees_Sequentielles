#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/* Structure of the queue */
typedef struct queue {
  int value;
  struct queue *tail;
} queue_s;

/* 
   Creates a new queue and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty queue
*/
queue_s *queue_create() {
  return NULL;
}

/* 
   Add the given value to the queue
   Parameters : a new value to add
                the address of the current queue
   Asserts    : 
   Return     : the address of the updated queue
*/ 
queue_s *queue_enqueue(int value, queue_s *queue) {
  queue_s *res = (queue_s *)malloc(sizeof(queue_s));
  assert(res != NULL);
  res->value=value;
  res->tail=queue;
  return res;
}

/* 
   Test if the stack queue or not
   Parameters : the address of the current queue
   Asserts    : 
   Return     : true if the queue is empty 
                false if the queue is not empty
*/
bool queue_empty(queue_s *queue) {
  return queue == NULL;
}

/* 
   Read the head element without removing it
   Parameters : the address of the current queue
   Asserts    : if the queue is not empty
   Return     : the value of the head element
*/
int queue_peek(queue_s *queue) {
  assert(!queue_empty(queue));
  if(queue->tail == NULL)
    return queue->value;
  else
    return queue_peek(queue->tail);
}

/* 
   Remove the head element
   Parameters : the address of the current queue
   Asserts    : the queue is not empty
   Return     : the address of the updated queue
*/
queue_s *queue_dequeue(queue_s *queue) {
  assert(!queue_empty(queue));

  if (queue->tail == NULL) {
    free(queue);
    return NULL;
  }
  else {
    queue->tail = queue_dequeue(queue->tail);
    return queue;
  } 
}

/* 
   Print the queue element from the head to the last element
   Parameters : the address of the current queue
   Asserts    : 
   Return     : 
*/
void queue_print(queue_s *queue) {
  queue_s *head=queue;
  printf("[ ");
  while(head != NULL) {
    printf("%d ",head->value);
    head=head->tail;
    if(head != NULL)
      printf(", ");
  }
  printf("]");
  return;
}

/* 
   Erase the queue
   Parameters : the address of the current queue
   Asserts    : 
   Return     :
*/
void queue_delete(queue_s *queue) {
  if(queue != NULL) {
    queue_delete(queue->tail);
    free(queue);
  }
  return;
}

