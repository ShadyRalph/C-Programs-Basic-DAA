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
            enqueue(&que,data);
                
            }
        if(ch==2){
            int del=dequeue(&que) ;
            if(del!=-1){
                printf("Element delted: %d\n",del);
                printarr(&que);
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
    if (que->rear == que->sz - 1) {
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
    que->arr[que->rear] = data;
    printarr(que);
}

int dequeue(qu *que) {
    int temp = 0;
    if (que->front == -1) {
        printf("Underflow!!\n");
        return -1;
    } 
    else if (que->front == que->rear) {
        temp = que->arr[que->front];
        que->rear = -1;
        que->front = -1;
    } 
    else {
        temp = que->arr[que->front];
        que->front++;
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
    for (i = que->rear; i >= que->front; i--)
        printf("%d ", que->arr[i]);
    printf("\n\n");
}

