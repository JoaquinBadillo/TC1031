#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node;

struct node* head = NULL;
struct node* tail = NULL;

short listIsEmpty () {
    return head == NULL ? 1 : 0;
}

int listLength() {
    struct node* temp;
    int length;

    for(temp = head; temp != NULL; temp = temp -> next)
        ++length;
    
    return length;
}

void insertBack(int x) {
    struct node* element = malloc(sizeof(struct node));
    if (element == NULL){
        printf("No hay memoria.\n");
        return;
    }

    element -> value = x;
    if (listIsEmpty()) {
        element -> prev = NULL;
        element -> next = NULL;
        head = element;
        tail = element;
        return;
    }

    element -> next = NULL;
    element -> prev = tail;
    tail -> next = element;
   
    tail = element;
}

void insertFront(int x) {
    struct node* element = malloc(sizeof(struct node));
    if (element == NULL){
        printf("No hay memoria.\n");
        return;
    }

    element -> value = x;
    if (listIsEmpty()) {
        element -> prev = NULL;
        element -> next = NULL;
        head = element;
        tail = element;
        return;
    }
    
    element -> prev = NULL;
    element -> next = head;
    head -> prev = element;
    head = element;
}

#endif