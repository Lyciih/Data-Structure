#ifndef AVLSPEC_H_INCLUDE
#define AVLSPEC_H_INCLUDE

#include<stdio.h>
#include<string.h>


typedef struct avl_node {
    struct avl_node* left;
    struct avl_node* right;
    int height;
} avl_node_t;


void AVL_init(avl_node_t* node);

void AVL_tree_height_update(avl_node_t* root);

int AVL_height_compare(avl_node_t** root);

void AVL_rotate(avl_node_t** root);

avl_node_t* AVL_find_minimum(avl_node_t* root);

avl_node_t* AVL_find_maximum(avl_node_t* root);

int count_AVL_tree_level(avl_node_t* root);

void printf_AVL_tree(avl_node_t* root,  int(*get_data)(avl_node_t* queue_member), int ascii);

int maximum(int a, int b);



// 以下三個需要使用者編寫用來比較的回調函數及對應的指標
void AVL_insert(avl_node_t* element, avl_node_t** root, int(*compare)(void* element, void* in_tree_element));

avl_node_t* AVL_find(int key, avl_node_t** root, int(*compare)(int key, void* in_tree_element));

void AVL_delete(avl_node_t* delete_element, avl_node_t** root, int(*compare)(void* delete_element, void* in_tree_element));



//-------  巨集  -------//

// 取得成員在結構中的偏移量
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

// 用成員指標反推出結構指標
#define return_to_user_struct_pointer(USER_STRUCT_TYPE, MEMBER_NAME, MEMBER_POINT)  ((USER_STRUCT_TYPE*)((size_t)MEMBER_POINT - offsetof(USER_STRUCT_TYPE, MEMBER_NAME)))

#endif 
