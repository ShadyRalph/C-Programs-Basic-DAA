#include <stdio.h>
#include <stdlib.h>
int CyclicSearch(int *arr,int key,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        //checking in right sorted array
        if(arr[mid]<=arr[high]){
            if(arr[mid]<key && key<=arr[high])
                low=mid+1;
            else    
                high=mid-1;
        }//checking in left sorted array
        else{
            if(arr[mid]>key && key>=arr[low])
                high=mid-1;
            else
                low=mid+1;
        }
    }
    return -1;
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
int main(){
    int arr[]={50,60,10,20,30,40};
    int i, piv=findpivot(arr,6),key;
    printf("Array: ");
    for(i=0;i<6;i++)
        printf("%d ",arr[i]);
    printf("\nPivot: %d",arr[piv]);
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
