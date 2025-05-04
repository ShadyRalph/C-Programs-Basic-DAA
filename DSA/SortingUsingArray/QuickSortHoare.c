#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
int Pivot(int *arr, int low, int high, int pind);
int partition(int *arr, int low, int high, int pind);
void QuickSort(int *arr, int low, int high, int pind);
void printArray(int *arr, int n);


int main() {
    int n, pind;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index of the pivot element (0 to %d): ", n - 1);
    scanf("%d", &pind);

    if (pind < 0 || pind >= n) {
        printf("Invalid pivot index! Exiting program.\n");
        return -1;
    }

    printf("Original Array: ");
    printArray(arr, n);

    QuickSort(arr, 0, n - 1, pind);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Pivot(int *arr, int low, int high, int pind) {
    swap(&arr[low], &arr[pind]);
    return arr[low]; 
}

int partition(int *arr, int low, int high, int pind) {
    int pivot = Pivot(arr, low, high, pind);

    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void QuickSort(int *arr, int low, int high, int pind) {
    if (low < high) {
        int partind = partition(arr, low, high, pind);

        QuickSort(arr, low, partind, low);
        QuickSort(arr, partind + 1, high, partind + 1);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


