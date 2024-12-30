#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(node** top, int value) {
    node* newNode = createNode(value);
    if (newNode != NULL) {
        newNode->next = *top;
        *top = newNode;
        printf("%d pushed to stack\n", value);
    }
}

int pop(node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

int peek(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void enqueue(node** front, node** rear, int value) {
    node* newNode = createNode(value);
    if (newNode != NULL) {
        if (*rear == NULL) {
            *front = *rear = newNode;
        } else {
            (*rear)->next = newNode;
            *rear = newNode;
        }
        printf("%d enqueued to queue\n", value);
    }
}

int dequeue(node** front, node** rear) {
    if (*front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    node* temp = *front;
    int dequeuedValue = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

int frontQueue(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* stackTop = NULL;
    node* queueFront = NULL;
    node* queueRear = NULL;
    
    int choice, value;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  
                printf("\nStack Operations:\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Peek\n");
                printf("4. Display Stack\n");
                printf("5. Back to Main Menu\n");
                while (1) {                   
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    
                    if (choice == 5) break; 
                    
                    switch (choice) {
                        case 1:
                            printf("Enter value to push to stack: ");
                            scanf("%d", &value);
                            push(&stackTop, value);
                            break;
                        
                        case 2:
                            value = pop(&stackTop);
                            if (value != -1) {
                                printf("Popped from stack: %d\n", value);
                            }
                            break;

                        case 3:
                            value = peek(stackTop);
                            if (value != -1) {
                                printf("Top of stack: %d\n", value);
                            }
                            break;

                        case 4:
                            printf("Stack: ");
                            display(stackTop);
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;
            
            case 2:
                printf("\nQueue Operations:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Front\n");
                printf("4. Display Queue\n");
                printf("5. Back to Main Menu\n");
                while (1) {                   
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    
                    if (choice == 5) break; 
                    switch (choice) {
                        case 1:
                            printf("Enter value to enqueue to queue: ");
                            scanf("%d", &value);
                            enqueue(&queueFront, &queueRear, value);
                            break;
                        
                        case 2:
                            value = dequeue(&queueFront, &queueRear);
                            if (value != -1) {
                                printf("Dequeued from queue: %d\n", value);
                            }
                            break;

                        case 3:
                            value = frontQueue(queueFront);
                            if (value != -1) {
                                printf("Front of queue: %d\n", value);
                            }
                            break;

                        case 4:
                            printf("Queue: ");
                            display(queueFront);
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;
            
            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
