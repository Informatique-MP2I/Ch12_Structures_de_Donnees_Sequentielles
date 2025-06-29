# Makefile - OCaml structures
SRC := Grimaud_stack_array
MOD := StackArray
EXE := stack_array

#SRC := Grimaud_stack_linked_list
#MOD := StackLinkedList
#EXE := stack_linked_list

.PHONY: clean

$(EXE): $(SRC).ml $(MOD).cmi $(MOD).cmx 
	ocamlopt -o $@ $(MOD).cmx $<

# Compiles the module, generates $(MOD).cmx
$(MOD).cmx: $(MOD).ml $(MOD).cmi 
	ocamlopt -c $<

# Compiles the interface, generates $(MOD).cmi
$(MOD).cmi: $(MOD).mli
	ocamlopt -c $<

clean:
	rm *.cmi *.o *.cmx $(EXE) *~
