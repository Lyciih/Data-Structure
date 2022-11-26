#include"bstSpec.h"
#include<string.h>


//測試用的結構
typedef struct test_tree_node{
	int data;
	char *name;
	btreeNode_t node;
}test_tree_node;


int compare_int(btreeNode_t * insert_element, btreeNode_t * in_tree_element)
{
	if(return_to_user_struct_pointer(test_tree_node, node, insert_element)->data < return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data){return -1;}
	if(return_to_user_struct_pointer(test_tree_node, node, insert_element)->data > return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data){return 1;}
	if(return_to_user_struct_pointer(test_tree_node, node, insert_element)->data == return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data){return 2;}
	return 0;
}

int compare_key(int key, btreeNode_t * in_tree_element)
{
	if(key < return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data){return -1;}
	if(key > return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data){return 1;}
	if(key == return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data){return 2;}
	return 0;
}

int compare_Equal(btreeNode_t * node_a, btreeNode_t * node_b)
{
	if(return_to_user_struct_pointer(test_tree_node, node, node_a)->data == return_to_user_struct_pointer(test_tree_node, node, node_b)->data)
	{
		if(strcmp(return_to_user_struct_pointer(test_tree_node, node, node_a)->name, return_to_user_struct_pointer(test_tree_node, node, node_b)->name) == 0)
		{
			return 1;
		}
	}
	return 0;
}



void print_data(btreeNode_t * root)
{
	printf("%d ", return_to_user_struct_pointer(test_tree_node, node, root)->data);
}

int get_data(btreeNode_t * root)
{
	return return_to_user_struct_pointer(test_tree_node, node, root)->data;
}

btreeNode_t * copy_test_node(btreeNode_t * root)
{
	test_tree_node * new_node = (test_tree_node *)malloc(sizeof(test_tree_node));
	*new_node = *return_to_user_struct_pointer(test_tree_node, node, root);
	Bst_init(&new_node->node);
	return &new_node->node;
}






int main()
{
	 
	btreeNode_t * tree_one = NULL;
	btreeNode_t * test = NULL;

	printf("create node : ");
	test_tree_node root;
	Bst_init(&root.node);	
	root.data = 7;
	root.name = "David";
	printf("%s %d\n",root.name, root.data);


	printf("create node : ");
	test_tree_node a;
	Bst_init(&a.node);
	a.data = 3;
	a.name = "Kent";
	printf("%s %d\n",a.name, a.data);

	printf("create node : ");
	test_tree_node b;
	Bst_init(&b.node);
	b.data = 2;
	b.name = "John";
	printf("%s %d\n",b.name, b.data);

	printf("create node : ");
	test_tree_node c;
	Bst_init(&c.node);
	c.data = 8;
	c.name = "Alice";
	printf("%s %d\n",c.name, c.data);

	printf("create node : ");
	test_tree_node d;
	Bst_init(&d.node);
	d.data = 4;
	d.name = "Alisa";
	printf("%s %d\n",d.name, d.data);
	

	printf("\n");
	
	printf("insert root to tree_one\n");
	insertNode(&root.node, &tree_one, compare_int);
	printf("insert a to tree_one\n");
	insertNode(&a.node, &tree_one, compare_int);
	printf("insert b to tree_one\n");
	insertNode(&b.node, &tree_one, compare_int);
	printf("insert c to tree_one\n");
	insertNode(&c.node, &tree_one, compare_int);
	printf("insert d to tree_one\n");
	insertNode(&d.node, &tree_one, compare_int);

	printf("\n");
	

	printf("print tree_one : \n");
	printf_tree(tree_one, get_data);
	printf("\n");

	printf("print tree_one inorder : ");
	inOrder(tree_one, print_data);
	printf("\n");

	printf("\n");

	printf("copy tree_one to tree_two\n");
	btreeNode_t * tree_two = treeCopy(tree_one, copy_test_node);

	printf("print tree_two : \n");	
	printf_tree(tree_two, get_data);
	printf("\n");

	printf("print tree_two inorder : ");
	inOrder(tree_two, print_data);
	printf("\n");



	printf("\nis tree_one and tree_two Equal? (1:ture 0:false): ");
	printf("%d\n", treeEqual(tree_one, tree_two, compare_Equal));


	printf("\n");


	test = findNode(2, tree_one, compare_key);
	printf("find who's ID is 2 : ");
	if(test != NULL)
	{
		printf("%s\n", return_to_user_struct_pointer(test_tree_node, node, test)->name);
	}

	test = findNode(7, tree_one, compare_key);
	printf("find who's ID is 7 : ");
	if(test != NULL)
	{
		printf("%s\n", return_to_user_struct_pointer(test_tree_node, node, test)->name);
	}

	test = findNode(3, tree_one, compare_key);
	printf("find who's ID is 3 : ");
	if(test != NULL)
	{
		printf("%s\n", return_to_user_struct_pointer(test_tree_node, node, test)->name);
	}

	test = findNode(8, tree_one, compare_key);
	printf("find who's ID is 8 : ");
	if(test != NULL)
	{
		printf("%s\n", return_to_user_struct_pointer(test_tree_node, node, test)->name);
	}

	printf("\n");

	printf("find minimum node in tree_one : ");
	printf("%d\n", return_to_user_struct_pointer(test_tree_node, node, findMinNode(tree_one))->data);
	
	printf("\n");


	printf("find maximum node in tree_one : ");
	printf("%d\n", return_to_user_struct_pointer(test_tree_node, node, findMaxNode(tree_one))->data);
	
	printf("\n");

	printf("print level order of tree_one : ");
	btreeNode_t * level_temp[10];
	for(int i = 0 ; i < 10 ; i++)
	{
		level_temp[i] = NULL;
	}

	tree_level_to_queue(tree_two, level_temp);
	for(int i = 0 ; i < 10 ; i++ )
	{
		if(level_temp[i] != NULL)
		{
			printf("%d ", return_to_user_struct_pointer(test_tree_node, node, level_temp[i])->data);
		}
	}

	printf("\n");
	
	printf("\n");

	printf("print tree_one : \n");
	printf_tree(tree_one, get_data);
	printf("\n");

	printf("delete a(3) in tree_one : \n");
	deleteNode(&a.node, &tree_one, compare_int);
	printf_tree(tree_one, get_data);
	printf("\n");

	printf("delete root(7) in tree_one : \n");
	deleteNode(&root.node, &tree_one, compare_int);
	printf_tree(tree_one, get_data);
	printf("\n");

	printf("delete c(8) in tree_one : \n");
	deleteNode(&c.node, &tree_one, compare_int);
	printf_tree(tree_one, get_data);
	printf("\n");

	printf("print tree_one inorder : ");
	inOrder(tree_one, print_data);
	printf("\n");

	printf("\nis tree_one and tree_two Equal? (1:ture 0:false): ");
	printf("%d\n", treeEqual(tree_one, tree_two, compare_Equal));
	


	test_tree_node a_test;
	Bst_init(&a_test.node);	
	a_test.data = 10;
	a_test.name = " ";

	test_tree_node b_test;
	Bst_init(&b_test.node);	
	b_test.data = 7;
	b_test.name = " ";

	test_tree_node c_test;
	Bst_init(&c_test.node);	
	c_test.data = 16;
	c_test.name = " ";

	test_tree_node d_test;
	Bst_init(&d_test.node);	
	d_test.data = 13;
	d_test.name = " ";

	test_tree_node e_test;
	Bst_init(&e_test.node);	
	e_test.data = 15;
	e_test.name = " ";

	test_tree_node f_test;
	Bst_init(&f_test.node);	
	f_test.data = 17;
	f_test.name = " ";

	test_tree_node g_test;
	Bst_init(&g_test.node);	
	g_test.data = 11;
	g_test.name = " ";

	test_tree_node h_test;
	Bst_init(&h_test.node);	
	h_test.data = 20;
	h_test.name = " ";

	test_tree_node i_test;
	Bst_init(&i_test.node);	
	i_test.data = 2;
	i_test.name = " ";

	test_tree_node j_test;
	Bst_init(&j_test.node);	
	j_test.data = 9;
	j_test.name = " ";

	test_tree_node k_test;
	Bst_init(&k_test.node);	
	k_test.data = 6;
	k_test.name = " ";

	test_tree_node l_test;
	Bst_init(&l_test.node);	
	l_test.data = 5;
	l_test.name = " ";

	test_tree_node m_test;
	Bst_init(&m_test.node);	
	m_test.data = 0;
	m_test.name = " ";

	test_tree_node n_test;
	Bst_init(&n_test.node);	
	n_test.data = 8;
	n_test.name = " ";

	test_tree_node o_test;
	Bst_init(&o_test.node);	
	o_test.data = 1;
	o_test.name = " ";

	btreeNode_t * tree_three = NULL;

	printf("\n");
	printf("insert a_test to tree_three\n");
	insertNode(&a_test.node, &tree_three, compare_int);
	printf("insert b_test to tree_three\n");
	insertNode(&b_test.node, &tree_three, compare_int);
	printf("insert c_test to tree_three\n");
	insertNode(&c_test.node, &tree_three, compare_int);
	printf("insert d_test to tree_three\n");
	insertNode(&d_test.node, &tree_three, compare_int);
	printf("insert e_test to tree_three\n");
	insertNode(&e_test.node, &tree_three, compare_int);
	printf("insert f_test to tree_three\n");
	insertNode(&f_test.node, &tree_three, compare_int);
	printf("insert g_test to tree_three\n");
	insertNode(&g_test.node, &tree_three, compare_int);
	printf("insert h_test to tree_three\n");
	insertNode(&h_test.node, &tree_three, compare_int);
	printf("insert i_test to tree_three\n");
	insertNode(&i_test.node, &tree_three, compare_int);
	printf("insert j_test to tree_three\n");
	insertNode(&j_test.node, &tree_three, compare_int);
	printf("insert k_test to tree_three\n");
	insertNode(&k_test.node, &tree_three, compare_int);
	printf("insert l_test to tree_three\n");
	insertNode(&l_test.node, &tree_three, compare_int);
	printf("insert m_test to tree_three\n");
	insertNode(&m_test.node, &tree_three, compare_int);
	printf("insert n_test to tree_three\n");
	insertNode(&n_test.node, &tree_three, compare_int);
	printf("insert o_test to tree_three\n");
	insertNode(&o_test.node, &tree_three, compare_int);
	printf("\n");

	printf("print tree_three inorder : ");
	inOrder(tree_three, print_data);
	printf("\n");

	printf("\n");
	printf("print tree_three level : ");
	printf("%d\n", count_tree_level(tree_three));
	printf("print tree_three : ");
	printf_tree(tree_three, get_data);
	printf("\n");

	printf("\n");
	printf("delete 10 in tree_three : \n");
	deleteNode(&a_test.node, &tree_three, compare_int);
	printf_tree(tree_three, get_data);
	printf("\n");

	printf("\n");
	printf("delete 7 in tree_three : \n");
	deleteNode(&b_test.node, &tree_three, compare_int);
	printf_tree(tree_three, get_data);
	printf("\n");

	printf("\n");
	printf("delete 2 in tree_three : \n");
	deleteNode(&i_test.node, &tree_three, compare_int);
	printf_tree(tree_three, get_data);
	printf("\n");

	printf("\n");
	printf("insert 17 in tree_three : \n");
	insertNode(&f_test.node, &tree_three, compare_int);
	printf_tree(tree_three, get_data);
	printf("\n");

	printf("\n");
	printf("delete 16 in tree_three : \n");
	deleteNode(&c_test.node, &tree_three, compare_int);
	printf_tree(tree_three, get_data);
	printf("\n");



}
