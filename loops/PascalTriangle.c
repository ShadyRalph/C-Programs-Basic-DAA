#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int binomialCoefficient(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}


void printEquilateralPascalsTriangle(int rows) {
    int maxLength = rows * 4; 
    
    for (int i = 0; i < rows; i++) {
        
        printSpaces((maxLength - (i * 4 + 2)) / 2);
        
        for (int j = 0; j <= i; j++) {
            printf("%4d ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    printf("Pascal's Triangle with %d rows:\n", rows);
    printEquilateralPascalsTriangle(rows);

    return 0;
}