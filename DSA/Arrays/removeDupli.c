#include <stdio.h>
#include <stdlib.h>

void printarr(char* ar, int sz);
char *rmv_dup(char* arr, int *n);

int main() {
    int sz, i;
    char *ar;

    printf("Enter the size: ");
    scanf("%d", &sz);
    
    ar = (char*)malloc(sz * sizeof(char));

    printf("Enter the elements: \n");
    for (i = 0; i < sz; i++) {
        scanf(" %c", &ar[i]); // Space before %c to ignore newline
    }

    printf("Original Array: \n");
    printarr(ar, sz);
    
    ar = rmv_dup(ar, &sz); // Make sure rmv_dup updates the pointer properly

    printf("Array after duplicates are removed: \n");
    printarr(ar, sz);

    free(ar);
    return 0;
}

void printarr(char* ar, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%c ", ar[i]);
    }
    printf("\n");
}

char *rmv_dup(char* arr, int *n) {
    int i, j, k;
    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n;) { 
            if (arr[i] == arr[j]) {
                for (k = j; k < *n - 1; k++)
                    arr[k] = arr[k + 1];
                (*n)--; 
            } 
            else {
                j++; 
            }
        }
    }
    return arr;
}
