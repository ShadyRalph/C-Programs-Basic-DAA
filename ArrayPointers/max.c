#include <stdio.h>
void maxi(int *x, int *y,int *k);

int main(){
    int x,y,k;
    printf("Enter the value of x and y\n");
    scanf("%d%d",&x,&y);

    maxi(&x,&y,&k);
    if(k==1){
        printf("max: %d\n",x);
    }
    else{
        printf("max: %d\n",y);
    }
    return 0;
}
void maxi(int *x, int *y,int *k){
    if(*x>*y){
    *k=1;
    }
    else{
    *k=0;
    }
}