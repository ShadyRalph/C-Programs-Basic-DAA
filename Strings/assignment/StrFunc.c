#include <stdio.h>
#include <stdlib.h>
int stlen(char*);
int stcmp(char* , char*);
char *stcpy(char*, char*);
char *strev(char*);
char *stcat(char*, char*);
int main(){
    int ch,len,cmp;
    char *str1, *str2, *cpy, *rev, *cat;
    str1=(char*) malloc(5*sizeof(char));
    str2=(char*) malloc(5*sizeof(char));
    for(;;){
        printf("Enter \n");
        printf("1 for finding out length \n" );
        printf("2 for comparison b/w 2 strings\n" );
        printf("3 for copying one string to another\n" );
        printf("4 for Reversing\n" );
        printf("5 for concatinating 2 strings\n" );
        printf("0 for exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==0)
            return 0;
        switch(ch){
            case 1: printf("Enter a string: " );
                    scanf(" %[^\n]",str1);
                    len=stlen(str1);
                    printf("Length = %d \n",len);
                    break;
            case 2: printf("Enter a string: " );
                    scanf(" %[^\n]",str1);
                    printf("Enter a another string: " );
                    scanf(" %[^\n]",str2);
                    cmp=stcmp(str1,str2);
                    printf("difference = %d \n",cmp);
                    break;
            case 3: printf("Enter a string: " );
                    scanf(" %[^\n]",str1);
                    printf("Enter a another string: " );
                    scanf(" %[^\n]",str2);
                    cpy=stcpy(str1,str2);
                    printf("str1 = %s \n",cpy);
                    break;
            case 4: printf("Enter a string: " );
                    scanf(" %[^\n]",str1);
                    rev=strev(str1);
                    printf("Reverse = %s \n",rev);
                    break;
            case 5: printf("Enter a string: " );
                    scanf(" %[^\n]",str1);
                    printf("Enter a another string: " );
                    scanf(" %[^\n]",str2);
                    cat=stcat(str1,str2);
                    printf("Concatinated string = %s \n",cat);
                    break;
            default: printf("Invalid choice... Enter again\n");

        }
    }
}

int stlen(char *str){
    int len;
    for(len=0;*str!='\0';str++,len++);
    return len;
}

int stcmp(char *str1 , char *str2){
    for(;*str1==*str2;str1++,str2++){
        if(*str1=='\0')
            return 0;
    }
    return(*str1-*str2);
}

char *stcpy(char *str1 , char *cpy){
    char *start=str1;
    while(*str1++=*cpy++);
    return start;
}

char *strev(char *str){
    int i,j;
    char c;
    for(i=0,j=stlen(str)-1; i<j;i++,j--){
        c=str[i];
        str[i]=str[j];
        str[j]=c;
    }
    return str;
}

char *stcat(char *str1 , char *str2){
    char *start=str1;
    while(*str1++);
    *str1--;
    while(*str1++ = *str2++);
    return start;
}

