#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Count Digits in a Number
// Count the number of digits in a number

/**
 * Count digits using iterative approach
 * Time Complexity: O(log n) where log is base 10
 * Space Complexity: O(1)
 */
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }
    
    n = abs(n); // Handle negative numbers
    int count = 0;
    
    while (n > 0) {
        count++;
        n /= 10;
    }
    
    return count;
}

/**
 * Count digits using recursive approach
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */
int countDigitsRecursive(int n) {
    n = abs(n); // Handle negative numbers
    if (n < 10) {
        return 1;
    }
    return 1 + countDigitsRecursive(n / 10);
}

/**
 * Count digits using logarithmic approach
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int countDigitsLog(int n) {
    if (n == 0) {
        return 1;
    }
    return (int) log10(abs(n)) + 1;
}

// Problem 2: Check if a Number is Armstrong Number
// An Armstrong number is a number that is equal to the sum of its own digits
// each raised to the power of the number of digits

/**
 * Helper function to calculate power
 */
long long power(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/**
 * Check if a number is Armstrong number
 * Time Complexity: O(d) where d is number of digits
 * Space Complexity: O(1)
 */
bool isArmstrong(int n) {
    if (n < 0) {
        return false;
    }
    
    int original = n;
    int numDigits = countDigits(n);
    long long sumPower = 0;
    
    while (n > 0) {
        int digit = n % 10;
        sumPower += power(digit, numDigits);
        n /= 10;
    }
    
    return original == sumPower;
}

/**
 * Find all Armstrong numbers in a given range
 * Time Complexity: O(n * d) where n is range size, d is average digits
 * Space Complexity: O(1) excluding output
 */
void findArmstrongNumbersInRange(int start, int end, int* result, int* count) {
    *count = 0;
    
    for (int num = start; num <= end; num++) {
        if (isArmstrong(num)) {
            result[*count] = num;
            (*count)++;
        }
    }
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Count Digits in a Number\n");
    printf("============================================================\n");
    
    // Test Case 1
    int num1 = 12345;
    int count1 = countDigits(num1);
    int countRec1 = countDigitsRecursive(num1);
    int countLog1 = countDigitsLog(num1);
    printf("Number: %d\n", num1);
    printf("Number of digits (Iterative): %d\n", count1);
    printf("Number of digits (Recursive): %d\n", countRec1);
    printf("Number of digits (Logarithmic): %d\n\n", countLog1);
    
    // Test Case 2
    int num2 = 9876;
    int count2 = countDigits(num2);
    int countRec2 = countDigitsRecursive(num2);
    int countLog2 = countDigitsLog(num2);
    printf("Number: %d\n", num2);
    printf("Number of digits (Iterative): %d\n", count2);
    printf("Number of digits (Recursive): %d\n", countRec2);
    printf("Number of digits (Logarithmic): %d\n\n", countLog2);
    
    // Test Case 3 - Single digit
    int num3 = 5;
    int count3 = countDigits(num3);
    int countRec3 = countDigitsRecursive(num3);
    int countLog3 = countDigitsLog(num3);
    printf("Number: %d\n", num3);
    printf("Number of digits (Iterative): %d\n", count3);
    printf("Number of digits (Recursive): %d\n", countRec3);
    printf("Number of digits (Logarithmic): %d\n\n", countLog3);
    
    // Test Case 4 - Zero
    int num4 = 0;
    int count4 = countDigits(num4);
    int countRec4 = countDigitsRecursive(num4);
    int countLog4 = countDigitsLog(num4);
    printf("Number: %d\n", num4);
    printf("Number of digits (Iterative): %d\n", count4);
    printf("Number of digits (Recursive): %d\n", countRec4);
    printf("Number of digits (Logarithmic): %d\n\n", countLog4);
    
    // Test Case 5 - Negative number
    int num5 = -123;
    int count5 = countDigits(num5);
    int countRec5 = countDigitsRecursive(num5);
    int countLog5 = countDigitsLog(num5);
    printf("Number: %d\n", num5);
    printf("Number of digits (Iterative): %d\n", count5);
    printf("Number of digits (Recursive): %d\n", countRec5);
    printf("Number of digits (Logarithmic): %d\n\n", countLog5);
    
    printf("============================================================\n");
    printf("Problem 2: Check if a Number is Armstrong Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Armstrong number (153: 1^3 + 5^3 + 3^3 = 153)
    int num7 = 153;
    bool result1 = isArmstrong(num7);
    printf("Number: %d\n", num7);
    printf("Is Armstrong: %s\n", result1 ? "true" : "false");
    if (result1) {
        int pow1 = (int)power(1, 3);
        int pow5 = (int)power(5, 3);
        int pow3 = (int)power(3, 3);
        printf("Verification: 1³ + 5³ + 3³ = %d + %d + %d = %d = %d\n\n", 
            pow1, pow5, pow3, pow1 + pow5 + pow3, num7);
    } else {
        printf("\n");
    }
    
    // Test Case 2 - Not Armstrong
    int num8 = 123;
    bool result2 = isArmstrong(num8);
    printf("Number: %d\n", num8);
    printf("Is Armstrong: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Armstrong number (371: 3^3 + 7^3 + 1^3 = 371)
    int num9 = 371;
    bool result3 = isArmstrong(num9);
    printf("Number: %d\n", num9);
    printf("Is Armstrong: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Armstrong number (407: 4^3 + 0^3 + 7^3 = 407)
    int num10 = 407;
    bool result4 = isArmstrong(num10);
    printf("Number: %d\n", num10);
    printf("Is Armstrong: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Single digit (all single digits are Armstrong)
    int num11 = 5;
    bool result5 = isArmstrong(num11);
    printf("Number: %d\n", num11);
    printf("Is Armstrong: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - 4-digit Armstrong (1634: 1^4 + 6^4 + 3^4 + 4^4 = 1634)
    int num12 = 1634;
    bool result6 = isArmstrong(num12);
    printf("Number: %d\n", num12);
    printf("Is Armstrong: %s\n\n", result6 ? "true" : "false");
    
    // Test Case 7 - Find Armstrong numbers in range
    int result[100];
    int count;
    findArmstrongNumbersInRange(100, 500, result, &count);
    printf("Armstrong numbers between 100 and 500: [");
    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        if (i < count - 1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}
