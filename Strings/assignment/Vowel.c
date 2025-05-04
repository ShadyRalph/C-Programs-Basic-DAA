#include <stdio.h>
#include <stdlib.h>
int main(){
    char *str,ch;
    int vow=0,digi=0,i;
    str=(char*) malloc(5*sizeof(char));
    printf("Enter a string: " );
    scanf(" %[^\n]",str);
    for (i = 0; str[i] != '\0'; i++) {
        ch = str[i]; 
        if (ch >= 'a' && ch <= 'z') { 
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' 
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                vow++;
        } 
        else if (ch >= '0' && ch <= '9') {
            digi++;
        }
    }
    printf("Number of vowels: %d\n",vow);
    printf("Number of digits: %d\n",digi);
    return 0;
}