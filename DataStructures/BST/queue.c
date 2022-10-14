// Queue interface implementation

#include "queue.h"

struct queue* Queue() {
    struct queue* q = malloc(sizeof(struct queue));
    if (q == NULL)
        return NULL;

    q -> front = NULL;
    q -> back = NULL;
    return q;
}

short isEmpty(struct queue* q) {
    return q -> front == NULL ? 1 : 0;
}

void enqueue(struct queue* q, struct vertex* v) {
    struct node* element;
    element = malloc(sizeof(struct node));

    if (element == NULL) {
        printf("Error: No memory.\n");
        return;
    }

    element -> vertex = v;
    element -> next = NULL;

    if (isEmpty(q) == 1) {
        q -> front = element;
        q -> back = element;
    } else {
        (q -> back) -> next = element;
        q -> back = element;
    }
}

struct vertex* dequeue(struct queue* q) {
    if (isEmpty(q)==1)
        return NULL;

    struct node* temp;
    temp = q -> front;
    if (q -> front == q -> back) {
        q -> front = NULL;
        q -> back = NULL;
    } else
        q -> front = (q -> front) -> next;
    
    struct vertex* v = temp -> vertex;
    free(temp);
    return v;
}

void deleteQueueNodes(struct queue* q) {
    if (q -> front == NULL)
        return;
        
    struct node* temp = q -> front;
    struct node* next = temp -> next;

    while (temp != NULL) {
        free(temp);
        temp = next;
        next = temp -> next;
    }

    q -> front = NULL;
    q -> back = NULL;
}