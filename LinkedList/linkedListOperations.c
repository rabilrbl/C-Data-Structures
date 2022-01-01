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

int size = 0;

// Function to create node and returns pointer to node
NODE createNode(int item) {
    NODE n = (NODE) malloc(sizeof(struct node));
    n -> data = item;
    n -> link = NULL;
    return n;
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
    size++;
    return TRUE;
}

// Insert at last
int insertLast(int item) {
    int bool = FALSE;
    NODE temp = createNode(item);
    NODE last = NULL;
    if (FIRST == NULL) {
        FIRST = temp;
        bool = TRUE;
    } else {
        last = FIRST;
        while(last -> link != NULL) {
            last = last -> link;
        }
        last -> link = temp;
        bool = TRUE;
    }
    size++;
    return bool;
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
        size--;
        return item;
    }
}

// Delete last node
int deleteLast() {
    int item;
    if (FIRST == NULL) {
        printf("List is empty\n");
    } else {
        NODE temp = FIRST;
        NODE last = NULL;
        while(temp -> link != NULL) {
            last = temp;
            temp = temp -> link;
        }
        if (temp == FIRST) {
            FIRST = NULL;
            item = temp -> data;
            free(temp); 
        } else {
            last -> link = NULL;
            item = temp -> data;
            free(temp);
        }
        size--;
        return item;
    }

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

// Insert at position
void insertAtPosition(int pos, int item){
    if (FIRST == NULL || pos < 1){
        insertFirst(item);
    } else if (FIRST -> link == NULL && pos < 1) {
        insertLast(item);
    } else  {
        NODE newNode = createNode(item);
        NODE temp = FIRST;
        int count = 0;
        while((++count != pos) && (temp->link != NULL)){
            printf("%d\n",count);
            temp = temp -> link;
        }
        newNode -> link = temp -> link;
        temp -> link = newNode;
        newNode = NULL;
    }
    size++;
}

// Sort List
void sortList(){
    return;
}

//

// Take input from stdout
int input(char *text) {
    int item;
    printf("%s", text);
    scanf("%d", &item);
    return item;
}

// Main function
int main() {
    int ch, item, pos;
    while(1) {
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Delete first\n");
        printf("4. Delete last\n");
        printf("5. Display list\n");
        printf("6. Insert at position\n");
        printf("7. Sort list\n");
        printf("8. Get Size\n");
        printf("9. Exit\n");
        ch = input("Enter your choice: ");
        switch(ch) {
            case 1:
                item = input("Enter the item: ");
                insertFirst(item);
                break;
            case 2:
                item = input("Enter the item: ");
                insertLast(item);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                displayList();
                break;
            case 6:
                pos = input("Enter the position: ");
                item = input("Enter the item: ");
                insertAtPosition(pos, item);
                break;
            case 7:
                sortList();
                break;
            case 8:
                printf("Size: %d\n", size);
                break;
            case 9:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
}
