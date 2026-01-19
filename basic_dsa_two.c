#include <stdio.h>
#include <stdlib.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Linear Search
// Search for an element in an array and return its index
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Element not found
}

// Problem 2: Sum of Array Elements
// Calculate the sum of all elements in an array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int sumOfArray(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
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
    printf("Problem 1: Linear Search\n");
    printf("============================================================\n");
    
    // Test Case 1
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 30;
    printf("Array: ");
    printArray(arr1, size1);
    printf("\n");
    int result1 = linearSearch(arr1, size1, target1);
    printf("Searching for %d: Index = %d\n\n", target1, result1);
    
    // Test Case 2
    int arr2[] = {5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 38;
    printf("Array: ");
    printArray(arr2, size2);
    printf("\n");
    int result2 = linearSearch(arr2, size2, target2);
    printf("Searching for %d: Index = %d\n\n", target2, result2);
    
    // Test Case 3 - Element not found
    int arr3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int target3 = 10;
    printf("Array: ");
    printArray(arr3, size3);
    printf("\n");
    int result3 = linearSearch(arr3, size3, target3);
    printf("Searching for %d: Index = %d (Not found)\n\n", target3, result3);
    
    // Test Case 4
    int arr4[] = {100};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 100;
    printf("Array: ");
    printArray(arr4, size4);
    printf("\n");
    int result4 = linearSearch(arr4, size4, target4);
    printf("Searching for %d: Index = %d\n\n", target4, result4);
    
    printf("============================================================\n");
    printf("Problem 2: Sum of Array Elements\n");
    printf("============================================================\n");
    
    // Test Case 1
    int arr5[] = {1, 2, 3, 4, 5};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Array: ");
    printArray(arr5, size5);
    printf("\n");
    int sum1 = sumOfArray(arr5, size5);
    printf("Sum: %d\n\n", sum1);
    
    // Test Case 2
    int arr6[] = {10, 20, 30, 40, 50};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Array: ");
    printArray(arr6, size6);
    printf("\n");
    int sum2 = sumOfArray(arr6, size6);
    printf("Sum: %d\n\n", sum2);
    
    // Test Case 3
    int arr7[] = {5};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("Array: ");
    printArray(arr7, size7);
    printf("\n");
    int sum3 = sumOfArray(arr7, size7);
    printf("Sum: %d\n\n", sum3);
    
    // Test Case 4 - Negative numbers
    int arr8[] = {-5, 10, -3, 8, -2};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    printf("Array: ");
    printArray(arr8, size8);
    printf("\n");
    int sum4 = sumOfArray(arr8, size8);
    printf("Sum: %d\n\n", sum4);
    
    // Test Case 5 - Empty array
    int arr9[] = {};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    printf("Array: ");
    printArray(arr9, size9);
    printf("\n");
    int sum5 = sumOfArray(arr9, size9);
    printf("Sum: %d\n\n", sum5);
    
    return 0;
}
