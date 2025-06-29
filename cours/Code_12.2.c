int *old_values = values; 
values = (int *)malloc(2*size*sizeof(int)); 
for (int i = 0; i < size; i++)  
  values[i] = old_values[i]; 
size = 2 * size;
values[top] = 7; 
top += 1; 
free(old_values); 
