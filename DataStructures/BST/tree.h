// Tree header file

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

// Tree vertices
typedef struct vertex {
    int value;
    struct vertex* left;
    struct vertex* right;
} vertex;

// Tree interface
vertex* Tree();

void insertVertex(vertex** root, int x);
void deleteSubTree(vertex** root, vertex* element);
void preOrderTraversal(vertex* v);
void inOrderTraversal(vertex* v);
void postOrderTraversal(vertex* v);
vertex* search(vertex* root, int x);
vertex* minNode(vertex* element);
vertex* deleteVertex(vertex** v, int x);
int size(vertex* root);
int addEvenValues(vertex* v);
int addOddValues(vertex* v);
void printLeaves(vertex* v);
void bfs(vertex* root);
#endif