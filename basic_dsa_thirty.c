#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Ugly Number
// An Ugly number is a number whose only prime factors are 2, 3, or 5
// Example: 6 = 2 × 3 (ugly), 8 = 2 × 2 × 2 (ugly), 14 = 2 × 7 (not ugly, has factor 7)

/**
 * Check if a number is Ugly number
 * An Ugly number has only prime factors 2, 3, or 5
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isUglyNumber(int n) {
    if (n <= 0) {
        return false;
    }
    if (n == 1) {
        return true; // 1 is considered ugly
    }
    
    // Remove all factors of 2, 3, and 5
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    
    // If after removing 2, 3, 5 factors, we get 1, it's ugly
    return n == 1;
}

/**
 * Get prime factors of a number (only 2, 3, 5 if ugly)
 * Stores factors in array and returns count, or -1 if has other factors
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
int getUglyFactors(int n, int* factors, int maxSize) {
    if (n <= 0 || factors == NULL || maxSize == 0) {
        return -1;
    }
    
    int count = 0;
    int num = n;
    int primes[] = {2, 3, 5};
    
    for (int i = 0; i < 3 && count < maxSize; i++) {
        while (num % primes[i] == 0 && count < maxSize) {
            factors[count++] = primes[i];
            num /= primes[i];
        }
    }
    
    return num == 1 ? count : -1;
}

/**
 * Find all Ugly numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Ugly numbers
 */
int getUglyNumbersInRange(int start, int end, int* uglyNumbers, int maxSize) {
    if (uglyNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isUglyNumber(num)) {
            uglyNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Find Sum of First N Odd Numbers
// Sum of first n odd numbers = n²
// Example: 1 + 3 + 5 + 7 = 16 = 4²

/**
 * Find sum of first n odd numbers using iteration
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long sumOfOddNumbersIterative(int n) {
    if (n <= 0) {
        return 0;
    }
    
    long long total = 0;
    int odd = 1;
    
    for (int i = 0; i < n; i++) {
        total += odd;
        odd += 2;
    }
    
    return total;
}

/**
 * Find sum of first n odd numbers using formula
 * Sum = n²
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long sumOfOddNumbersFormula(int n) {
    if (n <= 0) {
        return 0;
    }
    return (long long) n * n;
}

/**
 * Find sum of first n odd numbers using recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long sumOfOddNumbersRecursive(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // nth odd number = 2n - 1
    int nthOdd = 2 * n - 1;
    return nthOdd + sumOfOddNumbersRecursive(n - 1);
}

/**
 * Get list of first n odd numbers
 * Stores results in array and returns count
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int getFirstNOddNumbers(int n, int* oddNumbers, int maxSize) {
    if (n <= 0 || oddNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    int odd = 1;
    
    for (int i = 0; i < n && count < maxSize; i++) {
        oddNumbers[count++] = odd;
        odd += 2;
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Ugly Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Ugly number 6
    int num1 = 6;
    bool result1 = isUglyNumber(num1);
    int factors1[20];
    int count1 = getUglyFactors(num1, factors1, 20);
    printf("Number: %d\n", num1);
    if (count1 > 0) {
        printf("Prime factors: ");
        for (int i = 0; i < count1; i++) {
            printf("%d ", factors1[i]);
        }
        printf("\n");
    }
    printf("Is Ugly number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Ugly number 8
    int num2 = 8;
    bool result2 = isUglyNumber(num2);
    int factors2[20];
    int count2 = getUglyFactors(num2, factors2, 20);
    printf("Number: %d\n", num2);
    if (count2 > 0) {
        printf("Prime factors: ");
        for (int i = 0; i < count2; i++) {
            printf("%d ", factors2[i]);
        }
        printf("\n");
    }
    printf("Is Ugly number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Ugly number 14
    int num3 = 14;
    bool result3 = isUglyNumber(num3);
    int factors3[20];
    int count3 = getUglyFactors(num3, factors3, 20);
    printf("Number: %d\n", num3);
    if (count3 > 0) {
        printf("Prime factors: ");
        for (int i = 0; i < count3; i++) {
            printf("%d ", factors3[i]);
        }
        printf("\n");
    } else {
        printf("Has prime factors other than 2, 3, 5\n");
    }
    printf("Is Ugly number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Ugly number 1
    int num4 = 1;
    bool result4 = isUglyNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Ugly number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Ugly numbers in range
    int start = 1;
    int end = 30;
    int uglyNums[50];
    int count = getUglyNumbersInRange(start, end, uglyNums, 50);
    printf("Ugly numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", uglyNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Find Sum of First N Odd Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1 - Sum of first 4 odd numbers
    int n1 = 4;
    long long result1_sum = sumOfOddNumbersIterative(n1);
    long long result1_formula = sumOfOddNumbersFormula(n1);
    long long result1_rec = sumOfOddNumbersRecursive(n1);
    int oddNums1[20];
    int count_odd1 = getFirstNOddNumbers(n1, oddNums1, 20);
    printf("n = %d\n", n1);
    printf("First %d odd numbers: ", n1);
    for (int i = 0; i < count_odd1; i++) {
        printf("%d ", oddNums1[i]);
    }
    printf("\nSum (iterative): %lld\n", result1_sum);
    printf("Sum (formula): %lld\n", result1_formula);
    printf("Sum (recursive): %lld\n", result1_rec);
    printf("Verification: %d² = %d\n\n", n1, n1 * n1);
    
    // Test Case 2 - Sum of first 10 odd numbers
    int n2 = 10;
    long long result2_sum = sumOfOddNumbersFormula(n2);
    int oddNums2[20];
    int count_odd2 = getFirstNOddNumbers(n2, oddNums2, 20);
    printf("n = %d\n", n2);
    printf("First %d odd numbers: ", n2);
    for (int i = 0; i < count_odd2; i++) {
        printf("%d ", oddNums2[i]);
    }
    printf("\nSum: %lld\n", result2_sum);
    printf("Verification: %d² = %d\n\n", n2, n2 * n2);
    
    // Test Case 3 - Sum of first 1 odd number
    int n3 = 1;
    long long result3_sum = sumOfOddNumbersFormula(n3);
    printf("n = %d\n", n3);
    printf("Sum: %lld\n\n", result3_sum);
    
    // Test Case 4 - Sum of first 5 odd numbers
    int n4 = 5;
    long long result4_sum = sumOfOddNumbersFormula(n4);
    int oddNums4[20];
    int count_odd4 = getFirstNOddNumbers(n4, oddNums4, 20);
    printf("n = %d\n", n4);
    printf("First %d odd numbers: ", n4);
    for (int i = 0; i < count_odd4; i++) {
        printf("%d ", oddNums4[i]);
    }
    printf("\nSum: %lld\n\n", result4_sum);
    
    // Test Case 5 - Large n
    int n5 = 20;
    long long result5_sum = sumOfOddNumbersFormula(n5);
    printf("n = %d\n", n5);
    printf("Sum of first %d odd numbers: %lld\n", n5, result5_sum);
    printf("Verification: %d² = %d\n", n5, n5 * n5);
    
    return 0;
}
