#include <stdio.h>
void swap(int *a,int *b){
int t=*a;
*a=*b;
*b=t;
}

int main(){
    int x,y;
printf("Enter the value of x and y\n");
   scanf("%d%d",&x,&y);

swap(&x,&y);
printf("x= %d \n",x);
printf("y= %d \n",y);
}

