#include <stdio.h>
#include <stdlib.h>
int *sort(int*, int);
int linear(int*, int, int);
int binary(int*, int, int, int);
int interpol(int*, int, int, int);
void printarr(int*, int);

static int lin, bin, inter;

int main() {
        int sz, i, *ar, ch, ele, pos, *arr;

        printf("Enter the size: ");
        scanf("%d", &sz);
        ar = (int*)malloc(sz * sizeof(int));

        printf("Enter the elements: \n");
        for (i = 0; i < sz; i++) {
            scanf("%d", &ar[i]);
        }

        printf("Array: ");
        printarr(ar, sz);

    while (1) {
        printf("1 for linear search\n");
        printf("2 for binary search\n");
        printf("3 for interpolation search\n");
        printf("0 for exit\nEnter: ");
        scanf("%d", &ch);

        if (ch == 0) 
            return 0;
        printf("Enter the search element: ");
        scanf("%d", &ele);

        if (ch == 1) {
            lin = 0;
            pos = linear(ar, sz, ele);
            if(pos<0){
                printf("Element does not exist in the array.\n");
                continue;
            }
            printf("Position of the element: %d\n", pos+1);
            printf("No. of comparisons: %d\n", lin);
        }

        if (ch == 2) {
            bin = 0;
            arr = sort(ar, sz);
            printf("Array after sort: \n");
            printarr(arr, sz);
            pos = binary(arr, 0, sz - 1, ele);
            if(pos<0){
                printf("Element does not exist in the array.\n");
                continue;
            }
            printf("Position of the element: %d\n", pos+1);
            printf("No. of comparisons: %d\n", bin);
        }

        if (ch == 3) {
            inter = 0;
            arr = sort(ar, sz);
            printf("Array after sort: \n");
            printarr(arr, sz);
            pos = interpol(arr, 0, sz - 1, ele);
            if(pos<0){
                printf("Element does not exist in the array.\n");
                continue;
            }
            printf("Position of the element: %d\n", pos+1);
            printf("No. of comparisons: %d\n", inter);
        }
    }
}

int *sort(int* ar, int sz) {
    int i, j, temp;
    for (i = 0; i < sz - 1; i++) {
        for (j = 0; j < sz - i - 1; j++) {
            if (ar[j] > ar[j + 1]) {
                temp = ar[j + 1];
                ar[j + 1] = ar[j];
                ar[j] = temp;
            }
        }
    }
    return ar;
}

int linear(int* ar, int sz, int srele) {
    int i;
    for (i = 0; i < sz; i++) {
        lin++;
        if (srele == ar[i]) {
            return i;
        }
    }
    return -1;
}

int binary(int* ar, int down, int up, int srele) {
    if (up < down)
        return -1;

    int mid = (down + up) / 2;
    bin++;

    if (srele == ar[mid])
        return mid;
    if (srele < ar[mid])
        return binary(ar, down, mid - 1, srele);
    else
        return binary(ar, mid + 1, up, srele);
}

int interpol(int* ar, int down, int up, int srele) {
    if(up < down || ar[up]==ar[down])
        return -1;
        int mid = down + ((srele - ar[down]) * (up - down)) / (ar[up] - ar[down]);
        inter++;

        if (srele == ar[mid])
            return mid;
        if (srele < ar[mid])
            return interpol(ar, down, mid - 1, srele);
        if (srele > ar[mid])
            return interpol(ar, mid + 1, up, srele);
    
    return -1;
}

void printarr(int* ar, int sz) {
    int i;
    for (i = 0; i < sz; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
