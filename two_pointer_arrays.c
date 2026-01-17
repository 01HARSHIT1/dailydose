#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * Two Pointer Arrays DSA Problems
 * Collection of problems using two-pointer technique with arrays
 * Includes C-specific double pointer (pointer to pointer) examples
 */

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to print array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Problem 1: Two Sum (Two Pointers on Sorted Array)
// Find two numbers that add up to target in sorted array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int* twoSumSorted(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0, right = numbersSize - 1;
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    while (left < right) {
        int currentSum = numbers[left] + numbers[right];
        if (currentSum == target) {
            result[0] = left + 1; // 1-indexed
            result[1] = right + 1;
            return result;
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    *returnSize = 0;
    free(result);
    return NULL;
}

// Problem 4: Remove Duplicates from Sorted Array
// Remove duplicates in-place using two pointers
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int writeIndex = 1;
    
    for (int readIndex = 1; readIndex < numsSize; readIndex++) {
        if (nums[readIndex] != nums[readIndex - 1]) {
            nums[writeIndex] = nums[readIndex];
            writeIndex++;
        }
    }
    
    return writeIndex;
}

// Problem 5: Remove Element
// Remove all instances of val in-place
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int removeElement(int* nums, int numsSize, int val) {
    int writeIndex = 0;
    
    for (int readIndex = 0; readIndex < numsSize; readIndex++) {
        if (nums[readIndex] != val) {
            nums[writeIndex] = nums[readIndex];
            writeIndex++;
        }
    }
    
    return writeIndex;
}

// Problem 6: Move Zeros
// Move all zeros to end while maintaining relative order
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void moveZeroes(int* nums, int numsSize) {
    int writeIndex = 0;
    
    for (int readIndex = 0; readIndex < numsSize; readIndex++) {
        if (nums[readIndex] != 0) {
            swap(&nums[writeIndex], &nums[readIndex]);
            writeIndex++;
        }
    }
}

// Problem 7: Container With Most Water
// Find two lines that form container with most water
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;
    
    while (left < right) {
        int width = right - left;
        int currentArea = (height[left] < height[right] ? height[left] : height[right]) * width;
        maxWater = (currentArea > maxWater) ? currentArea : maxWater;
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}

// Problem 8: Trapping Rain Water
// Calculate trapped rainwater between bars
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int trap(int* height, int heightSize) {
    if (heightSize == 0) {
        return 0;
    }
    
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    
    return water;
}

// Problem 9: Valid Palindrome
// Check if string is palindrome using two pointers
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isPalindrome(char* s) {
    int left = 0, right = strlen(s) - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

// Problem 10: Reverse String
// Reverse string using two pointers
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// Problem 13: Sort Colors (Dutch National Flag)
// Sort array of 0s, 1s, and 2s in-place
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void sortColors(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int i = 0;
    
    while (i <= right) {
        if (nums[i] == 0) {
            swap(&nums[left], &nums[i]);
            left++;
            i++;
        } else if (nums[i] == 2) {
            swap(&nums[right], &nums[i]);
            right--;
        } else {
            i++;
        }
    }
}

// Problem 14: Squares of Sorted Array
// Return squares of sorted array in sorted order
/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    int left = 0, right = numsSize - 1;
    int idx = numsSize - 1;
    
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        
        if (leftSquare > rightSquare) {
            result[idx] = leftSquare;
            left++;
        } else {
            result[idx] = rightSquare;
            right--;
        }
        idx--;
    }
    
    return result;
}

// Problem 15: Merge Sorted Arrays
// Merge two sorted arrays using two pointers
/**
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

// Problem 18: Boats to Save People
// Find minimum boats needed to save people
/**
 * Time Complexity: O(n log n) - requires sorting first
 * Space Complexity: O(1)
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), compare);
    int left = 0, right = peopleSize - 1;
    int boats = 0;
    
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++;
        }
        right--;
        boats++;
    }
    
    return boats;
}

// Problem 19: Longest Mountain in Array
// Find length of longest mountain subarray
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int longestMountain(int* arr, int arrSize) {
    if (arrSize < 3) {
        return 0;
    }
    
    int maxLength = 0;
    int i = 1;
    
    while (i < arrSize - 1) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;
            
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }
            while (right < arrSize - 1 && arr[right] > arr[right + 1]) {
                right++;
            }
            
            int currentLength = right - left + 1;
            maxLength = (currentLength > maxLength) ? currentLength : maxLength;
            i = right;
        } else {
            i++;
        }
    }
    
    return maxLength;
}

// C-SPECIFIC: Double Pointer (Pointer to Pointer) Examples
// Problem 21: Allocate 2D Array using Double Pointer
// Demonstrate double pointer usage for dynamic 2D array
/**
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(rows * cols)
 */
int** allocate2DArray(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
    return matrix;
}

void free2DArray(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Problem 22: Swap Two Pointers
// Swap two pointer values using double pointer
/**
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapPointers(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

// Problem 23: Reverse Array using Double Pointer
// Reverse array by passing pointer to pointer
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void reverseArrayDoublePointer(int** arr, int size) {
    int* array = *arr;
    int left = 0, right = size - 1;
    
    while (left < right) {
        swap(&array[left], &array[right]);
        left++;
        right--;
    }
}

// Test cases
int main() {
    printf("Problem 1 - Two Sum (Sorted):\n");
    int numbers[] = {2, 7, 11, 15};
    int returnSize;
    int* result = twoSumSorted(numbers, 4, 9, &returnSize);
    if (result) {
        printArray(result, returnSize);
        free(result);
    }
    
    printf("\nProblem 4 - Remove Duplicates:\n");
    int nums1[] = {1, 1, 2};
    int newSize = removeDuplicates(nums1, 3);
    printf("New length: %d\n", newSize); // 2
    printArray(nums1, newSize);
    
    printf("\nProblem 7 - Container With Most Water:\n");
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(height, 9)); // 49
    
    printf("\nProblem 8 - Trapping Rain Water:\n");
    int height2[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(height2, 12)); // 6
    
    printf("\nProblem 13 - Sort Colors:\n");
    int nums3[] = {2, 0, 2, 1, 1, 0};
    sortColors(nums3, 6);
    printArray(nums3, 6); // [0, 0, 1, 1, 2, 2]
    
    printf("\nProblem 14 - Squares of Sorted Array:\n");
    int nums4[] = {-4, -1, 0, 3, 10};
    int* squares = sortedSquares(nums4, 5, &returnSize);
    printArray(squares, returnSize);
    free(squares);
    
    printf("\nProblem 18 - Boats to Save People:\n");
    int people[] = {1, 2};
    printf("%d\n", numRescueBoats(people, 2, 3)); // 1
    
    printf("\nProblem 21 - Allocate 2D Array (Double Pointer):\n");
    int** matrix = allocate2DArray(3, 4);
    for (int i = 0; i < 3; i++) {
        printArray(matrix[i], 4);
    }
    free2DArray(matrix, 3);
    
    printf("\nProblem 22 - Swap Two Pointers:\n");
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    printf("Before: *ptr1=%d, *ptr2=%d\n", *ptr1, *ptr2);
    swapPointers(&ptr1, &ptr2);
    printf("After: *ptr1=%d, *ptr2=%d\n", *ptr1, *ptr2);
    
    printf("\nProblem 23 - Reverse Array (Double Pointer):\n");
    int* arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    printf("Before: ");
    printArray(arr, 5);
    reverseArrayDoublePointer(&arr, 5);
    printf("After: ");
    printArray(arr, 5);
    free(arr);
    
    return 0;
}
