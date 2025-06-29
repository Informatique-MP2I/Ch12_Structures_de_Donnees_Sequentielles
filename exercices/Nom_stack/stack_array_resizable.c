#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/* Initial stack size */
/* TODO */

/* Structure of the stack */
typedef struct stack {
  /* TODO */
} stack_s;

/* 
   Creates a new stack and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty stack
*/
stack_s *stack_create() {
  /* TODO */
  return NULL;
}

/* 
   Add the given value to the stack
   Parameters : a new value to add
                the address of the current stack
   Asserts    : if the stack already created
                if the stack has enough space
   Return     : the address of the updated stack
*/
stack_s *stack_push(int value, stack_s *stack) {
  /* TODO */
  return NULL;
}

/* 
   Test if the stack empty or not
   Parameters : the address of the current stack
   Asserts    : if the stack is created
   Return     : true if the stack is empty 
                false if the stack is not empty
*/
bool stack_empty(stack_s *stack) {
  /* TODO */
  return false;
}

/* 
   Read the head element without removing it
   Parameters : the address of the current stack
   Asserts    : if the stack is not empty
   Return     : the value of the head element
*/
int stack_peek(stack_s *stack) {
  /* TODO */
  return 0;
}

/* 
   Remove the head element
   Parameters : the address of the current stack
   Asserts    : the stack is not empty
   Return     : the address of the updated stack
*/
stack_s *stack_pop(stack_s *stack) {
  /* TODO */
  return NULL;
}

/* 
   Print the stack element from the head to the last element
   Parameters : the address of the current stack
   Asserts    : if the stack already created
   Return     : 
*/
void stack_print(stack_s *stack) {
  /* TODO */
  return;
}

/* 
   Erase the stack
   Parameters : the address of the current stack
   Asserts    : if the stack is already created
   Return     :
*/
void stack_delete(stack_s *stack) {
  /* TODO */
  return;
}
