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
    else{return 2;}
}

int compare_key(int key, void * in_tree_element)
{
    if(key < return_to_user_struct_pointer(test_avl_t, node, in_tree_element)->value){return -1;}
    else if(key == return_to_user_struct_pointer(test_avl_t, node, in_tree_element)->value){return 0;}
    else{return 1;}
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

    avl_node_t * avl_root_a = NULL;


    test_avl_t a={
        .name = 'A',
        .value = 20,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t b={
        .name = 'B',
        .value = 4,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t c={
        .name = 'C',
        .value = 26,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t d={
        .name = 'D',
        .value = 3,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t e={
        .name = 'E',
        .value = 9,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t f={
        .name = 'F',
        .value = 21,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t g={
        .name = 'G',
        .value = 30,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t h={
        .name = 'H',
        .value = 2,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t i={
        .name = 'I',
        .value = 7,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t j={
        .name = 'J',
        .value = 11,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t k={
        .name = 'K',
        .value = 15,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };

    test_avl_t l={
        .name = 'L',
        .value = 8,
        .node.height = 0,
        .node.left = NULL,
        .node.right = NULL
    };   

    printf("\n--------------------------------------");
    printf("\ncase a");
    printf("\n--------------------------------------");
    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    AVL_init(&a.node);
    AVL_init(&b.node);
    avl_root_a = NULL;

    printf("\n----- case a insert 15 -----\n");
    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&k.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&k.node);
    avl_root_a = NULL;


    printf("\n----- case a insert 8 -----\n");
    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&l.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);
    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&l.node);
    avl_root_a = NULL;



    printf("\n--------------------------------------");
    printf("\ncase b");
    printf("\n--------------------------------------");

    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);    
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&c.node);
    AVL_init(&d.node);
    AVL_init(&e.node);
    avl_root_a = NULL;

    printf("\n----- case b insert 15 -----\n");

    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);    
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    AVL_insert(&k.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);
    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&c.node);
    AVL_init(&d.node);
    AVL_init(&e.node);
    AVL_init(&k.node);
    avl_root_a = NULL;

    printf("\n----- case b insert 8 -----\n");

    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);    
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    AVL_insert(&l.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&c.node);
    AVL_init(&d.node);
    AVL_init(&e.node);
    AVL_init(&l.node);
    avl_root_a = NULL;

    printf("\n--------------------------------------");
    printf("\ncase c");
    printf("\n--------------------------------------");

    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);    
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    AVL_insert(&f.node, &avl_root_a, compare_value);   
    AVL_insert(&g.node, &avl_root_a, compare_value);
    AVL_insert(&h.node, &avl_root_a, compare_value);
    AVL_insert(&i.node, &avl_root_a, compare_value);
    AVL_insert(&j.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&c.node);
    AVL_init(&d.node);
    AVL_init(&e.node);
    AVL_init(&f.node);
    AVL_init(&g.node);
    AVL_init(&h.node);
    AVL_init(&i.node);
    AVL_init(&j.node);
    avl_root_a = NULL;

    printf("\n----- case c insert 15 -----\n");


    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);    
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    AVL_insert(&f.node, &avl_root_a, compare_value);   
    AVL_insert(&g.node, &avl_root_a, compare_value);
    AVL_insert(&h.node, &avl_root_a, compare_value);
    AVL_insert(&i.node, &avl_root_a, compare_value);
    AVL_insert(&j.node, &avl_root_a, compare_value);
    AVL_insert(&k.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&c.node);
    AVL_init(&d.node);
    AVL_init(&e.node);
    AVL_init(&f.node);
    AVL_init(&g.node);
    AVL_init(&h.node);
    AVL_init(&i.node);
    AVL_init(&j.node);
    AVL_init(&k.node);
    avl_root_a = NULL;

    printf("\n----- case c insert 8 -----\n");


    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);    
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    AVL_insert(&f.node, &avl_root_a, compare_value);   
    AVL_insert(&g.node, &avl_root_a, compare_value);
    AVL_insert(&h.node, &avl_root_a, compare_value);
    AVL_insert(&i.node, &avl_root_a, compare_value);
    AVL_insert(&j.node, &avl_root_a, compare_value);
    AVL_insert(&l.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value);

    printf("\n");

    avl_node_t * found = AVL_find(8, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(7, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(11, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(26, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(21, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(30, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(2, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);

    found = AVL_find(20, &avl_root_a, compare_key);
    printf("%d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value);






}