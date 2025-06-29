
type queue = EmptyQueue | Queue of int * queue

let queue_create () =
  EmptyQueue

let queue_print queue =
  let rec aux queue =
    match queue with
  | EmptyQueue -> Printf.printf "]\n"
  | Queue (value, tail) -> Printf.printf " %d " value;
    if tail <> EmptyQueue then Printf.printf ",";
    aux tail
  in
  Printf.printf "[";
  aux queue

let queue_enqueue value queue =
  Queue (value, queue)

let queue_empty queue =
  queue = EmptyQueue

let queue_peek queue =
  assert (not (queue_empty queue));
  let rec aux queue =
    match queue with
    | Queue (value, EmptyQueue) -> value
    | Queue (_, tail) -> aux tail
    | EmptyQueue -> assert false
  in
  aux queue

let queue_dequeue queue =
  assert (not (queue_empty queue));
  let rec aux queue =
    match queue with
    | EmptyQueue -> assert false
    | Queue (value, EmptyQueue) -> EmptyQueue
    | Queue (value, tail) -> Queue (value, aux tail)
  in aux queue

let queue_delete queue =
  EmptyQueue
