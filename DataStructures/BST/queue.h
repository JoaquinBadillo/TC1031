// Queue header file

#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

// Queue node
typedef struct node {
    struct vertex* vertex;
    struct node* next;
} node;

// Queue struct
typedef struct queue {
    struct node* front;
    struct node* back;
} queue;

// Queue interface
struct queue* Queue();
short isEmpty(struct queue* q);
void enqueue(struct queue* q, struct vertex* v);
struct vertex* dequeue(struct queue* q);
void deleteQueueNodes(struct queue* q);

#endif