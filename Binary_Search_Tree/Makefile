CFLAG = -I include -Wall


SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=obj/%.o)



all: check lib test

check:
	$(shell mkdir -p obj)
	$(shell mkdir -p bin)

lib: $(OBJS)
	ar -rcs binary_search_tree.a  $^ 



test: test.c  binary_search_tree.a
	gcc $(CFLAG) -o ./bin/test $^ 


obj/%.o : src/%.c
	gcc  -I include -c -o $@ $< 


.PHONY: clean run

clean:
	rm -f ./bin/test.exe ./bin/test obj/*.o binary_search_tree.a

run:
	./bin/test
