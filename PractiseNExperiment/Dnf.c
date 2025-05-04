#include <stdio.h>
#include <stdlib.h>
void dnfSort(int *arr,int n,int piv);
void swapper(int *a,int *b);
void printarr(int *arr,int n);

int main(){
    int n,i,piv;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
    int ch=1;
    while(ch>0){
        printf("Array: ");
        printarr(arr,n);
        printf("Enter the pivot element: ");
        scanf("%d",&piv);
        dnfSort(arr,n,piv);
        printf("Array after dnf sort: ");
        printarr(arr,n);
        printf("Enter 0 to exit or any other no. to continue: ");
        scanf("%d",&ch);
    }
    return 0;
}
void dnfSort(int *arr,int n,int piv){
    int mid=0,low=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]<piv){
            swapper(&arr[low],&arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==piv){
            mid++;
        }
        else{
            swapper(&arr[high],&arr[mid]);
            high--;
        }
    }
}
void swapper(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printarr(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}