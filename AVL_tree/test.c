#include"AVLSpec.h"


typedef struct test_avl{
    char name;
    int value;
    avl_node_t node;
}test_avl_t;

int compare_value(void* elementA, void* elementB)
{
    if(return_to_user_struct_pointer(test_avl_t, node, elementA)->value < return_to_user_struct_pointer(test_avl_t, node, elementB)->value){return -1;}
    else if(return_to_user_struct_pointer(test_avl_t, node, elementA)->value == return_to_user_struct_pointer(test_avl_t, node, elementB)->value){return 0;}
    else if(return_to_user_struct_pointer(test_avl_t, node, elementA)->value > return_to_user_struct_pointer(test_avl_t, node, elementB)->value){return 1;}
    else{return 2;}
}

int compare_key(int key, void* in_tree_element)
{
    if(key < return_to_user_struct_pointer(test_avl_t, node, in_tree_element)->value){return -1;}
    else if(key == return_to_user_struct_pointer(test_avl_t, node, in_tree_element)->value){return 0;}
    else{return 1;}
}

int get_value(avl_node_t* element)
{
    return return_to_user_struct_pointer(test_avl_t, node, element)->value;
}

int get_name(avl_node_t* element)
{
    return return_to_user_struct_pointer(test_avl_t, node, element)->name;
}

int get_height(avl_node_t* element)
{
    return element->height;
}


int main(){

	// 初始化一個 AVL 樹
    avl_node_t* avl_root_a = NULL;


	// 初始化各節點
    test_avl_t a;
    a.name = 'A';
    a.value = 20;
    AVL_init(&a.node);

    test_avl_t b;
    b.name = 'B';
    b.value = 4;
    AVL_init(&b.node);

    test_avl_t c;
    c.name = 'C';
    c.value = 26;
    AVL_init(&c.node);

    test_avl_t d;
    d.name = 'D';
    d.value = 3;
    AVL_init(&d.node);

    test_avl_t e;
    e.name = 'E';
    e.value = 9;
    AVL_init(&e.node);

    test_avl_t f;
    f.name = 'F';
    f.value = 21;
    AVL_init(&f.node);

    test_avl_t g;
    g.name = 'G';
    g.value = 30;
    AVL_init(&g.node);

    test_avl_t h;
    h.name = 'H';
    h.value = 2;
    AVL_init(&h.node);

    test_avl_t i;
    i.name = 'I';
    i.value = 7;
    AVL_init(&i.node);

    test_avl_t j;
    j.name = 'J';
    j.value = 11;
    AVL_init(&j.node);

    test_avl_t k;
    k.name = 'K';
    k.value = 15;
    AVL_init(&k.node);

    test_avl_t l;
    l.name = 'L';
    l.value = 8;
    AVL_init(&l.node);

    
	// 各種示範操作

    printf("\n--------------------------------------");
    printf("\ncase a");
    printf("\n--------------------------------------");
    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value, 0);

    AVL_init(&a.node);
    AVL_init(&b.node);
    avl_root_a = NULL;

    printf("\n----- case a insert 15 -----\n");
    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&k.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value, 0);

    AVL_init(&a.node);
    AVL_init(&b.node);
    AVL_init(&k.node);
    avl_root_a = NULL;


    printf("\n----- case a insert 8 -----\n");
    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&l.node, &avl_root_a, compare_value);
    printf_AVL_tree(avl_root_a,  get_value, 0);
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
    printf_AVL_tree(avl_root_a,  get_value, 0);

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
    printf_AVL_tree(avl_root_a,  get_value, 0);
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
    printf_AVL_tree(avl_root_a,  get_value, 0);

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
    printf_AVL_tree(avl_root_a,  get_value, 0);

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
    printf_AVL_tree(avl_root_a,  get_value, 0);

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
    printf_AVL_tree(avl_root_a,  get_value, 0);

    printf("\n");
    
    printf_AVL_tree(avl_root_a,  get_name, 1);

    printf("\n");

    avl_node_t * found = AVL_find(8, &avl_root_a, compare_key);
    printf("who's value is 8 ? : %c\n", return_to_user_struct_pointer(test_avl_t, node, found)->name);
    
    found = AVL_find_minimum(avl_root_a);
    printf("who's value is minimum ? : %c\n", return_to_user_struct_pointer(test_avl_t, node, found)->name);

    found = AVL_find_maximum(avl_root_a);
    printf("who's value is maximum ? : %c\n", return_to_user_struct_pointer(test_avl_t, node, found)->name);
    
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(8, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(7, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(11, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(26, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(21, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(30, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(2, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");

    found = AVL_find(20, &avl_root_a, compare_key);
    printf("delete %d\n", return_to_user_struct_pointer(test_avl_t, node, found)->value);
    AVL_delete(found, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);
    printf("\n");
    printf("--------------------------------\n");
    printf("home work example\n");
    printf("90 80 70 60 65 67\n");
    printf("--------------------------------\n");

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

    a.value = 90;
    b.value = 80;
    c.value = 70;
    d.value = 60;
    e.value = 65;
    f.value = 67;

    AVL_insert(&a.node, &avl_root_a, compare_value);
    AVL_insert(&b.node, &avl_root_a, compare_value);
    AVL_insert(&c.node, &avl_root_a, compare_value);
    AVL_insert(&d.node, &avl_root_a, compare_value);
    AVL_insert(&e.node, &avl_root_a, compare_value);
    AVL_insert(&f.node, &avl_root_a, compare_value);

    printf_AVL_tree(avl_root_a, get_value, 0);

}
