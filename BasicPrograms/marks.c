#include <stdio.h>
void main(){
    int m;
    printf("Enter Marks: ");
    scanf("%d" ,&m);
 (m>=0 && m<=30)? printf("fail\n"):(m>30 && m<=100)? printf("Pass\n"):printf("wrong marks\n");
}
// '?' means 'if', ':' means 'else' and ':<expression>?' means 'else if' 