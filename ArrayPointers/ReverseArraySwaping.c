#include <stdio.h>
void reverse(int ar[] , int n);

int main(){
    int n,i,num1,num2;
     printf("Enter the size of the array\n");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
    //printf("\n");
    scanf("%d",&ar[i]);
    }
    int *ptr=&ar[0];
    reverse(ar, n);
    printf("Array in reverse: \n");
    for(i=0;i<n;i++){
        printf("%d ",*(ptr+i));
    }
    return 0;
}
void reverse(int ar[], int n){
     int i,num1,num2;
     for(i=0;i<n/2;i++){
     num1=ar[i];
     num2=ar[n-1-i];
     ar[i]=num2;
     ar[n-1-i]=num1;
    }
}
