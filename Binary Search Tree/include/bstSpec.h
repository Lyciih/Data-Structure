#ifndef BSTSPEC_H_INCLUDED
#define BSTSPEC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    struct node *left;
    struct node *right;
}btreeNode_t;


void Bst_init(btreeNode_t * node);

void insert_child_node(btreeNode_t * insert_element, btreeNode_t * root, int(*compare)(btreeNode_t * insert_element, btreeNode_t * in_tree_element));
void insertNode(btreeNode_t * insert_element, btreeNode_t ** root, int(*compare)(btreeNode_t * insert_element, btreeNode_t * in_tree_element));


btreeNode_t * find_child_node(int key, btreeNode_t * root, int(*compare)(int key, btreeNode_t * in_tree_element));
btreeNode_t * findNode(int key, btreeNode_t * root, int(*compare)(int key, btreeNode_t * in_tree_element));

btreeNode_t * findMinNode(btreeNode_t * root);
btreeNode_t * findMaxNode(btreeNode_t * root);


void delete_child_node(btreeNode_t * delete_node, btreeNode_t * root, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element));
void deleteNode(btreeNode_t * delete_node, btreeNode_t ** root, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element));

void inOrder(btreeNode_t * root, void(*print)(btreeNode_t * root));



#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define return_to_user_struct_pointer(USER_STRUCT, MEMBER_NAME, MEMBER_POINT)  ((USER_STRUCT *)((size_t)MEMBER_POINT - offsetof(USER_STRUCT, MEMBER_NAME)))
#endif