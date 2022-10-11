#include "stack.h"

void main(void) {
    struct node* head = initStack();
    int i;
    for (i = 0; i < 10; ++i) {
        push(&head, i);
    }

    printf("Stack:\n");
    printStack(head);
    printf("\n");

    for (i = 0; i < 10; ++i) {
        int x = pop(&head);
        printf("Popped: %i\n", x);
    }
}