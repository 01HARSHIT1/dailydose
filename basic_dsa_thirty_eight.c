#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

// Problem: Check if a Number is Circular Prime
// A Circular Prime is a prime number that remains prime when its digits are rotated
// Example: 197 is circular prime because 197, 971, and 719 are all prime
// Note: Single-digit primes (2, 3, 5, 7) are circular primes

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
 * Rotate a number by moving the last digit to the front
 * Example: 197 -> 719
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int rotateNumber(int n) {
    if (n < 10) {
        return n;
    }
    
    int lastDigit = n % 10;
    int remaining = n / 10;
    int numDigits = countDigits(n);
    
    // Move last digit to front
    int rotated = lastDigit * (int) pow(10, numDigits - 1) + remaining;
    
    return rotated;
}

/**
 * Get all rotations of a number
 * Stores results in array and returns count
 * Time Complexity: O(d * log n) where d is number of digits
 * Space Complexity: O(d)
 */
int getAllRotations(int n, int* rotations, int maxSize) {
    if (rotations == NULL || maxSize == 0) {
        return 0;
    }
    
    int numDigits = countDigits(n);
    if (numDigits > maxSize) {
        return 0;
    }
    
    int current = n;
    for (int i = 0; i < numDigits; i++) {
        rotations[i] = current;
        current = rotateNumber(current);
    }
    
    return numDigits;
}

/**
 * Check if a number is Circular Prime
 * A Circular Prime remains prime when its digits are rotated
 * Time Complexity: O(d * √n) where d is number of digits
 * Space Complexity: O(d)
 */
bool isCircularPrime(int n) {
    if (n < 2) {
        return false;
    }
    
    int numDigits = countDigits(n);
    int* rotations = (int*) malloc(numDigits * sizeof(int));
    if (rotations == NULL) {
        return false;
    }
    
    // Get all rotations
    getAllRotations(n, rotations, numDigits);
    
    // Check if all rotations are prime
    for (int i = 0; i < numDigits; i++) {
        if (!isPrime(rotations[i])) {
            free(rotations);
            return false;
        }
    }
    
    free(rotations);
    return true;
}

/**
 * Find all Circular Prime numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * d * √n)
 * Space Complexity: O(k) where k is the number of Circular Primes
 */
int getCircularPrimesInRange(int start, int end, int* circularPrimes, int maxSize) {
    if (circularPrimes == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isCircularPrime(num)) {
            circularPrimes[count++] = num;
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Check if a Number is Circular Prime\n");
    printf("============================================================\n");
    
    // Test Case 1 - Circular Prime 2
    int num1 = 2;
    bool result1 = isCircularPrime(num1);
    int rotations1[10];
    int count1 = getAllRotations(num1, rotations1, 10);
    printf("Number: %d\n", num1);
    printf("Rotations: ");
    for (int i = 0; i < count1; i++) {
        printf("%d ", rotations1[i]);
    }
    printf("\nIs Circular Prime: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Circular Prime 197
    int num2 = 197;
    bool result2 = isCircularPrime(num2);
    int rotations2[10];
    int count2 = getAllRotations(num2, rotations2, 10);
    bool allPrime2 = true;
    for (int i = 0; i < count2; i++) {
        if (!isPrime(rotations2[i])) {
            allPrime2 = false;
            break;
        }
    }
    printf("Number: %d\n", num2);
    printf("Rotations: ");
    for (int i = 0; i < count2; i++) {
        printf("%d ", rotations2[i]);
    }
    printf("\nAll rotations prime: %s\n", allPrime2 ? "true" : "false");
    printf("Is Circular Prime: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Circular Prime 113
    int num3 = 113;
    bool result3 = isCircularPrime(num3);
    int rotations3[10];
    int count3 = getAllRotations(num3, rotations3, 10);
    bool allPrime3 = true;
    for (int i = 0; i < count3; i++) {
        if (!isPrime(rotations3[i])) {
            allPrime3 = false;
            break;
        }
    }
    printf("Number: %d\n", num3);
    printf("Rotations: ");
    for (int i = 0; i < count3; i++) {
        printf("%d ", rotations3[i]);
    }
    printf("\nAll rotations prime: %s\n", allPrime3 ? "true" : "false");
    printf("Is Circular Prime: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not Circular Prime (19)
    int num4 = 19;
    bool result4 = isCircularPrime(num4);
    int rotations4[10];
    int count4 = getAllRotations(num4, rotations4, 10);
    bool allPrime4 = true;
    for (int i = 0; i < count4; i++) {
        if (!isPrime(rotations4[i])) {
            allPrime4 = false;
            break;
        }
    }
    printf("Number: %d\n", num4);
    printf("Rotations: ");
    for (int i = 0; i < count4; i++) {
        printf("%d ", rotations4[i]);
    }
    printf("\nAll rotations prime: %s\n", allPrime4 ? "true" : "false");
    printf("Is Circular Prime: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Single digit Circular Prime 7
    int num5 = 7;
    bool result5 = isCircularPrime(num5);
    int rotations5[10];
    int count5 = getAllRotations(num5, rotations5, 10);
    printf("Number: %d\n", num5);
    printf("Rotations: ");
    for (int i = 0; i < count5; i++) {
        printf("%d ", rotations5[i]);
    }
    printf("\nIs Circular Prime: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - Find Circular Primes in range
    int start = 1;
    int end = 100;
    int circularPrimes[30];
    int count = getCircularPrimesInRange(start, end, circularPrimes, 30);
    printf("Circular Prime numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", circularPrimes[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    // Test Case 7 - Circular Prime 199
    int num7 = 199;
    bool result7 = isCircularPrime(num7);
    int rotations7[10];
    int count7 = getAllRotations(num7, rotations7, 10);
    bool allPrime7 = true;
    for (int i = 0; i < count7; i++) {
        if (!isPrime(rotations7[i])) {
            allPrime7 = false;
            break;
        }
    }
    printf("Number: %d\n", num7);
    printf("Rotations: ");
    for (int i = 0; i < count7; i++) {
        printf("%d ", rotations7[i]);
    }
    printf("\nAll rotations prime: %s\n", allPrime7 ? "true" : "false");
    printf("Is Circular Prime: %s\n", result7 ? "true" : "false");
    
    return 0;
}
