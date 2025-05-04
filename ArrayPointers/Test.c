#include <stdio.h>
void main(){
    int n, *p=&n;// while declaration we have to write *p=&n to initialise the address of n in p
    printf("Enter the number: ");
     scanf("%d",p);// since p is actually = &n 
double fact=1;//factorial

 for(int i=n;i>=1;i--){
    fact*=i;
   }
   printf("%d",*p);//*p=*(&n)=n
   printf("! = ");
   printf("%f",fact); // %f for double or floating point variables
}
