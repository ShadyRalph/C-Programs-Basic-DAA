#include <stdio.h>
int main(){
    float cel,con1,con2,fr;
    printf("Enter temperature in celcius: ");
    scanf("%f",&cel);
    con1=(9*cel/5)+32;
    printf("%f cecius to fahrenheit: %f \n",cel,con1);
    printf("Enter temperature in fahrenheit: ");
    scanf("%f",&fr);
    con2=5*(fr-32)/9;
    printf("%f fahrenheit to cekcius: %f \n",fr,con2);
    return 0;
}
