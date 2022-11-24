#ifndef BSTSPEC_H_INCLUDED
#define BSTSPEC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node {
    struct node *left;
    struct node *right;
}btreeNode_t;

//-------  函數  -------//

void Bst_init(btreeNode_t * node);

void insertNode(btreeNode_t * insert_element, btreeNode_t ** root, int(*compare)(btreeNode_t * insert_element, btreeNode_t * in_tree_element));

void deleteNode(btreeNode_t * delete_node, btreeNode_t ** root, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element));

void inOrder(btreeNode_t * root, void(*print)(btreeNode_t * root));

btreeNode_t * findNode(int key, btreeNode_t * root, int(*compare)(int key, btreeNode_t * in_tree_element));

btreeNode_t * findMinNode(btreeNode_t * root);

btreeNode_t * findMaxNode(btreeNode_t * root);

btreeNode_t * treeCopy(btreeNode_t * root, btreeNode_t *(*copy)(btreeNode_t * root));

int treeEqual(btreeNode_t * root_A, btreeNode_t * root_B, int(*compare)(btreeNode_t * root_A, btreeNode_t * root_B));

int count_tree_level(btreeNode_t * root);

void tree_level_to_queue(btreeNode_t * root, btreeNode_t * queue[]);

void printf_tree(btreeNode_t * root,  int(*get_data)(btreeNode_t * queue_member));



//-------  巨集  -------//

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define return_to_user_struct_pointer(USER_STRUCT, MEMBER_NAME, MEMBER_POINT)  ((USER_STRUCT *)((size_t)MEMBER_POINT - offsetof(USER_STRUCT, MEMBER_NAME)))

#endif