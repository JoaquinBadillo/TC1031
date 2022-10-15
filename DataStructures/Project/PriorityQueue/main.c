#include <stdio.h>

#include "priorityQueue.h"


void main(void) {
    struct priority_queue* P = Priority_Queue();

    int priorities[8] = {5, 3, 7, 2, 0, 1, 8, 9};
    int data[8] = {10, 12, 13, 8, 2, 5, 1, 13};

    printf("ENQUEUE\n");

    // Insertion has a problem for elements after the 3rd insertion (probably accessing NIL)
    for (int i = 0; i < 3; i++)
        enqueue(P, priorities[i], data[i]);

    printf("\nDEQUEUE\n");

    for (int i = 0; i < 3; i++)
        dequeue(P);

    deleteQueue(&P);
}
