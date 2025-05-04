#include <stdio.h>
#include <stdlib.h>
typedef struct item{
    float weight;
    float value;
    float ratio;
}itm;

void BubbleSort(itm *it,int n);
float Fractknap(itm *itms,int n,float kpsz,float *select);

int main(){
    int n,i;
    float cap;
    printf("Enter the no. of items: ");
    scanf("%d",&n);
    itm *it=(itm*)malloc(n*sizeof(itm));
    for(i=0;i<n;i++){
        printf("Enter Weight and Value of item %d: ",i+1);
        scanf("%f %f",&it[i].weight,&it[i].value);
        it[i].ratio=it[i].value/it[i].weight;
    }
    printf("Enter the Kanpsack Capacity: ");
    scanf("%f",&cap);
    float *sel=(float*)calloc(n,sizeof(float));
    float Profit=Fractknap(it,n,cap,sel);
    printf("After geting Sorted: \n");
    printf("\nWeight: ");
    for(i=0;i<n;i++)
        printf("%8.2f ",it[i].weight);

    printf("\nValue: ");
    for(i=0;i<n;i++)
        printf("%8.2f ",it[i].value);

    printf("\nV/W ratio: ");
    for(i=0;i<n;i++)
        printf("%8.2f ",it[i].ratio);

    printf("\nSelected: { ");
    for(i=0;i<n;i++)
        printf("%8.2f ",sel[i]);
    
    printf("}\nTotal Profit: %.2f\n",Profit);
    
    return 0;
}
float Fractknap(itm *itms,int n,float kpsz,float *select){
    BubbleSort(itms,n);
    float totalVal=0.0;
    int i;
    for(i=0;i<n;i++){
        if(kpsz>=itms[i].weight){
            kpsz-=itms[i].weight;
            select[i]=1.0;
            totalVal+=itms[i].value * select[i];
        }
        else{
            select[i]=kpsz / itms[i].weight;
            totalVal+=itms[i].ratio*kpsz;//totalVal+=itms[i].value * select[i];
            break;
        }
    }
    return totalVal;
}
void BubbleSort(itm *it,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(it[j].ratio<it[j+1].ratio){
                itm temp=it[j+1];
                it[j+1]=it[j];
                it[j]=temp;
            }
        }
    }
}
