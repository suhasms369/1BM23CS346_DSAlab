/*Write a program to simulate the working of stack using an 
array with the following:
a) Push
b) Pop
c) Display
The program should print appropriate messages for stack 
overflow, stack underflow
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* data;
    int top;
    int max;
} stack;

bool isfull(stack* s) {
    return s->top == s->max - 1; 
}

bool isempty(stack* s) {
    return s->top == -1;
}

void push(stack* s) {
    if (isfull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    int data;
    printf("Enter the data to be pushed: ");
    scanf("%d", &data);
    s->data[++(s->top)] = data;
}

void pop(stack* s) {
    if (isempty(s)) {
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

void display(stack* s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n"); 
}

int main() {
    int choice, max;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);
    stack s;
    s.data = (int*)malloc(max * sizeof(int));
    s.max = max;
    s.top = -1;
    printf("\nStack Operations\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exeting the program\n");
                free(s.data); 
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
