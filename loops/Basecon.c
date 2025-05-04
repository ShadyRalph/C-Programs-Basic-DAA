#include <stdio.h>
#include <string.h>
int main(){
        int n,num,sum=0,rem,b,count,j,i;
        char equi, strb[100],temp;
        printf("Enter the number: ");
        scanf("%d", &n);
        printf("Enter the base for conversion: ");
        scanf("%d", &b);
        num=n, count=1;
        if(b<=10){
            while(num!=0){
                rem=num%b;
                sum=sum+count*rem;
                num=num/b;
                count*=10;
            }
            printf("Equivalent Number of base %d = %d",b,sum);
        }
        else{
             while(num!=0){
                rem=num%b;
                if(rem>9 && rem<37){
                    equi=rem+55;
                    strb[j]=equi;
                    j++;
                }
                else{
                    strb[j]='0'+rem;
                    j++;
                }
                num=num/b;
            }
            strb[j]='\0';
            int len = strlen(strb);
            for(i=0;i<len/2;i++){
                temp=strb[i];
                strb[i]=strb[len-i-1];
                strb[len-i-1]=temp;
            } 
            printf("Equivalent Number of base %d = %s",b,strb);
        }
        return 0;
    }