#include <stdio.h>
void main(){

    int n;//declaration
    printf("Enter the number: ");
    scanf("%d",&n);
    int i=1,sum=0,nn=n;
do{
    printf("%d ",i);
    printf("  %d \n",nn);
    sum+=i;
    i++;
    nn--;
}while(i<=n);
printf("SUM: %d",sum);
}