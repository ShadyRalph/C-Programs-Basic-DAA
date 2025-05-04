#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *arr,int key,int low,int high){
        if(low>high)
            return -1;
        int mid=(low+high)/2;
        if(arr[mid]<key)
            return binarySearch(arr,key,mid+1,high);
        else if(arr[mid]>key)
            return binarySearch(arr,key,low,mid-1);
        else
            return mid;   
}
int findpivot(int *arr,int n){
    int low=0,high=n-1;
    if(arr[low]<=arr[high])
        return 0;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid+1])
            return mid+1;
        if(arr[mid]<arr[low]){
            high=mid;
        }
        else{//arr[mid]>arr[low] condition assuming all are distinct elements
            low=mid+1;
        }
    }
    return low;
}
int CyclicSearch(int *arr,int key,int n){
    int piv=findpivot(arr,n);
    printf("Pivot: %d\n",arr[piv]);

    int ind=binarySearch(arr,key,0,piv-1);
    if(ind!=-1)
        return ind;
    ind=binarySearch(arr,key,piv,n-1);
    return ind;
}
int main(){
    int arr[]={50,60,10,20,30,40};
    int i,key;
    printf("Array: ");
    for(i=0;i<6;i++)
        printf("%d ",arr[i]);
    
    int ch=1;
    while(ch>0){
        printf("\nEnter the search element: ");
        scanf("%d",&key);
        int ind=CyclicSearch(arr,key,6);
        printf("Index of %d is at: %d\n",key,ind);
        printf("enter 0 to exit or any other no. to repeat: ");
        scanf("%d",&ch);
    }
    return 0;
}
