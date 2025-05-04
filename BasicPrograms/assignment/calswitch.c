#include <stdio.h>
int main(){
    float a,b;
    int c;
    float sum,mul,divi,sub;
    printf("Enter a number: ");
    scanf("%f",&a);
    printf("Enter another number: ");
    scanf("%f",&b);
    printf("1 for addition \n");
    printf("2 for substraction \n");
    printf("3 for multiplication \n");
    printf("4 for division \n");
    printf("Enter a choice: ");
    scanf("%d",&c);
    
    switch(c){
        case 1: sum=a+b;
                printf("%f + %f = %f",a,b,sum);
                break;
        case 2: sub=a-b;
                printf("%f - %f = %f",a,b,sub);
                break;
        case 3: mul=a*b;
                printf("%f x %f = %f",a,b,mul);
                break;
        case 4: divi=(float)a/(float)b;
                printf("%f / %f = %f",a,b,divi);
                break;
        default: printf("Invalid choice");
    }
    return 0;
}