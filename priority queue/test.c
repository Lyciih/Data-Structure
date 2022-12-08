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


char * get_ID(void * element)
{
	return ((student_t *)element)->ID;
}

char * get_eng(void * element)
{
    static char buffer[20];
    sprintf(buffer, "%d", ((student_t *)element)->eng);
	return buffer;
}

char * get_math(void * element)
{
    static char buffer[20];
    sprintf(buffer, "%d", ((student_t *)element)->math);
	return buffer;
}



int main() {
    student_t node[6] = {
        {"A", 70, 100},
        {"B", 60, 90},
        {"C", 80, 95},
        {"D", 65, 90},
        {"E", 10, 70},
        {"F", 90, 90}
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

    printf("pq level : %d\n", count_pq_level(&first_pq));

    pq_printf_tree(&first_pq, get_math);

}
