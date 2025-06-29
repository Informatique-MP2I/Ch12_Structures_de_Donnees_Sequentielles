#define INIT_ARRAY_SIZE 6 
int size = INIT_ARRAY_SIZE; 
int *values; 
int top = 0; 
values = (int *)malloc(size*sizeof(int)); 
assert(values != NULL);
