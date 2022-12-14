#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct queue {
    struct node* front;
    struct node* back;
} queue;

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

void enqueue(struct queue* q, int x) {
    struct node* element;
    element = malloc(sizeof(struct node));

    if (element == NULL) {
        printf("Error: No memory.\n");
        return;
    }
    element -> value = x;
    element -> next = NULL;

    if (isEmpty(q) == 1) {
        q -> front = element;
        q -> back = element;
    } else {
        (q -> back) -> next = element;
        q -> back = element;
    }
}

int dequeue(struct queue* q) {
    if (isEmpty(q)==1) {
        printf("Error: Empty queue\n");
        return -1;
    }

    struct node* temp;
    temp = q -> front;
    if (q -> front == q -> back) {
        q -> front = NULL;
        q -> back = NULL;
    } else
        q -> front = (q -> front) -> next;
    
    int val = temp -> value;
    free(temp);
    return val;
}

void printQueue(struct queue* q) {
    struct node* it;

    for (it = q -> front; it != NULL; it = it -> next)
        printf("%i <- ", it -> value);
    printf("//\n");
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

#endif