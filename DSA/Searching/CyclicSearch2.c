#include <stdio.h>
#include <stdlib.h>
int rotatedBinarySearch(int *arr, int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        // Else, right half is sorted
        else {
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1; // Not found
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements (rotated sorted array): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int ch = 1;
    while (ch > 0) {
        int target;
        printf("Enter the target element: ");
        scanf("%d", &target);

        int result = rotatedBinarySearch(arr, n, target);

        if (result != -1)
            printf("Element found at index: %d\n", result);
        else
            printf("Element not found\n");

        printf("Enter 0 to exit or any other number to repeat: ");
        scanf("%d", &ch);
    }

    free(arr);
    return 0;
}
