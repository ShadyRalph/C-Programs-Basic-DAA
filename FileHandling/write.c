#include <stdio.h>
#include <stdlib.h>
int main(){
    char *name= (char*) malloc(100*sizeof(char));
    int age;
    char *class= (char*) malloc(100*sizeof(char));;
    char sec;
    FILE *ptr=fopen("test.txt","w");
    if(ptr==NULL){
        return -1;
    }
    printf("Enter the name: ");
    scanf("%[^\n]",name);
    getchar();
    printf("Enter the age: ");
    scanf("%d",age);
    getchar();
    printf("Enter the class: ");
    scanf("%[^\n]",class);
    getchar();
    printf("Enter the section:");
    scanf(" %c",sec);
    fprintf(ptr,"Name: %s\n",name);
    fprintf(ptr,"Age: %d\n",age);
    fprintf(ptr,"Class: %s\n",class);
    fprintf(ptr,"Section: %c\n",sec);
    fclose(ptr);
    free(name);
    free(class);
    return 0; 
}