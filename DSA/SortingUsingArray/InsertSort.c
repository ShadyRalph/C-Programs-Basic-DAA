#include <stdio.h>
#include <stdlib.h>
void printarr(int* ar, int sz);
int* InsertSort(int* ar, int sz) , count=0;

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
    ar = InsertSort(ar, sz);
    printarr(ar, sz);
    printf("No. of Comparisions: %d",count);
    return 0;
}

void printarr(int* ar, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int* InsertSort(int* ar, int sz) {
    int i, j, dat;
    for(i = 1; i < sz; i++) {
        dat = ar[i]; 
        j = i - 1;
        while (j >= 0 && ar[j] > dat && ++count) {
            ar[j + 1] = ar[j]; 
            j--;
        }
        ar[j + 1] = dat; 
    }
    return ar;
}


