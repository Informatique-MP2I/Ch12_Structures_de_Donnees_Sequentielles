#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

int is_number(char *string) {
    assert(string != NULL);
    if(*string=='-') string++;
    if(*string=='\0') return 0;
    while(*string>='0' && *string<='9') string++;
    while(*string==' ' || *string=='\t' || *string=='\n') string++;
    return *string=='\0';
}
int main(int argc, char **argv) {
    stack_s *my_stack=stack_create();
    if(argc==1 || strcmp(argv[1],"-help")==0) {
      printf("%s: usage\n",argv[0]);
      printf("\t%s <cmd1> <cmd2> <cmd3> ...\n",argv[0]);
      printf("\twhere <cmdx> in :\n");
      printf("\t\tp      : means print the top of stack\n");
      printf("\t\tnumber : (e.g -3) means push number in the stack\n");
      printf("\t\tr      : means pop (remove) the top of stack\n");
      printf("\ttry\n");
      printf("\t\t%s 4 5 p 6 6 7 p r p r p 1 2 p r r r r p r\n",argv[0]);
      printf("\n");
      return 0;
    }	
    printf("stack_create -> ");
    stack_print(my_stack);
    printf("\n");
    for (int i=1;i<argc;i++) {
      if(strcmp(argv[i],"p")==0) {
	printf("stack_peek   -> %d\n",stack_peek(my_stack));
      } else if(strcmp(argv[i],"r")==0) {
	printf("stack_pop   ");
	my_stack=stack_pop(my_stack);
	printf(" -> ");
	stack_print(my_stack);
	printf("\n");
      } else if(is_number(argv[i])) {
	int v=atoi(argv[i]);
	printf("stack_push %d",v);
	my_stack=stack_push(v,my_stack);
	printf(" -> ");
	stack_print(my_stack);
	printf("\n");
      } else {
	printf("Operation '%s' is undefined. Try -help.\n",argv[i]);
	return 1;
      }
    }
    stack_delete(my_stack);
    printf("stack_delete\n");
    return 0;
}

