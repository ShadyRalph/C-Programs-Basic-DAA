#include <stdio.h>
void main(){

    int n;//declaration
    printf("Enter the number: \n");
    scanf("%d",&n);
    int i=1;
do{
    printf("%d ",i);
    i++;
    printf("%d \n",i);//after increment
}while(i<=n);
}