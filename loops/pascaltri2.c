#include <stdio.h> 
int main() { 
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n); 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            printf(" "); 
        } 
  
        int C = 1;
        for (int k = 1; k <= i; k++) { 
            printf("%d ", C); 
            C = C * (i - k) / k; 
        } 
        printf("\n"); 
    } 
    return 0; 
}