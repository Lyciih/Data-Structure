#include"AVLSpec.h"


typedef struct test_avl{
    char name;
    int value;
    avl_node_t node;
}test_avl_t;

int compare_value(void * elementA, void * elementB)
{
    if(return_to_user_struct_pointer(test_avl_t, node, elementA)->value < return_to_user_struct_pointer(test_avl_t, node, elementB)->value){return -1;}
    else if(return_to_user_struct_pointer(test_avl_t, node, elementA)->value == return_to_user_struct_pointer(test_avl_t, node, elementB)->value){return 0;}
    else if(return_to_user_struct_pointer(test_avl_t, node, elementA)->value > return_to_user_struct_pointer(test_avl_t, node, elementB)->value){return 1;}
    else{return 0;}
}

int get_value(avl_node_t * element)
{
    return return_to_user_struct_pointer(test_avl_t, node, element)->value;
}

int get_height(avl_node_t * element)
{
    return element->height;
}


int main(){

    avl_node_t * avl_root_one = NULL;

    test_avl_t a={
        .name = 'A',
        .value = 90,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t b={
        .name = 'B',
        .value = 80,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t c={
        .name = 'C',
        .value = 70,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t d={
        .name = 'D',
        .value = 60,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t e={
        .name = 'E',
        .value = 65,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t f={
        .name = 'F',
        .value = 67,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    printf("insert a\n");
    AVL_insert(&a.node, &avl_root_one, compare_value);
    printf("insert b\n");
    AVL_insert(&b.node, &avl_root_one, compare_value);
    printf("insert c\n");
    AVL_insert(&c.node, &avl_root_one, compare_value);
    printf("insert d\n");
    AVL_insert(&d.node, &avl_root_one, compare_value);
    printf("insert e\n");
    AVL_insert(&e.node, &avl_root_one, compare_value);
    printf("insert f\n");
    AVL_insert(&f.node, &avl_root_one, compare_value);

    printf_AVL_tree(avl_root_one,  get_value);

}