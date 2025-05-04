#include <stdio.h>
int calsum(int);
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("sum of first %d natural numbers = %d \n",n,calsum(n));
}

int calsum(int n){
    if(n<=1)
        return n;
    return(n+ calsum(n-1));
}