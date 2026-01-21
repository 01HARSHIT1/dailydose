#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Disarium Number
// A Disarium number is a number where the sum of its digits raised to their respective positions equals the number itself
// Example: 135 = 1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135

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
 * Check if a number is Disarium number
 * Time Complexity: O(d * log n) where d is number of digits
 * Space Complexity: O(1)
 */
bool isDisariumNumber(int n) {
    if (n <= 0) {
        return false;
    }
    
    int original = n;
    int numDigits = countDigits(n);
    long long sumPowers = 0;
    
    // Process digits from right to left
    int position = numDigits;
    while (n > 0) {
        int digit = n % 10;
        sumPowers += (long long) pow(digit, position);
        position--;
        n /= 10;
    }
    
    return sumPowers == original;
}

/**
 * Find all Disarium numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * d * log n)
 * Space Complexity: O(k) where k is the number of Disarium numbers
 */
int getDisariumNumbersInRange(int start, int end, int* disariumNumbers, int maxSize) {
    if (disariumNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isDisariumNumber(num)) {
            disariumNumbers[count++] = num;
        }
    }
    
    return count;
}

/**
 * Get the sum of digits raised to their positions
 * Time Complexity: O(d * log n) where d is number of digits
 * Space Complexity: O(1)
 */
long long getDigitPowersSum(int n) {
    if (n <= 0) {
        return 0;
    }
    
    int numDigits = countDigits(n);
    long long sumPowers = 0;
    int position = numDigits;
    int temp = n;
    
    while (temp > 0) {
        int digit = temp % 10;
        sumPowers += (long long) pow(digit, position);
        position--;
        temp /= 10;
    }
    
    return sumPowers;
}

// Problem 2: Convert Octal to Decimal
// Convert an octal (base 8) number to its decimal representation

/**
 * Convert octal string to decimal using iteration
 * Time Complexity: O(n) where n is length of octal string
 * Space Complexity: O(1)
 */
int octalToDecimalIterative(const char* octalStr) {
    if (octalStr == NULL || strlen(octalStr) == 0 || strcmp(octalStr, "0") == 0) {
        return 0;
    }
    
    bool isNegative = octalStr[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(octalStr);
    
    int decimal = 0;
    int power = 0;
    
    // Process from right to left
    for (int i = len - 1; i >= start; i--) {
        int digit = octalStr[i] - '0';
        if (digit < 0 || digit > 7) {
            printf("Error: Invalid octal digit: %d\n", digit);
            return -1;
        }
        decimal += digit * (int) pow(8, power);
        power++;
    }
    
    return isNegative ? -decimal : decimal;
}

/**
 * Helper function for recursive octal conversion
 */
int octalToDecimalRecursiveHelper(const char* octal, int index, int power) {
    if (index < 0) {
        return 0;
    }
    int digit = octal[index] - '0';
    if (digit < 0 || digit > 7) {
        printf("Error: Invalid octal digit: %d\n", digit);
        return -1;
    }
    return digit * (int) pow(8, power) + octalToDecimalRecursiveHelper(octal, index - 1, power + 1);
}

/**
 * Convert octal string to decimal using recursion
 * Time Complexity: O(n) where n is length of octal string
 * Space Complexity: O(n) due to recursion stack
 */
int octalToDecimalRecursive(const char* octalStr) {
    if (octalStr == NULL || strlen(octalStr) == 0 || strcmp(octalStr, "0") == 0) {
        return 0;
    }
    
    bool isNegative = octalStr[0] == '-';
    int start = isNegative ? 1 : 0;
    int len = strlen(octalStr);
    
    int result = octalToDecimalRecursiveHelper(octalStr + start, len - start - 1, 0);
    return isNegative ? -result : result;
}

/**
 * Convert octal array to decimal
 * Time Complexity: O(n) where n is length of array
 * Space Complexity: O(1)
 */
int octalArrayToDecimal(int* octalArray, int length) {
    if (octalArray == NULL || length == 0) {
        return 0;
    }
    
    int decimal = 0;
    int power = length - 1;
    
    for (int i = 0; i < length; i++) {
        if (octalArray[i] < 0 || octalArray[i] > 7) {
            printf("Error: Invalid octal digit: %d\n", octalArray[i]);
            return -1;
        }
        decimal += octalArray[i] * (int) pow(8, power);
        power--;
    }
    
    return decimal;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Disarium Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Disarium number 135
    int num1 = 135;
    bool result1 = isDisariumNumber(num1);
    long long sum1 = getDigitPowersSum(num1);
    printf("Number: %d\n", num1);
    printf("Sum of digits raised to positions: %lld\n", sum1);
    printf("Is Disarium number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Disarium number 89
    int num2 = 89;
    bool result2 = isDisariumNumber(num2);
    long long sum2 = getDigitPowersSum(num2);
    printf("Number: %d\n", num2);
    printf("Sum of digits raised to positions: %lld\n", sum2);
    printf("Is Disarium number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not Disarium number
    int num3 = 123;
    bool result3 = isDisariumNumber(num3);
    long long sum3 = getDigitPowersSum(num3);
    printf("Number: %d\n", num3);
    printf("Sum of digits raised to positions: %lld\n", sum3);
    printf("Is Disarium number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Single digit Disarium
    int num4 = 1;
    bool result4 = isDisariumNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Disarium number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Disarium numbers in range
    int start = 1;
    int end = 200;
    int disariumNums[100];
    int count = getDisariumNumbersInRange(start, end, disariumNums, 100);
    printf("Disarium numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", disariumNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Convert Octal to Decimal\n");
    printf("============================================================\n");
    
    // Test Case 1 - Basic octal
    const char* octal1 = "123";
    int result1_dec = octalToDecimalIterative(octal1);
    int result1_rec = octalToDecimalRecursive(octal1);
    printf("Octal: %s\n", octal1);
    printf("Decimal (iterative): %d\n", result1_dec);
    printf("Decimal (recursive): %d\n\n", result1_rec);
    
    // Test Case 2 - Zero
    const char* octal2 = "0";
    int result2_dec = octalToDecimalIterative(octal2);
    printf("Octal: %s\n", octal2);
    printf("Decimal: %d\n\n", result2_dec);
    
    // Test Case 3 - Large octal
    const char* octal3 = "377";
    int result3_dec = octalToDecimalIterative(octal3);
    printf("Octal: %s\n", octal3);
    printf("Decimal: %d\n\n", result3_dec);
    
    // Test Case 4 - Octal array
    int octal4[] = {1, 2, 7};
    int length4 = sizeof(octal4) / sizeof(octal4[0]);
    int result4_dec = octalArrayToDecimal(octal4, length4);
    printf("Octal (array): ");
    for (int i = 0; i < length4; i++) {
        printf("%d", octal4[i]);
    }
    printf("\nDecimal: %d\n\n", result4_dec);
    
    // Test Case 5 - Single digit
    const char* octal5 = "7";
    int result5_dec = octalToDecimalIterative(octal5);
    printf("Octal: %s\n", octal5);
    printf("Decimal: %d\n\n", result5_dec);
    
    return 0;
}
