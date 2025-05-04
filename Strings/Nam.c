#include <stdio.h>

void main(){
char ch[]="Ralph";
char ch1[]="Semister";
char *ptr= ch;
for(int i=0;ch[i]!='\0';i++)
{
    printf("%c",ch[i]);
}
printf(" ");
for(int i=0;ch1[i]!='\0';i++)
{
    printf("%c",ch1[i]);
}
}