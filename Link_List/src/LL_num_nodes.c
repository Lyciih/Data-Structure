#include "llSpec.h"

unsigned int LL_num_nodes(const llNode_t* head)	// 計算串列中有幾個節點
{
	int count = 0;
	llNode_t* current = (llNode_t*)head;
	while(current->next != NULL)
	{
		count++;
		current = current->next;
	}
	printf(">>> There are totally %d nodes (response from LL_num_nodes )\n", count);
	return count;
}
