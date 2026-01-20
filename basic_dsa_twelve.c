#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Even or Odd
// Determine whether a number is even or odd

/**
 * Check if a number is even or odd using modulo operator
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
const char* isEvenOrOdd(int n) {
    if (n % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}

/**
 * Check if a number is even or odd using bitwise AND
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
const char* isEvenOrOddBitwise(int n) {
    if ((n & 1) == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}

// Problem 2: Find Sum of First N Natural Numbers
// Calculate the sum of first n natural numbers (1 + 2 + 3 + ... + n)

/**
 * Find sum using iterative approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long sumNaturalNumbersIterative(int n) {
    if (n < 0) {
        return -1; // Invalid input
    }
    
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

/**
 * Find sum using mathematical formula: n * (n + 1) / 2
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long sumNaturalNumbersFormula(int n) {
    if (n < 0) {
        return -1; // Invalid input
    }
    return (long long) n * (n + 1) / 2;
}

/**
 * Find sum using recursive approach
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long sumNaturalNumbersRecursive(int n) {
    if (n < 0) {
        return -1; // Invalid input
    }
    if (n == 0) {
        return 0;
    }
    return (long long) n + sumNaturalNumbersRecursive(n - 1);
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Even or Odd\n");
    printf("============================================================\n");
    
    // Test Case 1 - Even number
    int num1 = 10;
    printf("Number: %d\n", num1);
    printf("Result (Modulo): %s\n", isEvenOrOdd(num1));
    printf("Result (Bitwise): %s\n\n", isEvenOrOddBitwise(num1));
    
    // Test Case 2 - Odd number
    int num2 = 15;
    printf("Number: %d\n", num2);
    printf("Result (Modulo): %s\n", isEvenOrOdd(num2));
    printf("Result (Bitwise): %s\n\n", isEvenOrOddBitwise(num2));
    
    // Test Case 3 - Zero
    int num3 = 0;
    printf("Number: %d\n", num3);
    printf("Result (Modulo): %s\n", isEvenOrOdd(num3));
    printf("Result (Bitwise): %s\n\n", isEvenOrOddBitwise(num3));
    
    // Test Case 4 - Negative even
    int num4 = -8;
    printf("Number: %d\n", num4);
    printf("Result (Modulo): %s\n", isEvenOrOdd(num4));
    printf("Result (Bitwise): %s\n\n", isEvenOrOddBitwise(num4));
    
    // Test Case 5 - Negative odd
    int num5 = -7;
    printf("Number: %d\n", num5);
    printf("Result (Modulo): %s\n", isEvenOrOdd(num5));
    printf("Result (Bitwise): %s\n\n", isEvenOrOddBitwise(num5));
    
    // Test Case 6 - Large even number
    int num6 = 1000;
    printf("Number: %d\n", num6);
    printf("Result (Modulo): %s\n", isEvenOrOdd(num6));
    printf("Result (Bitwise): %s\n\n", isEvenOrOddBitwise(num6));
    
    printf("============================================================\n");
    printf("Problem 2: Find Sum of First N Natural Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1
    int n1 = 5;
    long long sumIter1 = sumNaturalNumbersIterative(n1);
    long long sumFormula1 = sumNaturalNumbersFormula(n1);
    long long sumRec1 = sumNaturalNumbersRecursive(n1);
    printf("N = %d\n", n1);
    printf("Sum (Iterative): %lld\n", sumIter1);
    printf("Sum (Formula): %lld\n", sumFormula1);
    printf("Sum (Recursive): %lld\n", sumRec1);
    printf("Verification: 1+2+3+4+5 = %lld\n\n", sumIter1);
    
    // Test Case 2
    int n2 = 10;
    long long sumIter2 = sumNaturalNumbersIterative(n2);
    long long sumFormula2 = sumNaturalNumbersFormula(n2);
    long long sumRec2 = sumNaturalNumbersRecursive(n2);
    printf("N = %d\n", n2);
    printf("Sum (Iterative): %lld\n", sumIter2);
    printf("Sum (Formula): %lld\n", sumFormula2);
    printf("Sum (Recursive): %lld\n\n", sumRec2);
    
    // Test Case 3 - Single number
    int n3 = 1;
    long long sumIter3 = sumNaturalNumbersIterative(n3);
    long long sumFormula3 = sumNaturalNumbersFormula(n3);
    long long sumRec3 = sumNaturalNumbersRecursive(n3);
    printf("N = %d\n", n3);
    printf("Sum (Iterative): %lld\n", sumIter3);
    printf("Sum (Formula): %lld\n", sumFormula3);
    printf("Sum (Recursive): %lld\n\n", sumRec3);
    
    // Test Case 4 - Zero
    int n4 = 0;
    long long sumIter4 = sumNaturalNumbersIterative(n4);
    long long sumFormula4 = sumNaturalNumbersFormula(n4);
    long long sumRec4 = sumNaturalNumbersRecursive(n4);
    printf("N = %d\n", n4);
    printf("Sum (Iterative): %lld\n", sumIter4);
    printf("Sum (Formula): %lld\n", sumFormula4);
    printf("Sum (Recursive): %lld\n\n", sumRec4);
    
    // Test Case 5 - Large number
    int n5 = 100;
    long long sumIter5 = sumNaturalNumbersIterative(n5);
    long long sumFormula5 = sumNaturalNumbersFormula(n5);
    long long sumRec5 = sumNaturalNumbersRecursive(n5);
    printf("N = %d\n", n5);
    printf("Sum (Iterative): %lld\n", sumIter5);
    printf("Sum (Formula): %lld\n", sumFormula5);
    printf("Sum (Recursive): %lld\n\n", sumRec5);
    
    // Test Case 6 - Negative number
    int n6 = -5;
    long long sumIter6 = sumNaturalNumbersIterative(n6);
    long long sumFormula6 = sumNaturalNumbersFormula(n6);
    long long sumRec6 = sumNaturalNumbersRecursive(n6);
    printf("N = %d\n", n6);
    if (sumIter6 == -1) {
        printf("Sum (Iterative): Invalid input\n");
    } else {
        printf("Sum (Iterative): %lld\n", sumIter6);
    }
    if (sumFormula6 == -1) {
        printf("Sum (Formula): Invalid input\n");
    } else {
        printf("Sum (Formula): %lld\n", sumFormula6);
    }
    if (sumRec6 == -1) {
        printf("Sum (Recursive): Invalid input\n");
    } else {
        printf("Sum (Recursive): %lld\n", sumRec6);
    }
    
    return 0;
}
