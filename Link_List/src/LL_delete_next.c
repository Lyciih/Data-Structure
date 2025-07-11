#include "llSpec.h"

void LL_delete_next(llNode_t* node)	// 刪除下一個節點
{
	llNode_t* temp;
	if(node->next == NULL)
	{
		printf("there are not have next node");
	}
	else
	{
		temp = node->next; 
		node->next = node->next->next;
		temp->next = NULL;
	}
}
