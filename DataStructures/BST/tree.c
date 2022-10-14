// Tree interface implementation

#include "tree.h"
#include "queue.h"

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

    if ((*root) == NULL)
        *root = element;
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
        if (element == *root) {
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

vertex* deleteVertex(vertex** v, int x) {
	if (*v == NULL)
        return *v;
    
    if (x < (*v) -> value)
        (*v) -> left = deleteVertex(&(*v) -> left, x);
    
    else if (x > (*v) -> value)
        (*v) -> right = deleteVertex(&(*v) -> right, x);
    
    else {
        if ((*v) -> left == NULL) {
            vertex* temp = (*v) -> right;
            free(*v);
            *v = NULL;
            return temp;
        }

        else if ((*v) -> right == NULL) {
            vertex* temp = (*v) -> left;
            free(*v);
            *v = NULL;
            return temp;
        }

        vertex* temp = minNode((*v) -> right);
        (*v) -> value = temp -> value;
        (*v) -> right = deleteVertex(&(*v) -> right, temp -> value);
    }
    return *v;
}

int size(vertex* root) {
    int i = 0;
    if (root != NULL) {
        i++; // Count node

        // Add the size of the left and right subtrees
        i += size(root -> left);
        i += size(root -> right);
    }
    return i;
}

int addEvenValues(vertex* v) {
    int sum = 0;
    if (v != NULL) {
        if (v -> value % 2 == 0)
            sum += v -> value;

        sum += addEvenValues(v -> left);
        sum += addEvenValues(v -> right);
    }
    return sum;
}

int addOddValues(vertex* v) {
    int sum = 0;
    if (v != NULL) {
        if (v -> value % 2 == 1)
            sum += v -> value;

        sum += addOddValues(v -> left);
        sum += addOddValues(v -> right);
    }
    return sum;
}

void printLeaves(vertex* v) {
    if (v != NULL) {
        printLeaves(v -> left);
        if (v -> left == NULL && v -> right == NULL) {
            printf("%i\t", v -> value);   
        }
        printLeaves(v -> right);
    }
}

void bfs(vertex* root) {
    if (root == NULL)
        return;
    
    struct queue* q = Queue();
    enqueue(q, root);
    while (!(isEmpty(q))) {
        struct vertex* v = dequeue(q);
        printf("%i\t", v -> value);
        if (v -> left != NULL)
            enqueue(q, v -> left);
        if (v -> right != NULL)
            enqueue(q, v -> right);
    }
    free(q);
}