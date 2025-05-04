#include <stdio.h>
void main(){
    int n;
do{
     printf("Enter the number: ");
     scanf("%d",&n);
    if(n%2!=0){
        printf("%d",n);
        printf(" is odd \n");
        break;
    }
     printf("%d",n);
     printf(" is even \n");
}while(1); // another way to make an infinite loop 
}