#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main(){
    int a,b;
    float ar;
    printf("Enter the radius: ");
    scanf("%d",&a);
    ar=PI*(pow(a,2));
    printf("Area of the circle = %f",ar);
    return 0;
}