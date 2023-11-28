#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 5
#define COLS 5

//defines the node structure
typedef struct Node {
    struct Node* parent;
    int position[2];
    int g;
    int h;
    int f;
} Node;

//creates a new node
//parent: the parent node, i.e the node from which this node is reached
//row: the row number of the node
//col: the column number of the node
Node* createNode(Node* parent, int row, int col) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->parent = parent;
    newNode->position[0] = row;
    newNode->position[1] = col;
    newNode->g = 0; //distance from the start node
    newNode->h = 0; //heuristic value
    newNode->f = 0; //total cost
    return newNode;
}

//checks if the given position is valid or not, i.e it is within the maze
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

//checks if the given position is an obstacle or not
bool isObstacle(int maze[ROWS][COLS], int row, int col) {
    return (maze[row][col] == 1);
}

//checks if the given position is the destination or not
bool isDestination(int row, int col, int end[2]) {
    return (row == end[0] && col == end[1]);
}

//calculates the heuristic value of the given position
//uses the Euclidean distance formula
//formula : sqrt((x1-x2)^2 + (y1-y2)^2)
int calculateHValue(int current[2], int end[2]) {
    return (int)(pow((current[0] - end[0]), 2) + pow((current[1] - end[1]), 2));
}

//prints the path from the start node to the end node
//works when the end node is reached
void printPath(Node* current) {
    if (current == NULL) {
        return;
    }
    printPath(current->parent);
    printf("(%d, %d)\n", current->position[0], current->position[1]);
}

//implements the A* algorithm
bool aStar(int maze[ROWS][COLS], int start[2], int end[2]) {
    //creates first node with no parent, i.e the start node
    //sets the g, h and f values to 0
    Node* startNode = createNode(NULL, start[0], start[1]);
    startNode->g = startNode->h = startNode->f = 0;
    
    //creates the end node with no parent
    //sets the g, h and f values to 0
    Node* endNode = createNode(NULL, end[0], end[1]);
    endNode->g = endNode->h = endNode->f = 0;
    
    // Create a min-heap (priority queue)
    //stores the nodes in the priority queue
    //rows * cols is the maximum number of nodes that is rows * cols
    Node* priorityQueue[ROWS * COLS];
    int queueSize = 0;
    
    // Add the start node to the priority queue
    priorityQueue[queueSize++] = startNode;
    
    while (queueSize > 0) {
        // Find the node with the lowest f-value in the priority queue
        // wont run 1st time bcuz 1<1 is false"
        int minIndex = 0;
        for (int i = 1; i < queueSize; i++) {
            if (priorityQueue[i]->f < priorityQueue[minIndex]->f) {
                minIndex = i;
            }
        }
        
        Node* currentNode = priorityQueue[minIndex];
        
        // Remove the current node from the priority queue
        for (int i = minIndex; i < queueSize - 1; i++) {
            priorityQueue[i] = priorityQueue[i + 1];
        }
        queueSize--;
        
        if (isDestination(currentNode->position[0], currentNode->position[1], end)) {
            printf("Path:\n");
            printPath(currentNode);
            return true;
        }
        
        int directions[8][2] = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };
        
        for (int i = 0; i < 8; i++) {
            int newRow = currentNode->position[0] + directions[i][0];
            int newCol = currentNode->position[1] + directions[i][1];
            
            if (isValid(newRow, newCol) && !isObstacle(maze, newRow, newCol)) {
                Node* newNode = createNode(currentNode, newRow, newCol);
                
                newNode->g = currentNode->g + 1;
                newNode->h = calculateHValue(newNode->position, end);
                newNode->f = newNode->g + newNode->h;
                
                // Add the new node to the priority queue
                priorityQueue[queueSize++] = newNode;
            }
        }
    }
    
    printf("No path found.\n");
    return false;
}

int main() {
    int maze[ROWS][COLS] = {
        {0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    
    //creates 2 arrays to store the start and end positions
    int start[2], end[2];
    
    printf("Enter the start position (row, column): ");
    scanf("%d %d", &start[0], &start[1]);
    
    printf("Enter the end position (row, column): ");
    scanf("%d %d", &end[0], &end[1]);
    
    if (!aStar(maze, start, end)) {
        printf("No path found.\n");
    }
    
    return 0;
}

