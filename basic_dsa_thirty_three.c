#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

// Problem: Find nth Prime Number
// Find the nth prime number in the sequence of prime numbers
// Example: 1st prime = 2, 2nd prime = 3, 3rd prime = 5, 4th prime = 7, 5th prime = 11

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
 * Find nth prime number using brute force
 * Time Complexity: O(n * √n)
 * Space Complexity: O(1)
 */
int nthPrimeBruteForce(int n) {
    if (n <= 0) {
        printf("Error: n must be positive\n");
        return -1;
    }
    
    if (n == 1) {
        return 2;
    }
    
    int count = 1;
    int num = 3;
    
    while (count < n) {
        if (isPrime(num)) {
            count++;
            if (count == n) {
                return num;
            }
        }
        num += 2; // Check only odd numbers (except 2)
    }
    
    return num - 2;
}

/**
 * Find nth prime number using optimized approach with Sieve of Eratosthenes
 * Time Complexity: O(n log log n) for sieve
 * Space Complexity: O(n)
 */
int nthPrimeSieveOptimized(int n) {
    if (n <= 0) {
        printf("Error: n must be positive\n");
        return -1;
    }
    
    if (n == 1) {
        return 2;
    }
    
    // Estimate upper bound: n * log(n) + n * log(log(n)) for n > 6
    if (n <= 6) {
        int primes[] = {2, 3, 5, 7, 11, 13};
        return primes[n - 1];
    }
    
    int upperBound = (int) (n * log(n) + n * log(log(n)));
    if (upperBound < 20) {
        upperBound = 20;
    }
    
    // Sieve of Eratosthenes
    bool* isPrimeList = (bool*)malloc((upperBound + 1) * sizeof(bool));
    for (int i = 0; i <= upperBound; i++) {
        isPrimeList[i] = true;
    }
    isPrimeList[0] = isPrimeList[1] = false;
    
    for (int i = 2; i * i <= upperBound; i++) {
        if (isPrimeList[i]) {
            for (int j = i * i; j <= upperBound; j += i) {
                isPrimeList[j] = false;
            }
        }
    }
    
    // Collect primes
    int count = 0;
    int result = -1;
    for (int i = 2; i <= upperBound; i++) {
        if (isPrimeList[i]) {
            count++;
            if (count == n) {
                result = i;
                break;
            }
        }
    }
    
    free(isPrimeList);
    
    // If not enough primes found, use brute force
    if (result == -1) {
        return nthPrimeBruteForce(n);
    }
    
    return result;
}

/**
 * Get list of first n prime numbers
 * Stores results in array and returns count
 * Time Complexity: O(n * √n)
 * Space Complexity: O(n)
 */
int getFirstNPrimes(int n, int* primes, int maxSize) {
    if (n <= 0 || primes == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    int num = 2;
    
    while (count < n && count < maxSize) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
    
    return count;
}

/**
 * Get all prime numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * √n)
 * Space Complexity: O(k) where k is the number of primes
 */
int getPrimesInRange(int start, int end, int* primes, int maxSize) {
    if (primes == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
    }
    
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Find nth Prime Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - 1st prime
    int n1 = 1;
    int result1 = nthPrimeBruteForce(n1);
    printf("n = %d\n", n1);
    printf("%dst prime number: %d\n\n", n1, result1);
    
    // Test Case 2 - 5th prime
    int n2 = 5;
    int result2 = nthPrimeBruteForce(n2);
    int result2_sieve = nthPrimeSieveOptimized(n2);
    printf("n = %d\n", n2);
    printf("%dth prime number (brute force): %d\n", n2, result2);
    printf("%dth prime number (sieve): %d\n\n", n2, result2_sieve);
    
    // Test Case 3 - 10th prime
    int n3 = 10;
    int result3 = nthPrimeBruteForce(n3);
    int result3_sieve = nthPrimeSieveOptimized(n3);
    printf("n = %d\n", n3);
    printf("%dth prime number (brute force): %d\n", n3, result3);
    printf("%dth prime number (sieve): %d\n\n", n3, result3_sieve);
    
    // Test Case 4 - First 10 primes
    int n4 = 10;
    int primesList[20];
    int count4 = getFirstNPrimes(n4, primesList, 20);
    printf("First %d prime numbers:\n", n4);
    for (int i = 0; i < count4; i++) {
        printf("%d ", primesList[i]);
    }
    printf("\n\n");
    
    // Test Case 5 - 20th prime
    int n5 = 20;
    int result5 = nthPrimeBruteForce(n5);
    printf("n = %d\n", n5);
    printf("%dth prime number: %d\n\n", n5, result5);
    
    // Test Case 6 - Primes in range
    int start = 10;
    int end = 50;
    int primesRange[50];
    int count6 = getPrimesInRange(start, end, primesRange, 50);
    printf("Prime numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count6; i++) {
        printf("%d ", primesRange[i]);
    }
    printf("\nCount: %d\n\n", count6);
    
    // Test Case 7 - 100th prime
    int n7 = 100;
    int result7 = nthPrimeSieveOptimized(n7);
    printf("n = %d\n", n7);
    printf("%dth prime number: %d\n", n7, result7);
    
    return 0;
}
