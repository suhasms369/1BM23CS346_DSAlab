#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int front, rear, size;
} CircularQueue;

void initQueue(CircularQueue *q, int size) {
    q->size = size;
    q->items = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

int isFull(CircularQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % q->size;
    }
    printf("%d ", q->items[q->rear]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    CircularQueue q;
    initQueue(&q, size);

    int choice, value;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                free(q.items);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
