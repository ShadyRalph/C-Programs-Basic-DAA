#include <stdio.h>
void main(){
    int a;
    printf("Enter age: ");
    scanf("%d" ,&a);
 a>=18?printf("adult\n"):printf("not adult\n"); 
 //ternary operator to shorten the conditional statements
 // '?' means 'if', ':' means 'else' and ':<expression>?' means 'else if' 
}
// always use  gcc welcome.c and ./a.exe or ./welcome.exe i.e ./filename.exe
