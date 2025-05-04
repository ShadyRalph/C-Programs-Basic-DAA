#include <stdio.h>
#include <math.h>
int fact(int);
int main() {
    int i,n,j=0;
    int sum=0;
    printf("Enter the number of terms for series 1: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        j=(2*i)-1;
        printf("%d ",j);
        sum+=j;
        if(i!=n)
        printf("+ ");
    }
    printf(" = %d \n",sum);


    int n1;
    printf("Enter the number of terms for series 2: ");
    scanf("%d", &n1);
    int m,r=3;
    float sum2=1.0;
    printf(" 1 ");
    for(i=1;i<n1;i++){
        if(i % 2 != 0){
            printf("- ");
            m=pow(r,i);
            sum2=sum2-(1.0/(float)m);
            printf("1/%d ",m);
            
        }
        else{
            printf("+ ");
            m=pow(r,i);
            sum2=sum2+(1.0/(float)m);
            printf("1/%d ",m);
        }
    }
    printf(" = %f \n",sum2);

    int n2,x,k;
    float sum3;
    printf("Enter the number of terms for series 3: ");
    scanf("%d", &n2);
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf(" %d ",x);
    sum3=x;
    for(i=2;i<=n2;i++){
        k=(2*i)-1;
        if(i % 2 == 0){
            printf("- ");
            printf("%d^%d / %d! ",x,k,k);
            sum3=sum3-((float)pow(x,k)/(float)fact(k));
        }
        else{
            printf("+ ");
            printf("%d^%d / %d! ",x,k,k);
            sum3=sum3+((float)pow(x,k)/(float)fact(k));
        }
    }
     printf(" = %f \n",sum3);
}

int fact(int n){
    if(n==1 || n==0)
        return 1;
    return n*fact(n-1);
}