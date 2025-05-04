#include <stdio.h>
#include <stdlib.h>
    int main(){
    int c,r,k,i,j,temp,r1,c1;
    printf("Enter no. of rows & columns 1st matrix: ");
    scanf("%d %d",&r,&c);
    int **arr=(int**) malloc(r * sizeof(int*));
    for(i=0;i<r;i++)
        arr[i]=(int*)malloc(c*sizeof(int));
    printf("Enter no. of rows & columns of 2nd matrix: ");
    scanf("%d %d",&r1,&c1);
    int **ar=(int**) malloc(r1 * sizeof(int*));
    for(i=0;i<r1;i++)
        ar[i]=(int*)malloc(c1*sizeof(int));

    if(r!=r1 || c!=c1){
        printf("Addition not possible.");
        return 0;
    }
    printf("Enter the elements of the 1st matrix: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("Enter the elements of the 2nd matrix: \n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++)
            scanf("%d",&ar[i][j]);
    }
    printf("1st matrix of order %d x %d: \n",r,c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    printf("2nd matrix of order %d x %d: \n",r1,c1);
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++)
            printf("%d ",ar[i][j]);
        printf("\n");
    }
    

    int **ar1=(int**) malloc(r * sizeof(int*));
    for(i=0;i<r;i++)
        ar1[i]=(int*)malloc(c*sizeof(int));

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ar1[i][j] = 0;
        }
    }

    for(i=0;i<r;i++){
        for(j=0;j<c1;j++){
            ar1[i][j]=arr[i][j]+ar[i][j];
        }
    }

    printf("Resultant matrix of order %d x %d: \n",r,c1);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",ar1[i][j]);
        printf("\n");
    }

    return 0;
}