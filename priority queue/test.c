#include<stdio.h>
#include"pqSpec.h"

typedef struct test_element {
    char ID[10];
    int math;
    int eng;
}student_t;

int compareMath(void * elementA, void * elementB)
{
    if(((student_t *)elementA)->math > ((student_t *)elementB)->math)
    {
        return 1;
    }
    else if(((student_t *)elementA)->math < ((student_t *)elementB)->math)
    {
        return -1;
    }
    return 0;
}



int main() {
    student_t node[6] = {
        {"C120308001", 70, 100},
        {"B220406001", 60, 90},
        {"D120306001", 80, 95},
        {"A220407001", 65, 90},
        {"D220506001", 10, 70},
        {"A120406001", 90, 90}
    };


    PQ_t first_pq;
    createPQ(&first_pq, MINHEAP, sizeof(student_t), 10, compareMath);

    for(int i = 0 ; i < 6 ; i++)
    {
	    Enqueue(&first_pq, &node[i]);
    }
    
    
   // Enqueue(&first_pq, &node[0]);

    printf("%d\n",((student_t *)*((void **)first_pq.heap.elements))->eng);

    //printf("%d\n",first_pq.heap.numElementds);


    //Enqueue(&first_pq, &node[1]);

    printf("%d\n",((student_t *)*((void **)first_pq.heap.elements + 1))->eng);



}
