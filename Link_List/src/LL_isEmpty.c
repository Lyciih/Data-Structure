#include "llSpec.h"

int LL_isEmpty(const llNode_t* head)
{
	if(head->next == NULL)
	{
		printf(">>> next is empty (response from LL_isEmpty )\n");
		return 1;
	}
	return 0;
}
