#include"bstSpec.h"
#include<string.h>


//測試用的結構
typedef struct test_tree_node{
	char data;
	char *name;
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

int compare_Equal(btreeNode_t * node_a, btreeNode_t * node_b)
{
	if(atoi(&(return_to_user_struct_pointer(test_tree_node, node, node_a)->data)) == atoi(&(return_to_user_struct_pointer(test_tree_node, node, node_b)->data)))
	{
		if(strcmp(return_to_user_struct_pointer(test_tree_node, node, node_a)->name, return_to_user_struct_pointer(test_tree_node, node, node_b)->name) == 0)
		{
			return 1;
		}
	}
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

void print_data(btreeNode_t * root)
{
	printf("%c ", return_to_user_struct_pointer(test_tree_node, node, root)->data);
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
	root.data = '7';
	root.name = "David";
	printf("%s %c\n",root.name, root.data);


	printf("create node : ");
	test_tree_node a;
	Bst_init(&a.node);
	a.data = '3';
	a.name = "Kent";
	printf("%s %c\n",a.name, a.data);

	printf("create node : ");
	test_tree_node b;
	Bst_init(&b.node);
	b.data = '2';
	b.name = "John";
	printf("%s %c\n",b.name, b.data);

	printf("create node : ");
	test_tree_node c;
	Bst_init(&c.node);
	c.data = '8';
	c.name = "Alice";
	printf("%s %c\n",c.name, c.data);

	printf("create node : ");
	test_tree_node d;
	Bst_init(&d.node);
	d.data = '4';
	d.name = "Alisa";
	printf("%s %c\n",d.name, d.data);
	

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
	

	printf("print tree_one : root, root->left, root->right : \n");
	printf_tree(tree_one);
	printf("\n");
	printf("print a, a->left, a->right : \n");
	printf_tree(&a.node);
	printf("\n");

	printf("print tree_one inorder : ");
	inOrder(tree_one, print_data);
	printf("\n");

	printf("\n");

	printf("copy tree_one to tree_two\n");
	btreeNode_t * tree_two = treeCopy(tree_one, copy_test_node);

	printf("print tree_two : root, root->left, root->right : \n");	
	printf_tree(tree_two);
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

	printf("print tree_one : root, root->left, root->right : \n");
	printf_tree(tree_one);
	printf("\n");

	printf("delete a(3) in tree_one : \n");
	deleteNode(&a.node, &tree_one, compare_int);
	printf_tree(tree_one);
	printf("\n");

	printf("delete root(7) in tree_one : \n");
	deleteNode(&root.node, &tree_one, compare_int);
	printf_tree(tree_one);
	printf("\n");

	printf("delete c(8) in tree_one : \n");
	deleteNode(&c.node, &tree_one, compare_int);
	printf_tree(tree_one);
	printf("\n");

	printf("print b(2), b->left, b->right : \n");
	printf_tree(&b.node);
	printf("\n");

	printf("print tree_one inorder : ");
	inOrder(tree_one, print_data);
	printf("\n");

	printf("\nis tree_one and tree_two Equal? (1:ture 0:false): ");
	printf("%d\n", treeEqual(tree_one, tree_two, compare_Equal));

}
