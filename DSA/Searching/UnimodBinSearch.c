#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int low, int high, int target, int slope) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
             return mid;

        if (slope) { 
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        } 
        else {
            if (arr[mid] > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int findPeak(int *arr, int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1; 
        else
            high = mid;     
    }
    return low;
}

int unimodalSearch(int *arr, int n, int target) {
    int peak = findPeak(arr, n);

    printf("Peak Element: %d\n", arr[peak]);

    // Search in the increasing part
    int index = binarySearch(arr, 0, peak, target, 1);
    if (index != -1) 
        return index;
    // Search in the decreasing part
    index = binarySearch(arr, peak + 1, n - 1, target, 0);
    return index;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int ch=1;
    while(ch>0){
        int target;
        printf("Enter the target element: ");
        scanf("%d", &target);

        int result = unimodalSearch(arr, n, target);

        if (result != -1)
            printf("Element found at index: %d\n", result);
        else
            printf("Element not found\n");
        printf("Enter 0 to exit or any other number to repeat: ");
        scanf("%d",&ch);
    }
    return 0;
}
