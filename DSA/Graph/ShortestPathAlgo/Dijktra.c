#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
//Greedy Method
typedef struct {
    int vertex, distance;
} MinHeapNode;

typedef struct {
    int size, capacity, *pos;
    MinHeapNode **array;
} MinHeap;

MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->vertex = v;
    node->distance = dist;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return heap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->distance < heap->array[smallest]->distance)
        smallest = left;

    if (right < heap->size && heap->array[right]->distance < heap->array[smallest]->distance)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode* smallNode = heap->array[smallest];
        MinHeapNode* idxNode = heap->array[idx];
        heap->pos[smallNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isInMinHeap(MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

MinHeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    MinHeapNode* root = heap->array[0];
    MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->distance = dist;

    while (i && heap->array[i]->distance < heap->array[(i - 1) / 2]->distance) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printShortestPaths(int *dist, int V, int source, char **names) {
    int total=0,i;
    printf("\nShortest paths from %s:\n", names[source]);
    for (i = 0; i < V; i++) {
        printf("%s -> %s : Distance = ", names[source], names[i]);
        if (dist[i] == INT_MAX)
            printf("INF\n");
        else{
            printf("%d\n", dist[i]);
            total += dist[i];
        }
    }
    printf("\nTotal Minimum Cost of the MST: %d\n", total);
}

void dijkstra(int **graph, int V, int source, char **names) {
    int *dist = (int *)malloc(V * sizeof(int));
    MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    dist[source] = 0;
    decreaseKey(heap, source, 0);
    heap->size = V;

    while (heap->size > 0) {
        MinHeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(heap, v) && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(heap, v, dist[v]);
            }
        }
    }

    printShortestPaths(dist, V, source, names);
    free(dist);
}

int main() {
    FILE *file;
    int V, E, i, j, source;

    file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    fscanf(file, "%d", &V);
    fscanf(file, "%d", &E);
    
    int **graph = (int **)malloc(V * sizeof(int *));
    for (i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    int v1, v2, weight;
    for (i = 0; i < E; i++) {
        fscanf(file, "%d %d %d", &weight, &v1, &v2);
        graph[v1][v2] = weight;
        graph[v2][v1] = weight;
    }

    char **names = (char **)malloc(V * sizeof(char *));
    for (i = 0; i < V; i++) {
        names[i] = (char *)malloc(100 * sizeof(char));
    }
    for (i = 0; i < V; i++) {
        fscanf(file," %[^\n]s",names[i]);
    }
    printf("\nReading successful!\n");

    while(1) {
        printf("\nEnter the source vertex for Dijkstra's algorithm:\n");
        for (i = 0; i < V; i++) {
            printf("%d. %s\n", i, names[i]);
        }
        printf("Enter your choice: ");
        scanf("%d", &source);

        if (source < 0 || source >= V) {
            printf("Invalid source vertex. Exiting...\n");
            fclose(file);
            return -1;
        }

        dijkstra(graph, V, source, names);
    }

    fclose(file);
    return 0;
}
