

all: test

test: test.c dllSpec.h double_link_list.c
	gcc test.c dllSpec.h double_link_list.c -o test

.PHONY: clean run
clean:
	rm test 

run:
	./test
