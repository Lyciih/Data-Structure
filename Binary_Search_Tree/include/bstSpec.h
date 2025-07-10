#ifndef BSTSPEC_H_INCLUDED
#define BSTSPEC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node {
    struct node* left;
    struct node* right;
}btreeNode_t;

//-------  函數  -------//

void Bst_init(btreeNode_t* node);

void tree_level_to_queue(btreeNode_t* root, btreeNode_t* queue[]);

void printf_tree(btreeNode_t* root,  int(*get_data)(btreeNode_t* queue_member));

btreeNode_t* findMinNode(btreeNode_t* root);

btreeNode_t* findMaxNode(btreeNode_t* root);

int count_tree_level(btreeNode_t* root);




// 以下幾個需要使用者編寫用來比較的回調函數及對應的指標

void insertNode(btreeNode_t* insert_element, btreeNode_t** root, int (*compare)(btreeNode_t* insert_element, btreeNode_t* in_tree_element));

void deleteNode(btreeNode_t* delete_node, btreeNode_t** root, int (*compare)(btreeNode_t* delete_node, btreeNode_t* in_tree_element));

void inOrder(btreeNode_t* root, void (*print)(btreeNode_t* root));

btreeNode_t* findNode(int key, btreeNode_t* root, int (*compare)(int key, btreeNode_t* in_tree_element));

btreeNode_t* treeCopy(btreeNode_t* root, btreeNode_t* (*copy)(btreeNode_t* root));

int treeEqual(btreeNode_t* root_A, btreeNode_t* root_B, int (*compare)(btreeNode_t* root_A, btreeNode_t* root_B));


//-------  巨集  -------//

// 取得成員在結構中的偏移量
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

// 用成員指標反推出結構指標
#define return_to_user_struct_pointer(USER_STRUCT_TYPE, MEMBER_NAME, MEMBER_POINT)  ((USER_STRUCT_TYPE*)((size_t)MEMBER_POINT - offsetof(USER_STRUCT_TYPE, MEMBER_NAME)))

#endif
