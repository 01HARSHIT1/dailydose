#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Automorphic
// An automorphic number is a number whose square ends with the number itself
// Example: 5² = 25 (ends with 5), 6² = 36 (ends with 6), 25² = 625 (ends with 25)

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
 * Check if a number is automorphic number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isAutomorphicNumber(int n) {
    if (n < 0) {
        return false;
    }
    
    long long square = (long long) n * n;
    int numDigits = countDigits(n);
    
    // Extract last numDigits from square
    long long divisor = (long long) pow(10, numDigits);
    long long lastDigits = square % divisor;
    
    return lastDigits == n;
}

/**
 * Find all automorphic numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of automorphic numbers
 */
int getAutomorphicNumbersInRange(int start, int end, int* automorphicNumbers, int maxSize) {
    if (automorphicNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isAutomorphicNumber(num)) {
            automorphicNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Convert Decimal to Hexadecimal
// Convert a decimal number to its hexadecimal (base 16) representation

/**
 * Convert decimal to hexadecimal using iteration
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
void decimalToHexadecimalIterative(int n, char* hexadecimal) {
    if (n == 0) {
        strcpy(hexadecimal, "0");
        return;
    }
    
    const char* hexDigits = "0123456789ABCDEF";
    char temp[33]; // Max 32 bits + null terminator
    int temp_index = 0;
    
    // Handle negative sign
    if (n < 0) {
        temp[temp_index++] = '-';
    }
    
    int num = n < 0 ? -n : n;
    while (num > 0) {
        temp[temp_index++] = hexDigits[num % 16];
        num /= 16;
    }
    
    // Reverse the hex digits (excluding negative sign if present)
    int start = (n < 0) ? 1 : 0;
    int index = 0;
    if (n < 0) {
        hexadecimal[index++] = '-';
    }
    for (int i = temp_index - 1; i >= start; i--) {
        hexadecimal[index++] = temp[i];
    }
    hexadecimal[index] = '\0';
}

/**
 * Helper function for recursive hex conversion
 */
void decimalToHexadecimalRecursiveHelper(int n, char* hexadecimal, int* index) {
    const char* hexDigits = "0123456789ABCDEF";
    if (n == 0) {
        return;
    }
    decimalToHexadecimalRecursiveHelper(n / 16, hexadecimal, index);
    hexadecimal[(*index)++] = hexDigits[n % 16];
}

/**
 * Convert decimal to hexadecimal using recursion
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */
void decimalToHexadecimalRecursive(int n, char* hexadecimal) {
    const char* hexDigits = "0123456789ABCDEF";
    
    if (n == 0) {
        strcpy(hexadecimal, "0");
        return;
    }
    
    if (n < 0) {
        hexadecimal[0] = '-';
        int index = 1;
        decimalToHexadecimalRecursiveHelper(-n, hexadecimal, &index);
        hexadecimal[index] = '\0';
    } else {
        int index = 0;
        decimalToHexadecimalRecursiveHelper(n, hexadecimal, &index);
        hexadecimal[index] = '\0';
    }
}

/**
 * Convert hexadecimal string back to decimal (helper function)
 * Time Complexity: O(n) where n is length of hex string
 * Space Complexity: O(1)
 */
int hexadecimalToDecimal(const char* hex_str) {
    if (hex_str == NULL || strlen(hex_str) == 0 || strcmp(hex_str, "0") == 0) {
        return 0;
    }
    
    bool isNegative = hex_str[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(hex_str);
    
    int decimal = 0;
    int power = 0;
    const char* hexDigits = "0123456789ABCDEF";
    
    // Process from right to left
    for (int i = len - 1; i >= start; i--) {
        char ch = toupper(hex_str[i]);
        const char* pos = strchr(hexDigits, ch);
        if (pos == NULL) {
            printf("Error: Invalid hexadecimal digit: %c\n", ch);
            return -1;
        }
        int digitValue = pos - hexDigits;
        decimal += digitValue * (int) pow(16, power);
        power++;
    }
    
    return isNegative ? -decimal : decimal;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Automorphic\n");
    printf("============================================================\n");
    
    // Test Case 1 - Automorphic number 5
    int num1 = 5;
    bool result1 = isAutomorphicNumber(num1);
    long long square1 = (long long) num1 * num1;
    printf("Number: %d\n", num1);
    printf("Square: %lld\n", square1);
    printf("Is automorphic: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Automorphic number 6
    int num2 = 6;
    bool result2 = isAutomorphicNumber(num2);
    long long square2 = (long long) num2 * num2;
    printf("Number: %d\n", num2);
    printf("Square: %lld\n", square2);
    printf("Is automorphic: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Automorphic number 25
    int num3 = 25;
    bool result3 = isAutomorphicNumber(num3);
    long long square3 = (long long) num3 * num3;
    printf("Number: %d\n", num3);
    printf("Square: %lld\n", square3);
    printf("Is automorphic: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not automorphic number
    int num4 = 7;
    bool result4 = isAutomorphicNumber(num4);
    long long square4 = (long long) num4 * num4;
    printf("Number: %d\n", num4);
    printf("Square: %lld\n", square4);
    printf("Is automorphic: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find automorphic numbers in range
    int start = 1;
    int end = 100;
    int automorphicNums[100];
    int count = getAutomorphicNumbersInRange(start, end, automorphicNums, 100);
    printf("Automorphic numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", automorphicNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Convert Decimal to Hexadecimal\n");
    printf("============================================================\n");
    
    char hexadecimal[34]; // Max 32 bits + sign + null terminator
    
    // Test Case 1 - Positive number
    int num1_dec = 255;
    decimalToHexadecimalIterative(num1_dec, hexadecimal);
    printf("Decimal: %d\n", num1_dec);
    printf("Hexadecimal (iterative): %s\n", hexadecimal);
    
    decimalToHexadecimalRecursive(num1_dec, hexadecimal);
    printf("Hexadecimal (recursive): %s\n", hexadecimal);
    printf("Verification (hex to decimal): %d\n\n", hexadecimalToDecimal(hexadecimal));
    
    // Test Case 2 - Zero
    int num2_dec = 0;
    decimalToHexadecimalIterative(num2_dec, hexadecimal);
    printf("Decimal: %d\n", num2_dec);
    printf("Hexadecimal: %s\n\n", hexadecimal);
    
    // Test Case 3 - Large number
    int num3_dec = 4095;
    decimalToHexadecimalIterative(num3_dec, hexadecimal);
    printf("Decimal: %d\n", num3_dec);
    printf("Hexadecimal: %s\n", hexadecimal);
    printf("Verification: %d\n\n", hexadecimalToDecimal(hexadecimal));
    
    // Test Case 4 - Number with letters
    int num4_dec = 10;
    decimalToHexadecimalIterative(num4_dec, hexadecimal);
    printf("Decimal: %d\n", num4_dec);
    printf("Hexadecimal: %s\n\n", hexadecimal);
    
    // Test Case 5 - Negative number
    int num5_dec = -256;
    decimalToHexadecimalIterative(num5_dec, hexadecimal);
    printf("Decimal: %d\n", num5_dec);
    printf("Hexadecimal: %s\n", hexadecimal);
    printf("Verification: %d\n\n", hexadecimalToDecimal(hexadecimal));
    
    return 0;
}
