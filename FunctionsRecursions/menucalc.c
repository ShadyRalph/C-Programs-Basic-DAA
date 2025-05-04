#include <stdio.h>
#include <math.h>
int fact(int);
int checkarmstrong(int);
int power(int,int);
int GCD(int,int);
int main(){
    int a,b,v=0;
    char c,ch;
    int sum,mul,divi,sub;
    while(1){ 
        v++;
        printf("a for factoral of a number \n");
        printf("b for checking Armstrong number \n");
        printf("c for x^y \n");
        printf("d for GCD of two integers \n");
        printf("e for exit \n");
        printf("Enter a choice: ");
        if(v>1)
            scanf("%c",&ch);
        scanf("%c",&c);


        switch(c){
            case 'a':   printf("Enter a number: ");
                        scanf("%d",&a);
                        printf("%d! = %d \n",a,fact(a));
                        break;

            case 'b':   printf("Enter a number: ");
                        scanf("%d",&a);
                        if(checkarmstrong(a)==1)
                            printf("%d is a armstrong number \n",a);
                        else
                            printf("%d is not a armstrong number \n",a);
                        break;

            case 'c':   printf("Enter x: ");
                        scanf("%d",&a);
                        printf("Enter y: ");
                        scanf("%d",&b);
                        printf("%d ^ %d = %d \n",a,b,power(a,b));
                        break;

            case 'd':   printf("Enter a number: ");
                        scanf("%d",&a);
                        printf("Enter another number: ");
                        scanf("%d",&b);
                        printf("GCD of %d & %d = %d \n",a,b,GCD(a,b));
                        break;

            case 'e':   return 0;
                        break;

            default: printf("Invalid choice");
        }
    }
}

int fact(int n){
    if(n==1 || n==0)
        return 1;
    return n*fact(n-1);
}

int checkarmstrong(int n){
    int d,sum=0,num=n,len=0,nu=n;
    while(nu!=0){
        len++;
        nu=nu/10;
    }
    while(num!=0){
        d=num%10;
        sum+=power(d,len);
        num=num/10;
    }
    if(sum==n)
    return 1;
    else
    return 0;
}

int power(int a,int b){
    int i,pro;
    for(pro=1,i=1;i<=b;i++,pro*=a);
    return pro;
}

int GCD(int a,int b){
    if(b!=0)
        return GCD(b,a%b);
    else
        return a;
}