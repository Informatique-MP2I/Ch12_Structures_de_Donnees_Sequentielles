#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/* #define MAX_QUEUE_SIZE 100 */
const int MAX_QUEUE_SIZE=100;

/* Structure of the queue */
typedef struct queue {
  int values[MAX_QUEUE_SIZE];
  int in;
  int out;
} queue_s;

/* 
   Creates a new queue and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty queue
*/
queue_s *queue_create() {
  queue_s *queue=(queue_s *)malloc(sizeof(queue_s));
  assert(queue != NULL);
  queue->in = 0;
  queue->out = 0;
  return queue;
}

/* 
   Add the given value to the queue
   Parameters : a new value to add
                the address of the current queue
   Asserts    : if the queue already created
                if the queue has enough space
   Return     : the address of the updated queue
*/ 
queue_s *queue_enqueue(int value, queue_s *queue) {
  assert(queue != NULL); /* fail if queue was not created with queue_create */
  assert( (queue->in + 1) % MAX_QUEUE_SIZE != queue->out);
  queue->values[queue->in] = value;
  queue->in = (queue->in+1) % MAX_QUEUE_SIZE;
  return queue;
}

/* 
   Test if the stack queue or not
   Parameters : the address of the current queue
   Asserts    : if the queue is created
   Return     : true if the queue is empty 
                false if the queue is not empty
*/
bool queue_empty(queue_s *queue) {
  assert(queue != NULL); /* fail if queue was not created with queue_create */
  return queue->in == queue->out;
}

/* 
   Read the head element without removing it
   Parameters : the address of the current queue
   Asserts    : if the queue is not empty
   Return     : the value of the head element
*/
int queue_peek(queue_s *queue) {
  assert(!queue_empty(queue));
  return queue->values[queue->out];
}

/* 
   Remove the head element
   Parameters : the address of the current queue
   Asserts    : the queue is not empty
   Return     : the address of the updated queue
*/
queue_s *queue_dequeue(queue_s *queue) {
  assert(!queue_empty(queue));
  queue->out = (queue->out+1)% MAX_QUEUE_SIZE;
  return queue;
}

/* 
   Print the queue element from the head to the last element
   Parameters : the address of the current queue
   Asserts    : if the queue is already created
   Return     : 
*/
void queue_print(queue_s *queue) {
  assert(queue != NULL); /* fail if queue was not created with queue_create */
  printf("[ ");
  for(int i=queue->out; i!=queue->in; i=(i+1)% MAX_QUEUE_SIZE) {
    printf("%d ",queue->values[i]);
    if((i+1)% MAX_QUEUE_SIZE != queue->in)
      printf(", ");
  }
  printf("]");
  return;
}

/* 
   Erase the queue
   Parameters : the address of the current queue
   Asserts    : if the queue is already created
   Return     :
*/
void queue_delete(queue_s *queue) {
  assert(queue != NULL); /* fail if queue was not created with queue_create */
  free(queue);
  return;
}
