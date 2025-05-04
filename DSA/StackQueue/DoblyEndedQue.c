#include <stdio.h>
#include <stdlib.h>1
typedef struct deque {
    int rear;
    int front;
    int sz;
    int *arr;
} deq;

deq initialiseDeque(deq *que);
void enqueue_rear(deq *que, int data);
void enqueue_front(deq *que, int data);
int dequeue_rear(deq *que);
int dequeue_front(deq *que);
void printarr(deq *que);
void printarr_reverse(deq *que);

int main() {
    deq que;
    int data, ch,ch2;
    while(1){
        printf("1 for Input Restricted\n");
        printf("2 for Output Restricted\n");
        printf("0 for Exit\n");
        printf("Enter: ");
        scanf("%d",&ch2);   
        if(ch2==0)
            return 0;
        if(ch2==1){
            que = initialiseDeque(&que);
            printf("Enter the size: ");
            scanf("%d", &que.sz);
            que.arr = (int*)malloc(que.sz * sizeof(int));
            do{
                printf("1 for Enqueue at rear\n");
                printf("2 for Dequeue from rear\n");
                printf("3 for Dequeue from front\n");
                printf("0 to go back to the main menu\n");
                printf("Enter: ");
                scanf("%d",&ch);
                if(ch==1){
                    printf("Data: ");
                    scanf("%d",&data);
                    enqueue_rear(&que, data);
                }
                if(ch==2){
                    int del = dequeue_rear(&que);
                    if(del != -1){
                        printf("Element deleted from rear: %d\n", del);
                        printarr(&que);
                        printarr_reverse(&que);
                    }
                }
                if(ch==3){
                    int del = dequeue_front(&que);
                    if(del != -1){
                        printf("Element deleted from front: %d\n", del);
                        printarr(&que);
                        printarr_reverse(&que);
                    }
                }
            }while(ch!=0);
        }
        if(ch2==2){
            que = initialiseDeque(&que);
            printf("Enter the size: ");
            scanf("%d", &que.sz);
            que.arr = (int*)malloc(que.sz * sizeof(int));
            do{
                printf("1 for Enqueue at rear\n");
                printf("2 for Enqueue at front\n");
                printf("3 for Dequeue from front\n");
                printf("0 to go back to the main menu\n");
                printf("Enter: ");
                scanf("%d",&ch);
                if(ch==1){
                    printf("Data: ");
                    scanf("%d",&data);
                    enqueue_rear(&que, data);
                        
                    }
                if(ch==2){
                    printf("Data: ");
                    scanf("%d",&data);
                    enqueue_front(&que, data);
                        
                }
                if(ch==3){
                    int del = dequeue_front(&que);
                    if(del != -1){
                        printf("Element deleted from front: %d\n", del);
                        printarr(&que);
                        printarr_reverse(&que);
                    }
                }
            }while(ch!=0);
        }
    }
}

deq initialiseDeque(deq *que) {
    que->front = -1;
    que->rear = -1;
    return *que;
}

void enqueue_rear(deq *que, int data) {
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

void enqueue_front(deq *que, int data) {
    if ((que->rear + 1) % que->sz == que->front) {
        printf("Overflow!!\n");
        return;
    } 
    else if (que->front == -1) {  // First element being inserted
        que->front = 0;
        que->rear = 0;
    } 
    else {
        que->front = (que->front - 1 + que->sz) % que->sz;
    }
    que->arr[que->front] = data;
    printarr(que);
    printarr_reverse(que);
}

int dequeue_rear(deq *que) {
    if (que->front == -1) {
        printf("Underflow!!\n");
        return -1;
    } 
    int temp = que->arr[que->rear];
    if (que->front == que->rear) {  // Queue has only one element
        que->front = -1;
        que->rear = -1;
    } 
    else {
        que->rear = (que->rear - 1 + que->sz) % que->sz;
    }
    return temp;
}

int dequeue_front(deq *que) {
    if (que->front == -1) {
        printf("Underflow!!\n");
        return -1;
    } 
    int temp = que->arr[que->front];
    if (que->front == que->rear) {  // Queue has only one element
        que->front = -1;
        que->rear = -1;
    } 
    else {
        que->front = (que->front + 1) % que->sz;
    }
    return temp;
}

void printarr(deq *que) {
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

void printarr_reverse(deq *que) {
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
