#include <stdio.h>
void maxi(int *x, int *y,int *k);

int main(){
    char n,i;
    char a[26]="abcdefghijklmnopqrstuvwxyz", b[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptr=a,*ptr1=b;
    for(i=0;i<26;i++){
    //printf("\n");
    printf("%c: ",*(b+i));//or can also use a[i]
    printf("%u ",b+i);
    printf("%c: ",*(ptr+i));
    printf("%u \n",a+i);
    
    }
    return 0;
}