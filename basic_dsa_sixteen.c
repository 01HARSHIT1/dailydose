#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Perfect Number
// A perfect number is a positive integer that is equal to the sum of its proper divisors
// Example: 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14

/**
 * Check if a number is perfect number
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isPerfectNumber(int n) {
    if (n <= 1) {
        return false;
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
    
    return sumDivisors == n;
}

/**
 * Get sum of proper divisors of a number (excluding the number itself)
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
int getSumOfProperDivisors(int n) {
    if (n <= 1) {
        return 0;
    }
    
    int sum = 1; // 1 is always a divisor
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    
    return sum;
}

// Problem 2: Find Sum of Squares of First N Natural Numbers
// Calculate 1² + 2² + 3² + ... + N²

/**
 * Find sum of squares using iteration
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long sumOfSquaresIterative(int n) {
    if (n <= 0) {
        return 0;
    }
    
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += (long long) i * i;
    }
    return total;
}

/**
 * Find sum of squares using mathematical formula: n(n+1)(2n+1)/6
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long sumOfSquaresFormula(int n) {
    if (n <= 0) {
        return 0;
    }
    return (long long) n * (n + 1) * (2 * n + 1) / 6;
}

/**
 * Find sum of squares using recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long sumOfSquaresRecursive(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return (long long) n * n + sumOfSquaresRecursive(n - 1);
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Perfect Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Perfect number 6
    int num1 = 6;
    bool result1 = isPerfectNumber(num1);
    int sum1 = getSumOfProperDivisors(num1);
    printf("Number: %d\n", num1);
    printf("Sum of proper divisors: %d\n", sum1);
    printf("Is perfect number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Perfect number 28
    int num2 = 28;
    bool result2 = isPerfectNumber(num2);
    int sum2 = getSumOfProperDivisors(num2);
    printf("Number: %d\n", num2);
    printf("Sum of proper divisors: %d\n", sum2);
    printf("Is perfect number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not perfect number
    int num3 = 10;
    bool result3 = isPerfectNumber(num3);
    int sum3 = getSumOfProperDivisors(num3);
    printf("Number: %d\n", num3);
    printf("Sum of proper divisors: %d\n", sum3);
    printf("Is perfect number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Perfect number 496
    int num4 = 496;
    bool result4 = isPerfectNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is perfect number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Not perfect number
    int num5 = 1;
    bool result5 = isPerfectNumber(num5);
    printf("Number: %d\n", num5);
    printf("Is perfect number: %s\n\n", result5 ? "true" : "false");
    
    printf("============================================================\n");
    printf("Problem 2: Find Sum of Squares of First N Natural Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1
    int n1 = 5;
    long long result1_iter = sumOfSquaresIterative(n1);
    long long result1_formula = sumOfSquaresFormula(n1);
    long long result1_rec = sumOfSquaresRecursive(n1);
    printf("N = %d\n", n1);
    printf("1² + 2² + 3² + 4² + 5² = %lld\n", result1_iter);
    printf("Iterative method: %lld\n", result1_iter);
    printf("Formula method: %lld\n", result1_formula);
    printf("Recursive method: %lld\n\n", result1_rec);
    
    // Test Case 2
    int n2 = 10;
    long long result2 = sumOfSquaresFormula(n2);
    printf("N = %d\n", n2);
    printf("Sum of squares: %lld\n\n", result2);
    
    // Test Case 3
    int n3 = 1;
    long long result3 = sumOfSquaresFormula(n3);
    printf("N = %d\n", n3);
    printf("Sum of squares: %lld\n\n", result3);
    
    // Test Case 4
    int n4 = 20;
    long long result4 = sumOfSquaresFormula(n4);
    printf("N = %d\n", n4);
    printf("Sum of squares: %lld\n\n", result4);
    
    // Test Case 5 - Large number
    int n5 = 100;
    long long result5 = sumOfSquaresFormula(n5);
    printf("N = %d\n", n5);
    printf("Sum of squares: %lld\n\n", result5);
    
    return 0;
}
