#include <stdio.h>
#include <stdlib.h>
void printarr(int* ar, int sz);
int* ImprovBubble(int* ar, int sz);
static int count=0;

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
    ar = ImprovBubble(ar, sz);
    printarr(ar, sz);
    printf("No. of Coparisions: %d",count);
    return 0;
}

void printarr(int* ar, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int* ImprovBubble(int* ar, int sz) {
    int i, j, temp;
    int bound = sz;
    do {
        i = 0; 
        for (j = 0; j < bound - 1; j++) {
            count++;
            if (ar[j] > ar[j + 1]) {
                temp = ar[j + 1];
                ar[j + 1] = ar[j];
                ar[j] = temp;
                i = j;
            }
        }
        bound = i+1 ;
    } while (i > 0);
    return ar;
}

