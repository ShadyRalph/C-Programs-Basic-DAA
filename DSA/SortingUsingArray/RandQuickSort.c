#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
int Pivot(int *arr, int low, int high, int pind);
int partition(int *arr, int low, int high, int pind);
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

    srand(time(0)); 

    printf("Original Array: ");
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

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

void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int pind = low + rand() % (high - low + 1);

        int partind = partition(arr, low, high, pind);
        QuickSort(arr, low, partind);
        QuickSort(arr, partind + 1, high);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
