#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Find GCD (Greatest Common Divisor) / HCF (Highest Common Factor)
// Find the greatest common divisor of two numbers

/**
 * Find GCD using iterative approach (Euclidean Algorithm)
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(1)
 */
int gcdIterative(int a, int b) {
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
 * Find GCD using recursive approach (Euclidean Algorithm)
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(log(min(a, b))) due to recursion stack
 */
int gcdRecursive(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

// Problem 2: Check if a Number is Perfect Square
// Determine whether a number is a perfect square

/**
 * Check if a number is perfect square using sqrt
 * Time Complexity: O(1) - depends on sqrt implementation
 * Space Complexity: O(1)
 */
bool isPerfectSquare(int n) {
    if (n < 0) {
        return false;
    }
    
    int sqrtN = (int) sqrt(n);
    return sqrtN * sqrtN == n;
}

/**
 * Check if a number is perfect square without using sqrt library
 * Using binary search approach
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isPerfectSquareNoLibrary(int n) {
    if (n < 0) {
        return false;
    }
    if (n == 0 || n == 1) {
        return true;
    }
    
    long long left = 1;
    long long right = n / 2;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;
        
        if (square == n) {
            return true;
        } else if (square < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Find GCD (Greatest Common Divisor)\n");
    printf("============================================================\n");
    
    // Test Case 1
    int a1 = 48, b1 = 18;
    int gcdIter1 = gcdIterative(a1, b1);
    int gcdRec1 = gcdRecursive(a1, b1);
    printf("Numbers: %d, %d\n", a1, b1);
    printf("GCD (Iterative): %d\n", gcdIter1);
    printf("GCD (Recursive): %d\n\n", gcdRec1);
    
    // Test Case 2
    int a2 = 100, b2 = 25;
    int gcdIter2 = gcdIterative(a2, b2);
    int gcdRec2 = gcdRecursive(a2, b2);
    printf("Numbers: %d, %d\n", a2, b2);
    printf("GCD (Iterative): %d\n", gcdIter2);
    printf("GCD (Recursive): %d\n\n", gcdRec2);
    
    // Test Case 3 - Coprime numbers
    int a3 = 17, b3 = 13;
    int gcdIter3 = gcdIterative(a3, b3);
    int gcdRec3 = gcdRecursive(a3, b3);
    printf("Numbers: %d, %d\n", a3, b3);
    printf("GCD (Iterative): %d\n", gcdIter3);
    printf("GCD (Recursive): %d\n\n", gcdRec3);
    
    // Test Case 4 - Same numbers
    int a4 = 15, b4 = 15;
    int gcdIter4 = gcdIterative(a4, b4);
    int gcdRec4 = gcdRecursive(a4, b4);
    printf("Numbers: %d, %d\n", a4, b4);
    printf("GCD (Iterative): %d\n", gcdIter4);
    printf("GCD (Recursive): %d\n\n", gcdRec4);
    
    // Test Case 5 - One is zero
    int a5 = 0, b5 = 15;
    int gcdIter5 = gcdIterative(a5, b5);
    int gcdRec5 = gcdRecursive(a5, b5);
    printf("Numbers: %d, %d\n", a5, b5);
    printf("GCD (Iterative): %d\n", gcdIter5);
    printf("GCD (Recursive): %d\n\n", gcdRec5);
    
    // Test Case 6 - Large numbers
    int a6 = 252, b6 = 105;
    int gcdIter6 = gcdIterative(a6, b6);
    int gcdRec6 = gcdRecursive(a6, b6);
    printf("Numbers: %d, %d\n", a6, b6);
    printf("GCD (Iterative): %d\n", gcdIter6);
    printf("GCD (Recursive): %d\n\n", gcdRec6);
    
    printf("============================================================\n");
    printf("Problem 2: Check if a Number is Perfect Square\n");
    printf("============================================================\n");
    
    // Test Case 1 - Perfect square
    int num1 = 25;
    bool result1 = isPerfectSquare(num1);
    bool result1b = isPerfectSquareNoLibrary(num1);
    printf("Number: %d\n", num1);
    printf("Is Perfect Square (with sqrt): %s\n", result1 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result1b ? "true" : "false");
    
    // Test Case 2 - Not a perfect square
    int num2 = 26;
    bool result2 = isPerfectSquare(num2);
    bool result2b = isPerfectSquareNoLibrary(num2);
    printf("Number: %d\n", num2);
    printf("Is Perfect Square (with sqrt): %s\n", result2 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result2b ? "true" : "false");
    
    // Test Case 3 - Zero
    int num3 = 0;
    bool result3 = isPerfectSquare(num3);
    bool result3b = isPerfectSquareNoLibrary(num3);
    printf("Number: %d\n", num3);
    printf("Is Perfect Square (with sqrt): %s\n", result3 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result3b ? "true" : "false");
    
    // Test Case 4 - One
    int num4 = 1;
    bool result4 = isPerfectSquare(num4);
    bool result4b = isPerfectSquareNoLibrary(num4);
    printf("Number: %d\n", num4);
    printf("Is Perfect Square (with sqrt): %s\n", result4 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result4b ? "true" : "false");
    
    // Test Case 5 - Large perfect square
    int num5 = 144;
    bool result5 = isPerfectSquare(num5);
    bool result5b = isPerfectSquareNoLibrary(num5);
    printf("Number: %d\n", num5);
    printf("Is Perfect Square (with sqrt): %s\n", result5 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result5b ? "true" : "false");
    
    // Test Case 6 - Negative number
    int num6 = -16;
    bool result6 = isPerfectSquare(num6);
    bool result6b = isPerfectSquareNoLibrary(num6);
    printf("Number: %d\n", num6);
    printf("Is Perfect Square (with sqrt): %s\n", result6 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result6b ? "true" : "false");
    
    // Test Case 7 - Not perfect square
    int num7 = 50;
    bool result7 = isPerfectSquare(num7);
    bool result7b = isPerfectSquareNoLibrary(num7);
    printf("Number: %d\n", num7);
    printf("Is Perfect Square (with sqrt): %s\n", result7 ? "true" : "false");
    printf("Is Perfect Square (binary search): %s\n\n", result7b ? "true" : "false");
    
    return 0;
}
