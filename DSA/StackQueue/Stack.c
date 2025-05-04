#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int *arr;
    int top;
    int capcity;
}st;

void push(st *stack, int dat);
int pop(st *stack);
void printarr(st *stack);

int main(){
    st stack;
    printf("Enter the capacity: ");
    scanf("%d",&stack.capcity);
    stack.top=-1;
    stack.arr=(int*)malloc(stack.capcity * sizeof(int));
    int ch,data;
    while(1){
        printf("1 for Push\n");
        printf("2 for Pop\n");
        printf("0 for Exit\n");
        printf("Enter: ");
        scanf("%d",&ch);
        if(ch==0)
            return 0;
        if(ch==1){
            printf("Data: ");
            scanf("%d",&data);
            push(&stack,data);
                
            }
        if(ch==2){
            int del=pop(&stack);
            if(del!=-1){
                printf("Element delted: %d\n",del);
                printarr(&stack);
                }
        }
    }
}

void printarr(st *stack) {
    printf("Current stack: ");
    if(stack->top==-1){
        printf("Empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n\n");
}

void push(st *stack, int dat){
    if(stack->top==stack->capcity-1){
        printf("Overflow!!\n");
        return;
    }
    stack->arr[++stack->top]=dat;
    printf("\n");
    printarr(stack);

}

int pop(st *stack){
    if(stack->top==-1){
        printf("Stack is now Empty!! Underflow\n");
        return -1;
    }
    return (stack->arr[stack->top--]);
}