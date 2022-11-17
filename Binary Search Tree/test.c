#include"bstSpec.h"


//測試用的結構
typedef struct test_tree_node{
	char data;
	btreeNode_t node;
}test_tree_node;


int compare_int(btreeNode_t * insert_element, btreeNode_t * in_tree_element)
{
	if(atoi(&(return_to_user_struct_pointer(test_tree_node, node, insert_element)->data)) < atoi(&(return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data))){return -1;}
	if(atoi(&(return_to_user_struct_pointer(test_tree_node, node, insert_element)->data)) > atoi(&(return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data))){return 1;}
	if(atoi(&(return_to_user_struct_pointer(test_tree_node, node, insert_element)->data)) == atoi(&(return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data))){return 2;}
	return 0;
}

int compare_key(int key, btreeNode_t * in_tree_element)
{
	if(key < atoi(&(return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data))){return -1;}
	if(key > atoi(&(return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data))){return 1;}
	if(key == atoi(&(return_to_user_struct_pointer(test_tree_node, node, in_tree_element)->data))){return 2;}
	return 0;
}

void printf_tree(btreeNode_t * root)
{
	if(root != NULL)
	{
		printf(" %c\n", return_to_user_struct_pointer(test_tree_node, node, root)->data);
	}

	if(root->left != NULL)
	{
		printf("%c  ", return_to_user_struct_pointer(test_tree_node, node, root->left)->data);
	}
	else
	{
		printf(".  ");
	}

	if(root->right != NULL)
	{
		printf("%c  ", return_to_user_struct_pointer(test_tree_node, node, root->right)->data);
	}
	else
	{
		printf(".");
	}
}



int main()
{
	 
	btreeNode_t * tree_one = NULL;
	btreeNode_t * test = NULL;

	test_tree_node root;
	Bst_init(&root.node);	
	root.data = '7';

	test_tree_node a;
	Bst_init(&a.node);
	a.data = '3';

	test_tree_node b;
	Bst_init(&b.node);
	b.data = '2';

	test_tree_node c;
	Bst_init(&c.node);
	c.data = '8';

	test_tree_node d;
	Bst_init(&d.node);
	d.data = '4';
	
	printf("%c\n", root.data);

	printf("%c\n", a.data);

	printf("%c\n", b.data);


	insertNode(&root.node, &tree_one, compare_int);
	insertNode(&a.node, &tree_one, compare_int);
	insertNode(&b.node, &tree_one, compare_int);
	insertNode(&c.node, &tree_one, compare_int);
	insertNode(&d.node, &tree_one, compare_int);

	printf_tree(tree_one);
	printf("\n");
	printf_tree(&a.node);
	printf("\n");

	test = findNode(2, tree_one, compare_key);

	if(test != NULL)
	{
		printf("%c\n", return_to_user_struct_pointer(test_tree_node, node, test)->data);
	}

	test = findNode(7, tree_one, compare_key);

	if(test != NULL)
	{
		printf("%c\n", return_to_user_struct_pointer(test_tree_node, node, test)->data);
	}

	test = findNode(3, tree_one, compare_key);

	if(test != NULL)
	{
		printf("%c\n", return_to_user_struct_pointer(test_tree_node, node, test)->data);
	}

	test = findNode(8, tree_one, compare_key);

	if(test != NULL)
	{
		printf("%c\n", return_to_user_struct_pointer(test_tree_node, node, test)->data);
	}

	delete_node(&a.node, &tree_one, compare_int);
	printf_tree(tree_one);
	printf("\n");

	delete_node(&root.node, &tree_one, compare_int);
	printf_tree(tree_one);
	printf("\n");

	delete_node(&c.node, &tree_one, compare_int);
	printf_tree(tree_one);
	printf("\n");

	printf_tree(&b.node);
	printf("\n");

}
