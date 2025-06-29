#ifndef QUEUE_H
#define QUEUE_H

/* Structure of the queue */
typedef struct queue queue_s;

/* Creates a new queue and initializes eventual variables
   Return     : the pointer to the new empty queue */
queue_s *queue_create();
/* Add the given value to the queue
   Parameters : a new value to add
                the address of the current queue
   Asserts    : if the queue already created (if relevant)
                if the queue has enough space (if relevant)
   Return     : the address of the updated queue */ 
queue_s *queue_enqueue(int value, queue_s *queue);
/* Test if the stack queue or not
   Parameters : the address of the current queue
   Asserts    : if the queue is created (if relevant)
   Return     : true if the queue is empty 
                false if the queue is not empty */
bool queue_empty(queue_s *queue);
/* Read the head element without removing it
   Parameters : the address of the current queue
   Asserts    : if the queue is not empty
   Return     : the value of the head element */
int queue_peek(queue_s *queue);
/* Remove the head element
   Parameters : the address of the current queue
   Asserts    : the queue is not empty
   Return     : the address of the updated queue */
queue_s *queue_dequeue(queue_s *queue);
/* Print the queue element from the head to the last element
   Parameters : the address of the current queue
   Asserts    : if the queue is already created (if relevant) */
void queue_print(queue_s *queue);
/* Erase the queue
   Parameters : the address of the current queue
   Asserts    : if the queue is already created (if relevant) */
void queue_delete(queue_s *queue);

#endif // QUEUE_H
