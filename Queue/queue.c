/*
    Queue Operations with Linked List
    1. Insert at last
    2. Delete first
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

// Insert an element in the queue
int insertQueue(int item) {
    return insertLast(item);
}

// Delete an element from the queue
int deleteQueue() {
    return deleteFirst();
}

// Print the queue
void printQueue() {
    printf("Queue: ");
    displayList();
}

// Main Function
void main(){
    int ch;
    while(1) {
        printf("\n1. Insert an element in the queue\n");
        printf("2. Delete an element from the queue\n");
        printf("3. Print the queue\n");
        printf("4. Print Size\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                int item;
                scanf("%d", &item);
                insertQueue(item);
                break;
            case 2:
                printf("Deleted element: %d\n", deleteQueue());
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Size: %d\n", getSize());
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}