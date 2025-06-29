type queue =
  | EmptyQueue
  | QueueNode of int * queue
