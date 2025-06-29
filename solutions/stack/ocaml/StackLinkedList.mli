type stack
  
val stack_create : unit -> stack

val stack_print : stack -> unit

val stack_push : int -> stack -> stack

val stack_empty : stack -> bool

val stack_peek : stack -> int

val stack_pop : stack -> stack

val stack_delete : 'a -> stack
