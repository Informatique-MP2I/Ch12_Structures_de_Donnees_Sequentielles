SRC := Grimaud_queue
LIB := queue
CFLAGS := -Wall -O2

.PHONY: clean all

all: queue_array queue_linked_list queue_array_resizable queue_linked_list_2

queue_array: $(SRC).c queue_array.o $(LIB).h
	gcc $(CFLAGS) -o $@ $< queue_array.o 

queue_array.o: queue_array.c $(LIB).h
	gcc -c $< -o $@

queue_linked_list: $(SRC).c queue_linked_list.o $(LIB).h
	gcc $(CFLAGS) -o $@ $< queue_linked_list.o

queue_linked_list.o: queue_linked_list.c $(LIB).h
	gcc -c $< -o $@

queue_linked_list_2: $(SRC).c queue_linked_list_2.o $(LIB).h
	gcc $(CFLAGS) -o $@ $< queue_linked_list_2.o

queue_linked_list_2.o: queue_linked_list_2.c $(LIB).h
	gcc -c $< -o $@

queue_array_resizable: $(SRC).c queue_array_resizable.o $(LIB).h
	gcc $(CFLAGS) -o $@ $< queue_array_resizable.o 

queue_array_resizable.o: queue_array_resizable.c $(LIB).h
	gcc -c $< -o $@

clean:
	- rm queue_array.o queue_linked_list.o queue_array_resizable.o
	- rm queue_linked_list_2.o
	- rm queue_array queue_linked_list queue_array_resizable
	- rm queue_linked_list_2
