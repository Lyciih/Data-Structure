
SRCS_C =\
	src/pq.c\
	src/pq_printf_tree.c\


OBJS = $(SRCS_C:.c=.o)




all:test

test : test.c priority_queue.a
	gcc -I include -Wall -o test $^

%.a : $(OBJS)
	ar -rcs priority_queue.a $^


src/%.o : src/%.c
	gcc -c -I include -Wall -o $@ $^


.PHONY : clean run

clean :
	rm -rf test src/*.o *.a

run :
	./test
