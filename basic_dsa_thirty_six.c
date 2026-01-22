#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

// Problem: Check if a Number is Emirp
// An Emirp is a prime number that when reversed is also a prime number (and different from the original)
// Example: 13 is Emirp because 13 is prime and 31 (reversed) is also prime
// Note: Palindromic primes like 11, 131 are NOT Emirp because reversed number is same

/**
 * Check if a number is prime
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

/**
 * Reverse a number
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int reverseNumber(int n) {
    long long reversedNum = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    
    return (int) (n < 0 ? -reversedNum : reversedNum);
}

/**
 * Check if a number is Emirp
 * An Emirp is a prime that when reversed is also prime and different from original
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isEmirp(int n) {
    if (n < 2) {
        return false;
    }
    
    // Check if number is prime
    if (!isPrime(n)) {
        return false;
    }
    
    // Reverse the number
    int reversedN = reverseNumber(n);
    
    // Check if reversed number is different and also prime
    if (reversedN == n) {
        return false; // Palindromic primes are not Emirp
    }
    
    return isPrime(reversedN);
}

/**
 * Find all Emirp numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(k) where k is the number of Emirp numbers
 */
int getEmirpNumbersInRange(int start, int end, int* emirpNumbers, int maxSize) {
    if (emirpNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isEmirp(num)) {
            emirpNumbers[count++] = num;
        }
    }
    
    return count;
}

/**
 * Get the Emirp pair (original, reversed) if number is Emirp
 * Stores result in pair array and returns true if Emirp
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool getEmirpPair(int n, int* pair) {
    if (!isEmirp(n) || pair == NULL) {
        return false;
    }
    
    pair[0] = n;
    pair[1] = reverseNumber(n);
    return true;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Check if a Number is Emirp\n");
    printf("============================================================\n");
    
    // Test Case 1 - Emirp number 13
    int num1 = 13;
    bool result1 = isEmirp(num1);
    int reversed1 = reverseNumber(num1);
    int pair1[2];
    bool hasPair1 = getEmirpPair(num1, pair1);
    printf("Number: %d\n", num1);
    printf("Reversed: %d\n", reversed1);
    printf("Is Emirp: %s\n", result1 ? "true" : "false");
    if (hasPair1) {
        printf("Emirp pair: (%d, %d)\n\n", pair1[0], pair1[1]);
    } else {
        printf("\n");
    }
    
    // Test Case 2 - Emirp number 17
    int num2 = 17;
    bool result2 = isEmirp(num2);
    int reversed2 = reverseNumber(num2);
    int pair2[2];
    bool hasPair2 = getEmirpPair(num2, pair2);
    printf("Number: %d\n", num2);
    printf("Reversed: %d\n", reversed2);
    printf("Is Emirp: %s\n", result2 ? "true" : "false");
    if (hasPair2) {
        printf("Emirp pair: (%d, %d)\n\n", pair2[0], pair2[1]);
    } else {
        printf("\n");
    }
    
    // Test Case 3 - Not Emirp (palindromic prime 11)
    int num3 = 11;
    bool result3 = isEmirp(num3);
    int reversed3 = reverseNumber(num3);
    printf("Number: %d\n", num3);
    printf("Reversed: %d\n", reversed3);
    printf("Is Emirp: %s (palindromic prime, not Emirp)\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not Emirp (not prime)
    int num4 = 15;
    bool result4 = isEmirp(num4);
    printf("Number: %d\n", num4);
    printf("Is Emirp: %s (not prime)\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Emirp number 37
    int num5 = 37;
    bool result5 = isEmirp(num5);
    int reversed5 = reverseNumber(num5);
    int pair5[2];
    bool hasPair5 = getEmirpPair(num5, pair5);
    printf("Number: %d\n", num5);
    printf("Reversed: %d\n", reversed5);
    printf("Is Emirp: %s\n", result5 ? "true" : "false");
    if (hasPair5) {
        printf("Emirp pair: (%d, %d)\n\n", pair5[0], pair5[1]);
    } else {
        printf("\n");
    }
    
    // Test Case 6 - Find Emirp numbers in range
    int start = 1;
    int end = 100;
    int emirpNums[50];
    int count = getEmirpNumbersInRange(start, end, emirpNums, 50);
    printf("Emirp numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", emirpNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    // Test Case 7 - Emirp number 79
    int num7 = 79;
    bool result7 = isEmirp(num7);
    int reversed7 = reverseNumber(num7);
    int pair7[2];
    bool hasPair7 = getEmirpPair(num7, pair7);
    printf("Number: %d\n", num7);
    printf("Reversed: %d\n", reversed7);
    printf("Is Emirp: %s\n", result7 ? "true" : "false");
    if (hasPair7) {
        printf("Emirp pair: (%d, %d)\n", pair7[0], pair7[1]);
    }
    
    return 0;
}
