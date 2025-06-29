# Makefile - stack
SRC := Nom_stack
LIB := stack
CFLAGS := -Wall -O2

.PHONY: clean all

all: stack_array stack_linked_list

stack_array: $(SRC).c stack_array.o $(LIB).h
	gcc $(CFLAGS) -o $@ $(SRC).c stack_array.o 

stack_array.o: stack_array.c $(LIB).h
	gcc -c $< -o $@

stack_linked_list: $(SRC).c stack_linked_list.o $(LIB).h
	gcc $(CFLAGS) -o $@ $(SRC).c stack_linked_list.o

stack_linked_list.o: stack_linked_list.c $(LIB).h
	gcc -c $< -o $@

clean:
	- rm stack_array.o stack_linked_list.o
	- rm stack_array stack_linked_list
