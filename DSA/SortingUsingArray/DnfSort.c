#include <stdio.h>
#include <stdlib.h>
void DnfSort(int *arr, int n, int piv);
void printarr(int *arr, int n);

int main() {
    int n, piv,ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while(1){
    printf("Enter the pivot element: ");
    scanf("%d", &piv);

    printf("Original Array: ");
    printarr(arr, n);

    DnfSort(arr, n, piv);

    printf("Sorted Array: ");
    printarr(arr, n);
    printf("Enter 0 for exit else any other number to continue: ");
    scanf("%d",&ch);
    if(ch==0)
        return 0;
    }
}

void DnfSort(int *arr, int n, int piv) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] < piv) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } 
        else if (arr[mid] == piv) 
            mid++;
        
        else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

void printarr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


