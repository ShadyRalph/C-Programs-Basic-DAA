#include <stdio.h>
int main() {
    int i,n,n1;
    int pro;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Till how many? : ");
    scanf("%d", &n1);
    for(i=1;i<=n1;i++){
        pro=n*i;
        printf("%d x %d = %d \n",n,i,pro);
    }   
}

