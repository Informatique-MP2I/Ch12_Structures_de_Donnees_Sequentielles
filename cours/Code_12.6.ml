type 'a linkedlist =
  | EmptyLinkedList
  | LinkedList of 'a * 'a linkedlist
