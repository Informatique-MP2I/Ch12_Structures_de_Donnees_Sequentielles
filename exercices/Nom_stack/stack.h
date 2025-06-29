#ifndef STACK_H
#define STACK_H

/* Structure of the stack */
typedef struct stack stack_s;

/* 
   Creates a new stack and initializes eventual variables
   Parameters : 
   Asserts    : 
   Return     : the pointer to the new empty stack
*/
stack_s *stack_create();

/* 
   Add the given value to the stack
   Parameters : a new value to add
                the address of the current stack
   Asserts    : if the stack already created (if relevant)
                if the stack has enough space (if relevant)
   Return     : the address of the updated stack
*/
stack_s *stack_push(int value, stack_s *stack);

/* 
   Test if the stack empty or not
   Parameters : the address of the current stack
   Asserts    : if the stack is created (if relevant)
   Return     : true if the stack is empty 
                false if the stack is not empty
*/
bool stack_empty(stack_s *stack);

/* 
   Read the head element without removing it
   Parameters : the address of the current stack
   Asserts    : if the stack is not empty
   Return     : the value of the head element
*/
int stack_peek(stack_s *stack);

/* 
   Remove the head element
   Parameters : the address of the current stack
   Asserts    : the stack is not empty
   Return     : the address of the updated stack
*/
stack_s *stack_pop(stack_s *stack);

/* 
   Print the stack element from the head to the last element
   Parameters : the address of the current stack
   Asserts    : if the stack is created (if relevant)
   Return     : 
*/
void stack_print(stack_s *stack);

/* 
   Erase the stack
   Parameters : the address of the current stack
   Asserts    : if the stack is created (if relevant)
   Return     :
*/
void stack_delete(stack_s *stack);

#endif // STACK_H
