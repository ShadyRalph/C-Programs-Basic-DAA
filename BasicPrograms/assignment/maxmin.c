#include <stdio.h>
int main(){
    int max,min,a,b,c;
    printf("Enter a number: ");
    scanf("%d",&a);
    printf("Enter a number: ");
    scanf("%d",&b);
    printf("Enter a number: ");
    scanf("%d",&c);
    if(a>b && a>c)
    max=a;
    else if (b>a && b>c)
    max=b;
    else
    max=c;

    if(a<b && a<c)
    min=a;
    else if (b<a && b<c)
    min=b;
    else
    min=c;
    
    printf("max = %d & min = %d",max,min);
    return 0;

}