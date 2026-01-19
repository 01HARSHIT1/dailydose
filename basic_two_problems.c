#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Basic DSA Problems - Two Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Reverse an Array
// Reverse the elements of an array in-place
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        // Swap elements
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
}

// Problem 2: Find Maximum and Minimum in Array
// Find the maximum and minimum elements in an array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void findMaxMin(int arr[], int size, int *max, int *min) {
    if (size == 0) {
        *max = INT_MIN;
        *min = INT_MAX;
        return;
    }
    
    *max = arr[0];
    *min = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

// Helper function to print array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Test cases
int main() {
    printf("==================================================\n");
    printf("Problem 1: Reverse an Array\n");
    printf("==================================================\n");
    
    // Test Case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original array: ");
    printArray(arr1, size1);
    printf("\n");
    reverseArray(arr1, size1);
    printf("Reversed array: ");
    printArray(arr1, size1);
    printf("\n\n");
    
    // Test Case 2
    int arr2[] = {10, 20, 30};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Original array: ");
    printArray(arr2, size2);
    printf("\n");
    reverseArray(arr2, size2);
    printf("Reversed array: ");
    printArray(arr2, size2);
    printf("\n\n");
    
    // Test Case 3
    int arr3[] = {5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Original array: ");
    printArray(arr3, size3);
    printf("\n");
    reverseArray(arr3, size3);
    printf("Reversed array: ");
    printArray(arr3, size3);
    printf("\n\n");
    
    printf("==================================================\n");
    printf("Problem 2: Find Maximum and Minimum in Array\n");
    printf("==================================================\n");
    
    // Test Case 1
    int arr4[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int max1, min1;
    printf("Array: ");
    printArray(arr4, size4);
    printf("\n");
    findMaxMin(arr4, size4, &max1, &min1);
    printf("Maximum: %d, Minimum: %d\n\n", max1, min1);
    
    // Test Case 2
    int arr5[] = {10, 5, 8, 20, 15};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int max2, min2;
    printf("Array: ");
    printArray(arr5, size5);
    printf("\n");
    findMaxMin(arr5, size5, &max2, &min2);
    printf("Maximum: %d, Minimum: %d\n\n", max2, min2);
    
    // Test Case 3
    int arr6[] = {7};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int max3, min3;
    printf("Array: ");
    printArray(arr6, size6);
    printf("\n");
    findMaxMin(arr6, size6, &max3, &min3);
    printf("Maximum: %d, Minimum: %d\n\n", max3, min3);
    
    // Test Case 4
    int arr7[] = {5, 5, 5, 5};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int max4, min4;
    printf("Array: ");
    printArray(arr7, size7);
    printf("\n");
    findMaxMin(arr7, size7, &max4, &min4);
    printf("Maximum: %d, Minimum: %d\n\n", max4, min4);
    
    return 0;
}
