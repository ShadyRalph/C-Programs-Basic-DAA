#include <stdio.h>
void comsum(int, int,int,int);
void comsub(int, int,int,int);
void comMul(int, int,int,int);
int main(){
    int a,b,x,y;
    int c;
    while(1){ 
        printf("1 for addition \n");
        printf("2 for substraction \n");
        printf("3 for multiplication \n");
        printf("4 for exit \n");
        printf("Enter a choice: ");
        scanf("%d",&c);

        if(c==4)
            return 0;
        if(c>=1 && c<=4){
            printf("Enter real part a = ");
            scanf("%d",&a);
            printf("Enter imginary part b = ");
            scanf("%d",&b);
            printf("Enter real part x = ");
            scanf("%d",&x);
            printf("Enter Enter imginary part y = ");
            scanf("%d",&y);

            printf("1st complex number: %d + %di \n",a,b);
            printf("2nd complex number: %d + %di \n",x,y);
        }

        
            if(c==1){    
                comsum(a,b,x,y);        
            }

            else if(c==2){  
                comsub(a,b,x,y);
            }  

            else if(c==3){    
                comMul(a,b,x,y);
            } 

            else 
                printf("Invalid choice");
        
    }
}

void comsum(int a, int b,int x,int y){
    int realsum,imgsum;
    realsum=a+x;
    imgsum=b+y;
    printf("(%d + %di) + (%d + %di) = %d + %di\n",a,b,x,y,realsum,imgsum);
}

void comsub(int a, int b,int x,int y){
    int realsub,imgsub;
    realsub=a-x;
    imgsub=b-y;
    if(imgsub>0)
        printf("(%d + %di) - (%d + %di) = %d + %di\n",a,b,x,y,realsub,imgsub);
    else if(imgsub==0)
        printf("(%d + %di) - (%d + %di) = %d \n",a,b,x,y,realsub);
    else
        printf("(%d + %di) - (%d + %di) = %d + (%d)i \n",a,b,x,y,realsub,imgsub);
}
void comMul(int a, int b,int x,int y){
    int realmul,imgmul;
    realmul = a*x - b*y;
    imgmul = a*y + b*x;
    printf("(%d + %di) . (%d + %di) = %d + %di \n",a,b,x,y,realmul,imgmul);
}