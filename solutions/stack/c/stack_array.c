#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
/* const int MAX_STACK_SIZE=100; */

/* Structure of the stack */
typedef struct stack {
  int values[MAX_STACK_SIZE];
  int top;
} stack_s;

/* 
   Creates a new stack and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty stack
*/
stack_s *stack_create() {
  stack_s *stack=(stack_s *)malloc(sizeof(stack_s));
  assert(stack != NULL);
  stack->top=0;
  return stack;
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
  assert(stack != NULL); /* fail if stack was not created with stack_create */
  assert(stack->top<MAX_STACK_SIZE);
  stack->values[stack->top]=value;
  stack->top++;
  return stack;
}

/* 
   Test if the stack empty or not
   Parameters : the address of the current stack
   Asserts    : if the stack is created
   Return     : true if the stack is empty 
                false if the stack is not empty
*/
bool stack_empty(stack_s *stack) {
  assert(stack != NULL); /* fail if stack was not createed with stack_create */
  return !(stack->top > 0);
}

/* 
   Read the head element without removing it
   Parameters : the address of the current stack
   Asserts    : if the stack is not empty
   Return     : the value of the head element
*/
int stack_peek(stack_s *stack) {
  assert(!stack_empty(stack));
  return stack->values[stack->top-1];
}

/* 
   Remove the head element
   Parameters : the address of the current stack
   Asserts    : the stack is not empty
   Return     : the address of the updated stack
*/
stack_s *stack_pop(stack_s *stack) {
  assert(!stack_empty(stack));
  stack->top--;
  return stack;
}

/* 
   Print the stack element from the head to the last element
   Parameters : the address of the current stack
   Asserts    : if the stack already created
   Return     : 
*/
void stack_print(stack_s *stack) {
  assert(stack != NULL); /* fail if stack was not createed with stack_create */
  printf("[ ");
  for (int i=stack->top-1; i>=0; i--) {
    printf("%d ",stack->values[i]);
    if(i-1>=0)
      printf(", ");
  }
  printf("]");
  return;
}

/* 
   Erase the stack
   Parameters : the address of the current stack
   Asserts    : if the stack is already created
   Return     :
*/
void stack_delete(stack_s *stack) {
  assert(stack != NULL); /* fail if stack was not createed with stack_create */
  free(stack);
  return;
}
