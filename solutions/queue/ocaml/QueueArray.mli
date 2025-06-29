type queue

val queue_create : unit -> queue

val queue_print : queue -> unit

val queue_enqueue : int -> queue -> queue

val queue_empty : queue -> bool

val queue_peek : queue -> int

val queue_dequeue : queue -> queue
                                     
val queue_delete : 'a -> queue
