#include <stdio.h>
void fibonacci(int ar[] , int n);

int main(){
int n,i,num1,num2;
     printf("Enter the size of the array\n");
    scanf("%d",&n);
    int ar[n];
    fibonacci(ar, n);
    printf("fibonacci: \n");
    for(i=0;i<n;i++){
        printf("%d \t",ar[i]);
    }

    return 0;
}
void fibonacci(int ar[], int n){
     int i,num1,num2;
     ar[0]=0;
     ar[1]=1;
     for(i=2;i<n;i++){
        ar[i]=ar[i-1]+ar[i-2];   
    }
}
