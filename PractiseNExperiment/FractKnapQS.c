#include <stdio.h>
#include <stdlib.h>
typedef struct item{
    float weight;
    float value;
    float ratio;
}itm;
void swapper(itm *a,itm *b);
int partition(itm *itms,int low,int high);
void QuickSort(itm *items,int low,int high);
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
    QuickSort(itms,0,n-1);
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
void swapper(itm *a,itm *b){
    itm temp=*a;
    *a=*b;
    *b=temp;
}
int partition(itm *itms,int low,int high){
    itm piv=itms[low];
    int i=low,j=high;
    while(i<j){
        while(i<=high && itms[i].ratio>=piv.ratio)
            i++;
        while(j>=low && itms[j].ratio<piv.ratio)
            j--;
        if(i<j)
            swapper(&itms[i],&itms[j]);
    }
    swapper(&itms[low],&itms[j]);
    return j;
}
void QuickSort(itm *items,int low,int high){
    if(low<high){
        int part=partition(items,low,high);
        QuickSort(items,low,part-1);
        QuickSort(items,part+1,high);
    }
}
