#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Pronic/Heteromecic Number
// A Pronic number (also called Heteromecic number) is a number that is the product of two consecutive integers
// Example: 6 = 2 × 3, 12 = 3 × 4, 20 = 4 × 5

/**
 * Check if a number is Pronic/Heteromecic number
 * A Pronic number is the product of two consecutive integers
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isPronicNumber(int n) {
    if (n < 0) {
        return false;
    }
    
    // Check if there exists an integer i such that i * (i + 1) == n
    for (int i = 0; i * (i + 1) <= n; i++) {
        if (i * (i + 1) == n) {
            return true;
        }
    }
    
    return false;
}

/**
 * Get the two consecutive factors if number is Pronic
 * Stores factors in result array and returns true if Pronic, false otherwise
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool getPronicFactors(int n, int* factors) {
    if (n < 0 || factors == NULL) {
        return false;
    }
    
    for (int i = 0; i * (i + 1) <= n; i++) {
        if (i * (i + 1) == n) {
            factors[0] = i;
            factors[1] = i + 1;
            return true;
        }
    }
    
    return false;
}

/**
 * Find all Pronic numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(k) where k is the number of Pronic numbers
 */
int getPronicNumbersInRange(int start, int end, int* pronicNumbers, int maxSize) {
    if (pronicNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isPronicNumber(num)) {
            pronicNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Check if a Number is Deficient Number
// A Deficient number is a number for which the sum of its proper divisors is less than the number itself
// Example: 8 has proper divisors 1, 2, 4, sum = 7 < 8, so 8 is deficient

/**
 * Calculate sum of proper divisors of a number
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
int sumOfProperDivisors(int n) {
    if (n <= 1) {
        return 0;
    }
    
    int sumDivisors = 1; // 1 is always a divisor
    
    // Check divisors from 2 to √n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sumDivisors += i;
            // Add the corresponding divisor (avoid adding square twice)
            if (i != n / i) {
                sumDivisors += n / i;
            }
        }
    }
    
    return sumDivisors;
}

/**
 * Check if a number is deficient number
 * Sum of proper divisors is less than the number itself
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isDeficientNumber(int n) {
    if (n <= 0) {
        return false;
    }
    return sumOfProperDivisors(n) < n;
}

/**
 * Get all proper divisors of a number
 * Stores divisors in array and returns count
 * Time Complexity: O(√n)
 * Space Complexity: O(√n)
 */
int getProperDivisors(int n, int* divisors, int maxSize) {
    if (n <= 1 || divisors == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    divisors[count++] = 1;
    
    for (int i = 2; i * i <= n && count < maxSize; i++) {
        if (n % i == 0) {
            divisors[count++] = i;
            if (i != n / i && count < maxSize) {
                divisors[count++] = n / i;
            }
        }
    }
    
    return count;
}

/**
 * Find all Deficient numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(k) where k is the number of Deficient numbers
 */
int getDeficientNumbersInRange(int start, int end, int* deficientNumbers, int maxSize) {
    if (deficientNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isDeficientNumber(num)) {
            deficientNumbers[count++] = num;
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Pronic/Heteromecic Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Pronic number 6
    int num1 = 6;
    bool result1 = isPronicNumber(num1);
    int factors1[2];
    bool hasFactors1 = getPronicFactors(num1, factors1);
    printf("Number: %d\n", num1);
    if (hasFactors1) {
        printf("Factors: %d × %d = %d\n", factors1[0], factors1[1], num1);
    }
    printf("Is Pronic number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Pronic number 12
    int num2 = 12;
    bool result2 = isPronicNumber(num2);
    int factors2[2];
    bool hasFactors2 = getPronicFactors(num2, factors2);
    printf("Number: %d\n", num2);
    if (hasFactors2) {
        printf("Factors: %d × %d = %d\n", factors2[0], factors2[1], num2);
    }
    printf("Is Pronic number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Pronic number
    int num3 = 10;
    bool result3 = isPronicNumber(num3);
    printf("Number: %d\n", num3);
    printf("Is Pronic number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Pronic number 0
    int num4 = 0;
    bool result4 = isPronicNumber(num4);
    int factors4[2];
    bool hasFactors4 = getPronicFactors(num4, factors4);
    printf("Number: %d\n", num4);
    if (hasFactors4) {
        printf("Factors: %d × %d = %d\n", factors4[0], factors4[1], num4);
    }
    printf("Is Pronic number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Pronic numbers in range
    int start = 0;
    int end = 50;
    int pronicNums[20];
    int count = getPronicNumbersInRange(start, end, pronicNums, 20);
    printf("Pronic numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", pronicNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Check if a Number is Deficient Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Deficient number 8
    int num1_def = 8;
    bool result1_def = isDeficientNumber(num1_def);
    int divisors1[20];
    int count1 = getProperDivisors(num1_def, divisors1, 20);
    int sum1 = sumOfProperDivisors(num1_def);
    printf("Number: %d\n", num1_def);
    printf("Proper divisors: ");
    for (int i = 0; i < count1; i++) {
        printf("%d ", divisors1[i]);
    }
    printf("\nSum of proper divisors: %d\n", sum1);
    printf("Is deficient: %s\n\n", result1_def ? "true" : "false");
    
    // Test Case 2 - Not deficient (perfect number 6)
    int num2_def = 6;
    bool result2_def = isDeficientNumber(num2_def);
    int divisors2[20];
    int count2 = getProperDivisors(num2_def, divisors2, 20);
    int sum2 = sumOfProperDivisors(num2_def);
    printf("Number: %d\n", num2_def);
    printf("Proper divisors: ");
    for (int i = 0; i < count2; i++) {
        printf("%d ", divisors2[i]);
    }
    printf("\nSum of proper divisors: %d\n", sum2);
    printf("Is deficient: %s\n\n", result2_def ? "true" : "false");
    
    // Test Case 3 - Deficient number 10
    int num3_def = 10;
    bool result3_def = isDeficientNumber(num3_def);
    int divisors3[20];
    int count3 = getProperDivisors(num3_def, divisors3, 20);
    int sum3 = sumOfProperDivisors(num3_def);
    printf("Number: %d\n", num3_def);
    printf("Proper divisors: ");
    for (int i = 0; i < count3; i++) {
        printf("%d ", divisors3[i]);
    }
    printf("\nSum of proper divisors: %d\n", sum3);
    printf("Is deficient: %s\n\n", result3_def ? "true" : "false");
    
    // Test Case 4 - Deficient number 1
    int num4_def = 1;
    bool result4_def = isDeficientNumber(num4_def);
    printf("Number: %d\n", num4_def);
    printf("Is deficient: %s\n\n", result4_def ? "true" : "false");
    
    // Test Case 5 - Find Deficient numbers in range
    int start_def = 1;
    int end_def = 30;
    int deficientNums[30];
    int count_def = getDeficientNumbersInRange(start_def, end_def, deficientNums, 30);
    printf("Deficient numbers in range [%d, %d]:\n", start_def, end_def);
    for (int i = 0; i < count_def; i++) {
        printf("%d ", deficientNums[i]);
    }
    printf("\nCount: %d\n", count_def);
    
    return 0;
}
