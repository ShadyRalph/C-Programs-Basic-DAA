#include <stdio.h>
void calTable(int ar[][10],int n,int m);

void main(){
    int n,m;
    printf("Enter the 2 numbers whose table you want: \n");
    scanf("%d %d",&n,&m);
    int ar[2][10];
    calTable(ar,n,m);
    for(int i=0;i<2;i++){
        for(int j=0;j<10;j++){
            printf("%d \t",ar[i][j]);
        }
        printf("\n");
    }

}
void calTable(int ar[][10],int n,int m){
    int i,j;
    for(i=0;i<10;i++){
        ar[0][i]=n*(i+1);
        ar[1][i]=m*(i+1);
        }

}

