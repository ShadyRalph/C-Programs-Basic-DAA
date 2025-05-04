#include <stdio.h>
#include <stdlib.h>
// Standard binary search function
int binarySearch(int *arr, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) 
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Function to find the pivot (point of rotation)
int findPivot(int *arr, int n) {
    int low = 0, high = n - 1;
    //if the array is not rotated and sorted normally then the first index is the minimum pivot element
    if (arr[low] <= arr[high])
        return 0;
    
    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid + 1]) 
            return mid+1;  // Pivot found

        if (arr[mid] < arr[low]) 
            high = mid;  // Pivot on the left side
        else
            low = mid + 1;  // Pivot on the right side
    }
    return low; // Pivot index
}

// Function to search for the target in the cyclic array
int cyclicSearch(int *arr, int n, int target) {
    int pivot = findPivot(arr, n);

    printf("Pivot Element: %d\n", arr[pivot]);

    // Check in left increasing sorted portion
    int index = binarySearch(arr, 0, pivot-1, target);
    if (index != -1) return index;

    // Check in right increasing  sorted portion
    index = binarySearch(arr, pivot, n-1, target);
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

    int target;
    int ch=1;
    while(ch>0){
        int target;
        printf("Enter the target element: ");
        scanf("%d", &target);

        int result = cyclicSearch(arr, n, target);

        if (result != -1)
            printf("Element found at index: %d\n", result);
        else
            printf("Element not found\n");
        printf("Enter 0 to exit or any other number to repeat: ");
        scanf("%d",&ch);
    }
    return 0;
}
