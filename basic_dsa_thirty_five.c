#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

#define MAX_FACTORS 100

// Problem: Check if a Number is Smith Number
// A Smith number is a composite number whose sum of digits equals the sum of digits of its prime factors
// Example: 4 = 2 × 2, sum of digits of 4 = 4, sum of digits of prime factors (2+2) = 4, so 4 is Smith

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
 * Get all prime factors of a number (with repetition)
 * Stores factors in array and returns count
 * Time Complexity: O(√n)
 * Space Complexity: O(log n)
 */
int getPrimeFactors(int n, int* factors, int maxSize) {
    if (n < 2 || factors == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    int num = n < 0 ? -n : n;
    
    // Check for factor 2
    while (num % 2 == 0 && count < maxSize) {
        factors[count++] = 2;
        num /= 2;
    }
    
    // Check for odd factors
    for (int i = 3; i * i <= num && count < maxSize; i += 2) {
        while (num % i == 0 && count < maxSize) {
            factors[count++] = i;
            num /= i;
        }
    }
    
    // If remaining number is prime
    if (num > 1 && count < maxSize) {
        factors[count++] = num;
    }
    
    return count;
}

/**
 * Calculate sum of digits of all factors
 * Time Complexity: O(k * log m) where k is number of factors, m is max factor
 * Space Complexity: O(1)
 */
int sumOfDigitsOfFactors(int* factors, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += sumOfDigits(factors[i]);
    }
    return total;
}

/**
 * Check if a number is Smith number
 * A Smith number is composite and sum of digits equals sum of digits of prime factors
 * Time Complexity: O(√n)
 * Space Complexity: O(log n)
 */
bool isSmithNumber(int n) {
    if (n < 4) {
        return false; // No composite numbers below 4
    }
    
    // Smith numbers must be composite
    if (isPrime(n)) {
        return false;
    }
    
    // Get prime factors
    int factors[MAX_FACTORS];
    int factorCount = getPrimeFactors(n, factors, MAX_FACTORS);
    
    // Calculate sum of digits of number
    int sumDigitsNum = sumOfDigits(n);
    
    // Calculate sum of digits of prime factors
    int sumDigitsFactors = sumOfDigitsOfFactors(factors, factorCount);
    
    return sumDigitsNum == sumDigitsFactors;
}

/**
 * Find all Smith numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(k) where k is the number of Smith numbers
 */
int getSmithNumbersInRange(int start, int end, int* smithNumbers, int maxSize) {
    if (smithNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isSmithNumber(num)) {
            smithNumbers[count++] = num;
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Check if a Number is Smith Number\n");
    printf("============================================================\n");
    
    int factors[MAX_FACTORS];
    
    // Test Case 1 - Smith number 4
    int num1 = 4;
    bool result1 = isSmithNumber(num1);
    int count1 = getPrimeFactors(num1, factors, MAX_FACTORS);
    int sumDigits1 = sumOfDigits(num1);
    int sumFactors1 = sumOfDigitsOfFactors(factors, count1);
    printf("Number: %d\n", num1);
    printf("Prime factors: ");
    for (int i = 0; i < count1; i++) {
        printf("%d ", factors[i]);
    }
    printf("\nSum of digits of number: %d\n", sumDigits1);
    printf("Sum of digits of factors: %d\n", sumFactors1);
    printf("Is Smith number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Smith number 22
    int num2 = 22;
    bool result2 = isSmithNumber(num2);
    int count2 = getPrimeFactors(num2, factors, MAX_FACTORS);
    int sumDigits2 = sumOfDigits(num2);
    int sumFactors2 = sumOfDigitsOfFactors(factors, count2);
    printf("Number: %d\n", num2);
    printf("Prime factors: ");
    for (int i = 0; i < count2; i++) {
        printf("%d ", factors[i]);
    }
    printf("\nSum of digits of number: %d\n", sumDigits2);
    printf("Sum of digits of factors: %d\n", sumFactors2);
    printf("Is Smith number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Smith number 27
    int num3 = 27;
    bool result3 = isSmithNumber(num3);
    int count3 = getPrimeFactors(num3, factors, MAX_FACTORS);
    int sumDigits3 = sumOfDigits(num3);
    int sumFactors3 = sumOfDigitsOfFactors(factors, count3);
    printf("Number: %d\n", num3);
    printf("Prime factors: ");
    for (int i = 0; i < count3; i++) {
        printf("%d ", factors[i]);
    }
    printf("\nSum of digits of number: %d\n", sumDigits3);
    printf("Sum of digits of factors: %d\n", sumFactors3);
    printf("Is Smith number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not Smith number (prime)
    int num4 = 7;
    bool result4 = isSmithNumber(num4);
    printf("Number: %d\n", num4);
    printf("Is Smith number: %s (prime numbers are not Smith)\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Not Smith number (composite but not Smith)
    int num5 = 8;
    bool result5 = isSmithNumber(num5);
    int count5 = getPrimeFactors(num5, factors, MAX_FACTORS);
    int sumDigits5 = sumOfDigits(num5);
    int sumFactors5 = sumOfDigitsOfFactors(factors, count5);
    printf("Number: %d\n", num5);
    printf("Prime factors: ");
    for (int i = 0; i < count5; i++) {
        printf("%d ", factors[i]);
    }
    printf("\nSum of digits of number: %d\n", sumDigits5);
    printf("Sum of digits of factors: %d\n", sumFactors5);
    printf("Is Smith number: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - Find Smith numbers in range
    int start = 1;
    int end = 100;
    int smithNums[50];
    int count = getSmithNumbersInRange(start, end, smithNums, 50);
    printf("Smith numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", smithNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    // Test Case 7 - Smith number 666
    int num7 = 666;
    bool result7 = isSmithNumber(num7);
    int count7 = getPrimeFactors(num7, factors, MAX_FACTORS);
    int sumDigits7 = sumOfDigits(num7);
    int sumFactors7 = sumOfDigitsOfFactors(factors, count7);
    printf("Number: %d\n", num7);
    printf("Prime factors: ");
    for (int i = 0; i < count7; i++) {
        printf("%d ", factors[i]);
    }
    printf("\nSum of digits of number: %d\n", sumDigits7);
    printf("Sum of digits of factors: %d\n", sumFactors7);
    printf("Is Smith number: %s\n", result7 ? "true" : "false");
    
    return 0;
}
