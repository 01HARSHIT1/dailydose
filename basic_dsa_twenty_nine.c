#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

#define MAX_SIZE 1000

// Problem 1: Check if a Number is Happy Number
// A happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit

/**
 * Calculate sum of squares of digits
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int sumOfSquaresOfDigits(int n) {
    int total = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        int digit = num % 10;
        total += digit * digit;
        num /= 10;
    }
    
    return total;
}

/**
 * Check if a number is Happy number
 * Time Complexity: O(k) where k is the cycle length
 * Space Complexity: O(k)
 */
bool isHappyNumber(int n) {
    if (n <= 0) {
        return false;
    }
    
    bool seen[MAX_SIZE] = {false};
    int current = n;
    
    while (current != 1 && current < MAX_SIZE && !seen[current]) {
        seen[current] = true;
        current = sumOfSquaresOfDigits(current);
    }
    
    return current == 1;
}

/**
 * Get the sequence of numbers until it reaches 1 or detects a cycle
 * Stores sequence in array and returns count
 * Time Complexity: O(k) where k is the length of sequence
 * Space Complexity: O(k)
 */
int getHappySequence(int n, int* sequence, int maxSize) {
    if (n <= 0 || sequence == NULL || maxSize == 0) {
        return 0;
    }
    
    bool seen[MAX_SIZE] = {false};
    int current = n;
    int count = 0;
    
    while (current != 1 && current < MAX_SIZE && !seen[current] && count < maxSize) {
        sequence[count++] = current;
        seen[current] = true;
        current = sumOfSquaresOfDigits(current);
    }
    if (count < maxSize) {
        sequence[count++] = current;
    }
    
    return count;
}

/**
 * Find all Happy numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * k)
 * Space Complexity: O(m) where m is the number of Happy numbers
 */
int getHappyNumbersInRange(int start, int end, int* happyNumbers, int maxSize) {
    if (happyNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isHappyNumber(num)) {
            happyNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Find nth Fibonacci Number
// Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
// F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

/**
 * Find nth Fibonacci number using iteration
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long nthFibonacciIterative(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    if (n <= 1) {
        return n;
    }
    
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

/**
 * Find nth Fibonacci number using recursion
 * Time Complexity: O(2^n) - exponential
 * Space Complexity: O(n) due to recursion stack
 */
long long nthFibonacciRecursive(int n) {
    if (n < 0) {
        return -1;
    }
    if (n <= 1) {
        return n;
    }
    
    return nthFibonacciRecursive(n - 1) + nthFibonacciRecursive(n - 2);
}

/**
 * Find nth Fibonacci number using memoization (top-down DP)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
long long nthFibonacciMemoizationHelper(int n, long long* memo) {
    if (n <= 1) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = nthFibonacciMemoizationHelper(n - 1, memo) + 
               nthFibonacciMemoizationHelper(n - 2, memo);
    return memo[n];
}

long long nthFibonacciMemoization(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    
    long long* memo = (long long*)malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    long long result = nthFibonacciMemoizationHelper(n, memo);
    free(memo);
    return result;
}

/**
 * Find nth Fibonacci number using Binet's formula
 * Time Complexity: O(1) (but limited by floating point precision)
 * Space Complexity: O(1)
 */
long long nthFibonacciFormula(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    if (n <= 1) {
        return n;
    }
    
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;
    
    return (long long)round((pow(phi, n) - pow(psi, n)) / sqrt5);
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Happy Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Happy number 19
    int num1 = 19;
    bool result1 = isHappyNumber(num1);
    int sequence1[20];
    int count1 = getHappySequence(num1, sequence1, 20);
    printf("Number: %d\n", num1);
    printf("Sequence: ");
    for (int i = 0; i < count1; i++) {
        printf("%d ", sequence1[i]);
    }
    printf("\nIs Happy number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Happy number 7
    int num2 = 7;
    bool result2 = isHappyNumber(num2);
    int sequence2[20];
    int count2 = getHappySequence(num2, sequence2, 20);
    printf("Number: %d\n", num2);
    printf("Sequence: ");
    for (int i = 0; i < count2; i++) {
        printf("%d ", sequence2[i]);
    }
    printf("\nIs Happy number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Happy number 4
    int num3 = 4;
    bool result3 = isHappyNumber(num3);
    int sequence3[20];
    int count3 = getHappySequence(num3, sequence3, 20);
    printf("Number: %d\n", num3);
    printf("Sequence: ");
    for (int i = 0; i < count3; i++) {
        printf("%d ", sequence3[i]);
    }
    printf("\nIs Happy number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Single digit happy
    int num4 = 1;
    bool result4 = isHappyNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Happy number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Happy numbers in range
    int start = 1;
    int end = 50;
    int happyNums[50];
    int count = getHappyNumbersInRange(start, end, happyNums, 50);
    printf("Happy numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", happyNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Find nth Fibonacci Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - 10th Fibonacci number
    int n1 = 10;
    long long result1_fib = nthFibonacciIterative(n1);
    long long result1_memo = nthFibonacciMemoization(n1);
    long long result1_formula = nthFibonacciFormula(n1);
    printf("n = %d\n", n1);
    printf("Fibonacci (iterative): %lld\n", result1_fib);
    printf("Fibonacci (memoization): %lld\n", result1_memo);
    printf("Fibonacci (formula): %lld\n\n", result1_formula);
    
    // Test Case 2 - 5th Fibonacci number
    int n2 = 5;
    long long result2_iter = nthFibonacciIterative(n2);
    long long result2_rec = nthFibonacciRecursive(n2);
    printf("n = %d\n", n2);
    printf("Fibonacci (iterative): %lld\n", result2_iter);
    printf("Fibonacci (recursive): %lld\n\n", result2_rec);
    
    // Test Case 3 - 0th Fibonacci number
    int n3 = 0;
    long long result3 = nthFibonacciIterative(n3);
    printf("n = %d\n", n3);
    printf("Fibonacci: %lld\n\n", result3);
    
    // Test Case 4 - 1st Fibonacci number
    int n4 = 1;
    long long result4_fib = nthFibonacciIterative(n4);
    printf("n = %d\n", n4);
    printf("Fibonacci: %lld\n\n", result4_fib);
    
    // Test Case 5 - Larger Fibonacci number
    int n5 = 20;
    long long result5_iter = nthFibonacciIterative(n5);
    long long result5_memo = nthFibonacciMemoization(n5);
    printf("n = %d\n", n5);
    printf("Fibonacci (iterative): %lld\n", result5_iter);
    printf("Fibonacci (memoization): %lld\n", result5_memo);
    
    return 0;
}
