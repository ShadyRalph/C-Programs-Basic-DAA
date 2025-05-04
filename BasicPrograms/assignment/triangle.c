#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    int x,y,z;
    float ar,s,d;
    printf("Enter a side 1: ");
    scanf("%d",&a);
    printf("Enter a side 2: ");
    scanf("%d",&b);
    printf("Enter a side 3: ");
    scanf("%d",&c);
    x=a*a;
    y=b*b;
    z=c*c;
    s=(a+b+c)/2.0;
    if(a+b>c && b+c>a && c+a>b){
        if(a==b && a==c && b==c)
            printf("Its an equilateral triangle \n");
        else if(a==b || a==c || b==c)
            printf("Its an isosceles triangle \n");
        else if(x+y==z || y+z==x || x+z==y){
            printf("Its a right angled triangle \n");
            if(a!=b || a!=c || b!=c)
            printf("Its also a scalene triangle \n");
        }
        else if(a!=b && a!=c && b!=c)
            printf("Its a scalene triangle \n");
        d=s*(s-(float)a)*(s-(float)b)*(s-(float)c);
        ar=sqrt(d);
        printf("Area of the triangle = %f \n",ar);
    }
    else 
        printf("Its not a triangle \n");
    return 0;
}
