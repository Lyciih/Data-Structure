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


int IsEmpty(PQ_t * pq)
{
    if(pq->heap.numElementds == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int IsFull(PQ_t * pq)
{
    if(pq->heap.numElementds == pq->maxSize)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}





int Enqueue(PQ_t * pq, void * elementA)
{
    if(IsFull(pq) == 0)
    {
        return 1;
    }

    *((void **)(pq->heap.elements) + pq->heap.numElementds) = elementA;
    pq->heap.numElementds++;

    int location = pq->heap.numElementds;

    void * temp = NULL;

    if(pq->heap.numElementds != 1)
    {
        if(pq->pqClass == 0)
        {
            while(location != 1)
            {
                int TOP = location / 2;
                if((pq->compare(*((void **)(pq->heap.elements) + TOP - 1), elementA)) == 1)
                {
                    temp = *((void **)(pq->heap.elements) + TOP - 1);
                    *((void **)(pq->heap.elements) + TOP - 1) = *((void **)(pq->heap.elements) + location - 1);
                    *((void **)(pq->heap.elements) + location - 1) = temp;
                    location /= 2;
                }
                else
                {
                    break;
                }       
            }
        }

        if(pq->pqClass == 1)
        {
            while(location != 1)
            {
                int TOP = location / 2;
                if((pq->compare(*((void **)(pq->heap.elements) + TOP - 1), elementA)) == -1)
                {
                    temp = *((void **)(pq->heap.elements) + TOP - 1);
                    *((void **)(pq->heap.elements) + TOP - 1) = *((void **)(pq->heap.elements) + location - 1);
                    *((void **)(pq->heap.elements) + location - 1) = temp;
                    location /= 2;
                }
                else
                {
                    break;
                }       
            }
        }
    }
    return 0;
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



void * Dequeue(PQ_t * pq)
{

    if(IsEmpty(pq) == 0)
    {
        return NULL;
    }

    void * output = *((void **)(pq->heap.elements));
    *((void **)(pq->heap.elements)) = *((void **)(pq->heap.elements) + pq->heap.numElementds - 1);
    pq->heap.numElementds--;


    int location = 1;
    void * temp = NULL;

    if(pq->heap.numElementds > 1)
    {
        if(pq->pqClass == 0)
        {
            while(location * 2 <= pq->heap.numElementds)
            {
                if((pq->compare(*((void **)(pq->heap.elements) + location - 1), *((void **)(pq->heap.elements) + location * 2 - 1))) == 1)
                {
                    temp = *((void **)(pq->heap.elements) + location - 1);
                    *((void **)(pq->heap.elements) + location - 1) = *((void **)(pq->heap.elements) + location * 2 - 1);
                    *((void **)(pq->heap.elements) + location * 2 - 1) = temp;

                    int check = location;
                    location *= 2;

                    if((pq->compare(*((void **)(pq->heap.elements) + check - 1), *((void **)(pq->heap.elements) + check * 2))) == 1)
                    {
                        temp = *((void **)(pq->heap.elements) + check - 1);
                        *((void **)(pq->heap.elements) + check - 1) = *((void **)(pq->heap.elements) + check * 2);
                        *((void **)(pq->heap.elements) + check * 2) = temp;                       
                    }
                }
                else if((pq->compare(*((void **)(pq->heap.elements) + location - 1), *((void **)(pq->heap.elements) + location * 2))) == 1)
                {
                    temp = *((void **)(pq->heap.elements) + location - 1);
                    *((void **)(pq->heap.elements) + location - 1) = *((void **)(pq->heap.elements) + location * 2);
                    *((void **)(pq->heap.elements) + location * 2) = temp;
                    location *= 2;
                    location++; 
                }
                else
                {
                    break;
                }       
            }
        }

        if(pq->pqClass == 1)
        {
            while(location * 2 <= pq->heap.numElementds)
            {
                if((pq->compare(*((void **)(pq->heap.elements) + location - 1), *((void **)(pq->heap.elements) + location * 2 - 1))) == -1)
                {
                    temp = *((void **)(pq->heap.elements) + location - 1);
                    *((void **)(pq->heap.elements) + location - 1) = *((void **)(pq->heap.elements) + location * 2 - 1);
                    *((void **)(pq->heap.elements) + location * 2 - 1) = temp;

                    int check = location;
                    location *= 2;

                    if((pq->compare(*((void **)(pq->heap.elements) + check - 1), *((void **)(pq->heap.elements) + check * 2))) == -1)
                    {
                        temp = *((void **)(pq->heap.elements) + check - 1);
                        *((void **)(pq->heap.elements) + check - 1) = *((void **)(pq->heap.elements) + check * 2);
                        *((void **)(pq->heap.elements) + check * 2) = temp;                       
                    }
                }
                else if((pq->compare(*((void **)(pq->heap.elements) + location - 1), *((void **)(pq->heap.elements) + location * 2))) == -1)
                {
                    temp = *((void **)(pq->heap.elements) + location - 1);
                    *((void **)(pq->heap.elements) + location - 1) = *((void **)(pq->heap.elements) + location * 2);
                    *((void **)(pq->heap.elements) + location * 2) = temp;
                    location *= 2;
                    location++; 
                }
                else
                {
                    break;
                }       
            }
        }
    }
    return output;
}



void * Dequeue_new(PQ_t * pq)
{

    if(IsEmpty(pq) == 0)
    {
        return NULL;
    }

    void * output = *((void **)(pq->heap.elements));
    *((void **)(pq->heap.elements)) = *((void **)(pq->heap.elements) + pq->heap.numElementds - 1);
    pq->heap.numElementds--;


    int location = 1;
    void * temp = NULL;
    #define TOP  *((void **)(pq->heap.elements) + location - 1)
    #define LEFT  *((void **)(pq->heap.elements) + location * 2 - 1)
    #define RIGHT  *((void **)(pq->heap.elements) + location * 2)

    if(pq->heap.numElementds > 1)
    {
        if(pq->pqClass == 0)
        {
            while(location * 2 <= pq->heap.numElementds)
            {
                if(location * 2 < pq->heap.numElementds && location * 2 + 1 <= pq->heap.numElementds)
                {
                    if(pq->compare(TOP , LEFT) == -1 && pq->compare(TOP , RIGHT) == -1)
                    {
                        break;
                    }
                    else if(pq->compare(TOP , LEFT) == 1 && pq->compare(TOP , RIGHT) == -1)
                    {
                        temp = TOP;
                        TOP = LEFT;
                        LEFT = temp;
                        location *= 2;
                    }
                    else if(pq->compare(TOP , LEFT) == -1 && pq->compare(TOP , RIGHT) == 1)
                    {
                        temp = TOP;
                        TOP = RIGHT;
                        RIGHT = temp;
                        location *= 2;
                        location++;
                    }
                    else if(pq->compare(TOP , LEFT) == 1 && pq->compare(TOP , RIGHT) == 1)
                    {
                        if(pq->compare(LEFT, RIGHT) == 1)
                        {
                            temp = TOP;
                            TOP = RIGHT;
                            RIGHT = temp;
                            location *= 2;
                            location++;
                        }
                        else if(pq->compare(LEFT, RIGHT) == -1)
                        {
                            temp = TOP;
                            TOP = LEFT;
                            LEFT = temp;
                            location *= 2;
                        }
                    }
                }
                else if(location * 2 == pq->heap.numElementds)
                {
                    if(pq->compare(TOP , LEFT) == -1)
                    {
                        break;
                    }
                    else if(pq->compare(TOP , LEFT) == 1)
                    {
                        temp = TOP;
                        TOP = LEFT;
                        LEFT = temp;
                        location *= 2;
                    }
                }
                else
                {
                    break;
                }               
            }
        }


        if(pq->pqClass == 1)
        {
            while(location * 2 <= pq->heap.numElementds)
            {
                if(location * 2 < pq->heap.numElementds && location * 2 + 1 <= pq->heap.numElementds)
                {
                    if(pq->compare(TOP , LEFT) == 1 && pq->compare(TOP , RIGHT) == 1)
                    {
                        break;
                    }
                    else if(pq->compare(TOP , LEFT) == -1 && pq->compare(TOP , RIGHT) == 1)
                    {
                        temp = TOP;
                        TOP = LEFT;
                        LEFT = temp;
                        location *= 2;
                    }
                    else if(pq->compare(TOP , LEFT) == 1 && pq->compare(TOP , RIGHT) == -1)
                    {
                        temp = TOP;
                        TOP = RIGHT;
                        RIGHT = temp;
                        location *= 2;
                        location++;
                    }
                    else if(pq->compare(TOP , LEFT) == -1 && pq->compare(TOP , RIGHT) == -1)
                    {
                        if(pq->compare(LEFT, RIGHT) == -1)
                        {
                            temp = TOP;
                            TOP = RIGHT;
                            RIGHT = temp;
                            location *= 2;
                            location++;
                        }
                        else if(pq->compare(LEFT, RIGHT) == 1)
                        {
                            temp = TOP;
                            TOP = LEFT;
                            LEFT = temp;
                            location *= 2;
                        }
                    }
                }
                else if(location * 2 == pq->heap.numElementds)
                {
                    if(pq->compare(TOP , LEFT) == 1)
                    {
                        break;
                    }
                    else if(pq->compare(TOP , LEFT) == -1)
                    {
                        temp = TOP;
                        TOP = LEFT;
                        LEFT = temp;
                        location *= 2;
                    }
                }
                else
                {
                    break;
                }               
            }

         
        }
    }
    
    return output;
}
