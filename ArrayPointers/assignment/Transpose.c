#include <stdio.h>
#include <stdlib.h>
    int main(){
    int c,r,i,j,temp;
    printf("Enter no. of rows & columns: ");
    scanf("%d %d",&r,&c);
    int **arr=(int**) malloc(r * sizeof(int*));
    for(i=0;i<r;i++)
        arr[i]=(int*)malloc(c*sizeof(int));
    printf("Enter the elements: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("Array of order %d x %d: \n",r,c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    /*for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }*/

    printf("Transpose of the above: \n");
    for(i=0;i<c;i++){
        for(j=0;j<r;j++)
            printf("%d ",arr[j][i]);
        printf("\n");
    }
}