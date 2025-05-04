#include<stdio.h>
int t(int);
int main(){
   printf("%d " ,t(8));
   return 0;
}
int t(int n){
    if(n==1)
        return 0;
    else 
        return 1 + t(n/2);
}