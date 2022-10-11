#include "tree.h"

void main(void) {
    vertex* root = NULL;
    insertVertex(&root, 50);
    insertVertex(&root, 30);
    insertVertex(&root, 20);
    insertVertex(&root, 40);
    insertVertex(&root, 70);
    insertVertex(&root, 60);
    insertVertex(&root, 80);
    
    printf("TREE TRAVERSAL\n");
    printf("---------------\n");
    printf("Pre-Order\n");
    preOrderTraversal(root);
    printf("\n\nIn-Order\n");
    inOrderTraversal(root);
    printf("\n\nPost-Order\n");
    postOrderTraversal(root);
    printf("\n\nDELETION\n");
    printf("---------------\n");
    printf("Delete Vertex (20)\n");
    deleteVertex(root, 20);
    printf("In-Order Traversal:\t");
    inOrderTraversal(root);
    printf("\nDelete Vertex (30)\n");
    deleteVertex(root, 30);
    printf("In-Order Traversal:\t");
    inOrderTraversal(root);
    printf("\nDelete Vertex (50)\n");
    deleteVertex(root, 50);
    printf("In-Order Traversal:\t");
    inOrderTraversal(root);
    printf("\n");
    deleteVertex(root, 40);
    printf("1/4\n");
    deleteVertex(root, 60);
    printf("2/4\n");
    deleteVertex(root, 70);
    printf("3/4\n");
    deleteVertex(root, 80);
    printf("4/4\n");
    printf("%p\n", root);
    if (root == NULL) {
        printf("Works!\n");
    }
    //deleteSubTree(&root, root);
}