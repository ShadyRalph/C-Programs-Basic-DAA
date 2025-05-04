#include <stdio.h>
#include <stdlib.h>
void printarr(int* ar, int sz);
void MergeSort(int *arr,int l,int r);
void merge(int *arr,int lb,int mid,int up);
int count=0;

int main() {
    int sz, i, *ar;

    printf("Enter the size: ");
    scanf("%d", &sz);
    
    ar = (int*)malloc(sz * sizeof(int));

    printf("Enter the elements: \n");
    for (i = 0; i < sz; i++) {
        scanf("%d", &ar[i]);
    }

    printf("Original Array: \n");
    printarr(ar, sz);

    printf("After sorting: \n");
    MergeSort(ar,0,(sz-1));
    printarr(ar,sz);
    printf("No. of Comparisions: %d",count);
    return 0;
}

void printarr(int* ar, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void MergeSort(int *arr,int l,int r){
    int mid;
    if(l<r){
        mid=(l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void merge(int *arr, int lb, int mid, int up) {
    int i = lb, j = mid + 1, k = 0;
    int *temp = (int*)malloc(sizeof(int) * (up - lb + 1));

    while (i <= mid && j <= up) {
        if (++count && arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } 
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= up) {
        temp[k++] = arr[j++];
    }
    for (i = lb, k = 0; i <= up; i++, k++) {
        arr[i] = temp[k];
    }
}



