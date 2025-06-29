open StackLinkedList

let () = 
  let my_stack = stack_create () in
  stack_print my_stack;
  let my_stack = stack_push 1 my_stack in
  stack_print my_stack;
  let my_stack = stack_push 2 my_stack in
  let my_stack = stack_push 3 my_stack in
  let my_stack = stack_push 4 my_stack in
  let my_stack = stack_push 5 my_stack in
  let my_stack = stack_push 6 my_stack in
  Printf.printf "peek %d\n" (stack_peek my_stack);
  stack_print my_stack;
  let my_stack = stack_pop my_stack in
  stack_print my_stack
