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
	printf("測試程式開始\n");
	printf("\n");
	
	printf("1.申請一個空list\n");
	dllNode_t *list_one = DLL_init();
	printf("\n");
	
	printf("2.測試是否為空\n");
	DLL_isEmpty(list_one);
	printf("\n");

	printf("3.產生測試節點 z a b c d e f\n");	
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


	printf("4.測試 DLL_get_tail 在list_one為空時的結果\n");
	dllNode_t *tail = DLL_get_tail(list_one);
	printf("\n");

	printf("5.將z節點用 DLL_add_first 插入為list_one的第一個\n");
	DLL_add_first((dllNode_t *)&z, list_one);
	printf_all_list(list_one);
	printf("\n");

	printf("6.將a節點用 DLL_addto_next 插入到z節點之後\n");
        DLL_addto_next((dllNode_t *)&a, (dllNode_t *)&z);
	printf_all_list(list_one);
	printf("\n");

	printf("7.將b節點用 DLL_addto_next 插入到a節點之後\n");
	DLL_addto_next((dllNode_t *)&b, (dllNode_t *)&a);
	printf_all_list(list_one);
	printf("\n");

	printf("8.將c節點用 DLL_addto_next 插入到a節點之後\n");
	DLL_addto_next((dllNode_t *)&c, (dllNode_t *)&a);
	printf_all_list(list_one);
	printf("\n");
	
	printf("9.將d節點用 DLL_addto_prev 插入到b節點之前\n");
	DLL_addto_prev((dllNode_t *)&d, (dllNode_t *)&b);
	printf_all_list(list_one);
	printf("\n");
	
	printf("10.將d節點用 DLL_addto_prev 插入到list_one的head之前\n");
	DLL_addto_prev((dllNode_t *)&d, list_one);
	printf_all_list(list_one);
	printf("\n");
	
	printf("11.將e節點用 DLL_add_first 插入為list_one的第一個\n");
	DLL_add_first((dllNode_t *)&e, list_one);
	printf_all_list(list_one);
	printf("\n");
	
	printf("12.測試DLL_get_tail在list_one不為空的結果\n");
	tail = DLL_get_tail(list_one);
	printf(">>>尾巴是%c\n", ((testNode *)tail)->data);
	printf_all_list(list_one);
	printf("\n");
	
	printf("13.將f節點用 DLL_add_tail 插入為list_one的最後一個\n");
	DLL_add_tail((dllNode_t *)&f, list_one);
	printf_all_list(list_one);
	printf("\n");

	printf("14.列印最後結果的所有data\n");
	printf_all_list(list_one);
	printf("\n");

	printf("15.用 DLL_num_nodes 計算list_one中有幾個node\n");
	DLL_num_nodes(list_one);
	printf("\n");
	
	printf("16.用 DLL_prev_node 取得 c 的前一個node\n");
	printf(">>>c的前一個node是 ");
	printf_node_data(DLL_prev_node((dllNode_t *)&c));
	printf_all_list(list_one);
	printf("\n");
	
	printf("17.用 DLL_next_node 取得 c 的後一個node\n");
	printf(">>>c的後一個node是 ");
	printf_node_data(DLL_next_node((dllNode_t *)&c));
	printf_all_list(list_one);
	printf("\n");

	printf("18.用 DLL_delete 將 c 從list_one中刪除\n");
	DLL_delete((dllNode_t *)&c);
	printf_all_list(list_one);
	printf("\n");
	
	printf("19.用 DLL_delete 將 f 從list_one中刪除\n");
	DLL_delete((dllNode_t *)&f);
	printf_all_list(list_one);
	printf("\n");
	
	printf("20.建立list_two\n");
	dllNode_t *list_two = DLL_init();
	printf("\n");
	
	printf("21.產生測試節點 g h i j k l m\n");	
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

	printf("22.用 DLL_concate 將 list_two 串在 list_one 之後\n");
	DLL_concate(list_two, list_one);
	printf_all_list(list_one);
	printf("\n");
	
	printf("23.用 DLL_num_nodes 計算現在list_one中有幾個node\n");
	DLL_num_nodes(list_one);
	printf("\n");
}
