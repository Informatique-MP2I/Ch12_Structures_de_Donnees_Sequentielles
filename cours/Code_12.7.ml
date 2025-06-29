type 'a node = {
  mutable value : 'a; 
  mutable next  : 'a node option
}
