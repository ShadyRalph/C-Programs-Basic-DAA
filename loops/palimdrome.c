#include <stdio.h>
int main(){
    int n,num,rev=0,sum=0,d;
    printf("Enter the number: ");
    scanf("%d", &n);
    num=n;
    while(num!=0){
        d=num%10;
        sum+=d;
        rev=rev*10+d;
        num=num/10;
    }
    printf("sum of the digits = %d \n",sum);
    if(rev==n)
    printf("It is a palimdrome number");
    else
    printf("It is not a palimdrome number");
    return 0;
}