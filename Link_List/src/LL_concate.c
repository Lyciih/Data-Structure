#include "llSpec.h"

void LL_concate(llNode_t* srcList, llNode_t* dstList)	// 串列相接
{
	llNode_t* tail = LL_get_tail(dstList);
	tail->next = srcList->next;
	srcList->next = NULL;
	LL_free_head(srcList);
}
