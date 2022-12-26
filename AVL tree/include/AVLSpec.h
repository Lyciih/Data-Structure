#ifndef AVLSPEC_H_INCLUDE
#define AVLSPEC_H_INCLUDE

#include<stdio.h>
#include<string.h>


typedef struct avl_node {
    struct avl_node *left;
    struct avl_node *right;
    int height;
} avl_node_t;




void AVL_insert(avl_node_t * element, avl_node_t ** root, int (*compare)(void * elementA, void * elementB));

void AVL_delete(avl_node_t * element, avl_node_t * root, int (*compare)(void * elementA, void * elementB));

avl_node_t * AVL_find(avl_node_t * root, int (*compare)(void * elementA, void * elementB));

int count_AVL_tree_level(avl_node_t * root);

void printf_AVL_tree(avl_node_t * root,  int(*get_data)(avl_node_t * queue_member));

//-------  巨集  -------//

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define return_to_user_struct_pointer(USER_STRUCT, MEMBER_NAME, MEMBER_POINT)  ((USER_STRUCT *)((size_t)MEMBER_POINT - offsetof(USER_STRUCT, MEMBER_NAME)))

#endif