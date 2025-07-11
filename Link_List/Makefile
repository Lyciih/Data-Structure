
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=obj/%.o)

CFLAG = -I include -Wall


all: check lib test

check:
	$(shell mkdir -p obj)
	$(shell mkdir -p bin)

lib: $(OBJS)
	ar -rcs liblinked_list.a  $^ 


test: test.c liblinked_list.a 
	gcc $(CFLAG) -o ./bin/test $^ 


obj/%.o : src/%.c 
	gcc -c -o $@ $< $(CFLAG)

.PHONY: clean run
clean:
	rm -f ./bin/test ./bin/test.exe ./obj/*.o *.a

run:
	./bin/test
