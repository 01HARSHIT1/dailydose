#include <stdio.h>
#include <stdlib.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Calculate Power of a Number
// Calculate a raised to the power b (a^b)

/**
 * Calculate power using iterative approach
 * Time Complexity: O(exponent)
 * Space Complexity: O(1)
 */
long long powerIterative(int base, int exponent) {
    if (exponent < 0) {
        return -1; // Handle negative exponents separately
    }
    
    long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/**
 * Calculate power using recursive approach
 * Time Complexity: O(exponent)
 * Space Complexity: O(exponent) due to recursion stack
 */
long long powerRecursive(int base, int exponent) {
    if (exponent < 0) {
        return -1; // Handle negative exponents separately
    }
    if (exponent == 0) {
        return 1;
    }
    return base * powerRecursive(base, exponent - 1);
}

/**
 * Calculate power using optimized approach (binary exponentiation)
 * Time Complexity: O(log exponent)
 * Space Complexity: O(log exponent) due to recursion
 */
long long powerOptimized(int base, int exponent) {
    if (exponent < 0) {
        return -1;
    }
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    
    if (exponent % 2 == 0) {
        // If exponent is even: base^exponent = (base^2)^(exponent/2)
        return powerOptimized(base * base, exponent / 2);
    } else {
        // If exponent is odd: base^exponent = base * base^(exponent-1)
        return base * powerOptimized(base * base, (exponent - 1) / 2);
    }
}

// Problem 2: Find LCM (Least Common Multiple) of Two Numbers
// Find the smallest positive integer that is divisible by both numbers

/**
 * Calculate GCD using Euclidean algorithm
 */
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * Find LCM using formula: LCM(a, b) = (a * b) / GCD(a, b)
 * Time Complexity: O(log(min(a, b))) - due to GCD calculation
 * Space Complexity: O(1)
 */
long long findLCM(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    
    return (long long)abs(a) * abs(b) / gcd(a, b);
}

/**
 * Find LCM using brute force approach
 * Time Complexity: O(a * b)
 * Space Complexity: O(1)
 */
long long findLCMBruteForce(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) {
        return 0;
    }
    
    long long maxNum = (a > b) ? a : b;
    while (1) {
        if (maxNum % a == 0 && maxNum % b == 0) {
            return maxNum;
        }
        maxNum++;
    }
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Calculate Power of a Number\n");
    printf("============================================================\n");
    
    // Test Case 1
    int base1 = 2, exp1 = 5;
    long long powIter1 = powerIterative(base1, exp1);
    long long powRec1 = powerRecursive(base1, exp1);
    long long powOpt1 = powerOptimized(base1, exp1);
    printf("Base: %d, Exponent: %d\n", base1, exp1);
    printf("Result (Iterative): %lld\n", powIter1);
    printf("Result (Recursive): %lld\n", powRec1);
    printf("Result (Optimized): %lld\n\n", powOpt1);
    
    // Test Case 2
    int base2 = 3, exp2 = 4;
    long long powIter2 = powerIterative(base2, exp2);
    long long powRec2 = powerRecursive(base2, exp2);
    long long powOpt2 = powerOptimized(base2, exp2);
    printf("Base: %d, Exponent: %d\n", base2, exp2);
    printf("Result (Iterative): %lld\n", powIter2);
    printf("Result (Recursive): %lld\n", powRec2);
    printf("Result (Optimized): %lld\n\n", powOpt2);
    
    // Test Case 3 - Power of 0
    int base3 = 5, exp3 = 0;
    long long powIter3 = powerIterative(base3, exp3);
    long long powRec3 = powerRecursive(base3, exp3);
    long long powOpt3 = powerOptimized(base3, exp3);
    printf("Base: %d, Exponent: %d\n", base3, exp3);
    printf("Result (Iterative): %lld\n", powIter3);
    printf("Result (Recursive): %lld\n", powRec3);
    printf("Result (Optimized): %lld\n\n", powOpt3);
    
    // Test Case 4 - Base is 0
    int base4 = 0, exp4 = 5;
    long long powIter4 = powerIterative(base4, exp4);
    long long powRec4 = powerRecursive(base4, exp4);
    long long powOpt4 = powerOptimized(base4, exp4);
    printf("Base: %d, Exponent: %d\n", base4, exp4);
    printf("Result (Iterative): %lld\n", powIter4);
    printf("Result (Recursive): %lld\n", powRec4);
    printf("Result (Optimized): %lld\n\n", powOpt4);
    
    // Test Case 5 - Large exponent
    int base5 = 2, exp5 = 10;
    long long powIter5 = powerIterative(base5, exp5);
    long long powRec5 = powerRecursive(base5, exp5);
    long long powOpt5 = powerOptimized(base5, exp5);
    printf("Base: %d, Exponent: %d\n", base5, exp5);
    printf("Result (Iterative): %lld\n", powIter5);
    printf("Result (Recursive): %lld\n", powRec5);
    printf("Result (Optimized): %lld\n\n", powOpt5);
    
    printf("============================================================\n");
    printf("Problem 2: Find LCM (Least Common Multiple) of Two Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1
    int a1 = 12, b1 = 18;
    long long lcm1 = findLCM(a1, b1);
    long long lcmBf1 = findLCMBruteForce(a1, b1);
    printf("Numbers: %d, %d\n", a1, b1);
    printf("LCM (Using GCD formula): %lld\n", lcm1);
    printf("LCM (Brute Force): %lld\n\n", lcmBf1);
    
    // Test Case 2
    int a2 = 15, b2 = 25;
    long long lcm2 = findLCM(a2, b2);
    long long lcmBf2 = findLCMBruteForce(a2, b2);
    printf("Numbers: %d, %d\n", a2, b2);
    printf("LCM (Using GCD formula): %lld\n", lcm2);
    printf("LCM (Brute Force): %lld\n\n", lcmBf2);
    
    // Test Case 3 - Coprime numbers
    int a3 = 7, b3 = 13;
    long long lcm3 = findLCM(a3, b3);
    long long lcmBf3 = findLCMBruteForce(a3, b3);
    printf("Numbers: %d, %d\n", a3, b3);
    printf("LCM (Using GCD formula): %lld\n", lcm3);
    printf("LCM (Brute Force): %lld\n\n", lcmBf3);
    
    // Test Case 4 - Same numbers
    int a4 = 10, b4 = 10;
    long long lcm4 = findLCM(a4, b4);
    long long lcmBf4 = findLCMBruteForce(a4, b4);
    printf("Numbers: %d, %d\n", a4, b4);
    printf("LCM (Using GCD formula): %lld\n", lcm4);
    printf("LCM (Brute Force): %lld\n\n", lcmBf4);
    
    // Test Case 5 - One number is multiple of other
    int a5 = 5, b5 = 15;
    long long lcm5 = findLCM(a5, b5);
    long long lcmBf5 = findLCMBruteForce(a5, b5);
    printf("Numbers: %d, %d\n", a5, b5);
    printf("LCM (Using GCD formula): %lld\n", lcm5);
    printf("LCM (Brute Force): %lld\n\n", lcmBf5);
    
    // Test Case 6 - Large numbers
    int a6 = 48, b6 = 60;
    long long lcm6 = findLCM(a6, b6);
    long long lcmBf6 = findLCMBruteForce(a6, b6);
    printf("Numbers: %d, %d\n", a6, b6);
    printf("LCM (Using GCD formula): %lld\n", lcm6);
    printf("LCM (Brute Force): %lld\n\n", lcmBf6);
    
    return 0;
}
