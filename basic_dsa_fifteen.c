#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if Number is Positive, Negative, or Zero
// Determine whether a number is positive, negative, or zero

/**
 * Check if number is positive, negative, or zero
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
const char* checkNumberSign(int n) {
    if (n > 0) {
        return "Positive";
    } else if (n < 0) {
        return "Negative";
    } else {
        return "Zero";
    }
}

// Problem 2: Print Multiplication Table
// Print multiplication table for a given number

/**
 * Print multiplication table for a number
 * Time Complexity: O(limit)
 * Space Complexity: O(1)
 */
void printMultiplicationTable(int n, int limit) {
    printf("Multiplication table of %d:\n", n);
    for (int i = 1; i <= limit; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

/**
 * Store multiplication table in array
 * Time Complexity: O(limit)
 * Space Complexity: O(limit)
 */
void getMultiplicationTable(int n, int limit, int* table) {
    for (int i = 1; i <= limit; i++) {
        table[i - 1] = n * i;
    }
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if Number is Positive, Negative, or Zero\n");
    printf("============================================================\n");
    
    // Test Case 1 - Positive number
    int num1 = 15;
    printf("Number: %d\n", num1);
    printf("Sign: %s\n\n", checkNumberSign(num1));
    
    // Test Case 2 - Negative number
    int num2 = -10;
    printf("Number: %d\n", num2);
    printf("Sign: %s\n\n", checkNumberSign(num2));
    
    // Test Case 3 - Zero
    int num3 = 0;
    printf("Number: %d\n", num3);
    printf("Sign: %s\n\n", checkNumberSign(num3));
    
    // Test Case 4 - Large positive
    int num4 = 1000;
    printf("Number: %d\n", num4);
    printf("Sign: %s\n\n", checkNumberSign(num4));
    
    // Test Case 5 - Large negative
    int num5 = -500;
    printf("Number: %d\n", num5);
    printf("Sign: %s\n\n", checkNumberSign(num5));
    
    printf("============================================================\n");
    printf("Problem 2: Print Multiplication Table\n");
    printf("============================================================\n");
    
    // Test Case 1
    int num6 = 5;
    printMultiplicationTable(num6, 10);
    
    // Test Case 2
    printf("\n");
    int num7 = 7;
    printMultiplicationTable(num7, 12);
    
    // Test Case 3 - Zero
    printf("\n");
    int num8 = 0;
    printMultiplicationTable(num8, 5);
    
    // Test Case 4 - Negative number
    printf("\n");
    int num9 = -3;
    printMultiplicationTable(num9, 5);
    
    // Test Case 5 - Custom limit
    printf("\n");
    int num10 = 9;
    printMultiplicationTable(num10, 5);
    
    // Test Case 6 - Using array storage
    printf("\n");
    int num11 = 4;
    int limit = 10;
    int* table = (int*)malloc(limit * sizeof(int));
    getMultiplicationTable(num11, limit, table);
    printf("Multiplication table of %d (stored in array):\n", num11);
    for (int i = 0; i < limit; i++) {
        printf("%d x %d = %d\n", num11, i + 1, table[i]);
    }
    free(table);
    
    return 0;
}
