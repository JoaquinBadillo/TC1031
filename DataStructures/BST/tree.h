#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct vertex {
    int value;
    struct vertex* left;
    struct vertex* right;
    struct vertex* parent;
} vertex;

vertex* Tree() {
    return NULL;
}

void insertVertex(vertex** root, int x) {
    vertex* element = malloc(sizeof(vertex));
    if (element == NULL) {
        printf("Error: No memory\n");
        return;
    }

    element -> value = x;
    element -> left = element -> right = NULL;

    if ((*root) == NULL) {
        element -> parent = NULL;
        *root = element;
    }
    else {
        vertex* prev = NULL;
        vertex* current = *root;

        while (current != NULL) {
            prev = current;

            if (x < current -> value)
                current = current -> left;
            else 
                current = current -> right;
        }

        element -> parent = prev;

        if (x < prev -> value)
            prev -> left = element;
        else
            prev -> right = element;
    }
}

void deleteSubTree(vertex** root, vertex* element) {
    if (element != NULL) {
        deleteSubTree(root, element -> left);
        deleteSubTree(root, element -> right);
        if (element -> parent == NULL) {
            *root = NULL;
        }
        free(element);
    }
}

void preOrderTraversal(vertex* v) {
    if (v != NULL) {
        printf("%i\t", v -> value);
        preOrderTraversal(v -> left);
        preOrderTraversal(v -> right);
    }
}

void inOrderTraversal(vertex* v) {
    if (v != NULL) {
        inOrderTraversal(v -> left);
        printf("%i\t", v -> value);
        inOrderTraversal(v -> right);
    }
}

void postOrderTraversal(vertex* v) {
    if (v != NULL) {
        postOrderTraversal(v -> left);
        postOrderTraversal(v -> right);
        printf("%i\t", v -> value);
    }
}

vertex* search(vertex* root, int x) {
    vertex* current = root;

    while (current != NULL) {
        if (x < current -> value) {
            current = current -> left;
        }
        else if (x > current -> value) {
            current = current -> right;
        }
        else {
            return current;
        }
    }

    return NULL;
}

vertex* minNode(vertex* element) {
    vertex* current = element;

    while (current && current -> left != NULL)
        current = current -> left;
    
    return current;
}

vertex* deleteVertex(vertex* v, int x) {
	if (v == NULL)
        return v;
    
    if (x < v -> value)
        v -> left = deleteVertex(v -> left, x);
    
    else if (x > v -> value)
        v -> right = deleteVertex(v -> right, x);
    
    else {
        if (v -> left == NULL) {
            vertex* temp = v -> right;
            free(v);
            return temp;
        }

        else if (v -> right == NULL) {
            vertex* temp = v -> left;
            free(v);
            return temp;
        }

        vertex* temp = minNode(v -> right);
        v -> value = temp -> value;
        v -> right = deleteVertex(v -> right, temp -> value);
    }
    return v;
}

// void deleteVertex(vertex** v, int x) {
//     if (((*v) -> left == NULL) && ((*v) -> right == NULL)) {
//         printf("Deleting: %i\n", (*v) -> value);
//         vertex* temp = *v;
//         *v = NULL;
//         free(temp);
//         return;
//     }
//     deleteFunction(*v, x);
// }

#endif