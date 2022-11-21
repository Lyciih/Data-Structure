CFLAG = -I include -Wall


SRCS_C = \
	bst.c \

	
TEST_C = \
	test.c \

OBJS = $(SRCS_C:.c=.o)
TEST = $(TEST_C:.c=.o)



all: test

test: test.c  binary_search_tree.a
	gcc $(CFLAG) -o test $^ 



%.a : $(OBJS)
	ar -rcs binary_search_tree.a  $^ 


%.o : src/%.c
	gcc  -I include -c -o $@ $< 


.PHONY: clean run

clean:
	rm -f *.exe *.a *.out *.elf

run:
	./test