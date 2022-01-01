#include <stdio.h>
#include <stdlib.h>

// Boolean Values
#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE FIRST = NULL;

int SIZE = 0;

// Function to create node and returns pointer to node
NODE createNode(int item) {
    NODE n = (NODE) malloc(sizeof(struct node));
    n -> data = item;
    n -> link = NULL;
    return n;
}

// Delete first node
int deleteFirst() {
    if (FIRST == NULL) {
        printf("List is empty\n");
        return -1;
    } else {
        NODE temp = FIRST;
        FIRST = FIRST -> link;
        int item = temp -> data;
        free(temp);
        SIZE--;
        return item;
    }
}

// Insert at first
int insertFirst(int item) {
    int bool = FALSE;
    NODE temp = createNode(item);
    if (FIRST == NULL) {
        FIRST = temp;
    } else {
        temp -> link = FIRST;
        FIRST = temp;
    }
    SIZE++;
    return TRUE;
}

int getSize() {
    return SIZE;
}

// Display the list
void displayList() {
    if (FIRST == NULL) {
        printf("List empty!\n");
    } else {
        NODE temp = FIRST;
        while(temp != NULL) {
            printf("%d ",temp -> data);
            temp = temp -> link;
        }
        printf("\n");
    }
}