#include"pqSpec.h"

void createPQ(PQ_t * pq, H_class pqClass, int elementsSize, int maxSize, int (*compare)(void * elementA, void * elementB))
{   
    pq->pqClass = pqClass;
    pq->heap.elements = malloc(maxSize * sizeof(void *));
    pq->heap.numElementds = 0;
    pq->maxSize = maxSize;
    pq->elementSize = elementsSize;
    pq->compare = compare;
}


int Enqueue(PQ_t * pq, void * elementA)
{
    *((void **)(pq->heap.elements) + pq->heap.numElementds) = elementA;
    pq->heap.numElementds++;
    printf("%d\n", pq->heap.numElementds);
}

int count_pq_level(PQ_t * pq)
{    
    int nodes = pq->heap.numElementds;
    int count = 0;
    
    while(1)
    {
        if(nodes == 1)
        {
            return count;
        }
        else if(nodes % 2 == 0)
        {
            count++;
            nodes /= 2;
        }
        else
        {
            count++;
            nodes--;
            nodes /= 2;
        }
    }
}
