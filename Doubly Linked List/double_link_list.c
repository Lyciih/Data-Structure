#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dllSpec.h"




dllNode_t * DLL_init()
{
	dllNode_t *init = (dllNode_t*)malloc(sizeof(dllNode_t));
	if(init == NULL)
	{
		printf(">>>空間不足 (DLL_init 的回應)\n");
	}
	else
	{
		printf(">>>申請成功 (DLL_init 的回應)\n");
		init->prev = NULL;
		init->next = NULL;
	}
	return init;
}


int DLL_isEmpty(const dllNode_t *head)
{
	if(head->prev == NULL)
	{
		printf(">>>prev為空 (DLL_isEmpty 的回應)\n");
		if(head->next == NULL)
		{
			printf(">>>next為空 (DLL_isEmpty 的回應)\n");
			printf(">>>檢查完成,list的head正常且為空 (DLL_isEmpty 的回應)\n");
		}
		else
		{
			printf(">>>檢查完成,list不為空 (DLL_isEmpty 的回應)\n");
		}
	}
	return 0;
}


void DLL_addto_next(dllNode_t *new_node, dllNode_t *node)
{
	if(node->next != NULL)
	{
		node->next->prev = new_node;
	}
	new_node->next = node->next;
	node->next = new_node;
	new_node->prev = node;
	printf(">>>插入完成 (DLL_addto_next 的回應)\n");
}


void DLL_addto_prev(dllNode_t *new_node, dllNode_t *node)
{
	if(node->prev != NULL)
	{
		new_node->prev = node->prev;
		node->prev->next = new_node;
		node->prev = new_node;
		new_node->next = node;
		printf(">>>插入完成 (DLL_addto_prev 的回應)\n");
	}
	else
	{
		printf(">>>這裡是head,不可以在prev插入 (DLL_addto_prev 的回應)\n");
	}
}

void DLL_add_first(dllNode_t * new_node, dllNode_t * head)
{
	if(head->next == NULL)
	{
		head->next = new_node;
		new_node->prev = head;
		printf(">>>加入在空list中 (DLL_add_first 的回應)\n");
	}
	else
	{
		new_node->next = head->next;
		head->next->prev = new_node;
		head->next = new_node;
		new_node->prev = head;
		printf(">>>加入在不為空的list (DLL_add_first 的回應)\n");
			
	}
}

dllNode_t * DLL_get_tail(dllNode_t *head)
{
	dllNode_t *current = head;
	if(current->next == NULL)
	{
		printf(">>>這是一個空list (DLL_get_tail 的回應)\n");
	}
	else
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		printf(">>>找到尾巴了 (DLL_get_tail 的回應)\n");
	}
	return current;
}


void DLL_add_tail(dllNode_t * new_node, dllNode_t *head)
{
	dllNode_t *current = DLL_get_tail(head);
	DLL_addto_next(new_node, current);
}



dllNode_t * DLL_next_node(const dllNode_t * node)//(下一個節點)
{
	return node->next;
}

dllNode_t * DLL_prev_node(const dllNode_t * node)//(上一個節點)
{
	return node->prev;
}


unsigned int DLL_num_nodes(const dllNode_t *head)//計算List中有幾個node
{
	int count = 0;
	dllNode_t *current = (dllNode_t *)head;
	while(current->next != NULL)
	{
		count++;
		current = current->next;
	}
	printf(">>>總共有 %d 個node (DLL_num_nodes 的回應)\n", count);
	return count;
}



void DLL_delete(dllNode_t * node)//(從node所在的 Linked List 中刪除此點)
{
	if(node->next == NULL)
	{
		node->prev->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->prev = NULL;
		node->next = NULL;
	}
}


dllNode_t * DLL_concate(dllNode_t *srcList, dllNode_t * dstList)//(將srcList 串在dstList之後)
{
	dllNode_t *tail = DLL_get_tail(dstList);
	tail->next = srcList->next;
	srcList->next->prev = tail;
	srcList->next = NULL;
	DLL_free_head(srcList);
}

void DLL_free_head(dllNode_t *head)
{
	memset(head, 0, sizeof(dllNode_t));
	free(head);
	printf(">>>來源list的head已被釋放 (DLL_free_head 的回應)\n");
}




