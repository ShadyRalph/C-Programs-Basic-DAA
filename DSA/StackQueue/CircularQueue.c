#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int rear;
    int front;
    int sz;
    int *arr;
} qu;

qu initialiseQueue(qu *que);
void enqueue(qu *que, int data);
int dequeue(qu *que);
void printarr(qu *que);
void printarr_reverse(qu *que);

int main() {
    qu que;
    que = initialiseQueue(&que);
    int data, ch;
    
    printf("Enter the size: ");
    scanf("%d", &que.sz);
    que.arr = (int*)malloc(que.sz * sizeof(int));
    while(1){
        printf("1 for Enqueue\n");
        printf("2 for Dequeue\n");
        printf("0 for Exit\n");
        printf("Enter: ");
        scanf("%d",&ch);
        if(ch==0)
            return 0;
        if(ch==1){
            printf("Data: ");
            scanf("%d",&data);
            enqueue(&que, data);
                
            }
        if(ch==2){
            int del = dequeue(&que);
            if(del != -1){
                printf("Element deleted: %d\n", del);
                printarr(&que);
                printarr_reverse(&que);
                }
        }
    }
}

qu initialiseQueue(qu *que) {
    que->front = -1;
    que->rear = -1;
    return *que;
}

void enqueue(qu *que, int data) {
    if ((que->rear + 1) % que->sz == que->front) {
        printf("Overflow!!\n");
        return;
    } 
    else if (que->front == -1) {  // First element being inserted
        que->front = 0;
        que->rear = 0;
    } 
    else {
        que->rear = (que->rear + 1) % que->sz;
    }
    que->arr[que->rear] = data;
    printarr(que);
    printarr_reverse(que);
}

int dequeue(qu *que) {
    int temp = 0;
    if (que->front == -1) {
        printf("Underflow!!\n");
        return -1;
    } 
    temp = que->arr[que->front];
    if (que->front == que->rear) {  // Queue has only one element
        que->front = -1;
        que->rear = -1;
    } 
    else {
        que->front = (que->front + 1) % que->sz;
    }
    return temp;
}

void printarr(qu *que) {
    int i;
    printf("Queue: ");
    if (que->front == -1) {
        printf("Empty\n");
        return;
    }
    i = que->front;
    while (i != que->rear) {
        printf("%d ", que->arr[i]);
        i = (i + 1) % que->sz;
    }
    printf("%d ", que->arr[i]);  // Print the last element (rear)
    printf("\n\n");
}

void printarr_reverse(qu *que) {
    int i;
    printf("Queue (Reversed): ");
    if (que->front == -1) {
        printf("Empty\n");
        return;
    }
    i = que->rear;
    while (i != que->front) {
        printf("%d ", que->arr[i]);
        i = (i - 1 + que->sz) % que->sz;  // Move backward in a circular manner
    }
    printf("%d ", que->arr[i]);  // Print the front element
    printf("\n\n");
}
