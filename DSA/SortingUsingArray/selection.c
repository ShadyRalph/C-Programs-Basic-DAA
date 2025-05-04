#include <stdio.h>
#include <stdlib.h>
void printarr(int* ar, int sz);
int* SelectSort(int* ar, int sz) ;
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
    ar = SelectSort(ar, sz);
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

int* SelectSort(int* ar, int sz) {
    int i, j, min=0,temp=0;
    for(i = 0; i < sz-1; i++) {
        min= i; 
        for(j=i+1;j<sz;j++){
            ++count;
            if(ar[j]<ar[min])
                min=j;
        }
        temp=ar[min];
        ar[min]=ar[i];
        ar[i]=temp;
    }
    return ar;
}


