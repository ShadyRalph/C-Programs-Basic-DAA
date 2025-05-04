#include <stdio.h>

void main(){
    char c;
    printf("Enter character: ");
    scanf("%s" ,&c);
    (c>=65 && c<=90)? printf("Its in upper case\n")
    :(c>=97 && c<=122)? printf("Its in lower case\n")
    :printf("Some special case\n");
}
