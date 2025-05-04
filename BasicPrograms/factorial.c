#include <stdio.h>
void main(){
    int n;
    printf("Enter the number: ");
     scanf("%d",&n);
double fact=1;//factorial

 for(int i=n;i>=1;i--){
    fact*=i;
   }
   printf("%d",n);
   printf("! = ");
   printf("%f",fact); // %f for double or floating point variables
}
