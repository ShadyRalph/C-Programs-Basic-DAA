#include <stdio.h>

void main(){
    int m;
    printf("Enter Marks: ");
    scanf("%d" ,&m);
 (m>=0 && m<30)? printf("C\n")
   :(m>=30 && m<70)? printf("B\n")
   :(m>=70 && m<90)? printf("A\n")
   :(m>=90 && m<=100)? printf("A+\n")
   :printf("wrong marks\n");



//              OR
// Alternative:
/*     
if(m>=0 && m<30)
    printf("C\n");

   else if(m>=30 && m<70) 
   printf("B\n");

   else if(m>=70 && m<90)
   printf("A\n");

   else if(m>=90 && m<=100)
    printf("A+\n");

   else
   printf("wrong marks\n");
   */
}