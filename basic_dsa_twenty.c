#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Harshad/Niven Number
// A Harshad number (or Niven number) is a number that is divisible by the sum of its digits
// Example: 18 is Harshad because 1 + 8 = 9, and 18 is divisible by 9

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
 * Check if a number is Harshad/Niven number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isHarshadNumber(int n) {
    if (n <= 0) {
        return false;
    }
    
    int digitSum = sumOfDigits(n);
    return n % digitSum == 0;
}

/**
 * Find all Harshad numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Harshad numbers
 */
int getHarshadNumbersInRange(int start, int end, int* harshadNumbers, int maxSize) {
    if (harshadNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isHarshadNumber(num)) {
            harshadNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Convert Decimal to Octal
// Convert a decimal number to its octal (base 8) representation

/**
 * Convert decimal to octal using iteration
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
void decimalToOctalIterative(int n, char* octal) {
    if (n == 0) {
        strcpy(octal, "0");
        return;
    }
    
    int num = n < 0 ? -n : n;
    char temp[33]; // Max 32 bits + null terminator
    int temp_index = 0;
    
    // Handle negative sign
    if (n < 0) {
        temp[temp_index++] = '-';
    }
    
    while (num > 0) {
        temp[temp_index++] = (num % 8) + '0';
        num /= 8;
    }
    
    // Reverse the octal digits (excluding negative sign if present)
    int start = (n < 0) ? 1 : 0;
    int index = 0;
    if (n < 0) {
        octal[index++] = '-';
    }
    for (int i = temp_index - 1; i >= start; i--) {
        octal[index++] = temp[i];
    }
    octal[index] = '\0';
}

/**
 * Helper function for recursive octal conversion
 */
void decimalToOctalRecursiveHelper(int n, char* octal, int* index) {
    if (n == 0) {
        return;
    }
    decimalToOctalRecursiveHelper(n / 8, octal, index);
    octal[(*index)++] = (n % 8) + '0';
}

/**
 * Convert decimal to octal using recursion
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */
void decimalToOctalRecursive(int n, char* octal) {
    if (n == 0) {
        strcpy(octal, "0");
        return;
    }
    
    if (n < 0) {
        octal[0] = '-';
        int index = 1;
        decimalToOctalRecursiveHelper(-n, octal, &index);
        octal[index] = '\0';
    } else {
        int index = 0;
        decimalToOctalRecursiveHelper(n, octal, &index);
        octal[index] = '\0';
    }
}

/**
 * Convert decimal to octal and return as array of digits
 * Returns the length of the octal array
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
int decimalToOctalArray(int n, int* octal_array) {
    if (n == 0) {
        octal_array[0] = 0;
        return 1;
    }
    
    int num = n < 0 ? -n : n;
    int length = 0;
    int temp[32];
    int temp_index = 0;
    
    while (num > 0) {
        temp[temp_index++] = num % 8;
        num /= 8;
    }
    
    // Reverse to get correct octal representation
    for (int i = temp_index - 1; i >= 0; i--) {
        octal_array[length++] = temp[i];
    }
    
    return length;
}

/**
 * Convert octal string back to decimal (helper function)
 * Time Complexity: O(n) where n is length of octal string
 * Space Complexity: O(1)
 */
int octalToDecimal(const char* octal_str) {
    if (octal_str == NULL || strlen(octal_str) == 0 || strcmp(octal_str, "0") == 0) {
        return 0;
    }
    
    bool isNegative = octal_str[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(octal_str);
    
    int decimal = 0;
    int power = 0;
    
    // Process from right to left
    for (int i = len - 1; i >= start; i--) {
        int digit = octal_str[i] - '0';
        if (digit < 0 || digit > 7) {
            printf("Error: Invalid octal digit: %d\n", digit);
            return -1;
        }
        decimal += digit * (int) pow(8, power);
        power++;
    }
    
    return isNegative ? -decimal : decimal;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Harshad/Niven Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Harshad number 18
    int num1 = 18;
    bool result1 = isHarshadNumber(num1);
    int sum1 = sumOfDigits(num1);
    printf("Number: %d\n", num1);
    printf("Sum of digits: %d\n", sum1);
    printf("%d ÷ %d = %d\n", num1, sum1, num1 / sum1);
    printf("Is Harshad number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Harshad number 12
    int num2 = 12;
    bool result2 = isHarshadNumber(num2);
    int sum2 = sumOfDigits(num2);
    printf("Number: %d\n", num2);
    printf("Sum of digits: %d\n", sum2);
    printf("%d ÷ %d = %d\n", num2, sum2, num2 / sum2);
    printf("Is Harshad number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Harshad number
    int num3 = 19;
    bool result3 = isHarshadNumber(num3);
    int sum3 = sumOfDigits(num3);
    printf("Number: %d\n", num3);
    printf("Sum of digits: %d\n", sum3);
    printf("%d ÷ %d = %.2f (not divisible)\n", num3, sum3, (double)num3 / sum3);
    printf("Is Harshad number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Harshad number 1
    int num4 = 1;
    bool result4 = isHarshadNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Harshad number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Harshad numbers in range
    int start = 1;
    int end = 30;
    int harshadNums[100];
    int count = getHarshadNumbersInRange(start, end, harshadNums, 100);
    printf("Harshad numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", harshadNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Convert Decimal to Octal\n");
    printf("============================================================\n");
    
    char octal[34]; // Max 32 bits + sign + null terminator
    
    // Test Case 1 - Positive number
    int num1_dec = 64;
    decimalToOctalIterative(num1_dec, octal);
    printf("Decimal: %d\n", num1_dec);
    printf("Octal (iterative): %s\n", octal);
    
    decimalToOctalRecursive(num1_dec, octal);
    printf("Octal (recursive): %s\n", octal);
    
    int octal_array1[32];
    int len1 = decimalToOctalArray(num1_dec, octal_array1);
    printf("Octal (array): ");
    for (int i = 0; i < len1; i++) {
        printf("%d", octal_array1[i]);
    }
    printf("\n");
    printf("Verification (octal to decimal): %d\n\n", octalToDecimal(octal));
    
    // Test Case 2 - Zero
    int num2_dec = 0;
    decimalToOctalIterative(num2_dec, octal);
    printf("Decimal: %d\n", num2_dec);
    printf("Octal: %s\n\n", octal);
    
    // Test Case 3 - Large number
    int num3_dec = 255;
    decimalToOctalIterative(num3_dec, octal);
    printf("Decimal: %d\n", num3_dec);
    printf("Octal: %s\n", octal);
    printf("Verification: %d\n\n", octalToDecimal(octal));
    
    // Test Case 4 - Single digit
    int num4_dec = 7;
    decimalToOctalIterative(num4_dec, octal);
    printf("Decimal: %d\n", num4_dec);
    printf("Octal: %s\n\n", octal);
    
    // Test Case 5 - Negative number
    int num5_dec = -100;
    decimalToOctalIterative(num5_dec, octal);
    printf("Decimal: %d\n", num5_dec);
    printf("Octal: %s\n", octal);
    printf("Verification: %d\n\n", octalToDecimal(octal));
    
    return 0;
}
