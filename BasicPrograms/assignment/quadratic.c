#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c,d,d1;
    float r1,r2,s,q;
    printf("Enter a = ");
    scanf("%d",&a);
    printf("Enter b = ");
    scanf("%d",&b);
    printf("Enter c = ");
    scanf("%d",&c);

    printf("equation : %dx^2 + %dx + %d = 0 \n",a,b,c);
    
    d=(b*b)-(4*a*c);

    if(d>=0){
        r1=(-b + sqrt(d))/(2.0 * a);
        r2=(-b - sqrt(d))/(2.0 * a);
        printf("root 1 = %f \n",r1);
        printf("root 2 = %f \n",r2);
    }

    else{
        d1=abs(d);
        s=-b/(2.0 * a);
        q=sqrt(d1)/(2.0 * a);
        printf("root 1 = %f + %fi \n",s,q);
        printf("root 2 = %f - %fi \n",s,q);
    }
    
    return 0;
}