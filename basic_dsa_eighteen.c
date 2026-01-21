#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Strong Number
// A strong number is a number whose sum of factorial of digits equals the number itself
// Example: 145 = 1! + 4! + 5! = 1 + 24 + 120 = 145

/**
 * Calculate factorial of a number
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Check if a number is strong number
 * Time Complexity: O(d * k) where d is number of digits, k is average digit value
 * Space Complexity: O(1)
 */
bool isStrongNumber(int n) {
    if (n <= 0) {
        return false;
    }
    
    int original = n;
    long long sumFactorial = 0;
    
    while (n > 0) {
        int digit = n % 10;
        sumFactorial += factorial(digit);
        n /= 10;
    }
    
    return sumFactorial == original;
}

/**
 * Get sum of factorials of each digit
 * Time Complexity: O(d * k) where d is number of digits
 * Space Complexity: O(1)
 */
long long getSumOfDigitFactorials(int n) {
    if (n <= 0) {
        return 0;
    }
    
    long long sum = 0;
    int temp = n;
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }
    
    return sum;
}

// Problem 2: Convert Binary to Decimal
// Convert a binary number to its decimal representation

/**
 * Convert binary string to decimal using iteration
 * Time Complexity: O(n) where n is length of binary string
 * Space Complexity: O(1)
 */
int binaryToDecimalIterative(const char* binaryStr) {
    if (binaryStr == NULL || strlen(binaryStr) == 0 || strcmp(binaryStr, "0") == 0) {
        return 0;
    }
    
    bool isNegative = binaryStr[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(binaryStr);
    
    int decimal = 0;
    int power = 0;
    
    // Process from right to left (least significant bit to most)
    for (int i = len - 1; i >= start; i--) {
        if (binaryStr[i] == '1') {
            decimal += (int) pow(2, power);
        } else if (binaryStr[i] != '0') {
            printf("Error: Invalid binary digit: %c\n", binaryStr[i]);
            return -1;
        }
        power++;
    }
    
    return isNegative ? -decimal : decimal;
}

/**
 * Helper function for recursive binary conversion
 */
int binaryToDecimalRecursiveHelper(const char* binary, int index, int power) {
    if (index < 0) {
        return 0;
    }
    if (binary[index] == '1') {
        return (int) pow(2, power) + binaryToDecimalRecursiveHelper(binary, index - 1, power + 1);
    } else if (binary[index] == '0') {
        return binaryToDecimalRecursiveHelper(binary, index - 1, power + 1);
    } else {
        printf("Error: Invalid binary digit: %c\n", binary[index]);
        return -1;
    }
}

/**
 * Convert binary string to decimal using recursion
 * Time Complexity: O(n) where n is length of binary string
 * Space Complexity: O(n) due to recursion stack
 */
int binaryToDecimalRecursive(const char* binaryStr) {
    if (binaryStr == NULL || strlen(binaryStr) == 0 || strcmp(binaryStr, "0") == 0) {
        return 0;
    }
    
    bool isNegative = binaryStr[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(binaryStr);
    
    int result = binaryToDecimalRecursiveHelper(binaryStr + start, len - start - 1, 0);
    return isNegative ? -result : result;
}

/**
 * Convert binary array to decimal
 * Time Complexity: O(n) where n is length of array
 * Space Complexity: O(1)
 */
int binaryArrayToDecimal(int* binaryArray, int length) {
    if (binaryArray == NULL || length == 0) {
        return 0;
    }
    
    int decimal = 0;
    int power = length - 1;
    
    for (int i = 0; i < length; i++) {
        if (binaryArray[i] != 0 && binaryArray[i] != 1) {
            printf("Error: Invalid binary digit: %d\n", binaryArray[i]);
            return -1;
        }
        decimal += binaryArray[i] * (int) pow(2, power);
        power--;
    }
    
    return decimal;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Strong Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Strong number 145
    int num1 = 145;
    bool result1 = isStrongNumber(num1);
    long long sum1 = getSumOfDigitFactorials(num1);
    printf("Number: %d\n", num1);
    printf("Sum of digit factorials: %lld\n", sum1);
    printf("Is strong number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Not strong number
    int num2 = 123;
    bool result2 = isStrongNumber(num2);
    long long sum2 = getSumOfDigitFactorials(num2);
    printf("Number: %d\n", num2);
    printf("Sum of digit factorials: %lld\n", sum2);
    printf("Is strong number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Strong number 1
    int num3 = 1;
    bool result3 = isStrongNumber(num3);
    printf("Number: %d\n", num3);
    printf("Is strong number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Strong number 2
    int num4 = 2;
    bool result4 = isStrongNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is strong number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Not strong number
    int num5 = 10;
    bool result5 = isStrongNumber(num5);
    long long sum5 = getSumOfDigitFactorials(num5);
    printf("Number: %d\n", num5);
    printf("Sum of digit factorials: %lld\n", sum5);
    printf("Is strong number: %s\n\n", result5 ? "true" : "false");
    
    printf("============================================================\n");
    printf("Problem 2: Convert Binary to Decimal\n");
    printf("============================================================\n");
    
    // Test Case 1 - Basic binary
    const char* binary1 = "1010";
    int result1_dec = binaryToDecimalIterative(binary1);
    int result1_rec = binaryToDecimalRecursive(binary1);
    printf("Binary: %s\n", binary1);
    printf("Decimal (iterative): %d\n", result1_dec);
    printf("Decimal (recursive): %d\n\n", result1_rec);
    
    // Test Case 2 - Zero
    const char* binary2 = "0";
    int result2_dec = binaryToDecimalIterative(binary2);
    printf("Binary: %s\n", binary2);
    printf("Decimal: %d\n\n", result2_dec);
    
    // Test Case 3 - Large binary
    const char* binary3 = "11111111";
    int result3_dec = binaryToDecimalIterative(binary3);
    printf("Binary: %s\n", binary3);
    printf("Decimal: %d\n\n", result3_dec);
    
    // Test Case 4 - Binary array
    int binary4[] = {1, 0, 1, 1, 0, 1};
    int length4 = sizeof(binary4) / sizeof(binary4[0]);
    int result4_dec = binaryArrayToDecimal(binary4, length4);
    printf("Binary (array): ");
    for (int i = 0; i < length4; i++) {
        printf("%d", binary4[i]);
    }
    printf("\nDecimal: %d\n\n", result4_dec);
    
    // Test Case 5 - Single bit
    const char* binary5 = "1";
    int result5_dec = binaryToDecimalIterative(binary5);
    printf("Binary: %s\n", binary5);
    printf("Decimal: %d\n\n", result5_dec);
    
    return 0;
}
