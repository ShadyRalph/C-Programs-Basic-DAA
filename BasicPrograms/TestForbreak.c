#include<stdio.h>
// In a nested loop break only takes you out of the loop that its in
void main(){
    int i,j,k;
    for(i=1;i<=5;i++){
        printf("i= %d | ",i); 
        for(j=1;j<=i;j++){
            if(i==3){
            printf("NIL");
            break;
            }
            else{
             
             printf("j= %d ",j);
            }
            }
             printf("\n"); 
            }
            }
   
