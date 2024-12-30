/*Write a program to traverse a graph using BFS and DFS
method.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX], front = -1, rear = -1;


void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    queue[++rear] = vertex;
    if (front == -1)
        front = 0;
}

int dequeue() {
    if (front == -1)
        return -1;
    int vertex = queue[front++];
    if (front > rear)
        front = rear = -1;
    return vertex;
}


void bfs(int start, int n) {
    int i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, e, u, v, start, choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    do {
        for (int i = 0; i < n; i++)
            visited[i] = 0;

        printf("\nChoose Traversal Method:\n");
        printf("1. BFS\n2. DFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bfs(start, n);
                break;
            case 2:
                printf("DFS Traversal: ");
                dfs(start, n);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}