#include <stdio.h>

void main(){
   float pr=100.00,*p=&pr,**pp=&p;
    printf("price: %f\n",pr);
    printf("value at the address of price %u",p);
    printf(" is %f\n",*p);
    printf("value at address of address of price: %u",pp);
    printf(" is %f\n",**pp);// *(*pp)=*(&p)=*(&(&pr))=**(&(pr))=pr
    }