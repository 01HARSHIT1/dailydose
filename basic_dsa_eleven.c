#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Swap Two Numbers
// Swap two numbers using different methods

/**
 * Swap two numbers using temporary variable
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapWithTemp(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Swap two numbers without temporary variable (using arithmetic)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapWithoutTempArithmetic(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

/**
 * Swap two numbers without temporary variable (using XOR)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapWithoutTempXOR(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// Problem 2: Find All Factors of a Number
// Find all factors (divisors) of a given number

/**
 * Find all factors of a number (brute force)
 * Time Complexity: O(n)
 * Space Complexity: O(√n)
 */
int* findFactors(int n, int* count) {
    if (n == 0) {
        *count = 0;
        return NULL;
    }
    
    n = abs(n);
    int* factors = (int*)malloc(n * sizeof(int));
    *count = 0;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            factors[*count] = i;
            (*count)++;
        }
    }
    
    return factors;
}

/**
 * Find all factors of a number (optimized - only iterate up to √n)
 * Time Complexity: O(√n)
 * Space Complexity: O(√n)
 */
int* findFactorsOptimized(int n, int* count) {
    if (n == 0) {
        *count = 0;
        return NULL;
    }
    
    n = abs(n);
    int* factors = (int*)malloc((int)sqrt(n) * 2 * sizeof(int));
    *count = 0;
    
    // Iterate only up to √n
    int i = 1;
    while (i * i <= n) {
        if (n % i == 0) {
            factors[*count] = i;
            (*count)++;
            // If i != n/i, then n/i is also a factor
            if (i != n / i) {
                factors[*count] = n / i;
                (*count)++;
            }
        }
        i++;
    }
    
    // Simple bubble sort for factors
    for (int j = 0; j < *count - 1; j++) {
        for (int k = 0; k < *count - j - 1; k++) {
            if (factors[k] > factors[k + 1]) {
                int temp = factors[k];
                factors[k] = factors[k + 1];
                factors[k + 1] = temp;
            }
        }
    }
    
    return factors;
}

/**
 * Count the number of factors of a number
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
int countFactors(int n) {
    if (n == 0) {
        return 0;
    }
    
    n = abs(n);
    int count = 0;
    
    int i = 1;
    while (i * i <= n) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
        i++;
    }
    
    return count;
}

// Helper function to print array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

#include <math.h>

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Swap Two Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1
    int a1 = 10, b1 = 20;
    printf("Before swap: a = %d, b = %d\n", a1, b1);
    swapWithTemp(&a1, &b1);
    printf("After swap (with temp): a = %d, b = %d\n\n", a1, b1);
    
    // Test Case 2 - Without temp (arithmetic)
    int a2 = 15, b2 = 25;
    printf("Before swap: a = %d, b = %d\n", a2, b2);
    swapWithoutTempArithmetic(&a2, &b2);
    printf("After swap (arithmetic): a = %d, b = %d\n\n", a2, b2);
    
    // Test Case 3 - Without temp (XOR)
    int a3 = 7, b3 = 13;
    printf("Before swap: a = %d, b = %d\n", a3, b3);
    swapWithoutTempXOR(&a3, &b3);
    printf("After swap (XOR): a = %d, b = %d\n\n", a3, b3);
    
    // Test Case 4 - Negative numbers
    int a4 = -5, b4 = 10;
    printf("Before swap: a = %d, b = %d\n", a4, b4);
    swapWithoutTempXOR(&a4, &b4);
    printf("After swap (XOR): a = %d, b = %d\n\n", a4, b4);
    
    // Test Case 5 - Same numbers
    int a5 = 42, b5 = 42;
    printf("Before swap: a = %d, b = %d\n", a5, b5);
    swapWithoutTempXOR(&a5, &b5);
    printf("After swap (XOR): a = %d, b = %d\n\n", a5, b5);
    
    printf("============================================================\n");
    printf("Problem 2: Find All Factors of a Number\n");
    printf("============================================================\n");
    
    // Test Case 1
    int num1 = 12;
    int count1, count1Opt;
    int* factors1 = findFactors(num1, &count1);
    int* factorsOpt1 = findFactorsOptimized(num1, &count1Opt);
    int factorCount1 = countFactors(num1);
    printf("Number: %d\n", num1);
    printf("Factors (Brute Force): ");
    printArray(factors1, count1);
    printf("\n");
    printf("Factors (Optimized): ");
    printArray(factorsOpt1, count1Opt);
    printf("\n");
    printf("Number of factors: %d\n\n", factorCount1);
    free(factors1);
    free(factorsOpt1);
    
    // Test Case 2
    int num2 = 24;
    int count2, count2Opt;
    int* factors2 = findFactors(num2, &count2);
    int* factorsOpt2 = findFactorsOptimized(num2, &count2Opt);
    int factorCount2 = countFactors(num2);
    printf("Number: %d\n", num2);
    printf("Factors (Brute Force): ");
    printArray(factors2, count2);
    printf("\n");
    printf("Factors (Optimized): ");
    printArray(factorsOpt2, count2Opt);
    printf("\n");
    printf("Number of factors: %d\n\n", factorCount2);
    free(factors2);
    free(factorsOpt2);
    
    // Test Case 3 - Prime number
    int num3 = 17;
    int count3, count3Opt;
    int* factors3 = findFactors(num3, &count3);
    int* factorsOpt3 = findFactorsOptimized(num3, &count3Opt);
    int factorCount3 = countFactors(num3);
    printf("Number: %d\n", num3);
    printf("Factors (Brute Force): ");
    printArray(factors3, count3);
    printf("\n");
    printf("Factors (Optimized): ");
    printArray(factorsOpt3, count3Opt);
    printf("\n");
    printf("Number of factors: %d\n\n", factorCount3);
    free(factors3);
    free(factorsOpt3);
    
    // Test Case 4 - Perfect square
    int num4 = 16;
    int count4, count4Opt;
    int* factors4 = findFactors(num4, &count4);
    int* factorsOpt4 = findFactorsOptimized(num4, &count4Opt);
    int factorCount4 = countFactors(num4);
    printf("Number: %d\n", num4);
    printf("Factors (Brute Force): ");
    printArray(factors4, count4);
    printf("\n");
    printf("Factors (Optimized): ");
    printArray(factorsOpt4, count4Opt);
    printf("\n");
    printf("Number of factors: %d\n\n", factorCount4);
    free(factors4);
    free(factorsOpt4);
    
    // Test Case 5 - Single factor (1)
    int num5 = 1;
    int count5, count5Opt;
    int* factors5 = findFactors(num5, &count5);
    int* factorsOpt5 = findFactorsOptimized(num5, &count5Opt);
    int factorCount5 = countFactors(num5);
    printf("Number: %d\n", num5);
    printf("Factors (Brute Force): ");
    printArray(factors5, count5);
    printf("\n");
    printf("Factors (Optimized): ");
    printArray(factorsOpt5, count5Opt);
    printf("\n");
    printf("Number of factors: %d\n\n", factorCount5);
    free(factors5);
    free(factorsOpt5);
    
    // Test Case 6 - Large number
    int num6 = 100;
    int count6, count6Opt;
    int* factors6 = findFactors(num6, &count6);
    int* factorsOpt6 = findFactorsOptimized(num6, &count6Opt);
    int factorCount6 = countFactors(num6);
    printf("Number: %d\n", num6);
    printf("Factors (Brute Force): ");
    printArray(factors6, count6);
    printf("\n");
    printf("Factors (Optimized): ");
    printArray(factorsOpt6, count6Opt);
    printf("\n");
    printf("Number of factors: %d\n\n", factorCount6);
    free(factors6);
    free(factorsOpt6);
    
    return 0;
}
