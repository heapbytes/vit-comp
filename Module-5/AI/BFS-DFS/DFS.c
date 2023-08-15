#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int vertices, edges;

// Stack data structure for DFS
struct Stack {
    int items[MAX_VERTICES];
    int top;
};

// Initialize a stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    stack->top++;
    stack->items[stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

// DFS algorithm
void dfs(int startVertex) {
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, startVertex);
    visited[startVertex] = 1;

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);

    while (stack.top != -1) {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                push(&stack, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited array
    for (int i = 0; i < vertices; ++i) {
        visited[i] = 0;
        for (int j = 0; j < vertices; ++j)
            graph[i][j] = 0;
    }

    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < edges; ++i) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    dfs(startVertex);
    printf("\n");

    return 0;
}

