#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if Array is Sorted
// Check whether an array is sorted in ascending order
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isSorted(int arr[], int size) {
    if (size <= 1) {
        return true;
    }
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    
    return true;
}

// Problem 2: Find Second Largest Element in Array
// Find the second largest element in an array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findSecondLargest(int arr[], int size, bool* found) {
    *found = false;
    
    if (size < 2) {
        return INT_MIN;
    }
    
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    if (secondLargest != INT_MIN && secondLargest != largest) {
        *found = true;
        return secondLargest;
    }
    
    return INT_MIN; // All elements are same or only one unique element
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
    printf("============================================================\n");
    printf("Problem 1: Check if Array is Sorted\n");
    printf("============================================================\n");
    
    // Test Case 1 - Sorted array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Array: ");
    printArray(arr1, size1);
    printf("\n");
    printf("Is sorted: %s\n\n", isSorted(arr1, size1) ? "true" : "false");
    
    // Test Case 2 - Unsorted array
    int arr2[] = {5, 2, 8, 1, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Array: ");
    printArray(arr2, size2);
    printf("\n");
    printf("Is sorted: %s\n\n", isSorted(arr2, size2) ? "true" : "false");
    
    // Test Case 3 - Single element
    int arr3[] = {10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Array: ");
    printArray(arr3, size3);
    printf("\n");
    printf("Is sorted: %s\n\n", isSorted(arr3, size3) ? "true" : "false");
    
    // Test Case 4 - Empty array
    int arr4[] = {};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Array: ");
    printArray(arr4, size4);
    printf("\n");
    printf("Is sorted: %s\n\n", isSorted(arr4, size4) ? "true" : "false");
    
    // Test Case 5 - Duplicate elements (sorted)
    int arr5[] = {1, 2, 2, 3, 4};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Array: ");
    printArray(arr5, size5);
    printf("\n");
    printf("Is sorted: %s\n\n", isSorted(arr5, size5) ? "true" : "false");
    
    // Test Case 6 - Descending order (not sorted for ascending)
    int arr6[] = {5, 4, 3, 2, 1};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Array: ");
    printArray(arr6, size6);
    printf("\n");
    printf("Is sorted: %s\n\n", isSorted(arr6, size6) ? "true" : "false");
    
    printf("============================================================\n");
    printf("Problem 2: Find Second Largest Element in Array\n");
    printf("============================================================\n");
    
    // Test Case 1
    int arr7[] = {10, 5, 8, 20, 15};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    bool found1;
    printf("Array: ");
    printArray(arr7, size7);
    printf("\n");
    int result7 = findSecondLargest(arr7, size7, &found1);
    if (found1) {
        printf("Second largest: %d\n\n", result7);
    } else {
        printf("Second largest: None\n\n");
    }
    
    // Test Case 2
    int arr8[] = {1, 2, 3, 4, 5};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    bool found2;
    printf("Array: ");
    printArray(arr8, size8);
    printf("\n");
    int result8 = findSecondLargest(arr8, size8, &found2);
    if (found2) {
        printf("Second largest: %d\n\n", result8);
    } else {
        printf("Second largest: None\n\n");
    }
    
    // Test Case 3 - Duplicate largest
    int arr9[] = {10, 10, 8, 7, 5};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    bool found3;
    printf("Array: ");
    printArray(arr9, size9);
    printf("\n");
    int result9 = findSecondLargest(arr9, size9, &found3);
    if (found3) {
        printf("Second largest: %d\n\n", result9);
    } else {
        printf("Second largest: None\n\n");
    }
    
    // Test Case 4 - All same elements
    int arr10[] = {5, 5, 5, 5};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    bool found4;
    printf("Array: ");
    printArray(arr10, size10);
    printf("\n");
    int result10 = findSecondLargest(arr10, size10, &found4);
    if (found4) {
        printf("Second largest: %d\n\n", result10);
    } else {
        printf("Second largest: None\n\n");
    }
    
    // Test Case 5 - Two elements
    int arr11[] = {10, 5};
    int size11 = sizeof(arr11) / sizeof(arr11[0]);
    bool found5;
    printf("Array: ");
    printArray(arr11, size11);
    printf("\n");
    int result11 = findSecondLargest(arr11, size11, &found5);
    if (found5) {
        printf("Second largest: %d\n\n", result11);
    } else {
        printf("Second largest: None\n\n");
    }
    
    // Test Case 6 - Negative numbers
    int arr12[] = {-5, -2, -10, -8, -1};
    int size12 = sizeof(arr12) / sizeof(arr12[0]);
    bool found6;
    printf("Array: ");
    printArray(arr12, size12);
    printf("\n");
    int result12 = findSecondLargest(arr12, size12, &found6);
    if (found6) {
        printf("Second largest: %d\n\n", result12);
    } else {
        printf("Second largest: None\n\n");
    }
    
    return 0;
}
