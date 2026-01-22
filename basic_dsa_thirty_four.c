#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

// Problem: Check if Two Numbers are Twin Primes
// Twin primes are pairs of prime numbers that differ by 2
// Example: (3, 5), (5, 7), (11, 13), (17, 19) are twin prime pairs

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
 * Check if two numbers are twin primes
 * Twin primes are pairs of primes that differ by exactly 2
 * Time Complexity: O(√a + √b)
 * Space Complexity: O(1)
 */
bool areTwinPrimes(int a, int b) {
    // Check if both are prime
    if (!isPrime(a) || !isPrime(b)) {
        return false;
    }
    
    // Check if they differ by 2
    return abs(a - b) == 2;
}

/**
 * Find all twin prime pairs in a given range
 * Stores results in array of pairs and returns count
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(k) where k is the number of twin prime pairs
 */
int getTwinPrimePairsInRange(int start, int end, int* twinPairs, int maxPairs) {
    if (twinPairs == NULL || maxPairs == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num < end && count < maxPairs; num++) {
        if (isPrime(num) && isPrime(num + 2) && (num + 2) <= end) {
            twinPairs[count * 2] = num;
            twinPairs[count * 2 + 1] = num + 2;
            count++;
        }
    }
    
    return count;
}

/**
 * Get all twin prime pairs up to n
 * Stores results in array of pairs and returns count
 * Time Complexity: O(n * √n)
 * Space Complexity: O(k) where k is the number of twin prime pairs
 */
int getAllTwinPrimesUpTo(int n, int* twinPairs, int maxPairs) {
    if (twinPairs == NULL || maxPairs == 0) {
        return 0;
    }
    
    int count = 0;
    // Start from 3 (first twin prime pair is (3, 5))
    for (int num = 3; num < n - 1 && count < maxPairs; num++) {
        if (isPrime(num) && isPrime(num + 2)) {
            twinPairs[count * 2] = num;
            twinPairs[count * 2 + 1] = num + 2;
            count++;
        }
    }
    
    return count;
}

/**
 * Count number of twin prime pairs in a given range
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(1)
 */
int countTwinPrimesInRange(int start, int end) {
    int count = 0;
    
    for (int num = start; num < end; num++) {
        if (isPrime(num) && isPrime(num + 2) && (num + 2) <= end) {
            count++;
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Check if Two Numbers are Twin Primes\n");
    printf("============================================================\n");
    
    // Test Case 1 - Twin primes (3, 5)
    int a1 = 3, b1 = 5;
    bool result1 = areTwinPrimes(a1, b1);
    printf("Numbers: (%d, %d)\n", a1, b1);
    printf("Are twin primes: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Twin primes (5, 7)
    int a2 = 5, b2 = 7;
    bool result2 = areTwinPrimes(a2, b2);
    printf("Numbers: (%d, %d)\n", a2, b2);
    printf("Are twin primes: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Not twin primes (3, 7)
    int a3 = 3, b3 = 7;
    bool result3 = areTwinPrimes(a3, b3);
    printf("Numbers: (%d, %d)\n", a3, b3);
    printf("Are twin primes: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not twin primes (4, 6) - not primes
    int a4 = 4, b4 = 6;
    bool result4 = areTwinPrimes(a4, b4);
    printf("Numbers: (%d, %d)\n", a4, b4);
    printf("Are twin primes: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Twin primes (11, 13)
    int a5 = 11, b5 = 13;
    bool result5 = areTwinPrimes(a5, b5);
    printf("Numbers: (%d, %d)\n", a5, b5);
    printf("Are twin primes: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - Find twin prime pairs in range
    int start = 1;
    int end = 50;
    int twinPairs[100]; // Store pairs as [a1, b1, a2, b2, ...]
    int count = getTwinPrimePairsInRange(start, end, twinPairs, 50);
    printf("Twin prime pairs in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("(%d, %d) ", twinPairs[i * 2], twinPairs[i * 2 + 1]);
    }
    printf("\nCount: %d\n\n", count);
    
    // Test Case 7 - All twin primes up to 100
    int n7 = 100;
    int allTwinPairs[200];
    int count7 = getAllTwinPrimesUpTo(n7, allTwinPairs, 100);
    printf("All twin prime pairs up to %d:\n", n7);
    for (int i = 0; i < count7; i++) {
        printf("(%d, %d) ", allTwinPairs[i * 2], allTwinPairs[i * 2 + 1]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\nTotal count: %d\n", count7);
    
    return 0;
}
