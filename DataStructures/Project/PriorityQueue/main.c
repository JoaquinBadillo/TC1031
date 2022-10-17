#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "priorityQueue.h"

void main(void) {
    struct priority_queue* P = Priority_Queue();
    
    int n = 15;
    
    printf("ENQUEUE\n");
    for (int i = 0; i < n; i++)
        enqueue(P, rand() % 5 + 1, i);

    printf("\nQueue:\n");
    printPQueue(P);

    printf("\nDEQUEUE\n");
    for (int i = 0; i < n; i++)
        dequeue(P);

    printf("\nQueue:\n");
    printPQueue(P);

    deleteQueue(&P);
}
