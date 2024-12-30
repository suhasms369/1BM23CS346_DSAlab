/* WAP to Implement Single Link List with following
operations: Sort the linked list, Reverse the linked list,
Concatenation of two linked lists.
WAP to Implement Single Link List to simulate Stack &
Queue Operations.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;  
struct Node* head2 = NULL;  

void createLinkedList(struct Node** head, int n) {
    int data, i;
    struct Node *newNode, *temp;
    if (n <= 0) return;
    *head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    (*head)->data = data;
    (*head)->next = NULL;
    temp = *head;
    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void sortLinkedList(struct Node* head) {
    struct Node *i, *j;
    int tempData;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
}

void reverseLinkedList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLinkedLists(struct Node** head1, struct Node* head2) {
    struct Node *temp = *head1;
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void displayList(struct Node* head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, m, choice;

    printf("Enter number of nodes for the first linked list: ");
    scanf("%d", &n);
    createLinkedList(&head1, n);

    printf("Enter number of nodes for the second linked list: ");
    scanf("%d", &m);
    createLinkedList(&head2, m);

    printf("\nMenu:\n");
    printf("1. Sort first linked list\n");
    printf("2. Reverse first linked list\n");
    printf("3. Sort second linked list\n");
    printf("4. Reverse second linked list\n");
    printf("5. Concatenate the second linked list to the first linked list\n");
    printf("6. Display first linked list\n");
    printf("7. Display second linked list\n");
    printf("8. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sortLinkedList(head1);
                printf("Sorted first linked list: ");
                displayList(head1);
                break;
            case 2:
                reverseLinkedList(&head1);
                printf("Reversed first linked list: ");
                displayList(head1);
                break;
            case 3:
                sortLinkedList(head2);
                printf("Sorted second linked list: ");
                displayList(head2);
                break;
            case 4:
                reverseLinkedList(&head2);
                printf("Reversed second linked list: ");
                displayList(head2);
                break;
            case 5:
                concatenateLinkedLists(&head1, head2);  
                printf("Concatenated list: ");
                displayList(head1);  
                break;
            case 6:
                printf("First linked list: ");
                displayList(head1);
                break;
            case 7:
                printf("Second linked list: ");
                displayList(head2);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
