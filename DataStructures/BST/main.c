#include "tree.h"
#include "queue.h"

void main(void) {
    vertex* root = Tree();

    insertVertex(&root, 50);
    insertVertex(&root, 30);
    insertVertex(&root, 15);
    insertVertex(&root, 40);
    insertVertex(&root, 77);
    insertVertex(&root, 63);
    insertVertex(&root, 80);

    printf("TREE SIZE:\n");
    printf("%i\n", size(root));

    printf("\nADD EVEN VALUES:\n");
    printf("%i\n", addEvenValues(root));

    printf("\nADD ODD VALUES:\n");
    printf("%i\n", addOddValues(root));

    printf("\nPRINT LEAVES:\n");
    printLeaves(root);
    printf("\n");

    printf("\nBREADTH FIRST SEARCH: \n");
    bfs(root);
    printf("\n");

    deleteSubTree(&root, root);
}