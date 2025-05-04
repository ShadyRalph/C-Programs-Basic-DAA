#include <stdio.h>
#include <stdlib.h>
int UnimodalSearch(int *arr,int n,int key);
int Maxpeak(int *arr,int n);
int binarySearch(int *arr,int key,int low,int high,int slope);
int main(){
    int i,*arr,n;
    printf("Enter the size: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int key,ch=1;
    while(ch>0){
        printf("Enter the search element: ");
        scanf("%d",&key);
        int ind=UnimodalSearch(arr,n,key);
        if(ind!=-1)
            printf("Index of %d: %d\n",key,ind);
        else
            printf("Element not found!!\n");
        printf("Enter 0 for exit or any other number to continue: ");
        scanf("%d",&ch);
    }
    return 0;
}
int Maxpeak(int *arr,int n){
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]<arr[mid+1])
            low=mid+1;
        else if(arr[mid]>arr[mid+1])
            high=mid;
    }
    return low;
}
int UnimodalSearch(int *arr,int n,int key){
    int peak=Maxpeak(arr,n);
    printf("Peak element: %d\n",arr[peak]);
    //Increasing slope
    int ind=binarySearch(arr,key,0,peak,1);
    if(ind!=-1)
        return ind;
    //decreasing slope   
    ind=binarySearch(arr,key,peak+1,n-1,0);
    return ind;  
}
int binarySearch(int *arr,int key,int low,int high,int slope){
    if(low>high)
        return -1;
    if(slope){//for Increasing slope
        int mid=(low+high)/2;
        if(arr[mid]<key)
            return binarySearch(arr,key,mid+1,high,1);
        else if(arr[mid]>key)
            return binarySearch(arr,key,low,mid-1,1);
        else
            return mid;
    }
    else{//for decreasing slope
        int mid=(low+high)/2;
        if(arr[mid]>key)
            return binarySearch(arr,key,mid+1,high,0);
        else if(arr[mid]<key)
            return binarySearch(arr,key,low,mid-1,0);
        else
            return mid;
    }
}