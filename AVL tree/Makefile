CFLAG = -I include -Wall

OBJ = \
	obj/AVL.o \
	obj/AVL_printf_tree.o \
	obj/AVL_insert.o \
	obj/AVL_find.o \
	obj/AVL_delete.o \

all : test

test : test.c $(OBJ)
	gcc $(CFLAG) -o $@ $^

obj/%.o : src/%.c
	gcc $(CFLAG) -c -o $@ $<


.PHONY : clean run

run :
	./test

clean : 
	rm -rf test obj/*.o