#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printParenthesis(int **s,int i,int j);
int minScalerMulti(int **cost,int **split,int *Parr,int totDim);
void printTable(int **costsplit,int totDim);

int main(){
    int n,i,j;
    printf("Enter no. of matrices: ");
    scanf("%d",&n);
    int totDim=n+1;
    int *p=(int*)malloc(totDim*sizeof(int));
    printf("Enter the %d dimensions: ",totDim);
    for(i=0;i<totDim;i++){
        scanf("%d",&p[i]);
    }
    printf("\nHence Dimension of each matrix:\n");
    for(i=0;i<totDim-1;i++){
        printf("M%d: %d x %d\n",i,p[i],p[i+1]);
    }
    int **cs=(int**)malloc(totDim*sizeof(int*));
    int **sp=(int**)malloc(totDim*sizeof(int*));
    for(i=0;i<totDim;i++){
        cs[i]=(int*)malloc(totDim*sizeof(int));
        sp[i]=(int*)malloc(totDim*sizeof(int));
    }
    int min=minScalerMulti(cs,sp,p,totDim);
    printf("\nCost Table: \n");
    printTable(cs,totDim);
    printf("\nSplit Table: \n");
    printTable(sp,totDim);
    printf("Optimal Parenthesisation: ");
    printParenthesis(sp,0,n-1);
    printf("\nMin Scalar Multiplication = %d\n",min);
}

void printParenthesis(int **s,int i,int j){
    if(i==j)
        printf("M%d",i);
    else{
        printf("(");
        printParenthesis(s, i, s[i][j]);
        printf("*"); 
        printParenthesis(s,s[i][j]+1,j);
        printf(")");
    }
}

int minScalerMulti(int **cost,int **split,int *Parr,int totDim){
    int i,j,k,l,cst;
    for(i=0;i<totDim-1;i++)
        cost[i][i]=0;
    for(l=1;l<totDim-1;l++){
        for(i=0;i<totDim-1-l;i++){
            j=i+l;
            cost[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                cst=cost[i][k]+cost[k+1][j]+Parr[i]*Parr[k+1]*Parr[j+1];
                if(cst<cost[i][j]){
                    cost[i][j]=cst;
                    split[i][j]=k;
                }
            }
        }
    }
    return cost[0][totDim-2];
}
void printTable(int **costsplit,int totDim){
    int i,j;
    for(i=0;i<totDim-1;i++){
        for(j=0;j<totDim-1;j++){
            if(i<j)
                printf("%8d",costsplit[i][j]);
            else if(i==j){
                printf("%8c",'-');
            }
            else
                printf("%8c",'x');
        }
        printf("\n");
    }
}
