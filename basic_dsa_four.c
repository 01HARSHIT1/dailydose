#include <stdio.h>
#include <stdlib.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Find Average of Array Elements
// Calculate the average of all elements in an array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double findAverage(int arr[], int size) {
    if (size == 0) {
        return 0.0;
    }
    
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    
    return (double) total / size;
}

// Problem 2: Count Even and Odd Numbers in Array
// Count the number of even and odd numbers in an array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void countEvenOdd(int arr[], int size, int *evenCount, int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
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
    printf("============================================================\n");
    printf("Problem 1: Find Average of Array Elements\n");
    printf("============================================================\n");
    
    // Test Case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Array: ");
    printArray(arr1, size1);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr1, size1));
    
    // Test Case 2
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Array: ");
    printArray(arr2, size2);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr2, size2));
    
    // Test Case 3 - Single element
    int arr3[] = {15};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Array: ");
    printArray(arr3, size3);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr3, size3));
    
    // Test Case 4 - Decimal result
    int arr4[] = {1, 2, 3, 4};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Array: ");
    printArray(arr4, size4);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr4, size4));
    
    // Test Case 5 - Negative numbers
    int arr5[] = {-5, -10, -15, -20};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Array: ");
    printArray(arr5, size5);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr5, size5));
    
    // Test Case 6 - Mixed positive and negative
    int arr6[] = {-5, 10, -3, 8, -2};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Array: ");
    printArray(arr6, size6);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr6, size6));
    
    // Test Case 7 - Empty array
    int arr7[] = {};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("Array: ");
    printArray(arr7, size7);
    printf("\n");
    printf("Average: %.2f\n\n", findAverage(arr7, size7));
    
    printf("============================================================\n");
    printf("Problem 2: Count Even and Odd Numbers in Array\n");
    printf("============================================================\n");
    
    // Test Case 1
    int arr8[] = {1, 2, 3, 4, 5};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    int even1, odd1;
    printf("Array: ");
    printArray(arr8, size8);
    printf("\n");
    countEvenOdd(arr8, size8, &even1, &odd1);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even1, odd1);
    
    // Test Case 2
    int arr9[] = {2, 4, 6, 8, 10};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    int even2, odd2;
    printf("Array: ");
    printArray(arr9, size9);
    printf("\n");
    countEvenOdd(arr9, size9, &even2, &odd2);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even2, odd2);
    
    // Test Case 3
    int arr10[] = {1, 3, 5, 7, 9};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    int even3, odd3;
    printf("Array: ");
    printArray(arr10, size10);
    printf("\n");
    countEvenOdd(arr10, size10, &even3, &odd3);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even3, odd3);
    
    // Test Case 4 - Mixed with zero
    int arr11[] = {0, 1, 2, 3, 4, 5};
    int size11 = sizeof(arr11) / sizeof(arr11[0]);
    int even4, odd4;
    printf("Array: ");
    printArray(arr11, size11);
    printf("\n");
    countEvenOdd(arr11, size11, &even4, &odd4);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even4, odd4);
    
    // Test Case 5 - Negative numbers
    int arr12[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
    int size12 = sizeof(arr12) / sizeof(arr12[0]);
    int even5, odd5;
    printf("Array: ");
    printArray(arr12, size12);
    printf("\n");
    countEvenOdd(arr12, size12, &even5, &odd5);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even5, odd5);
    
    // Test Case 6 - Single element
    int arr13[] = {7};
    int size13 = sizeof(arr13) / sizeof(arr13[0]);
    int even6, odd6;
    printf("Array: ");
    printArray(arr13, size13);
    printf("\n");
    countEvenOdd(arr13, size13, &even6, &odd6);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even6, odd6);
    
    // Test Case 7 - Empty array
    int arr14[] = {};
    int size14 = sizeof(arr14) / sizeof(arr14[0]);
    int even7, odd7;
    printf("Array: ");
    printArray(arr14, size14);
    printf("\n");
    countEvenOdd(arr14, size14, &even7, &odd7);
    printf("Even numbers: %d, Odd numbers: %d\n\n", even7, odd7);
    
    return 0;
}
