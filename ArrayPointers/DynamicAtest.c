#include <stdio.h>
#include <stdlib.h>
void main(){
    int i;
    int *ptr=(int*)malloc(5*sizeof(int));//garbage value is stored
    int *ptr1=(int*)calloc(10,sizeof(int));// 0s are initialised when using calloc but only 10 times
    for(i=0;i<5*sizeof(int);i++){
        printf("%d ",ptr[i]);
        printf("\n");
    }
    printf("for calloc: \n");
    for(;;){
        printf("%d ",*ptr1++);
        printf("\n");
        if(*ptr1!=0)
            break;
    }
}
