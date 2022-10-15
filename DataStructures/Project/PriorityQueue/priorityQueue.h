/* 
    Priority Queue header file
*/

#ifndef QUEUE_H
#define QUEUE_H

// Nodes and Queue definition
typedef struct node {
    int key; // Priority
    int data; // Value

    char color;
    struct node* parent;
    struct node* left;
    struct node* right;
} node;

typedef struct priority_queue {
    struct node* root;
    int size;
} priority_queue;

// Tree Interface
struct node* Node();
void deleteSubtree(struct node** root, struct node*);
void insertNode(struct node** T, int key, int data);
void deleteNode(struct node** T, struct node* z);

// Priority Queue Interface
struct priority_queue* Priority_Queue();
void deleteQueue(struct priority_queue** P);
void enqueue(struct priority_queue* P, int key, int data);
int dequeue(struct priority_queue* P);

// Additonal Functions

// Helper Functions
void leftRotate(struct node** tree, struct node* x); 
void rightRotate(struct node** tree, struct node* y);
void insertFixUp(struct node** tree, struct node* z);
struct node* minimum(struct node* subtree);
void transplant(struct node** tree, struct node* u, struct node* v);
void deleteFixUp(struct node** tree, struct node* x);

#endif