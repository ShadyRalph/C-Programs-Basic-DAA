#include <stdio.h>
#include <stdlib.h>
void printarr(int* ar, int sz);
int* CocktailSort(int* ar, int sz) ;
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
    ar = CocktailSort(ar, sz);
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

int* CocktailSort(int* ar, int sz) {
    int i, j, swapped=1,temp;
    int start=0,end=sz-1;
    while(swapped){
        if(!swapped){
                break;
            }
        swapped=0;
        //Forward Pass
       // printf("Forward Pass:\n");
        for(i=start;i<end;i++){
            if(++count && ar[i]>ar[i+1]){
                temp=ar[i];
                ar[i]=ar[i+1];
                ar[i+1]=temp;
                swapped=1;
            }
           // printf("%d\n",count);
        }
       // printf("\n");
        if(!swapped){
                break;
            }
            end--;
            swapped=0;
        //Backward Pass
      //  printf("backward Pass:\n");
        for (i = end; i > start; i--) { 
            if (++count && ar[i - 1] > ar[i]) { 
                temp = ar[i - 1];
                ar[i - 1] = ar[i];
                ar[i] = temp;
                swapped = 1;
            }
            //printf("%d\n",count);
        }
       // printf("\n");
        start++;
    }
    return ar;
}


