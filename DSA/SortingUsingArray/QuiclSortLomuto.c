#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void quickSort(int *arr, int low, int high);
void printarr(int *arr, int n);

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printarr(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printarr(arr, n);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { 
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printarr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printarr(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printarr(arr, n);

    return 0;
}