// Queue header file

#ifndef QUEUE_H
#define QUEUE_H

#include "priorityQueue.h"

// Queue node
typedef struct qnode {
    struct node* vertex;
    struct qnode* next;
} qnode;

// Queue struct
typedef struct queue {
    struct qnode* front;
    struct qnode* back;
} queue;

// Queue interface
short queueIsEmpty(struct queue* q);
void queueEnqueue(struct queue* q, struct node* v);
struct node* queueDequeue(struct queue* q);
void queueDeleteNodes(struct queue* q);

#endif