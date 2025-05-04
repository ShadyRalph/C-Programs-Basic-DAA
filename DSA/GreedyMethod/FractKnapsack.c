#include <stdio.h>
#include <stdlib.h>
typedef struct Item {
    float weight;
    float value;
    float ratio;
} itm;
void swapitms(itm *a, itm *b) {
    itm temp = *a;
    *a = *b;
    *b = temp;
}
int partitionH(itm *itms, int low, int high) {

    float pivot = itms[low].ratio; 
    int i = low - 1, j = high + 1;  

    while (1) {
        do {
            i++;  
        } while (itms[i].ratio > pivot);

        do {
            j--;  
        } while (itms[j].ratio < pivot);

        if (i >= j)  
            return j;

        swapitms(&itms[i], &itms[j]);  
    }
}

void QuickSortitms(itm *itms, int low, int high) {
    if (low < high) {
        int partind = partitionH(itms, low, high);
        QuickSortitms(itms, low, partind);
        QuickSortitms(itms, partind + 1, high); 
    }
}

float fractionalKnapsack(itm *itms, int n, float capacity) {
    QuickSortitms(itms, 0, n - 1);  

    float totalValue = 0.0; 
    for (int i = 0; i < n; i++) {
        if (capacity >= itms[i].weight) {  
            capacity -= itms[i].weight;
            totalValue += itms[i].value;
        } 
        else { 
            totalValue += itms[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    float capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    itm *itms = (itm *)malloc(n * sizeof(itm));
    
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%f %f", &itms[i].weight, &itms[i].value);
        itms[i].ratio = itms[i].value / itms[i].weight; 
    }
    
    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);
    
    float maxProfit = fractionalKnapsack(itms, n, capacity);
    printf("Maximum profit: %.2f\n", maxProfit);
    return 0;
}
