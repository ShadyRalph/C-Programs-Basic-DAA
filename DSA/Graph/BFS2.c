#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

static int front = -1;
static int rear = -1;
static int count = 0;
int queue[MAX_QUEUE_SIZE];

void enqueue(int n) {
    if (count == MAX_QUEUE_SIZE) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = n;
    count++;
}

void dequeue() {
    if (count == 0) {
        printf("Queue underflow\n");
        return;
    }
    int temp = queue[front++];
    count--;
    printf("\nVertex dequeued %d\n", temp);
    if (count == 0)
        front = rear = -1; // Reset when queue is empty
}

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int);
struct Graph {
    int numVertices;
    struct node** adjLists;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int s, char* color, int* d, int* pi);
void printpath(struct Graph* graph, int s, int v, int* pi);

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\nAdjacency list of vertex %d\n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void bfs(struct Graph* graph, int s, char* color, int* d, int* pi) {
    for (int v = 0; v < graph->numVertices; v++) {
        if (v != s) {
            color[v] = 'w';
            d[v] = 9999;
            pi[v] = -1;
        }
    }
    color[s] = 'g';
    d[s] = 0;
    pi[s] = -1;
    enqueue(s);
    while (count != 0) {
        int v = queue[front];
        printf("\nVertex %d\n", v);
        struct node* temp = graph->adjLists[v];
        while (temp) {
            if (color[temp->vertex] == 'w') {
                printf("\nProcessing vertex %d\n", temp->vertex);
                color[temp->vertex] = 'g';
                d[temp->vertex] = d[v] + 1;
                pi[temp->vertex] = v;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
        dequeue();
        color[v] = 'b';
    }
}

void printpath(struct Graph* graph, int s, int v, int* pi) {
    if (v == s)
        printf(" %d ", s);
    else if (pi[v] == -1)
        printf("No path from %d to %d exists", s, v);
    else {
        printpath(graph, s, pi[v], pi);
        printf(" -> %d ", v);
    }
}

int main() {
    int numVertices = 0, src, dest, s;

    printf("Enter the edges (source and destination for each edge, -1 -1 to stop):\n");

    // Dynamically determine the number of vertices
    struct Graph* graph = NULL;

    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
            break;

        // Determine the maximum vertex index to adjust graph size
        if (src > numVertices) numVertices = src;
        if (dest > numVertices) numVertices = dest;

        // Create graph dynamically if not already created
        if (!graph) {
            graph = createGraph(numVertices + 1);
        }

        // If the graph size is insufficient, resize it
        if (graph->numVertices <= numVertices) {
            int newSize = numVertices + 1;
            graph->adjLists = realloc(graph->adjLists, newSize * sizeof(struct node*));
            for (int i = graph->numVertices; i < newSize; i++) {
                graph->adjLists[i] = NULL;
            }
            graph->numVertices = newSize;
        }

        // Add the edge to the graph
        addEdge(graph, src, dest);
    }

    printf("Graph created successfully.\n");
    printGraph(graph);

    // Initialize BFS-related arrays dynamically
    char* color = malloc(graph->numVertices * sizeof(char));
    int* d = malloc(graph->numVertices * sizeof(int));
    int* pi = malloc(graph->numVertices * sizeof(int));

    // Prompt user for the starting vertex
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &s);

    // Perform BFS
    bfs(graph, s, color, d, pi);

    // Print BFS results
    printf("\nVertex  Color  Distance  Predecessor\n");
    for (int v = 0; v < graph->numVertices; v++) {
        printf("\n  %d       %c      %d         %d\n", v, color[v], d[v], pi[v]);
    }

    printf("\nPredecessor Subgraph\n");
    for (int v = 0; v < graph->numVertices; v++) {
        if (v != s) {
            printpath(graph, s, v, pi);
            printf("\n");
        }
    }

    // Free dynamically allocated memory
    free(color);
    free(d);
    free(pi);

    return 0;
}

