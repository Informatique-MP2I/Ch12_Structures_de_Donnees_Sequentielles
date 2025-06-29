open QueueLinkedList
    
let () = 
  let my_queue = queue_create () in
  queue_print my_queue;
  let my_queue = queue_enqueue 1 my_queue in
  queue_print my_queue;
  let my_queue = queue_enqueue 2 my_queue in
  let my_queue = queue_enqueue 3 my_queue in
  let my_queue = queue_enqueue 4 my_queue in
  let my_queue = queue_enqueue 5 my_queue in
  let my_queue = queue_enqueue 6 my_queue in
  Printf.printf "peek %d\n" (queue_peek my_queue);
  queue_print my_queue;
  let my_queue = queue_dequeue my_queue in
  queue_print my_queue

