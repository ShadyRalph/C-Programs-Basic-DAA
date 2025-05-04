#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n = argc - 1;
    int numbers[n];

    for (int i = 0; i < n; i++) {
        numbers[i] = atoi(argv[i+1]);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
