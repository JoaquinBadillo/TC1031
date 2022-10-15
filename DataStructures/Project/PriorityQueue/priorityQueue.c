#include <stdlib.h>
#include <stdio.h>

#include "priorityQueue.h"


/*
    Priority Queue Implementation 

    It uses a Red Black Tree to keep a balanced Binary Search Tree
    This is important as it supports insertion, deletion and search in O(lg n) time

    The enqueue operation is just an insertion thus it takes O(lg n) time
    The dequeue operation searches the minimum key and deletes it, thus it takes O(lg n) time 
*/

#define RED 'R'
#define BLACK 'B'

struct node NIL_Node;
node* NIL = &NIL_Node;

// RED BLACK TREE INTERFACE

// Constructor
struct node* Node(int key, int data) {
    struct node* element;
    element = malloc(sizeof(struct node));

    if (element == NULL) {
        return NIL;
    }

    element -> key = key;
    element -> data = data;
    element -> color = RED;

    element -> left = NIL;
    element -> right = NIL;
    element -> parent = NIL;

    return element;
}

// Destructor
void deleteSubtree(struct node** root, struct node* element) {
    if (element != NIL) {
        deleteSubtree(root, element -> left);
        deleteSubtree(root, element -> right);
        if (element == *root) {
            *root = NIL;
        }
        free(element);
    }
}

// Insertion
void insertNode(struct node** root, int key, int data) {
    node* element = Node(key, data);
    
    node* prev = NIL;
    node* current = *root;

    while (current != NIL) {
       prev = current;

       if (element -> key < current -> key)
          current = current -> left;
       else
          current = current -> right;
    }

    element -> parent = prev;

    if (prev == NIL)
       *root = element;
    else if (element -> key < prev -> key)
        prev -> left  = element;
    else
        prev -> right = element;

    insertFixUp(root, element);
}

// Deletion
void deleteNode(struct node** root, struct node* z) {
    struct node* x;
    struct node* y = z; 
    char yColor = y -> color;

    if (z -> left == NIL) {
        x = z -> right;
        transplant(root, z, z -> right);
    } else if (z -> right == NIL) {
        x = z -> left;
        transplant(root, z, z -> left);
    } else {
        y = minimum(z -> right);
        yColor = y -> color;
        x = y -> right;
        if (y -> parent == z)
            x -> parent = y;
        else {
            transplant(root, y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }

        transplant(root, z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
        y -> color = z -> color;
    }

    free(z);

    if (yColor == BLACK)
        deleteFixUp(root, x);
}

// PRIORITY QUEUE INTERFACE

// Constructor
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

// Destructor
void deleteQueue(struct priority_queue** P) {
    deleteSubtree(&(P[0] -> root), P[0] -> root);
    free(*P);
    *P = NULL;
}

// Enqueue (with priority)
void enqueue(struct priority_queue* P, int key, int data) {
    insertNode(&(P -> root), key, data);
    printf("Enqueued: (%i, %i)\n", key, data);
}

// Dequeue (with priority)
int dequeue(struct priority_queue* P) {
    struct node* x = minimum(P -> root);
    int priority = x -> key;
    int value = x -> data;
    deleteNode(&(P -> root), x);
    printf("Dequeued: (%i, %i)\n", priority, value);
    return value;
}

// HELPER FUNCTIONS

void leftRotate(struct node** root, struct node* x) {
    node* y  = x -> right;
    x -> right = y -> left;

    if (x -> right != NIL)
        x -> right -> parent = x;

    y -> parent = x -> parent;

    if (x -> parent == NIL)
       *root = y;
    else if (x == x -> parent -> left)
       x -> parent -> left = y;
    else
       x -> parent -> right = y;

    y -> left = x;
    x -> parent = y;
}

void rightRotate(struct node** root, struct node* y) {
    node* x = y -> left;
    y -> left = x -> right;

    if (y -> left != NIL)
        y -> left -> parent = y;

    x -> parent = y -> parent;

    if (y -> parent == NIL)
       *root = x;
    else if (y == y -> parent -> left)
       y -> parent -> left = x;
    else
       y -> parent -> right = x;

    x -> right = y;
    y -> parent = x;
}

void insertFixUp(struct node** root, struct node* z) {
    node* temp;

    while ((z != *root) && (z -> parent -> color == RED)) {
        if (z -> parent -> key == z -> parent -> parent -> key) {
            temp = z -> parent -> parent -> right;
            if (temp -> color == RED) {
                z -> parent -> color = BLACK;
                temp -> color = BLACK;
                z -> parent -> parent -> color = RED;
                z = z -> parent -> parent;
            }
            else if(z -> key == z -> parent -> right -> key) {
                z = z -> parent;
                leftRotate(root, z);
            }
            z -> parent -> color = BLACK;
            z -> parent -> parent -> color = RED;
            rightRotate(root, z -> parent -> parent);
        }
        else {
            temp = z -> parent -> parent -> left;
            if(temp -> color == RED) {
                z -> parent -> color = BLACK;
                z -> color = BLACK;
                z -> parent -> parent -> color = RED;
                z = z -> parent -> parent;
            }
            else if(z -> key == z -> parent -> left -> key)
            {
                z = z -> parent;
                rightRotate(root, z);
            }
            z -> parent -> color = BLACK;
            z -> parent -> parent -> color = RED;
            leftRotate(root, z -> parent -> parent);
        }
    }
    root[0] -> color = BLACK;
}

void deleteFixUp(struct node** root, struct node* x) {
    node* w;
    while ((x != *root) && (x -> color == BLACK)) {
        if (x == x -> parent -> left) {
            w = x -> parent -> right;

            if (w -> color == RED) {
                w -> color = BLACK;
                x -> parent -> color = RED;
                leftRotate(root, x -> parent);
                w = x -> parent -> right;
            }

            if ((w -> left -> color == BLACK) && (w -> right -> color == BLACK)) {
                w -> color = RED;
                x = x -> parent;
            } else if (w -> right -> color == BLACK) {
                w -> left -> color = BLACK;
                w -> color = RED;
                rightRotate(root, w);
                w = x -> parent -> right;
            }

            w -> color = x -> parent -> color;
            x -> parent -> color = BLACK;
            w -> right -> color = BLACK;
            leftRotate(root, x -> parent);
            x = *root;
        }
        else {
            w = x -> parent -> left;

            if (w -> color == RED) {
                w -> color = BLACK;
                x -> parent -> color = RED;
                rightRotate(root, x -> parent);
                w = x -> parent -> left;
            }

            if ((w -> right -> color == BLACK) && (w -> left -> color == BLACK)) {
                w -> color = RED;
                x = x -> parent;
            } else if (w -> left -> color == BLACK) {
                w -> right -> color = BLACK;
                w -> color = RED;
                leftRotate(root, w);
                w = x -> parent -> left;
            }

            w -> color = x -> parent -> color;
            x -> parent -> color = BLACK;
            w -> left -> color = BLACK;
            rightRotate(root, x -> parent);
            x = *root;      
        }
    }

    x -> color = BLACK;
}

void transplant(struct node** root, struct node* u, struct node* v) {
    if (u -> parent == NIL)
        *root = v;
    else if (u == u -> parent -> left)
        u -> parent -> left = v;
    else
        u -> parent -> right = v;
    
    v -> parent = u -> parent;
}

struct node* minimum(struct node* T) {
    node* temp = T;

    while (temp -> left != NIL) {
        temp = temp -> left;
    }

    return temp;
}