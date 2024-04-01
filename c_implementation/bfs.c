#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue a node to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// BFS traversal of the graph
void BFS(int** graph, int vertices, int start) {
    struct Queue* queue = createQueue();
    int* visited = (int*)calloc(vertices, sizeof(int));
    
    // Mark the start vertex as visited and enqueue it
    visited[start] = 1;
    enqueue(queue, start);

    printf("Breadth First Traversal starting from vertex %d: ", start);

    // Traverse the graph using BFS
    while (!isEmpty(queue)) {
        int current = dequeue(queue);
        printf("%d ", current);

        // Visit all adjacent vertices of the current vertex
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    
    printf("\n");
    
    free(queue);
    free(visited);
}

int main() {
    // Example graph represented as an adjacency matrix
    int vertices = 6;
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }

    // Adding edges to the graph
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;
    graph[4][5] = graph[5][4] = 1;

    // Starting vertex for BFS traversal
    int startVertex = 0;

    // Perform BFS traversal with timer
    clock_t start = clock();
    BFS(graph, vertices, startVertex);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;
    printf("Breadth-First Search completed in: %f ms\n", time_taken);
    
    // Free dynamically allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
