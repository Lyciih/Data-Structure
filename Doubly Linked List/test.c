#include<stdio.h>
#include "dllSpec.h"

typedef struct test{
	dllNode_t node;
	char data;
}testNode;


testNode testNode_new()
{
	testNode new;
	new.node.prev = NULL;
	new.node.next = NULL;
	return new;
}



int printf_all_list(dllNode_t *head)
{
	printf(">>>");
	dllNode_t *current = head;
	while(current->next != NULL )
	{
		current = current->next;
		printf("%c " , ((testNode *)current)->data);
	}
	printf("end\n");
}

int printf_node_data(dllNode_t *current)
{
	printf("%c\n", ((testNode *)current)->data);
}


int main()
{
	printf("Test program begin\n");
	printf("\n");
	
	printf("1.Apply a empty list\n");
	dllNode_t *list_one = DLL_init();
	printf("\n");
	
	printf("2.Test list is empty?\n");
	DLL_isEmpty(list_one);
	printf("\n");

	printf("3.Create nodes z a b c d e f\n");	
	testNode z = testNode_new();
	z.data = 'z';
	testNode a = testNode_new();
	a.data = 'a';
	testNode b = testNode_new();
	b.data = 'b';
	testNode c = testNode_new();
	c.data = 'c';
	testNode d = testNode_new();
	d.data = 'd';
	testNode e = testNode_new();
	e.data = 'e';
	testNode f = testNode_new();
	f.data = 'f';
	printf("\n");


	printf("4.Test DLL_get_tail when list_one is empty\n");
	dllNode_t *tail = DLL_get_tail(list_one);
	printf("\n");

	printf("5.Use DLL_add_first insert z as first node of list_one\n");
	DLL_add_first((dllNode_t *)&z, list_one);
	printf_all_list(list_one);
	printf("\n");

	printf("6.Use DLL_addto_next insert a after z\n");
        DLL_addto_next((dllNode_t *)&a, (dllNode_t *)&z);
	printf_all_list(list_one);
	printf("\n");

	printf("7.Use DLL_addto_next insert b after a\n");
	DLL_addto_next((dllNode_t *)&b, (dllNode_t *)&a);
	printf_all_list(list_one);
	printf("\n");

	printf("8.Use DLL_addto_next insert c after a\n");
	DLL_addto_next((dllNode_t *)&c, (dllNode_t *)&a);
	printf_all_list(list_one);
	printf("\n");
	
	printf("9.Use DLL_addto_prev insert d before b\n");
	DLL_addto_prev((dllNode_t *)&d, (dllNode_t *)&b);
	printf_all_list(list_one);
	printf("\n");
	
	printf("10.Use DLL_addto_prev insert d before head of list_one\n");
	DLL_addto_prev((dllNode_t *)&d, list_one);
	printf_all_list(list_one);
	printf("\n");
	
	printf("11.Use DLL_add_first insert e as first of list_one\n");
	DLL_add_first((dllNode_t *)&e, list_one);
	printf_all_list(list_one);
	printf("\n");
	
	printf("12.Test DLL_get_tail  when list_one not empty\n");
	tail = DLL_get_tail(list_one);
	printf(">>>The tail is %c\n", ((testNode *)tail)->data);
	printf_all_list(list_one);
	printf("\n");
	
	printf("13.Using DLL_add_tail insert f as tail of list_one\n");
	DLL_add_tail((dllNode_t *)&f, list_one);
	printf_all_list(list_one);
	printf("\n");

	printf("14.Print data for each node in list_one\n");
	printf_all_list(list_one);
	printf("\n");

	printf("15.Use DLL_num_nodes to calculate how many nodes are in list_one\n");
	DLL_num_nodes(list_one);
	printf("\n");
	
	printf("16.get the previous node of c with DLL_prev_node\n");
	printf(">>>The previous node of c is ");
	printf_node_data(DLL_prev_node((dllNode_t *)&c));
	printf_all_list(list_one);
	printf("\n");
	
	printf("17.Get the next node of c with DLL_next_node\n");
	printf(">>>The next node of c is ");
	printf_node_data(DLL_next_node((dllNode_t *)&c));
	printf_all_list(list_one);
	printf("\n");

	printf("18. Use DLL_delete remove c from list_one\n");
	DLL_delete((dllNode_t *)&c);
	printf_all_list(list_one);
	printf("\n");
	
	printf("19.Use DLL_delete remove f from list_one\n");
	DLL_delete((dllNode_t *)&f);
	printf_all_list(list_one);
	printf("\n");
	
	printf("20.Create list_two\n");
	dllNode_t *list_two = DLL_init();
	printf("\n");
	
	printf("21.Create nodes g h i j k l m\n");	
	testNode g = testNode_new();
	g.data = 'g';
	testNode h = testNode_new();
	h.data = 'h';
	testNode i = testNode_new();
	i.data = 'i';
	testNode j = testNode_new();
	j.data = 'j';
	testNode k = testNode_new();
	k.data = 'k';
	testNode l = testNode_new();
	l.data = 'l';
	testNode m = testNode_new();
	m.data = 'm';

	DLL_add_tail((dllNode_t *)&g, list_two);
	DLL_add_tail((dllNode_t *)&h, list_two);
	DLL_add_tail((dllNode_t *)&i, list_two);
	DLL_add_tail((dllNode_t *)&j, list_two);
	DLL_add_tail((dllNode_t *)&k, list_two);
	DLL_add_tail((dllNode_t *)&l, list_two);
	DLL_add_tail((dllNode_t *)&m, list_two);

	printf_all_list(list_two);
	printf("\n");

	printf("22.Use DLL_concate Concatenate list_two after list_one\n");
	DLL_concate(list_two, list_one);
	printf_all_list(list_one);
	printf("\n");
	
	printf("23.Use DLL_num_nodes to calculate how many nodes there are now in list_one\n");
	DLL_num_nodes(list_one);
	printf("\n");
}
