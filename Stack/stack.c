/*
    Stack implementation with a linked list.
    1. Push -> Insert at first
    2. Pop -> Delete first
    3. Peek -> Return first element
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

// Push an element in the stack
int push(int item) {
    return insertFirst(item);
}

// Pop an element from the stack
int pop() {
    return deleteFirst();
}

// Peek an element from the stack
int peek() {
    if (FIRST == NULL) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return FIRST -> data;
    }
}

// Display the stack
void displayStack() {
    printf("Stack: ");
    displayList();
}

// Main Function
void main() {
    int ch;
    while(1) {
        printf("\n1. Push an element in the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Peek an element from the stack\n");
        printf("4. Print the stack\n");
        printf("5. Print Size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                int item;
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                printf("Deleted element: %d\n", pop());
                break;
            case 3:
                printf("First element: %d\n", peek());
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Size: %d\n", getSize());
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}