#ifndef DLLSPEC_H_INCLUDED
#define DLLSPEC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dllNode_t {
    struct dllNode_t* prev;
    struct dllNode_t* next;
} dllNode_t;





dllNode_t* DLL_init();	// 建構一個空的 list

int DLL_isEmpty(const dllNode_t* head);	// head 是否為空的 list

dllNode_t* DLL_next_node(const dllNode_t* node);	// (下一個節點)

dllNode_t* DLL_prev_node(const dllNode_t* node);	// (上一個節點)

unsigned int DLL_num_nodes(const dllNode_t* head);	// 計算 List 中有幾個 node

void DLL_add_first(dllNode_t* new_node, dllNode_t* head);	// (將新 new_node 加入到 head List 的第一個)

void DLL_add_tail(dllNode_t* new_node, dllNode_t* head);	// (將新 new_node 加入到 head List 的最後一個)

void DLL_addto_prev(dllNode_t* new_node, dllNode_t* node);	// (將新 new_node 加入到指定 node 的前一個)

void DLL_addto_next(dllNode_t* new_node, dllNode_t* node);	// (將新 new_node 加入到指定 node 的後一個)

void DLL_delete(dllNode_t* node);	// (從指定 node 所在的 Linked List 中刪除此節點)

void DLL_concate(dllNode_t* srcList, dllNode_t* dstList);	// (將 srcList 串在 dstList 之後)

dllNode_t* DLL_get_tail(dllNode_t* head);	// 取得 list 的尾巴

void DLL_free_head(dllNode_t* head);	// 釋放空的 head


//------------- 巨集 ----------------------------------------------------------------------------------------------------------------------

// 取得成員在結構中的偏移量
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

// 用成員指標反推出結構指標
#define return_to_user_struct_pointer(USER_STRUCT_TYPE, MEMBER_NAME, MEMBER_POINT)  ((USER_STRUCT_TYPE*)((size_t)MEMBER_POINT - offsetof(USER_STRUCT_TYPE, MEMBER_NAME)))

#endif
