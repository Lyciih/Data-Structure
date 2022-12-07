#ifndef PQSPEC_H_INCLUDED
#define PQSPEC_H_INCLUDED

typedef struct HeapType {
    void * elements;
    int numElementds;
}Heap_t;

typedef enum {
    MINHEAP = 0,
    MAXHEAP
}H_class;

typedef struct PQ {
    H_class pqClass;
    Heap_t heap;
    int maxSize;
    int elementSize;
    int (*compare)(void * elementA, void * elementB);
}PQ_t;


void createPQ(PQ_t * pq, H_class pqClass, int elementsSize, int maxSize, int (*compare)(void * elementA, void * elementB));

int IsEmpty(PQ_t * pq);

int IsFull(PQ_t * pq);

int Enqueue(PQ_t * pq, void * elementA);

void * Dequeue(PQ_t * pq);

#endif