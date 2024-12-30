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

void insert(node** head, int value) {
    node* newNode = create(value);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } 
        else {
            node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void delete_first(node** head) {
    if (*head == NULL) {
        printf("List is empty, no element to delete\n");
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_last(node** head) {
    if (*head == NULL) {
        printf("List is empty, no element to delete\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display(node* head) {
    node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int choice, value;

    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete first element\n");
    printf("3. Delete last element\n");
    printf("4. Display list\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;

            case 2:
                delete_first(&head);
                break;

            case 3:
                delete_last(&head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
