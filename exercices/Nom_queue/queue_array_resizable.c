#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/* Initial queue size */
/* TODO */

/* Structure of the queue */
typedef struct queue {
  /* TODO */
} queue_s;

/* 
   Creates a new queue and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty queue
*/
queue_s *queue_create() {
  /* TODO */
  return NULL;
}

/* 
   Add the given value to the queue
   Parameters : a new value to add
                the address of the current queue
   Asserts    : if the queue already created
   Return     : the address of the updated queue
*/ 
queue_s *queue_enqueue(int value, queue_s *queue) {
  /* TODO */
  return NULL;
}

/* 
   Test if the stack queue or not
   Parameters : the address of the current queue
   Asserts    : if the queue is created
   Return     : true if the queue is empty 
                false if the queue is not empty
*/
bool queue_empty(queue_s *queue) {
  /* TODO */
  return false;
}

/* 
   Read the head element without removing it
   Parameters : the address of the current queue
   Asserts    : if the queue is not empty
   Return     : the value of the head element
*/
int queue_peek(queue_s *queue) {
  /* TODO */
  return 0;
}

/* 
   Remove the head element
   Parameters : the address of the current queue
   Asserts    : the queue is not empty
   Return     : the address of the updated queue
*/
queue_s *queue_dequeue(queue_s *queue) {
  /* TODO */
  return NULL;
}

/* 
   Print the queue element from the head to the last element
   Parameters : the address of the current queue
   Asserts    : if the queue is already created
   Return     : 
*/
void queue_print(queue_s *queue) {
  /* TODO */
  return;
}

/* 
   Erase the queue
   Parameters : the address of the current queue
   Asserts    : if the queue is already created
   Return     :
*/
void queue_delete(queue_s *queue) {
  /* TODO */
  return;
}
