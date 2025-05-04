#include <stdio.h>
#include <stdlib.h>

int vert;

typedef struct Queue{
    int front, rear;
    int *data;
    int size;
} Queue;

typedef struct Stack{
    int top;
    int *data;
    int size;
} Stack;

void printGraph(int **adj);
void dfs(int **adj, int *visited, int start);
void bfs(int **adj, int start);

Queue *createQueue(int size);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int isQueueEmpty(Queue *queue);


Stack *createStack(int size);
void push(Stack *stack, int value);
int pop(Stack *stack);
int isStackEmpty(Stack *stack);

int main() {
    int s, d, ch, start;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &vert);

    int **adj = (int **)malloc(vert * sizeof(int *));
    for (int i = 0; i < vert; i++) {
        adj[i] = (int *)calloc(vert, sizeof(int));
    }

    printf("Enter edges (Enter -1 -1 to stop):\n");
    while (1) {
        printf("Enter an Edge from node (0 to %d) to node (0 to %d): ", vert - 1, vert - 1);
        scanf("%d %d", &s, &d);
        if (s == -1 && d == -1) {
            break;
        }
        if (s >= 0 && s < vert && d >= 0 && d < vert) {
            adj[s][d] = 1;
            adj[d][s] = 1; 
        } else {
            printf("Invalid edge! Please enter values between 0 and %d.\n", vert - 1);
        }
    }

    do {
        printf("\n1 for BFS\n2 for DFS\n3 for printing adjacency matrix\n0 to Exit\nEnter: ");
        scanf("%d", &ch);
        if(ch==1){
            printf("Enter the Vertex from which you want to start: ");
            scanf("%d", &start);
            printf("BFS: ");
            bfs(adj, start);
        }

        if(ch==2){
            printf("Enter the Vertex from which you want to start: ");
            scanf("%d", &start);
            printf("DFS: ");
            int visited[vert];
            for (int i = 0; i < vert; i++) 
                visited[i] = 0;
            dfs(adj, visited, start);
            printf("\n");
        }

        if(ch==3)
            printGraph(adj);
        if(ch==0)
            printf("Exiting program...\n");
        
    } while (ch != 0);
    return 0;
}

void printGraph(int **adj) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < vert; j++) {
            printf(" %d  ", adj[i][j]);
        }
        printf("\n");
    }
}

void dfs(int **adj, int *visited, int start) {
    Stack *stack = createStack(vert);
    push(stack, start);

    while (!isStackEmpty(stack)) {
        int current = pop(stack);
        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = vert - 1; i >= 0; i--) { // Reverse to maintain order
                if (adj[current][i] == 1 && !visited[i]) {
                    push(stack, i);
                }
            }
        }
    }
}

void bfs(int **adj, int start) {
    int visited[vert];
    for (int i = 0; i < vert; i++) {
        visited[i] = 0;
    }

    Queue *queue = createQueue(vert);
    enqueue(queue, start);
    visited[start] = 1;

    while (!isQueueEmpty(queue)) {
        int current = dequeue(queue);
        printf("%d ", current);

        for (int i = 0; i < vert; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(size * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(Queue *que, int val) {
    if (que->rear == que->size - 1) {
        printf("Overflow!!\n");
        return;
    } 
    else if (que->front == -1) {
        que->rear = 0;
        que->front = 0;
    } 
    else {
        que->rear++;
    }
    que->data[que->rear] = val;
}

int dequeue(Queue *que) {
    int temp = 0;
    if (que->front == -1) {
        printf("Underflow!!\n");
        return -1;
    } 
    else if (que->front == que->rear) {
        temp = que->data[que->front];
        que->rear = -1;
        que->front = -1;
    } 
    else {
        temp = que->data[que->front];
        que->front++;
    }
    return temp;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}


Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(Stack *stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

