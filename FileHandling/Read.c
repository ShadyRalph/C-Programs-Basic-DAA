#include <stdio.h>
int main(){
    FILE *ptr=fopen("Intro.txt","r");
    char ch=fgetc(ptr);
    while(ch!=EOF){
        printf("%c",ch);
        ch=fgetc(ptr);
    }
    fclose(ptr);
    return 0; 
}