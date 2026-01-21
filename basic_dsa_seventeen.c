#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Convert Decimal to Binary
// Convert a decimal number to its binary representation

/**
 * Convert decimal to binary using iteration
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
void decimalToBinaryIterative(int n, char* binary) {
    if (n == 0) {
        strcpy(binary, "0");
        return;
    }
    
    int num = n < 0 ? -n : n;
    int index = 0;
    char temp[33]; // Max 32 bits for int + null terminator
    int temp_index = 0;
    
    // Handle negative sign
    if (n < 0) {
        temp[temp_index++] = '-';
    }
    
    while (num > 0) {
        temp[temp_index++] = (num % 2) + '0';
        num /= 2;
    }
    
    // Reverse the binary digits (excluding negative sign if present)
    int start = (n < 0) ? 1 : 0;
    if (n < 0) {
        binary[index++] = '-';
    }
    for (int i = temp_index - 1; i >= start; i--) {
        binary[index++] = temp[i];
    }
    binary[index] = '\0';
}

/**
 * Helper function for recursive binary conversion
 */
void decimalToBinaryRecursiveHelper(int n, char* binary, int* index) {
    if (n == 0) {
        return;
    }
    decimalToBinaryRecursiveHelper(n / 2, binary, index);
    binary[(*index)++] = (n % 2) + '0';
}

/**
 * Convert decimal to binary using recursion
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */
void decimalToBinaryRecursive(int n, char* binary) {
    if (n == 0) {
        strcpy(binary, "0");
        return;
    }
    
    if (n < 0) {
        binary[0] = '-';
        int index = 1;
        decimalToBinaryRecursiveHelper(-n, binary, &index);
        binary[index] = '\0';
    } else {
        int index = 0;
        decimalToBinaryRecursiveHelper(n, binary, &index);
        binary[index] = '\0';
    }
}

/**
 * Convert decimal to binary and return as array of digits
 * Returns the length of the binary array
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
int decimalToBinaryArray(int n, int* binary_array) {
    if (n == 0) {
        binary_array[0] = 0;
        return 1;
    }
    
    int num = n < 0 ? -n : n;
    int length = 0;
    int temp[32];
    int temp_index = 0;
    
    while (num > 0) {
        temp[temp_index++] = num % 2;
        num /= 2;
    }
    
    // Reverse to get correct binary representation
    for (int i = temp_index - 1; i >= 0; i--) {
        binary_array[length++] = temp[i];
    }
    
    return length;
}

// Problem 2: Find Sum of Cubes of First N Natural Numbers
// Calculate 1³ + 2³ + 3³ + ... + N³

/**
 * Find sum of cubes using iteration
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long sumOfCubesIterative(int n) {
    if (n <= 0) {
        return 0;
    }
    
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += (long long) i * i * i;
    }
    return total;
}

/**
 * Find sum of cubes using mathematical formula: [n(n+1)/2]²
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long sumOfCubesFormula(int n) {
    if (n <= 0) {
        return 0;
    }
    long long sum = (long long) n * (n + 1) / 2;
    return sum * sum;
}

/**
 * Find sum of cubes using recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
 */
long long sumOfCubesRecursive(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return (long long) n * n * n + sumOfCubesRecursive(n - 1);
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Convert Decimal to Binary\n");
    printf("============================================================\n");
    
    char binary[34]; // Max 32 bits + sign + null terminator
    
    // Test Case 1 - Positive number
    int num1 = 10;
    decimalToBinaryIterative(num1, binary);
    printf("Decimal: %d\n", num1);
    printf("Binary (iterative): %s\n", binary);
    
    decimalToBinaryRecursive(num1, binary);
    printf("Binary (recursive): %s\n", binary);
    
    int binary_array1[32];
    int len1 = decimalToBinaryArray(num1, binary_array1);
    printf("Binary (array): ");
    for (int i = 0; i < len1; i++) {
        printf("%d", binary_array1[i]);
    }
    printf("\n");
    
    // Test Case 2 - Zero
    int num2 = 0;
    decimalToBinaryIterative(num2, binary);
    printf("\nDecimal: %d\n", num2);
    printf("Binary: %s\n", binary);
    
    // Test Case 3 - Negative number
    int num3 = -15;
    decimalToBinaryIterative(num3, binary);
    printf("\nDecimal: %d\n", num3);
    printf("Binary: %s\n", binary);
    
    // Test Case 4 - Large number
    int num4 = 255;
    decimalToBinaryIterative(num4, binary);
    printf("\nDecimal: %d\n", num4);
    printf("Binary: %s\n", binary);
    
    // Test Case 5 - Single digit
    int num5 = 7;
    decimalToBinaryIterative(num5, binary);
    printf("\nDecimal: %d\n", num5);
    printf("Binary: %s\n", binary);
    
    printf("\n============================================================\n");
    printf("Problem 2: Find Sum of Cubes of First N Natural Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1
    int n1 = 5;
    long long result1_iter = sumOfCubesIterative(n1);
    long long result1_formula = sumOfCubesFormula(n1);
    long long result1_rec = sumOfCubesRecursive(n1);
    printf("N = %d\n", n1);
    printf("1³ + 2³ + 3³ + 4³ + 5³ = %lld\n", result1_iter);
    printf("Iterative method: %lld\n", result1_iter);
    printf("Formula method: %lld\n", result1_formula);
    printf("Recursive method: %lld\n\n", result1_rec);
    
    // Test Case 2
    int n2 = 10;
    long long result2 = sumOfCubesFormula(n2);
    printf("N = %d\n", n2);
    printf("Sum of cubes: %lld\n\n", result2);
    
    // Test Case 3
    int n3 = 1;
    long long result3 = sumOfCubesFormula(n3);
    printf("N = %d\n", n3);
    printf("Sum of cubes: %lld\n\n", result3);
    
    // Test Case 4
    int n4 = 7;
    long long result4 = sumOfCubesFormula(n4);
    printf("N = %d\n", n4);
    printf("Sum of cubes: %lld\n\n", result4);
    
    // Test Case 5 - Larger number
    int n5 = 20;
    long long result5 = sumOfCubesFormula(n5);
    printf("N = %d\n", n5);
    printf("Sum of cubes: %lld\n\n", result5);
    
    // Verification: Formula should equal sum of first n natural numbers squared
    long long verification = (long long) n5 * (n5 + 1) / 2;
    verification = verification * verification;
    printf("Verification: (1+2+...+20)² = %lld\n", verification);
    
    return 0;
}
