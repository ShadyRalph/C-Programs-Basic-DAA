#include <stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the size: ");
    scanf("%d",&n);
    int p=(2*n)-1,r=0;

    
    for(i=1;i<=n;i++){
        for(j=1;j<=p;j++){
            if(j<=r || j>p-r){
                printf(" ");
            }
            else
                printf("*");

        }
        printf("\n");
        r++;
    }
    return 0;
}