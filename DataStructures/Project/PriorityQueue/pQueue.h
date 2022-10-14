/* 
    Priority Queue Implementation 

    It uses a Red Black Tree to keep a balanced Binary Search Tree
    This is important as it supports insertion, deletion and search in O(lg n) time

    The enqueue operation is just an insertion thus it takes O(lg n) time
    The dequeue operation searches the minimum key and deletes it, thus it takes O(lg n) time 
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#define RED 'R'
#define BLACK 'B'

typedef struct node {
    int key;
    int data;
    char color;

    struct node* parent;
    struct node* left;
    struct node* right;
} node;

typedef struct priority_queue {
    struct node* root;
    int size;
} priority_queue;

// Create NIL sentinel
struct node NIL_Node;
node* NIL = &NIL_Node;

struct priority_queue* Priority_Queue() {
    struct priority_queue* P;
    P = malloc(sizeof(struct priority_queue));

    if (P == NULL) {
        return NULL;
    }

    P -> root = NIL;
    P -> size = 0;

    return P;
}

void leftRotate(struct priority_queue* P, struct node* x) {
    node* y = x -> right;
    x -> right = y -> left;

    y -> parent = x -> parent;

    if (y -> left != NIL)
        y -> left -> parent = x;

    if (x -> parent == NIL)
        P -> root = y;
    else if (x == x -> parent -> left)
        x -> parent -> left = y;
    else
        x -> parent -> right = y;

    y -> left = x;
    x -> parent = y;
}

void rightRotate(struct priority_queue* P, struct node* y) {
    node* x = y -> left;
    y -> left = x -> right;
    if (y -> left != NIL) {
        P -> root = y;
    } else if (x == x -> parent -> left) {
        x -> parent -> left = y;
    } else {
        x -> parent -> right = y;
        y -> left = x;
        x -> parent = y;
    }
}



#endif