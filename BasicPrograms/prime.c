#include<stdio.h>
void main(){
int i,n,k=0;
printf("Enter number: ");
scanf("%d",&n);
            if(n==2){
               k=1;
            }
          for(i=2;i<=n/2;i++){
                if(n%i!=0){
               k=1;
            }
            else{
                k=0;
                break;
            }
          }
          if(k==1){
            printf("%d",n);
            printf(" is a prime number \n");
          }
          else{
            printf("%d",n);
            printf(" is not a prime number \n");
          }
    }