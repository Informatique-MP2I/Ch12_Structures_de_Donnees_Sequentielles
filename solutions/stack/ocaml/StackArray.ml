
let init_stack_size = 5
  
type stack = {
  values : int array;
  top    : int
} 

let stack_create () =
  {values = Array.make init_stack_size 0; top = 0}
      
let stack_print stack =
  let rec aux values i =
    if i<0 then
      Printf.printf "]\n"
    else
      begin
        Printf.printf " %d " (values.(i));
        if (i-1)>=0 then
            Printf.printf ",";
        aux values (i-1)
      end
  in
  Printf.printf "[";
  aux stack.values (stack.top-1)

let stack_push value stack =
  let new_stack = 
  if stack.top = Array.length stack.values then
    begin
      let tmp = {values = (Array.make (2*(Array.length stack.values)) 0); top = stack.top + 1} in
      Array.iteri (fun i x -> tmp.values.(i) <- stack.values.(i)) stack.values;
      tmp
    end
  else
    {stack with top = stack.top + 1} in
  new_stack.values.(stack.top) <- value;
  new_stack
  
let stack_empty stack =
  not (stack.top > 0)

let stack_peek stack =
  assert (not (stack_empty stack));
  stack.values.(stack.top - 1)

(*
let stack_pop stack =
  assert (not (stack_empty stack));
  {stack with top = stack.top-1}
  *)

let stack_pop stack =
  assert (not (stack_empty stack));
  let new_top = stack.top - 1 in 
  let size = Array.length stack.values in
  if new_top < size / 2 && size > init_stack_size then
    let new_size = max (size / 2) init_stack_size in 
    let new_values = Array.make new_size 0 in
    for i = 0 to new_top - 1 do
      new_values.(i) <- stack.values.(i)
    done;
    {values = new_values; top = new_top}
  else
    {stack with top = new_top}

let stack_delete stack =
  stack_create ()
