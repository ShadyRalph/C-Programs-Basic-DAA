#include <stdio.h>
#include <stdlib.h>
    int main(){
            int n,i,insert,pos;
            printf("Enter the size: ");
            scanf("%d",&n);
            int *arr=(int*) malloc(n * sizeof(int));
            printf("Enter the elements: \n");
            for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
            printf("Enter the insert element: " );
            scanf("%d",&insert);
            printf("Enter the position: " );   
            scanf("%d",&pos);
            for(i=0;i<n;i++){
                if(i+1==pos)
                    arr[i]=insert;
            }
            
            printf("Array after inserting: \n");
            for(i=0;i<n;i++)
                printf("%d \n",arr[i]);
        }