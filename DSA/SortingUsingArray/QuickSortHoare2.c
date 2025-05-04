#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void QuickSort(int *arr, int low, int high);
void printArray(int *arr, int n);

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArray(arr, n);

    free(arr);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }        
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j; 
}

void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int partind = partition(arr, low, high);
        QuickSort(arr, low, partind-1); 
        QuickSort(arr, partind + 1, high);
    }
}


void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
