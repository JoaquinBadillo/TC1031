#include "list.h"

#include <time.h>

void main(void) {
    srand(time(NULL));
    struct node* head = List();
    int input;

    for (int i=0; i<15; ++i){
        insertFront(&head, rand() % 10);
    }
    printf("Randomly generated list:\n");
    printList(head);

    printf("\nChoose a number to insert at the beginning: ");
    scanf("%i", &input);
    insertFront(&head, input);
    printList(head);

    printf("\nChoose a number to find the number of times it is repeated in the list: ");
    scanf("%i", &input);
    findOccurrences(head, input);

    printf("\nDelete even numbers from list:\n");
    deleteEven(&head);
    printList(head);

    printf("\nFind average:\n");
    printf("Average = %f\n", average(head));

    printf("\nChoose a number to delete all its occurrences in the list: ");
    scanf("%i", &input);
    deleteOccurrences(&head, input);
    printList(head);

    // Free every node from memory
    deleteList(&head);
}
