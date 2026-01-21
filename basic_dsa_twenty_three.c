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

// Problem 1: Check if a Number is Spy Number
// A Spy number is a number where the sum of its digits equals the product of its digits
// Example: 1124 = 1+1+2+4 = 8 and 1*1*2*4 = 8, so 1124 is a Spy number

/**
 * Calculate sum of digits of a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int sumOfDigits(int n) {
    int total = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        total += num % 10;
        num /= 10;
    }
    
    return total;
}

/**
 * Calculate product of digits of a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int productOfDigits(int n) {
    int product = 1;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        int digit = num % 10;
        product *= digit;
        num /= 10;
    }
    
    return product;
}

/**
 * Check if a number is Spy number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isSpyNumber(int n) {
    if (n <= 0) {
        return false;
    }
    
    return sumOfDigits(n) == productOfDigits(n);
}

/**
 * Find all Spy numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Spy numbers
 */
int getSpyNumbersInRange(int start, int end, int* spyNumbers, int maxSize) {
    if (spyNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isSpyNumber(num)) {
            spyNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Convert Hexadecimal to Decimal
// Convert a hexadecimal (base 16) number to its decimal representation

/**
 * Convert hexadecimal string to decimal using iteration
 * Time Complexity: O(n) where n is length of hex string
 * Space Complexity: O(1)
 */
int hexadecimalToDecimalIterative(const char* hexStr) {
    if (hexStr == NULL || strlen(hexStr) == 0 || strcmp(hexStr, "0") == 0) {
        return 0;
    }
    
    const char* hexDigits = "0123456789ABCDEF";
    bool isNegative = hexStr[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(hexStr);
    
    int decimal = 0;
    int power = 0;
    
    // Process from right to left
    for (int i = len - 1; i >= start; i--) {
        char ch = toupper(hexStr[i]);
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

/**
 * Helper function for recursive hex conversion
 */
int hexadecimalToDecimalRecursiveHelper(const char* hex, int index, int power) {
    const char* hexDigits = "0123456789ABCDEF";
    if (index < 0) {
        return 0;
    }
    char ch = toupper(hex[index]);
    const char* pos = strchr(hexDigits, ch);
    if (pos == NULL) {
        printf("Error: Invalid hexadecimal digit: %c\n", ch);
        return -1;
    }
    int digitValue = pos - hexDigits;
    return digitValue * (int) pow(16, power) + hexadecimalToDecimalRecursiveHelper(hex, index - 1, power + 1);
}

/**
 * Convert hexadecimal string to decimal using recursion
 * Time Complexity: O(n) where n is length of hex string
 * Space Complexity: O(n) due to recursion stack
 */
int hexadecimalToDecimalRecursive(const char* hexStr) {
    if (hexStr == NULL || strlen(hexStr) == 0 || strcmp(hexStr, "0") == 0) {
        return 0;
    }
    
    bool isNegative = hexStr[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(hexStr);
    
    int result = hexadecimalToDecimalRecursiveHelper(hexStr + start, len - start - 1, 0);
    return isNegative ? -result : result;
}

/**
 * Convert hexadecimal array (array of characters) to decimal
 * Time Complexity: O(n) where n is length of array
 * Space Complexity: O(1)
 */
int hexadecimalArrayToDecimal(char* hexArray, int length) {
    if (hexArray == NULL || length == 0) {
        return 0;
    }
    
    const char* hexDigits = "0123456789ABCDEF";
    int decimal = 0;
    int power = length - 1;
    
    for (int i = 0; i < length; i++) {
        char ch = toupper(hexArray[i]);
        const char* pos = strchr(hexDigits, ch);
        if (pos == NULL) {
            printf("Error: Invalid hexadecimal digit: %c\n", ch);
            return -1;
        }
        int digitValue = pos - hexDigits;
        decimal += digitValue * (int) pow(16, power);
        power--;
    }
    
    return decimal;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Spy Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Spy number 1124
    int num1 = 1124;
    bool result1 = isSpyNumber(num1);
    int sum1 = sumOfDigits(num1);
    int product1 = productOfDigits(num1);
    printf("Number: %d\n", num1);
    printf("Sum of digits: %d\n", sum1);
    printf("Product of digits: %d\n", product1);
    printf("Is Spy number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Spy number 22
    int num2 = 22;
    bool result2 = isSpyNumber(num2);
    int sum2 = sumOfDigits(num2);
    int product2 = productOfDigits(num2);
    printf("Number: %d\n", num2);
    printf("Sum of digits: %d\n", sum2);
    printf("Product of digits: %d\n", product2);
    printf("Is Spy number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Spy number
    int num3 = 123;
    bool result3 = isSpyNumber(num3);
    int sum3 = sumOfDigits(num3);
    int product3 = productOfDigits(num3);
    printf("Number: %d\n", num3);
    printf("Sum of digits: %d\n", sum3);
    printf("Product of digits: %d\n", product3);
    printf("Is Spy number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Single digit (always Spy)
    int num4 = 1;
    bool result4 = isSpyNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Spy number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Spy numbers in range
    int start = 1;
    int end = 2000;
    int spyNums[1000];
    int count = getSpyNumbersInRange(start, end, spyNums, 1000);
    printf("Spy numbers in range [%d, %d] (first 20):\n", start, end);
    for (int i = 0; i < (count < 20 ? count : 20); i++) {
        printf("%d ", spyNums[i]);
    }
    printf("\nTotal count: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Convert Hexadecimal to Decimal\n");
    printf("============================================================\n");
    
    // Test Case 1 - Basic hexadecimal
    const char* hex1 = "FF";
    int result1_dec = hexadecimalToDecimalIterative(hex1);
    int result1_rec = hexadecimalToDecimalRecursive(hex1);
    printf("Hexadecimal: %s\n", hex1);
    printf("Decimal (iterative): %d\n", result1_dec);
    printf("Decimal (recursive): %d\n\n", result1_rec);
    
    // Test Case 2 - Zero
    const char* hex2 = "0";
    int result2_dec = hexadecimalToDecimalIterative(hex2);
    printf("Hexadecimal: %s\n", hex2);
    printf("Decimal: %d\n\n", result2_dec);
    
    // Test Case 3 - Large hexadecimal
    const char* hex3 = "ABCD";
    int result3_dec = hexadecimalToDecimalIterative(hex3);
    printf("Hexadecimal: %s\n", hex3);
    printf("Decimal: %d\n\n", result3_dec);
    
    // Test Case 4 - Hexadecimal array
    char hex4[] = {'1', 'A', 'F', '\0'};
    int result4_dec = hexadecimalArrayToDecimal(hex4, 3);
    printf("Hexadecimal (array): %s\n", hex4);
    printf("Decimal: %d\n\n", result4_dec);
    
    // Test Case 5 - Lowercase hexadecimal
    const char* hex5 = "abc";
    int result5_dec = hexadecimalToDecimalIterative(hex5);
    printf("Hexadecimal: %s\n", hex5);
    printf("Decimal: %d\n\n", result5_dec);
    
    return 0;
}
