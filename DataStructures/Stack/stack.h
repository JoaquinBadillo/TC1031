#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

struct node* Stack() {
    return NULL;
}

short isEmpty(struct node* head) {
    return head == NULL ? 1 : 0;
}

void push(struct node** head, int x) {
    struct node* element;
    element = malloc(sizeof(struct node));
    if (element == NULL) {
        printf("Error: No memory\n");
        return;
    }

    element -> value = x;
    element -> next = *head;
    *head = element;
}

int pop(struct node** head) {
    if (isEmpty(*head) == 1) {
        printf("Error: Empty stack\n");
        return -1;
    }
    struct node* temp = *head;
    int val = temp -> value;
    *head = (*head) -> next;
    free(temp);
    return val;   
}

void printStack(struct node* head) {
    struct node* it;
    for (it = head; it != NULL; it = it -> next)
        printf("%i\n", it -> value);
}

#endif