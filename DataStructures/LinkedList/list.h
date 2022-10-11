#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

struct node* List() {
    return NULL;
}

short listIsEmpty(struct node* head) {
    return head == NULL ? 1 : 0;
}

int listLength(struct node* head) {
    struct node* temp;
    int length = 0;
    for (temp = head; temp != NULL; temp = temp -> next)
        ++length;
    return length;
}

void insertBack(struct node** head, int x) {
    struct node* element;
    element = malloc(sizeof(struct node));
    if (element == NULL) {
        printf("No memory\n");
        return;
    }
    if (listIsEmpty(*head)) {
        element -> value = x;
        element -> next = *head;
        *head = element;
        return;
    }
    struct node* temp = *head;
    while (temp -> next != NULL)
        temp = temp -> next;

    element -> value = x;
    element -> next = NULL;
    temp -> next = element;
}

void insertFront(struct node** head, int x) {
    struct node* element;
    element = malloc(sizeof(struct node));
    if (element == NULL) {
        printf("No memory\n");
        return;
    }

    element -> value = x;
    element -> next = *head;
    *head = element;
}

void deleteItem(struct node** head, int x) {
    if (listIsEmpty(*head)) {
        printf("Cannot delete from empty list!\n");
        return;
    }
    struct node* current = NULL;
    struct node* prev = NULL;
    struct node* temp;

    for (current = *head; current != NULL; current = current -> next) {
        if (current -> value == x) {
            temp = current;

            if(prev == NULL) {
                *head = current -> next;
                free(temp);
                return;
            }

            prev -> next = current -> next;
            free(temp);
            return;
        }
        prev = current;
    }
    printf("Item not found in list\n");
}

void printList(struct node* head) {
    struct node* temp;

    for (temp = head; temp != NULL; temp = temp -> next)
        printf("%i -> ", temp -> value);
    printf("// \n");
}

void findOccurrences(struct node* head, int x) {
    if (listIsEmpty(head)) {
        printf("List is empty: No occurences\n");
        return;
    }

    int counter = 0;
    int position = 0;
    struct node* temp;
    printf("%i was found in the following positions: \n[", x);

    for (temp = head; temp != NULL; temp = temp -> next) {
        if (temp -> value == x) {
            if (counter > 0)
                printf(", ");
            printf("%i", position);
            counter++;
        }
        position++;
    }
    printf("]\nTherefore it is repeated %i time(s)\n", counter);  
}

void deleteEven(struct node** head) {
    if (listIsEmpty(*head)) {
        printf("List is empty: No items to delete\n");
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;

    while (current != NULL) {
        if (current -> value % 2) {
            prev = current;
            current = current -> next;
        } 
        else {
            struct node* temp = current;
            if (prev == NULL) {
                *head = (*head) -> next;
                current = *head;
                free(temp);
            }
            else {
                prev -> next = current -> next;
                current = current -> next;
                free(temp);
            }
        }
    }
}

float average(struct node* head) {
    if (listIsEmpty(head)) {
        printf("Empty list: Average is not well defined.\n");
        return 0;
    }
    int sum = 0;
    int n = 0;
    struct node* temp;
    for (temp = head; temp != NULL; temp = temp -> next){
        sum += temp -> value;
        n++;
    }
    return (float) sum / n;
}

void deleteOccurrences(struct node** head, int x) {
    if (listIsEmpty(*head)) {
        printf("List is empty: No items to delete\n");
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;

    while (current != NULL) {
        if (current -> value == x) {
            struct node* temp = current;
            if (prev == NULL) {
                *head = (*head) -> next;
                current = *head;
                free(temp);
            }
            else {
                prev -> next = current -> next;
                current = current -> next;
                free(temp);
            }    
        } 
        else {
            prev = current;
            current = current -> next;   
        } 
    }
}

void deleteList(struct node** head) {
    if (listIsEmpty(*head))
        return;

    struct node* current = *head;
    while (current != NULL) {
        struct node* next = current -> next;
        free(current);
        current = next;
    }
    *head = NULL;
}
#endif