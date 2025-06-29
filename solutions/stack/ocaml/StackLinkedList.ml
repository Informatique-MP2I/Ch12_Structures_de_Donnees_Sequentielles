
type stack = EmptyStack | Stack of int * stack

let stack_create () =
  EmptyStack

let stack_print stack =
  let rec aux stack =
  match stack with
  | EmptyStack -> Printf.printf "]\n"
  | Stack (value, tail) -> Printf.printf " %d " value;
    if tail <> EmptyStack then Printf.printf ",";
    aux tail
  in
  Printf.printf "[";
  aux stack

let stack_push value stack =
  Stack (value, stack)

let stack_empty stack =
  stack = EmptyStack

let stack_peek stack =
  assert (not (stack_empty stack));
  match stack with
  | EmptyStack -> assert false
  | Stack (value, _) -> value

let stack_pop stack =
  assert (not (stack_empty stack));
  match stack with
  | EmptyStack -> assert false
  | Stack (_, tail) -> tail

let stack_delete stack =
  EmptyStack
