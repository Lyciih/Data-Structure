CFLAG = -I include -Wall


SRCS_C = \
	src/bst.c \
	src/bst_delete.c\
	src/bst_find.c\
	src/bst_insert.c\
	src/printf_tree.c\

	
TEST_C = \
	test.c \

OBJS = $(SRCS_C:.c=.o)
TEST = $(TEST_C:.c=.o)



all: test

test: test.c  binary_search_tree.a
	gcc $(CFLAG) -o test $^ 



%.a : $(OBJS)
	ar -rcs binary_search_tree.a  $^ 


src/%.o : src/%.c
	gcc  -I include -c -o $@ $< 


.PHONY: clean run

clean:
	rm -f *.exe *.a *.out *.elf src/*.o

run:
	./test