#include <stdio.h>
#include <stdlib.h>
    int main(){
    int n,i,pos;
    printf("Enter the size: ");
    scanf("%d",&n);
    int *arr=(int*) malloc(n * sizeof(int));
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the location where you wish to delete element: ");
    scanf("%d", &pos);
    if (pos>= n+1)
        printf("Deletion not possible.\n");
    else
    {
        for (i = pos-1; i < n - 1; i++)
            arr[i] = arr[i+1];
        printf("Resultant array:\n");
        for (i = 0; i < n-1; i++)
            printf("%d\n", arr[i]);
    }

   return 0;
}