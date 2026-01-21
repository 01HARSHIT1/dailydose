#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Kaprekar Number
// A Kaprekar number is a number whose square, when split into two parts and added, gives the original number
// Example: 45² = 2025, split as 20 and 25, 20 + 25 = 45

/**
 * Count number of digits in a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }
    int count = 0;
    int num = n < 0 ? -n : n;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

/**
 * Check if a number is Kaprekar number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isKaprekarNumber(int n) {
    if (n <= 0) {
        return false;
    }
    if (n == 1) {
        return true; // 1² = 1, 0 + 1 = 1
    }
    
    long long square = (long long) n * n;
    int numDigits = countDigits((int) square);
    
    // Try splitting at different positions
    for (int splitPos = 1; splitPos < numDigits; splitPos++) {
        long long divisor = (long long) pow(10, splitPos);
        
        // Split the square into two parts
        long long rightPart = square % divisor;
        long long leftPart = square / divisor;
        
        // Check if sum equals original number
        if (leftPart + rightPart == n && rightPart > 0) {
            return true;
        }
    }
    
    return false;
}

/**
 * Get the split of square that makes it Kaprekar number
 * Stores result in split array [left_part, right_part] and returns true if Kaprekar
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool getKaprekarSplit(int n, long long* split) {
    if (n <= 0 || split == NULL) {
        return false;
    }
    if (n == 1) {
        split[0] = 0;
        split[1] = 1;
        return true;
    }
    
    long long square = (long long) n * n;
    int numDigits = countDigits((int) square);
    
    for (int splitPos = 1; splitPos < numDigits; splitPos++) {
        long long divisor = (long long) pow(10, splitPos);
        
        long long rightPart = square % divisor;
        long long leftPart = square / divisor;
        
        if (leftPart + rightPart == n && rightPart > 0) {
            split[0] = leftPart;
            split[1] = rightPart;
            return true;
        }
    }
    
    return false;
}

/**
 * Find all Kaprekar numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Kaprekar numbers
 */
int getKaprekarNumbersInRange(int start, int end, int* kaprekarNumbers, int maxSize) {
    if (kaprekarNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isKaprekarNumber(num)) {
            kaprekarNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Find nth Triangular Number
// A triangular number is the number of dots that can be arranged in an equilateral triangle
// Formula: T(n) = n(n+1)/2
// Example: T(4) = 1 + 2 + 3 + 4 = 10

/**
 * Find nth triangular number using formula
 * T(n) = n(n+1)/2
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long nthTriangularNumberFormula(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    return (long long) n * (n + 1) / 2;
}

/**
 * Find nth triangular number using iteration
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long nthTriangularNumberIterative(int n) {
    if (n < 0) {
        printf("Error: n must be non-negative\n");
        return -1;
    }
    
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

/**
 * Find nth triangular number using recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long nthTriangularNumberRecursive(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    return n + nthTriangularNumberRecursive(n - 1);
}

/**
 * Find all triangular numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O(end - start)
 * Space Complexity: O(k) where k is the number of triangular numbers
 */
int getTriangularNumbersInRange(int start, int end, int* triangularNumbers, int maxSize) {
    if (triangularNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        // Check if number is triangular by solving n(n+1)/2 = num
        // This gives us a quadratic equation: n² + n - 2*num = 0
        // n = (-1 + sqrt(1 + 8*num)) / 2
        double discriminant = 1 + 8 * (long long) num;
        if (discriminant >= 0) {
            double n = (-1 + sqrt(discriminant)) / 2;
            if (n >= 0 && fabs(n - round(n)) < 1e-9) {
                triangularNumbers[count++] = num;
            }
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Kaprekar Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Kaprekar number 9
    int num1 = 9;
    bool result1 = isKaprekarNumber(num1);
    long long split1[2];
    bool hasSplit1 = getKaprekarSplit(num1, split1);
    long long square1 = (long long) num1 * num1;
    printf("Number: %d\n", num1);
    printf("Square: %lld\n", square1);
    if (hasSplit1) {
        printf("Split: %lld + %lld = %lld\n", split1[0], split1[1], split1[0] + split1[1]);
    }
    printf("Is Kaprekar number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Kaprekar number 45
    int num2 = 45;
    bool result2 = isKaprekarNumber(num2);
    long long split2[2];
    bool hasSplit2 = getKaprekarSplit(num2, split2);
    long long square2 = (long long) num2 * num2;
    printf("Number: %d\n", num2);
    printf("Square: %lld\n", square2);
    if (hasSplit2) {
        printf("Split: %lld + %lld = %lld\n", split2[0], split2[1], split2[0] + split2[1]);
    }
    printf("Is Kaprekar number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Kaprekar number 55
    int num3 = 55;
    bool result3 = isKaprekarNumber(num3);
    long long split3[2];
    bool hasSplit3 = getKaprekarSplit(num3, split3);
    long long square3 = (long long) num3 * num3;
    printf("Number: %d\n", num3);
    printf("Square: %lld\n", square3);
    if (hasSplit3) {
        printf("Split: %lld + %lld = %lld\n", split3[0], split3[1], split3[0] + split3[1]);
    }
    printf("Is Kaprekar number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not Kaprekar number
    int num4 = 10;
    bool result4 = isKaprekarNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Kaprekar number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Kaprekar numbers in range
    int start = 1;
    int end = 100;
    int kaprekarNums[20];
    int count = getKaprekarNumbersInRange(start, end, kaprekarNums, 20);
    printf("Kaprekar numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", kaprekarNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Find nth Triangular Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - 4th triangular number
    int n1 = 4;
    long long result1_tri = nthTriangularNumberFormula(n1);
    long long result1_iter = nthTriangularNumberIterative(n1);
    long long result1_rec = nthTriangularNumberRecursive(n1);
    printf("n = %d\n", n1);
    printf("Triangular number (formula): %lld\n", result1_tri);
    printf("Triangular number (iterative): %lld\n", result1_iter);
    printf("Triangular number (recursive): %lld\n", result1_rec);
    printf("Pattern: 1 + 2 + 3 + 4 = %lld\n\n", result1_tri);
    
    // Test Case 2 - 10th triangular number
    int n2 = 10;
    long long result2_tri = nthTriangularNumberFormula(n2);
    printf("n = %d\n", n2);
    printf("10th triangular number: %lld\n\n", result2_tri);
    
    // Test Case 3 - 0th triangular number
    int n3 = 0;
    long long result3_tri = nthTriangularNumberFormula(n3);
    printf("n = %d\n", n3);
    printf("0th triangular number: %lld\n\n", result3_tri);
    
    // Test Case 4 - Large triangular number
    int n4 = 100;
    long long result4_tri = nthTriangularNumberFormula(n4);
    printf("n = %d\n", n4);
    printf("100th triangular number: %lld\n\n", result4_tri);
    
    // Test Case 5 - Find triangular numbers in range
    int start_tri = 1;
    int end_tri = 50;
    int triangularNums[20];
    int count_tri = getTriangularNumbersInRange(start_tri, end_tri, triangularNums, 20);
    printf("Triangular numbers in range [%d, %d]:\n", start_tri, end_tri);
    for (int i = 0; i < count_tri; i++) {
        printf("%d ", triangularNums[i]);
    }
    printf("\nCount: %d\n", count_tri);
    
    return 0;
}
