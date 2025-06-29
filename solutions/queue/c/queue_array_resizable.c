#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/* #define INIT_QUEUE_SIZE 5 */
const int INIT_QUEUE_SIZE=5;

/* Structure of the queue */
typedef struct queue {
  int size;
  int *values;
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
  queue->size = INIT_QUEUE_SIZE;
  queue->values=(int *)malloc(queue->size*sizeof(int));
  assert(queue->values != NULL);
  queue->in = 0;
  queue->out = 0;
  return queue;
}

/* 
   Add the given value to the queue
   Parameters : a new value to add
                the address of the current queue
   Asserts    : if the queue already created
   Return     : the address of the updated queue
*/ 
queue_s *queue_enqueue(int value, queue_s *queue) {
  assert(queue != NULL); /* fail if queue was not created with queue_create */
  if ((queue->in+1)%queue->size == queue->out) {
    queue->size = 2*queue->size;
    int *old_values = queue->values;
    queue->values = (int *)malloc(queue->size*sizeof(int));
    assert(queue->values != NULL);
    
    if (queue->in < queue->out) {
      for (int i=queue->out; i<queue->size; i++) {
	queue->values[i+(queue->size/2)] = old_values[i];
      }
      for (int i=0; i<queue->in; i++) {
	queue->values[i] = old_values[i];
      }
      queue->out = queue->out + queue->size/2;
    }
    if (queue->in > queue->out) {
      for (int i=queue->out; i<queue->in; i++) {
	queue->values[i] = old_values[i];
      }
    }
    free(old_values);
  }
  queue->values[queue->in] = value;
  queue->in = (queue->in+1) % queue->size;
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

  // Remove head element
  queue->out = (queue->out + 1) % queue->size;

  // update the array if necessary
  int numElements = (queue->in - queue->out + queue->size) % queue->size;
  if (numElements < queue->size / 2 && queue->size > INIT_QUEUE_SIZE * 2) {
    int newSize = queue->size / 2;
    int *newValues = (int *)malloc(newSize * sizeof(int)); 
    assert(newValues != NULL);
   
    for (int i = 0; i < numElements; i++) {
      int index = (queue->out + i) % queue->size; 
      newValues[i] = queue->values[index]; 
    }

    free(queue->values);
    queue->values = newValues;
    queue->size = newSize;
    queue->in = numElements; 
    queue->out = 0; 
  }
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
  for(int i=queue->out; i!=queue->in; i=(i+1)%queue->size) {
    printf("%d ",queue->values[i]);
    if((i+1)%queue->size != queue->in)
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
  free(queue->values);
  free(queue);
  return;
}
