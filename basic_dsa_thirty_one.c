#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Perfect Cube
// A perfect cube is a number that can be expressed as the cube of an integer
// Example: 8 = 2³, 27 = 3³, 64 = 4³

/**
 * Check if a number is perfect cube using math library
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool isPerfectCubeMath(int n) {
    int num = n < 0 ? -n : n;
    int cubeRoot = (int) round(cbrt(num));
    return cubeRoot * cubeRoot * cubeRoot == num;
}

/**
 * Check if a number is perfect cube using binary search
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isPerfectCubeBinarySearch(int n) {
    int num = n < 0 ? -n : n;
    if (num == 0 || num == 1) {
        return true;
    }
    
    long long left = 1, right = num;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cube = mid * mid * mid;
        
        if (cube == num) {
            return true;
        } else if (cube < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

/**
 * Get the cube root if number is perfect cube
 * Returns cube root if perfect cube, -1 otherwise
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
long long getCubeRoot(int n) {
    int num = n < 0 ? -n : n;
    bool isNegative = n < 0;
    
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return isNegative ? -1 : 1;
    }
    
    long long left = 1, right = num;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cube = mid * mid * mid;
        
        if (cube == num) {
            return isNegative ? -mid : mid;
        } else if (cube < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Not a perfect cube
}

/**
 * Find all perfect cubes in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of perfect cubes
 */
int getPerfectCubesInRange(int start, int end, int* perfectCubes, int maxSize) {
    if (perfectCubes == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isPerfectCubeBinarySearch(num)) {
            perfectCubes[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Find Sum of First N Even Numbers
// Sum of first n even numbers = n(n+1)
// Example: 2 + 4 + 6 + 8 = 20 = 4 × 5

/**
 * Find sum of first n even numbers using iteration
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long sumOfEvenNumbersIterative(int n) {
    if (n <= 0) {
        return 0;
    }
    
    long long total = 0;
    int even = 2;
    
    for (int i = 0; i < n; i++) {
        total += even;
        even += 2;
    }
    
    return total;
}

/**
 * Find sum of first n even numbers using formula
 * Sum = n(n+1)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long sumOfEvenNumbersFormula(int n) {
    if (n <= 0) {
        return 0;
    }
    return (long long) n * (n + 1);
}

/**
 * Find sum of first n even numbers using recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long sumOfEvenNumbersRecursive(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }
    
    // nth even number = 2n
    int nthEven = 2 * n;
    return nthEven + sumOfEvenNumbersRecursive(n - 1);
}

/**
 * Get list of first n even numbers
 * Stores results in array and returns count
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int getFirstNEvenNumbers(int n, int* evenNumbers, int maxSize) {
    if (n <= 0 || evenNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    int even = 2;
    
    for (int i = 0; i < n && count < maxSize; i++) {
        evenNumbers[count++] = even;
        even += 2;
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Perfect Cube\n");
    printf("============================================================\n");
    
    // Test Case 1 - Perfect cube 8
    int num1 = 8;
    bool result1_math = isPerfectCubeMath(num1);
    bool result1_bs = isPerfectCubeBinarySearch(num1);
    long long cubeRoot1 = getCubeRoot(num1);
    printf("Number: %d\n", num1);
    printf("Is perfect cube (math): %s\n", result1_math ? "true" : "false");
    printf("Is perfect cube (binary search): %s\n", result1_bs ? "true" : "false");
    if (cubeRoot1 != -1) {
        printf("Cube root: %lld\n\n", cubeRoot1);
    }
    
    // Test Case 2 - Perfect cube 27
    int num2 = 27;
    bool result2 = isPerfectCubeBinarySearch(num2);
    long long cubeRoot2 = getCubeRoot(num2);
    printf("Number: %d\n", num2);
    printf("Is perfect cube: %s\n", result2 ? "true" : "false");
    if (cubeRoot2 != -1) {
        printf("Cube root: %lld\n\n", cubeRoot2);
    }
    
    // Test Case 3 - Not perfect cube
    int num3 = 25;
    bool result3 = isPerfectCubeBinarySearch(num3);
    long long cubeRoot3 = getCubeRoot(num3);
    printf("Number: %d\n", num3);
    printf("Is perfect cube: %s\n", result3 ? "true" : "false");
    if (cubeRoot3 == -1) {
        printf("Not a perfect cube\n\n");
    }
    
    // Test Case 4 - Perfect cube 1
    int num4 = 1;
    bool result4 = isPerfectCubeBinarySearch(num4);
    long long cubeRoot4 = getCubeRoot(num4);
    printf("Number: %d\n", num4);
    printf("Is perfect cube: %s\n", result4 ? "true" : "false");
    if (cubeRoot4 != -1) {
        printf("Cube root: %lld\n\n", cubeRoot4);
    }
    
    // Test Case 5 - Find perfect cubes in range
    int start = 1;
    int end = 100;
    int perfectCubes[20];
    int count = getPerfectCubesInRange(start, end, perfectCubes, 20);
    printf("Perfect cubes in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", perfectCubes[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Find Sum of First N Even Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1 - Sum of first 4 even numbers
    int n1 = 4;
    long long result1_iter = sumOfEvenNumbersIterative(n1);
    long long result1_formula = sumOfEvenNumbersFormula(n1);
    long long result1_rec = sumOfEvenNumbersRecursive(n1);
    int evenNums1[20];
    int count_even1 = getFirstNEvenNumbers(n1, evenNums1, 20);
    printf("n = %d\n", n1);
    printf("First %d even numbers: ", n1);
    for (int i = 0; i < count_even1; i++) {
        printf("%d ", evenNums1[i]);
    }
    printf("\nSum (iterative): %lld\n", result1_iter);
    printf("Sum (formula): %lld\n", result1_formula);
    printf("Sum (recursive): %lld\n", result1_rec);
    printf("Verification: %d × (%d + 1) = %d\n\n", n1, n1, n1 * (n1 + 1));
    
    // Test Case 2 - Sum of first 10 even numbers
    int n2 = 10;
    long long result2_sum = sumOfEvenNumbersFormula(n2);
    int evenNums2[20];
    int count_even2 = getFirstNEvenNumbers(n2, evenNums2, 20);
    printf("n = %d\n", n2);
    printf("First %d even numbers: ", n2);
    for (int i = 0; i < count_even2; i++) {
        printf("%d ", evenNums2[i]);
    }
    printf("\nSum: %lld\n", result2_sum);
    printf("Verification: %d × (%d + 1) = %d\n\n", n2, n2, n2 * (n2 + 1));
    
    // Test Case 3 - Sum of first 1 even number
    int n3 = 1;
    long long result3_sum = sumOfEvenNumbersFormula(n3);
    printf("n = %d\n", n3);
    printf("Sum: %lld\n\n", result3_sum);
    
    // Test Case 4 - Sum of first 5 even numbers
    int n4 = 5;
    long long result4_sum = sumOfEvenNumbersFormula(n4);
    int evenNums4[20];
    int count_even4 = getFirstNEvenNumbers(n4, evenNums4, 20);
    printf("n = %d\n", n4);
    printf("First %d even numbers: ", n4);
    for (int i = 0; i < count_even4; i++) {
        printf("%d ", evenNums4[i]);
    }
    printf("\nSum: %lld\n\n", result4_sum);
    
    // Test Case 5 - Large n
    int n5 = 20;
    long long result5_sum = sumOfEvenNumbersFormula(n5);
    printf("n = %d\n", n5);
    printf("Sum of first %d even numbers: %lld\n", n5, result5_sum);
    printf("Verification: %d × (%d + 1) = %lld\n", n5, n5, (long long) n5 * (n5 + 1));
    
    return 0;
}
