CFLAG = -I include -Wall

OBJ = \
	obj/AVL.o \
	obj/AVL_printf_tree.o \
	obj/AVL_insert.o \
	obj/AVL_find.o \
	obj/AVL_delete.o \

all : check lib test

# 檢查需要的路徑是否存在
check:
	$(shell mkdir -p obj)

# 編譯靜態庫
lib: $(OBJ)
	ar -rcs AVL_tree.a $^


# 編譯測試程式
test : test.c AVL_tree.a  
	gcc $(CFLAG) -o $@ $^


# 編譯.o檔
obj/%.o : src/%.c
	gcc $(CFLAG) -c -o $@ $<


.PHONY : clean run

run :
	./test

clean : 
	rm -f test test.exe obj/*.o  AVL_tree.a
