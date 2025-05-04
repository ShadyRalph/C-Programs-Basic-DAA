#include <stdio.h>
int main(){
    long n,n1;
    printf("Enter Rs.");
    scanf("%ld",&n);
    n1=n;
    long d1,d2,d3,d4,d5,d6,d7;
    d1= n1/100;
    n1=n1%100;
    d2=n1/50;
    n1=n1%50;
    d3=n1/10;
    n1=n1%10;
    d4=n1/5;
    n1=n1%5;
    d5=n1/2;
    n1=n1%2;
    d6=n1/1;
    printf("no. Rs. 100: %ld \n",d1);
    printf("no. Rs. 50: %ld \n",d2);
    printf("no. Rs. 10: %ld \n",d3);
    printf("no. Rs. 5: %ld \n",d4);
    printf("no. Rs. 2: %ld \n",d5);
    printf("no. Rs. 1: %ld \n",d6);

    return 0;
}