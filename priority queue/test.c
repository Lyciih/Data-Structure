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


    student_t node[10] = {
        {"A", 70, 100},
        {"B", 60, 90},
        {"C", 80, 95},
        {"D", 65, 90},
        {"E", 10, 70},
        {"F", 90, 90},
        {"G", 20, 60},
        {"H", 30, 50},
        {"I", 40, 40},
        {"J", 50, 30}
    };

    PQ_t first_pq;
    createPQ(&first_pq, MINHEAP, sizeof(student_t), 10, compareMath);

    printf("is queue empty? 0->true 1->false : %d\n", IsEmpty(&first_pq));



    for(int i = 0 ; i < 10 ; i++)
    {
	    Enqueue(&first_pq, &node[i]);
        pq_printf_tree(&first_pq, get_math);
    }

    printf("\n");
    printf("is queue full? 0->true 1->false : %d\n", IsFull(&first_pq));
    printf("\n");
    printf("DELETE :\n");

    while(Dequeue_new(&first_pq))
    {       
        pq_printf_tree(&first_pq, get_math);
    }



//---------------------------------------------------------------

    printf("\n");
    printf("MAXIMUM HEAP :\n");


    student_t node_two[10] = {
        {"A", 70, 100},
        {"B", 60, 90},
        {"C", 80, 95},
        {"D", 65, 90},
        {"E", 10, 70},
        {"F", 90, 90},
        {"G", 20, 60},
        {"H", 30, 50},
        {"I", 40, 40},
        {"J", 50, 30}
    };


    PQ_t second_pq;
    createPQ(&second_pq, MAXHEAP, sizeof(student_t), 10, compareMath);

    for(int i = 0 ; i < 10 ; i++)
    {
	    Enqueue(&second_pq, &node_two[i]);
        pq_printf_tree(&second_pq, get_math);
    }

    printf("\n");
    printf("DELETE :\n");

    while(Dequeue_new(&second_pq))
    {
        pq_printf_tree(&second_pq, get_math);
    }

    

}
