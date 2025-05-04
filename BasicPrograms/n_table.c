#include<stdio.h>
void main(){
    int i,j,n,product;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%d ",n);
         printf("X %d ",i);
          printf("= %d \n",n*i);
    }
}