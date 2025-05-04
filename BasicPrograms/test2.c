#include<stdio.h>

int *fun() {
int *b;
int a=700;
b=&a;
printf("%p\n", b);
return b;
}

int main(){

int a = 600;

int *ptr=NULL;

printf("%p\n", &a);

ptr = fun();

printf("%d\n", *ptr);

return 0;

}