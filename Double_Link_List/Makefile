
SRCS = $(wildcard src/*.c)	
OBJS = $(SRCS:src/%.c=obj/%.o)


all: check lib test

check:
	$(shell mkdir -p obj)
	$(shell mkdir -p bin)

lib: $(OBJS)
	ar -rcs libdouble_linked_list.a  $^ 


test: test.c libdouble_linked_list.a
	gcc -I include -Wall -o ./bin/test $^ 


obj/%.o : src/%.c 
	gcc -c -I include -Wall -o $@ $^ 

.PHONY: clean run
clean:
	rm -f ./bin/test ./bin/test.exe ./obj/*.o *.a

run:
	./bin/test
