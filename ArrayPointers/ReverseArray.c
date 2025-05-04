#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i,pos;
    printf("Enter the size: ");
    scanf("%d",&n);
    int *ar=(int*) malloc(n * sizeof(int));
    printf("Enter %d elements\n", n);
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    printf("Array in reverse: \n");
    for(i=n-1;i>=0;i--)
        printf("%d ",ar[i]);//or can also use ar[i]
    
    return 0;
}
