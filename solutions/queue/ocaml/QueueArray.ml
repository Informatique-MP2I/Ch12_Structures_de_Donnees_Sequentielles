
let init_queue_size = 5

type queue = {
  values : int array;
  q_in   : int;
  q_out  : int
}

let queue_create () =
  {values = Array.make init_queue_size 0; q_in = 0; q_out = 0}

let queue_print queue =
  let rec aux values i =
    if i = queue.q_in then
      Printf.printf "["
    else
      begin
        aux values ((i+1) mod (Array.length queue.values));
        Printf.printf " %d " (values.(i));
        if (i mod (Array.length queue.values)) != queue.q_out then
            Printf.printf ",";
      end
  in
  aux queue.values (queue.q_out);
  Printf.printf "]\n"

let queue_enqueue value queue =
  let new_queue = 
  if ((queue.q_in + 1) mod (Array.length queue.values)) = queue.q_out then
    begin
      let tmp = {values = (Array.make (2*(Array.length queue.values)) 0); q_in = queue.q_in; q_out = if (queue.q_in < queue.q_out) then queue.q_out + (Array.length queue.values) else queue.q_out} in

      if (queue.q_in < queue.q_out) then
        begin
          for i=queue.q_out to Array.length queue.values do
            tmp.values.(i+Array.length queue.values) <- queue.values.(i)
          done;
          for i=0 to queue.q_in do
            tmp.values.(i) <- queue.values.(i)
          done
        end
      else
        for i=queue.q_out to queue.q_in do
          tmp.values.(i) <- queue.values.(i)
        done;
      tmp
    end
  else
    {values = queue.values; q_in = ((queue.q_in +1) mod (Array.length queue.values)); q_out = queue.q_out} in
  new_queue.values.(queue.q_in) <- value;
  new_queue
  
let queue_empty queue =
  queue.q_in = queue.q_out

let queue_peek queue =
  assert (not (queue_empty queue));
  queue.values.(queue.q_out)

(*
let queue_dequeue queue =
  assert (not (queue_empty queue));
  {values=queue.values; q_in = queue.q_in; q_out = (queue.q_out + 1) mod (Array.length queue.values)}
*)

let queue_dequeue queue =
  assert (not (queue_empty queue));
  let new_out = (queue.q_out + 1) mod (Array.length queue.values) in
  let size = Array.length queue.values in
  let num_elements = (queue.q_in - new_out + size) mod size in
  if num_elements < size / 2 && size > init_queue_size then
    let new_size = max (size / 2) init_queue_size in  
    let new_values = Array.make new_size 0 in
    for i = 0 to num_elements - 1 do
      new_values.(i) <- queue.values.((new_out + i) mod size)
    done;
    {values = new_values; q_in = num_elements; q_out = 0}
  else
    {queue with q_out = new_out}

let queue_delete queue =
  queue_create ()


