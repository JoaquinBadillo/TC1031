#include "queue.h"

void main(void) {
    printf("Here\n");
    struct queue* q = Queue();

    for (int i = 0; i < 10; i++)
        enqueue(q, i + 1);

    printQueue(q);

    for (int i = 0; i < 10; i++)
        printf("dequeued: %i\n", dequeue(q));

    deleteQueueNodes(q);
    free(q);
}