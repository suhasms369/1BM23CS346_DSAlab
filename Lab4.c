/*WAP to Implement Singly Linked List with following
operations
a) Create a linked list.
b) Insertion of a node at first position, at any position
and at end of list.
Display the contents of the linked list. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertf(node** head, int value) {
    node* newNode = create(value);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertb(node** head, int value) {
    node* newNode = create(value);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    node* head = NULL;
    int choice, value, position;
    printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertf(&head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertb(&head, value);
                break;

            case 3:
                printf("List contents: ");
                display(head);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

