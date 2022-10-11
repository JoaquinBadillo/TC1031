#include "queue.h"

void main(void) {
    struct queue q;

    for (int i = 0; i < 10; i++) {
        enqueue(&q, i + 1);
    }

    printQueue(&q);

    for (int i = 0; i < 10; i++) {
        printf("dequeued: %i\n", dequeue(&q));
    }
}