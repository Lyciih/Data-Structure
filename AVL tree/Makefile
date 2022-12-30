CFLAG = -I include -Wall

OBJ = \
	obj/AVL.o \
	obj/AVL_printf_tree.o \
	obj/AVL_insert.o \
	obj/AVL_find.o \
	obj/AVL_delete.o \

all : test

test : test.c AVL_tree.a  
	gcc $(CFLAG) -o test $^

%.a : $(OBJ)
	ar -rcs AVL_tree.a $^


obj/%.o : src/%.c
	gcc $(CFLAG) -c -o $@ $<


.PHONY : clean run

run :
	./test

clean : 
	rm -f test obj/*.o  AVL_tree.a
