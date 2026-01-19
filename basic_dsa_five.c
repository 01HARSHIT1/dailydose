#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Find Factorial of a Number
// Calculate factorial using both iterative and recursive approaches

/**
 * Iterative approach to find factorial
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long factorialIterative(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Recursive approach to find factorial
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long factorialRecursive(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return (long long) n * factorialRecursive(n - 1);
}

// Problem 2: Check if a Number is Prime
// Determine whether a number is prime or not

/**
 * Check if a number is prime
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    
    // Check divisibility from 3 to √n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Find Factorial of a Number\n");
    printf("============================================================\n");
    
    // Test Case 1
    int num1 = 5;
    long long factIter1 = factorialIterative(num1);
    long long factRec1 = factorialRecursive(num1);
    printf("Number: %d\n", num1);
    printf("Factorial (Iterative): %lld\n", factIter1);
    printf("Factorial (Recursive): %lld\n\n", factRec1);
    
    // Test Case 2
    int num2 = 0;
    long long factIter2 = factorialIterative(num2);
    long long factRec2 = factorialRecursive(num2);
    printf("Number: %d\n", num2);
    printf("Factorial (Iterative): %lld\n", factIter2);
    printf("Factorial (Recursive): %lld\n\n", factRec2);
    
    // Test Case 3
    int num3 = 1;
    long long factIter3 = factorialIterative(num3);
    long long factRec3 = factorialRecursive(num3);
    printf("Number: %d\n", num3);
    printf("Factorial (Iterative): %lld\n", factIter3);
    printf("Factorial (Recursive): %lld\n\n", factRec3);
    
    // Test Case 4
    int num4 = 7;
    long long factIter4 = factorialIterative(num4);
    long long factRec4 = factorialRecursive(num4);
    printf("Number: %d\n", num4);
    printf("Factorial (Iterative): %lld\n", factIter4);
    printf("Factorial (Recursive): %lld\n\n", factRec4);
    
    // Test Case 5 - Negative number
    int num5 = -5;
    long long factIter5 = factorialIterative(num5);
    long long factRec5 = factorialRecursive(num5);
    printf("Number: %d\n", num5);
    if (factIter5 == -1) {
        printf("Factorial (Iterative): Not defined for negative numbers\n");
    } else {
        printf("Factorial (Iterative): %lld\n", factIter5);
    }
    if (factRec5 == -1) {
        printf("Factorial (Recursive): Not defined for negative numbers\n\n");
    } else {
        printf("Factorial (Recursive): %lld\n\n", factRec5);
    }
    
    printf("============================================================\n");
    printf("Problem 2: Check if a Number is Prime\n");
    printf("============================================================\n");
    
    // Test Case 1 - Prime number
    int num6 = 7;
    bool result1 = isPrime(num6);
    printf("Number: %d\n", num6);
    printf("Is Prime: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Non-prime number
    int num7 = 10;
    bool result2 = isPrime(num7);
    printf("Number: %d\n", num7);
    printf("Is Prime: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Smallest prime
    int num8 = 2;
    bool result3 = isPrime(num8);
    printf("Number: %d\n", num8);
    printf("Is Prime: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Number less than 2
    int num9 = 1;
    bool result4 = isPrime(num9);
    printf("Number: %d\n", num9);
    printf("Is Prime: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Large prime
    int num10 = 17;
    bool result5 = isPrime(num10);
    printf("Number: %d\n", num10);
    printf("Is Prime: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - Even number (except 2)
    int num11 = 4;
    bool result6 = isPrime(num11);
    printf("Number: %d\n", num11);
    printf("Is Prime: %s\n\n", result6 ? "true" : "false");
    
    // Test Case 7 - Large non-prime
    int num12 = 100;
    bool result7 = isPrime(num12);
    printf("Number: %d\n", num12);
    printf("Is Prime: %s\n\n", result7 ? "true" : "false");
    
    // Test Case 8 - Prime number
    int num13 = 13;
    bool result8 = isPrime(num13);
    printf("Number: %d\n", num13);
    printf("Is Prime: %s\n\n", result8 ? "true" : "false");
    
    return 0;
}
