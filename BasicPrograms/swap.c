#include <stdio.h>
int main(){
    int x,y;
printf("Enter the value of x and y\n");
   scanf("%d%d",&x,&y);
int temp=x;
x=y;
y=temp;
printf("x= %d \n",x);
printf("y= %d \n",y);
}