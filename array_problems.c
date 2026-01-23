#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * Array DSA Interview Problems
 * Collection of common array problems with solutions
 */

// Helper function to find minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Helper function to find maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Problem 1: Two Sum
// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
/**
 * Time Complexity: O(n^2) - C version without hash map
 * Space Complexity: O(1)
 */
void twoSum(int* nums, int numsSize, int target, int* result) {
    result[0] = -1;
    result[1] = -1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}

// Problem 2: Maximum Subarray (Kadane's Algorithm)
// Find the contiguous subarray with the largest sum
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxSubarray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// Problem 3: Best Time to Buy and Sell Stock
// Find the maximum profit from buying and selling stock once
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    
    return maxProfit;
}

// Problem 4: Contains Duplicate
// Check if array contains any duplicates
/**
 * Time Complexity: O(n^2) - C version without hash set
 * Space Complexity: O(1)
 */
int containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Problem 5: Product of Array Except Self
// Return an array output such that output[i] is equal to the 
// product of all elements of nums except nums[i]
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1) excluding output array
 */
void productExceptSelf(int* nums, int numsSize, int* result) {
    // Initialize result array with 1
    for (int i = 0; i < numsSize; i++) {
        result[i] = 1;
    }
    
    // Calculate left products
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Calculate right products and multiply
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
}

// Problem 6: Maximum Product Subarray
// Find the contiguous subarray with the largest product
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProductSubarray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < 0) {
            int temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }
        
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        result = max(result, maxProd);
    }
    
    return result;
}

// Problem 7: Find Minimum in Rotated Sorted Array
// Find the minimum element in a rotated sorted array
/**
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int findMinRotated(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return nums[left];
}

// Problem 8: Search in Rotated Sorted Array
// Search for target in rotated sorted array
/**
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int searchRotated(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

// Helper function for qsort in 3Sum
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Problem 9: 3Sum
// Find all unique triplets that sum to zero
/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) excluding output
 * Note: This version prints results instead of returning array of arrays
 */
void threeSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    printf("Triplets: ");
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            
            if (total < 0) {
                left++;
            } else if (total > 0) {
                right--;
            } else {
                printf("[%d, %d, %d] ", nums[i], nums[left], nums[right]);
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            }
        }
    }
    printf("\n");
}

// Problem 10: Container With Most Water
// Find two lines that together with x-axis forms a container with most water
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;
    
    while (left < right) {
        int width = right - left;
        int currentArea = min(height[left], height[right]) * width;
        maxWater = max(maxWater, currentArea);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}

// Problem 11: Merge Sorted Arrays
// Merge two sorted arrays in-place (nums1 has enough space)
/**
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */
void mergeSortedArrays(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
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

// Helper function to reverse array
void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Problem 12: Rotate Array
// Rotate array to the right by k steps
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void rotateArray(int* nums, int numsSize, int k) {
    k = k % numsSize;
    
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

// Problem 13: Find First Repeating Element
// Find the first element that appears more than once in the array
/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int findFirstRepeating(int* nums, int numsSize) {
    // Using a simple approach: for each element, check if it appears again later
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return nums[i];
            }
        }
    }
    return -1; // No repeating element found
}

// Helper function to print array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Test cases
int main() {
    // Test Two Sum
    printf("Problem 1 - Two Sum:\n");
    int nums1[] = {2, 7, 11, 15};
    int result[2];
    twoSum(nums1, 4, 9, result);
    printArray(result, 2); // Output: [0, 1]
    
    // Test Maximum Subarray
    printf("\nProblem 2 - Maximum Subarray:\n");
    int nums2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubarray(nums2, 9)); // Output: 6
    
    // Test Max Profit
    printf("\nProblem 3 - Best Time to Buy and Sell Stock:\n");
    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, 6)); // Output: 5
    
    // Test Contains Duplicate
    printf("\nProblem 4 - Contains Duplicate:\n");
    int nums3[] = {1, 2, 3, 1};
    printf("%s\n", containsDuplicate(nums3, 4) ? "true" : "false"); // Output: true
    
    // Test Product Except Self
    printf("\nProblem 5 - Product of Array Except Self:\n");
    int nums4[] = {1, 2, 3, 4};
    int result5[4];
    productExceptSelf(nums4, 4, result5);
    printArray(result5, 4); // Output: [24, 12, 8, 6]
    
    // Test Max Product Subarray
    printf("\nProblem 6 - Maximum Product Subarray:\n");
    int nums5[] = {2, 3, -2, 4};
    printf("%d\n", maxProductSubarray(nums5, 4)); // Output: 6
    
    // Test Find Min Rotated
    printf("\nProblem 7 - Find Minimum in Rotated Sorted Array:\n");
    int nums6[] = {3, 4, 5, 1, 2};
    printf("%d\n", findMinRotated(nums6, 5)); // Output: 1
    
    // Test Search Rotated
    printf("\nProblem 8 - Search in Rotated Sorted Array:\n");
    int nums7[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", searchRotated(nums7, 7, 0)); // Output: 4
    
    // Test 3Sum
    printf("\nProblem 9 - 3Sum:\n");
    int nums8[] = {-1, 0, 1, 2, -1, -4};
    threeSum(nums8, 6); // Output: [-1, -1, 2] [-1, 0, 1]
    
    // Test Max Area
    printf("\nProblem 10 - Container With Most Water:\n");
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(height, 9)); // Output: 49
    
    // Test Merge Sorted Arrays
    printf("\nProblem 11 - Merge Sorted Arrays:\n");
    int nums9[] = {1, 2, 3, 0, 0, 0};
    int nums10[] = {2, 5, 6};
    mergeSortedArrays(nums9, 3, nums10, 3);
    printArray(nums9, 6); // Output: [1, 2, 2, 3, 5, 6]
    
    // Test Rotate Array
    printf("\nProblem 12 - Rotate Array:\n");
    int nums11[] = {1, 2, 3, 4, 5, 6, 7};
    rotateArray(nums11, 7, 3);
    printArray(nums11, 7); // Output: [5, 6, 7, 1, 2, 3, 4]
    
    // Test Find First Repeating
    printf("\nProblem 13 - Find First Repeating Element:\n");
    int nums12[] = {10, 5, 3, 4, 3, 5, 6};
    printf("%d\n", findFirstRepeating(nums12, 7)); // Output: 5
    
    return 0;
}
