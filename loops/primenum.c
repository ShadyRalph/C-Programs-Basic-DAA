#include<stdio.h>
    int main(){
    int i,j,k,a,b;
    printf("Enter a range: ");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("prime nos. between %d & %d: \n",a,b);
    for(i=a;i<=b;i++){
        k=0;
        for(j=2;j<=i/2;j++){
            if(i%j==0){
                k++;
                break;
            }
        }
        if(k==0 && i!=1){
            printf("%d \n",i);
        }    
    }
    return 0;
}