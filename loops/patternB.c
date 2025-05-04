#include <stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the size: ");
    scanf("%d",&n);
    int p=1;
    for(i=n;i>0;i--){
        for(j=0;j<i;j++)
            printf("*");
        printf("\n");
        for(k=0;k<p;k++)
            printf(" ");
        p++;
        
    }
    return 0;
}