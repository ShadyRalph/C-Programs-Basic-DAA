     #include<stdio.h>
     int main(int n){
     int i,j,k;
     printf("Enter number: ");
     scanf("%d",&n);
     printf("prime nos: \n");
     for(i=1;i<=n;i++){
          k=0;
          for(j=2;j<=i/2;j++){
               if(i%j==0){
                    k++;
                    break;
                    }
               }
          if(k==0 && i!=1)
          printf("%d \n",i);
               
     }
     return 0;
}