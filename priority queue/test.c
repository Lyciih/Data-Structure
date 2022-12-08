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

    printf("\n");
    printf("MINIMUM HEAP :\n");


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
        pq_printf_tree(&first_pq, get_math);
    }

    printf("\n");
    printf("DELETE :\n");

    while(Dequeue(&first_pq))
    {       
        pq_printf_tree(&first_pq, get_math);
    }



//---------------------------------------------------------------

    printf("\n");
    printf("MAXIMUM HEAP :\n");


    student_t node_two[6] = {
        {"A", 70, 100},
        {"B", 60, 90},
        {"C", 80, 95},
        {"D", 65, 90},
        {"E", 10, 70},
        {"F", 90, 90}
    };


    PQ_t second_pq;
    createPQ(&second_pq, MAXHEAP, sizeof(student_t), 10, compareMath);

    for(int i = 0 ; i < 6 ; i++)
    {
	    Enqueue(&second_pq, &node_two[i]);
        pq_printf_tree(&second_pq, get_math);
    }

    printf("\n");
    printf("DELETE :\n");

    while(Dequeue(&second_pq))
    {
        pq_printf_tree(&second_pq, get_math);
    }

    

}
