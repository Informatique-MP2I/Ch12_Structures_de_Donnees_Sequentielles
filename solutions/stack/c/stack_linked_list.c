#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/* Structure of the stack */
typedef struct stack {
  int value;
  struct stack *tail;
} stack_s;

/* 
   Creates a new stack and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty stack
*/
stack_s *stack_create() {
  return NULL;
}

/* 
   Add the given value to the stack
   Parameters : a new value to add
                the address of the current stack
   Asserts    : 
   Return     : the address of the updated stack
*/
stack_s *stack_push(int value, stack_s *stack) {
  stack_s *head = (stack_s *)malloc(sizeof(stack_s));
  assert(head != NULL);
  head->value=value;
  head->tail=stack;
  return head;
}

/* 
   Test if the stack empty or not
   Parameters : the address of the current stack
   Asserts    : 
   Return     : true if the stack is empty 
                false if the stack is not empty
*/
bool stack_empty(stack_s *stack) {
  return stack == NULL;
}

/* 
   Read the head element without removing it
   Parameters : the address of the current stack
   Asserts    : if the stack is not empty
   Return     : the value of the head element
*/
int stack_peek(stack_s *stack) {
  assert(!stack_empty(stack));
  return stack->value;
}

/* 
   Remove the head element
   Parameters : the address of the current stack
   Asserts    : the stack is not empty
   Return     : the addresse of the updated stack
*/
stack_s *stack_pop(stack_s *stack) {
  assert(!stack_empty(stack));
  stack_s *res = stack->tail;
  free(stack);
  return res;
}

/* 
   Print the stack element from the head to the last element
   Parameters : the address of the current stack
   Asserts    : 
   Return     : 
*/
void stack_print(stack_s *stack) {
  stack_s *head=stack;
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
   Erase the stack
   Parameters : the address of the current stack
   Asserts    : 
   Return     :
*/
void stack_delete(stack_s *stack) {
  if(!stack_empty(stack)) {
    stack_delete(stack->tail);
    free(stack);
  }
  return;
}
