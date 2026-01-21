#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Duck Number
// A Duck number is a number that contains at least one zero, but should not start with zero
// Example: 102, 1020 are Duck numbers, but 012, 0123 are not

/**
 * Check if a number is Duck number
 * A Duck number contains at least one zero but doesn't start with zero
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) for string conversion
 */
bool isDuckNumber(int n) {
    if (n <= 0) {
        return false;
    }
    
    char numStr[20];
    sprintf(numStr, "%d", n);
    
    // Check if it starts with zero
    if (numStr[0] == '0') {
        return false;
    }
    
    // Check if it contains at least one zero
    return strchr(numStr, '0') != NULL;
}

/**
 * Check if a number is Duck number using iterative approach
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isDuckNumberIterative(int n) {
    if (n <= 0) {
        return false;
    }
    
    bool hasZero = false;
    
    // Process digits from right to left
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0) {
            hasZero = true;
        }
        n /= 10;
        
        // If we've seen all digits and the number is 0, we've processed the whole number
        // But we need to make sure the first digit (which will be last processed) is not zero
        // This is tricky, so we'll use the fact that if n > 0 after removing last digit,
        // the original didn't start with zero
    }
    
    // For integers in C, they can't start with zero by definition
    // So we just check if there's a zero somewhere
    return hasZero;
}

/**
 * Find all Duck numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Duck numbers
 */
int getDuckNumbersInRange(int start, int end, int* duckNumbers, int maxSize) {
    if (duckNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isDuckNumber(num)) {
            duckNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Check if a Number is Neon Number
// A Neon number is a number where the sum of digits of the square of the number equals the number itself
// Example: 9² = 81, and 8 + 1 = 9, so 9 is a Neon number

/**
 * Calculate sum of digits of a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int sumOfDigits(int n) {
    int total = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        total += num % 10;
        num /= 10;
    }
    
    return total;
}

/**
 * Check if a number is Neon number
 * Sum of digits of square equals the number itself
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isNeonNumber(int n) {
    if (n < 0) {
        return false;
    }
    
    long long square = (long long) n * n;
    int sumOfSquareDigits = sumOfDigits((int) square);
    
    return sumOfSquareDigits == n;
}

/**
 * Find all Neon numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Neon numbers
 */
int getNeonNumbersInRange(int start, int end, int* neonNumbers, int maxSize) {
    if (neonNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isNeonNumber(num)) {
            neonNumbers[count++] = num;
        }
    }
    
    return count;
}

/**
 * Get the sum of digits of square of a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int getSquareDigitsSum(int n) {
    long long square = (long long) n * n;
    return sumOfDigits((int) square);
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Duck Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Duck number 102
    int num1 = 102;
    bool result1 = isDuckNumber(num1);
    bool result1_iter = isDuckNumberIterative(num1);
    printf("Number: %d\n", num1);
    printf("Is Duck number: %s\n", result1 ? "true" : "false");
    printf("Is Duck number (iterative): %s\n\n", result1_iter ? "true" : "false");
    
    // Test Case 2 - Duck number 1020
    int num2 = 1020;
    bool result2 = isDuckNumber(num2);
    printf("Number: %d\n", num2);
    printf("Is Duck number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Duck number (no zero)
    int num3 = 123;
    bool result3 = isDuckNumber(num3);
    printf("Number: %d\n", num3);
    printf("Is Duck number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Single digit (not Duck as no zero)
    int num4 = 5;
    bool result4 = isDuckNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Duck number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Duck numbers in range
    int start = 100;
    int end = 200;
    int duckNums[200];
    int count = getDuckNumbersInRange(start, end, duckNums, 200);
    printf("Duck numbers in range [%d, %d] (first 15):\n", start, end);
    for (int i = 0; i < (count < 15 ? count : 15); i++) {
        printf("%d ", duckNums[i]);
    }
    printf("\nTotal count: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Check if a Number is Neon Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Neon number 9
    int num1_neon = 9;
    bool result1_neon = isNeonNumber(num1_neon);
    long long square1 = (long long) num1_neon * num1_neon;
    int sum1 = getSquareDigitsSum(num1_neon);
    printf("Number: %d\n", num1_neon);
    printf("Square: %lld\n", square1);
    printf("Sum of digits of square: %d\n", sum1);
    printf("Is Neon number: %s\n\n", result1_neon ? "true" : "false");
    
    // Test Case 2 - Not Neon number
    int num2_neon = 12;
    bool result2_neon = isNeonNumber(num2_neon);
    long long square2 = (long long) num2_neon * num2_neon;
    int sum2 = getSquareDigitsSum(num2_neon);
    printf("Number: %d\n", num2_neon);
    printf("Square: %lld\n", square2);
    printf("Sum of digits of square: %d\n", sum2);
    printf("Is Neon number: %s\n\n", result2_neon ? "true" : "false");
    
    // Test Case 3 - Single digit Neon
    int num3_neon = 1;
    bool result3_neon = isNeonNumber(num3_neon);
    long long square3 = (long long) num3_neon * num3_neon;
    int sum3 = getSquareDigitsSum(num3_neon);
    printf("Number: %d\n", num3_neon);
    printf("Square: %lld\n", square3);
    printf("Sum of digits of square: %d\n", sum3);
    printf("Is Neon number: %s\n\n", result3_neon ? "true" : "false");
    
    // Test Case 4 - Zero
    int num4_neon = 0;
    bool result4_neon = isNeonNumber(num4_neon);
    printf("Number: %d\n", num4_neon);
    printf("Is Neon number: %s\n\n", result4_neon ? "true" : "false");
    
    // Test Case 5 - Find Neon numbers in range
    int start_neon = 0;
    int end_neon = 1000;
    int neonNums[10];
    int count_neon = getNeonNumbersInRange(start_neon, end_neon, neonNums, 10);
    printf("Neon numbers in range [%d, %d]:\n", start_neon, end_neon);
    for (int i = 0; i < count_neon; i++) {
        printf("%d ", neonNums[i]);
    }
    printf("\nCount: %d\n", count_neon);
    
    return 0;
}
