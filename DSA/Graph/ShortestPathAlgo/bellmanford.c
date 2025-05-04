#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

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

void bellmanFord(int **graph, int V, int source, char **names) {
    int *dist = (int *)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("\nGraph contains a negative weight cycle!\n");
                free(dist);
                return;
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
        fscanf(file, " %[^\n]s", names[i]);
    }
    printf("\nReading successful!\n");

    while (1) {
        printf("\nEnter the source vertex for Bellman-Ford algorithm:\n");
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

        bellmanFord(graph, V, source, names);
    }

    fclose(file);
    return 0;
}
