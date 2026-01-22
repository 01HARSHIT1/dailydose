#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

// Problem: Check if a Number is Palindrome
// A palindrome number is a number that remains the same when its digits are reversed
// Example: 121, 1331, 12321 are palindromes

/**
 * Reverse a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
long long reverseNumber(int n) {
    long long reversedNum = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    
    return n < 0 ? -reversedNum : reversedNum;
}

/**
 * Check if a number is palindrome using string conversion
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
bool isPalindromeNumberString(int n) {
    char numStr[20];
    sprintf(numStr, "%d", n < 0 ? -n : n);
    
    int len = strlen(numStr);
    for (int i = 0; i < len / 2; i++) {
        if (numStr[i] != numStr[len - 1 - i]) {
            return false;
        }
    }
    
    return true;
}

/**
 * Check if a number is palindrome by reversing it
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isPalindromeNumberReverse(int n) {
    if (n < 0) {
        return false; // Negative numbers are not palindromes
    }
    
    int original = n;
    long long reversedNum = reverseNumber(n);
    return original == reversedNum;
}

/**
 * Check if a number is palindrome using two-pointer approach
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) for string conversion
 */
bool isPalindromeNumberTwoPointers(int n) {
    if (n < 0) {
        return false;
    }
    
    char numStr[20];
    sprintf(numStr, "%d", n);
    
    int left = 0;
    int right = strlen(numStr) - 1;
    
    while (left < right) {
        if (numStr[left] != numStr[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

/**
 * Find all palindrome numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of palindrome numbers
 */
int getPalindromeNumbersInRange(int start, int end, int* palindromeNumbers, int maxSize) {
    if (palindromeNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isPalindromeNumberReverse(num)) {
            palindromeNumbers[count++] = num;
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Check if a Number is Palindrome\n");
    printf("============================================================\n");
    
    // Test Case 1 - Palindrome number 121
    int num1 = 121;
    bool result1_string = isPalindromeNumberString(num1);
    bool result1_reverse = isPalindromeNumberReverse(num1);
    bool result1_two_pointers = isPalindromeNumberTwoPointers(num1);
    long long reversed1 = reverseNumber(num1);
    printf("Number: %d\n", num1);
    printf("Reversed: %lld\n", reversed1);
    printf("Is palindrome (string): %s\n", result1_string ? "true" : "false");
    printf("Is palindrome (reverse): %s\n", result1_reverse ? "true" : "false");
    printf("Is palindrome (two pointers): %s\n\n", result1_two_pointers ? "true" : "false");
    
    // Test Case 2 - Palindrome number 1331
    int num2 = 1331;
    bool result2 = isPalindromeNumberReverse(num2);
    long long reversed2 = reverseNumber(num2);
    printf("Number: %d\n", num2);
    printf("Reversed: %lld\n", reversed2);
    printf("Is palindrome: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not palindrome
    int num3 = 123;
    bool result3 = isPalindromeNumberReverse(num3);
    long long reversed3 = reverseNumber(num3);
    printf("Number: %d\n", num3);
    printf("Reversed: %lld\n", reversed3);
    printf("Is palindrome: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Single digit (always palindrome)
    int num4 = 7;
    bool result4 = isPalindromeNumberReverse(num4);
    printf("Number: %d\n", num4);
    printf("Is palindrome: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Palindrome number 12321
    int num5 = 12321;
    bool result5 = isPalindromeNumberReverse(num5);
    long long reversed5 = reverseNumber(num5);
    printf("Number: %d\n", num5);
    printf("Reversed: %lld\n", reversed5);
    printf("Is palindrome: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - Find palindrome numbers in range
    int start = 100;
    int end = 200;
    int palindromeNums[50];
    int count = getPalindromeNumbersInRange(start, end, palindromeNums, 50);
    printf("Palindrome numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", palindromeNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    // Test Case 7 - Zero
    int num7 = 0;
    bool result7 = isPalindromeNumberReverse(num7);
    printf("Number: %d\n", num7);
    printf("Is palindrome: %s\n", result7 ? "true" : "false");
    
    return 0;
}
