#include <stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the size: ");
    scanf("%d",&n);
    int p=n-1;
    for(i=1;i<=n;i++){
        for(k=0;k<p;k++)
            printf(" ");
        for(j=0;j<i;j++)
            printf("*");
        printf("\n");
        p--;
        
    }
    return 0;
}
/*
      *
     **
    ***
   ****
  *****
*/