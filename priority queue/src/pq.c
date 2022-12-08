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
    *((void **)(pq->heap.elements)) = elementA;
    printf("%d", pq->heap.numElementds);
}