#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int comp1=0,comp2=0,rswap=0,swapb=0,swaph=0;
void adjust(int *arr, int i, int sz) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int lar = i;
    int temp;
    if (l < sz && ++comp2 && arr[l] > arr[i]) 
        lar = l;
    if (r < sz && ++comp2 && arr[r] > arr[lar]) 
        lar = r;
    if (lar != i && ++comp2) {
        temp = arr[i];
        arr[i] = arr[lar];
        arr[lar] = temp;
        swaph++;
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
    for (i = sz - 1; i > 0; i--) {
        temp = ar[0];
        ar[0] = ar[i];
        ar[i] = temp;
        swaph++;
        adjust(ar, 0, i);
    }
    return ar;
}

int* Bubble(int* ar, int sz) {
    int i, j, temp;
    for(i=0;i<sz;i++){
        for(j=0;j<sz-i-1;j++){
            if(++comp1 && ar[j+1]<ar[j]){
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1] = temp;
                swapb++;
            }
        }
    }
    return ar;
}

void randomSwap(int *arr, int sz){
    int i,ind,temp;
    for(i=0;i<sz;i++){
        ind = rand() % (i+1); 
        temp=arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
        rswap++;
    }
}
void printarr(int* ar, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int main(){
    int sz, i, *ar;
    srand(time(0));
    printf("Enter the size: ");
    scanf("%d", &sz);
    ar = (int*)malloc(sz*sizeof(int));
    for (i = 0; i < sz; i++) 
       ar[i] = (rand() % 100);
    printf("Original Array: \n");
    printarr(ar, sz);

    printf("Bubble sort: ");
    ar=Bubble(ar,sz);
    printarr(ar, sz);
    printf("no. of comparisons: %d\n",comp1);
    printf("no. of swaps: %d\n\n",swapb);

    printf("After random swaps: ");
    randomSwap(ar,sz);
    printarr(ar, sz);
    printf("no. of swaps: %d\n\n",rswap);

    printf("Heap sort: ");
    ar=HeapSort(ar,sz);
    printarr(ar, sz);
    printf("no. of comparisons: %d\n",comp2);
    printf("no. of swaps: %d\n",swaph);

    return 0;
}