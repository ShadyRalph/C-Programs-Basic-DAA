#include <stdio.h>
int main(){
    int n;
do{
     printf("Enter the number: ");
     scanf("%d",&n);
    if(n%7==0){
        printf("%d",n);
        printf(" is multiple of 7 \n");
        break;
    }
     printf("%d \n",n);
}while(1); // another way to make an infinite loop 
return 0;
}
