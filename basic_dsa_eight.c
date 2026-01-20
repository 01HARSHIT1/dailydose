#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Sum of Digits of a Number
// Calculate the sum of all digits in a number

/**
 * Calculate sum of digits using iterative approach
 * Time Complexity: O(log n) where log is base 10
 * Space Complexity: O(1)
 */
int sumOfDigits(int n) {
    n = abs(n); // Handle negative numbers
    int total = 0;
    
    while (n > 0) {
        total += n % 10;
        n /= 10;
    }
    
    return total;
}

/**
 * Calculate sum of digits using recursive approach
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */
int sumOfDigitsRecursive(int n) {
    n = abs(n); // Handle negative numbers
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigitsRecursive(n / 10);
}

// Problem 2: Reverse a Number
// Reverse the digits of a number

/**
 * Reverse a number using iterative approach
 * Time Complexity: O(log n) where log is base 10
 * Space Complexity: O(1)
 */
int reverseNumber(int n) {
    int isNegative = (n < 0);
    n = abs(n);
    long long reversedNum = 0; // Use long long to check overflow
    
    while (n > 0) {
        reversedNum = reversedNum * 10 + n % 10;
        n /= 10;
        
        // Check for overflow
        if (reversedNum > INT_MAX) {
            return 0; // Overflow
        }
    }
    
    return isNegative ? -(int)reversedNum : (int)reversedNum;
}

/**
 * Reverse a number using recursive approach (helper function)
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */
long long reverseNumberHelper(int n, long long reversedSoFar) {
    if (n == 0) {
        return reversedSoFar;
    }
    return reverseNumberHelper(n / 10, reversedSoFar * 10 + n % 10);
}

int reverseNumberRecursive(int n) {
    int isNegative = (n < 0);
    long long reversed = reverseNumberHelper(abs(n), 0);
    
    // Check for overflow
    if (reversed > INT_MAX) {
        return 0;
    }
    
    return isNegative ? -(int)reversed : (int)reversed;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Sum of Digits of a Number\n");
    printf("============================================================\n");
    
    // Test Case 1
    int num1 = 12345;
    int sumIter1 = sumOfDigits(num1);
    int sumRec1 = sumOfDigitsRecursive(num1);
    printf("Number: %d\n", num1);
    printf("Sum of digits (Iterative): %d\n", sumIter1);
    printf("Sum of digits (Recursive): %d\n\n", sumRec1);
    
    // Test Case 2
    int num2 = 9876;
    int sumIter2 = sumOfDigits(num2);
    int sumRec2 = sumOfDigitsRecursive(num2);
    printf("Number: %d\n", num2);
    printf("Sum of digits (Iterative): %d\n", sumIter2);
    printf("Sum of digits (Recursive): %d\n\n", sumRec2);
    
    // Test Case 3 - Single digit
    int num3 = 5;
    int sumIter3 = sumOfDigits(num3);
    int sumRec3 = sumOfDigitsRecursive(num3);
    printf("Number: %d\n", num3);
    printf("Sum of digits (Iterative): %d\n", sumIter3);
    printf("Sum of digits (Recursive): %d\n\n", sumRec3);
    
    // Test Case 4 - Negative number
    int num4 = -123;
    int sumIter4 = sumOfDigits(num4);
    int sumRec4 = sumOfDigitsRecursive(num4);
    printf("Number: %d\n", num4);
    printf("Sum of digits (Iterative): %d\n", sumIter4);
    printf("Sum of digits (Recursive): %d\n\n", sumRec4);
    
    // Test Case 5 - Zero
    int num5 = 0;
    int sumIter5 = sumOfDigits(num5);
    int sumRec5 = sumOfDigitsRecursive(num5);
    printf("Number: %d\n", num5);
    printf("Sum of digits (Iterative): %d\n", sumIter5);
    printf("Sum of digits (Recursive): %d\n\n", sumRec5);
    
    // Test Case 6 - Number with zeros
    int num6 = 1005;
    int sumIter6 = sumOfDigits(num6);
    int sumRec6 = sumOfDigitsRecursive(num6);
    printf("Number: %d\n", num6);
    printf("Sum of digits (Iterative): %d\n", sumIter6);
    printf("Sum of digits (Recursive): %d\n\n", sumRec6);
    
    printf("============================================================\n");
    printf("Problem 2: Reverse a Number\n");
    printf("============================================================\n");
    
    // Test Case 1
    int num7 = 12345;
    int revIter1 = reverseNumber(num7);
    int revRec1 = reverseNumberRecursive(num7);
    printf("Number: %d\n", num7);
    printf("Reversed (Iterative): %d\n", revIter1);
    printf("Reversed (Recursive): %d\n\n", revRec1);
    
    // Test Case 2
    int num8 = 9876;
    int revIter2 = reverseNumber(num8);
    int revRec2 = reverseNumberRecursive(num8);
    printf("Number: %d\n", num8);
    printf("Reversed (Iterative): %d\n", revIter2);
    printf("Reversed (Recursive): %d\n\n", revRec2);
    
    // Test Case 3 - Single digit
    int num9 = 5;
    int revIter3 = reverseNumber(num9);
    int revRec3 = reverseNumberRecursive(num9);
    printf("Number: %d\n", num9);
    printf("Reversed (Iterative): %d\n", revIter3);
    printf("Reversed (Recursive): %d\n\n", revRec3);
    
    // Test Case 4 - Negative number
    int num10 = -123;
    int revIter4 = reverseNumber(num10);
    int revRec4 = reverseNumberRecursive(num10);
    printf("Number: %d\n", num10);
    printf("Reversed (Iterative): %d\n", revIter4);
    printf("Reversed (Recursive): %d\n\n", revRec4);
    
    // Test Case 5 - Number ending with zero
    int num11 = 1200;
    int revIter5 = reverseNumber(num11);
    int revRec5 = reverseNumberRecursive(num11);
    printf("Number: %d\n", num11);
    printf("Reversed (Iterative): %d\n", revIter5);
    printf("Reversed (Recursive): %d\n\n", revRec5);
    
    // Test Case 6 - Palindrome number
    int num12 = 1221;
    int revIter6 = reverseNumber(num12);
    int revRec6 = reverseNumberRecursive(num12);
    printf("Number: %d\n", num12);
    printf("Reversed (Iterative): %d\n", revIter6);
    printf("Reversed (Recursive): %d\n\n", revRec6);
    
    return 0;
}
