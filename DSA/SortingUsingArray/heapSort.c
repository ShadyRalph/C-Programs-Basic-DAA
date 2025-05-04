#include <stdio.h>
#include <stdlib.h>

void printarr(int* ar, int sz);
int* HeapSort(int* ar, int sz);
void adjust(int *arr, int i, int sz);
void heapify(int *arr, int sz);
static int count = 0;

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
    ar = HeapSort(ar, sz);
    printarr(ar, sz);
    printf("No. of Comparisons: %d\n", count);
    return 0;
}

void printarr(int* ar, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void adjust(int *arr, int i, int sz) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int lar = i;
    int temp;

    count++;
    if (l < sz && arr[l] > arr[i]) {
        lar = l;
    }

    count++;
    if (r < sz && arr[r] > arr[lar]) {
        lar = r;
    }

    if (lar != i) {
        temp = arr[i];
        arr[i] = arr[lar];
        arr[lar] = temp;
        adjust(arr, lar, sz);
    }
}

void heapify(int *arr, int sz) {
    for (int i = (sz - 2) / 2; i >= 0; i--) {
        adjust(arr, i, sz);
    }
}

int* HeapSort(int* ar, int sz) {
    heapify(ar, sz);
    int i, temp;
    count=0;
    for (i = sz - 1; i > 0; i--) {
        temp = ar[0];
        ar[0] = ar[i];
        ar[i] = temp;

        adjust(ar, 0, i);
    }
    return ar;
}


