#include <stdio.h>
#include <stdlib.h>
typedef struct item{
    float weight;
    float value;
    float ratio;
}itm;
void Merge(itm *itms,int low,int mid,int high);
void MergeSort(itm *items,int low,int high);
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
    MergeSort(itms,0,n-1);
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
void Merge(itm *itms,int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    itm temp[high-low+1];
    while(i<=mid && j<=high){
        if(itms[i].ratio>=itms[j].ratio)
            temp[k++]=itms[i++];
        else
            temp[k++]=itms[j++];
    }
    while(i<=mid)
        temp[k++]=itms[i++];
    while(j<=high)
        temp[k++]=itms[j++];
    for(i=low,k=0;i<=high;i++,k++)
        itms[i]=temp[k];
}

void MergeSort(itm *items,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(items,low,mid);
        MergeSort(items,mid+1,high);
        Merge(items,low,mid,high);
    }
}
