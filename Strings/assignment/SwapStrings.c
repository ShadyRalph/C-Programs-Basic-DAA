#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char*,char*);
int main(){
    int ch,len,cmp;
    char *str1, *str2;
    str1=(char*) malloc(5*sizeof(char));
    str2=(char*) malloc(5*sizeof(char));
    printf("Enter a string: " );
    scanf(" %[^\n]",str1);
    printf("Enter a another string: " );
    scanf(" %[^\n]",str2);
    printf("Before swaping: \n");
    printf("%s %s \n",str1,str2);
    swap(str1,str2);
    printf("After swaping: \n");
    printf("%s %s \n",str1,str2);
    return 0;
}
void swap(char *str1, char *str2) {
    char *temp = (char*)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}