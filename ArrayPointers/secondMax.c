#include <stdio.h>
#include <stdlib.h>
    int main(){
            int n,i,j,temp;
            printf("Enter the size: ");
            scanf("%d",&n);
            int *arr=(int*) malloc(n * sizeof(int));
            printf("Enter the elements: \n");
            for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
            for(i=0;i<n;i++){
                for(j=0;j<n-1;j++){
                    if(arr[j]<arr[j+1]){
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
            printf("Second maximum number = %d\n",arr[1]);
        }