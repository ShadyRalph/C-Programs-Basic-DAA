#include <stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the size: ");
    scanf("%d",&n);
    int r=1;
    k=(n+1)/2;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j<=r || j>n-r){
                printf("*");
            }
            else
                printf(" ");

        }
        printf("\n");
        if(i<k)
        r++;
        else
        r--;
    }
    return 0;
}

