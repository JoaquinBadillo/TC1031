// Queue interface implementation
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

short queueIsEmpty(struct queue* q) {
    return q -> front == NULL ? 1 : 0;
}

void queueEnqueue(struct queue* q, struct node* v) {
    struct qnode* element;
    element = malloc(sizeof(struct qnode));

    if (element == NULL) {
        printf("Error: No memory.\n");
        return;
    }

    element -> vertex = v;
    element -> next = NULL;

    if (queueIsEmpty(q) == 1) {
        q -> front = element;
        q -> back = element;
    } else {
        (q -> back) -> next = element;
        q -> back = element;
    }
}

struct node* queueDequeue(struct queue* q) {
    if (queueIsEmpty(q)==1)
        return NULL;

    struct qnode* temp;
    temp = q -> front;
    if (q -> front == q -> back) {
        q -> front = NULL;
        q -> back = NULL;
    } else
        q -> front = (q -> front) -> next;
    
    struct node* v = temp -> vertex;
    free(temp);
    return v;
}

void deleteQueueNodes(struct queue* q) {
    if (q -> front == NULL)
        return;
        
    struct qnode* temp = q -> front;
    struct qnode* next = temp -> next;

    while (temp != NULL) {
        free(temp);
        temp = next;
        next = temp -> next;
    }

    q -> front = NULL;
    q -> back = NULL;
}