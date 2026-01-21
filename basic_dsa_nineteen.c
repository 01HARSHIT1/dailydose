#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Abundant Number
// An abundant number is a number for which the sum of its proper divisors is greater than the number itself
// Example: 12 has proper divisors 1, 2, 3, 4, 6, sum = 16 > 12, so 12 is abundant

/**
 * Calculate sum of proper divisors of a number
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
int sumOfProperDivisors(int n) {
    if (n <= 1) {
        return 0;
    }
    
    int sumDivisors = 1; // 1 is always a divisor
    
    // Check divisors from 2 to √n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sumDivisors += i;
            // Add the corresponding divisor (avoid adding square twice)
            if (i != n / i) {
                sumDivisors += n / i;
            }
        }
    }
    
    return sumDivisors;
}

/**
 * Check if a number is abundant number
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isAbundantNumber(int n) {
    if (n <= 0) {
        return false;
    }
    return sumOfProperDivisors(n) > n;
}

/**
 * Get sum of proper divisors and store divisors in array
 * Returns the count of divisors
 * Time Complexity: O(√n)
 * Space Complexity: O(√n)
 */
int getProperDivisors(int n, int* divisors, int maxSize) {
    if (n <= 1 || divisors == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    divisors[count++] = 1;
    
    for (int i = 2; i * i <= n && count < maxSize; i++) {
        if (n % i == 0) {
            divisors[count++] = i;
            if (i != n / i && count < maxSize) {
                divisors[count++] = n / i;
            }
        }
    }
    
    return count;
}

// Problem 2: Find All Prime Numbers in a Range
// Find all prime numbers between two given numbers using Sieve of Eratosthenes

/**
 * Find all prime numbers up to n using Sieve of Eratosthenes
 * Stores primes in the primes array and returns the count
 * Time Complexity: O(n log log n)
 * Space Complexity: O(n)
 */
int sieveOfEratosthenes(int n, int* primes, int maxSize) {
    if (n < 2 || primes == NULL || maxSize == 0) {
        return 0;
    }
    
    // Create boolean array, initially all true
    bool* isPrime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    
    // Mark multiples of primes as false
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Collect all prime numbers
    int count = 0;
    for (int i = 2; i <= n && count < maxSize; i++) {
        if (isPrime[i]) {
            primes[count++] = i;
        }
    }
    
    free(isPrime);
    return count;
}

/**
 * Find all prime numbers in a given range [start, end]
 * Stores primes in the primes array and returns the count
 * Time Complexity: O(end log log end)
 * Space Complexity: O(end)
 */
int primesInRange(int start, int end, int* primes, int maxSize) {
    if (end < 2 || start > end || primes == NULL || maxSize == 0) {
        return 0;
    }
    
    // Adjust start to be at least 2
    if (start < 2) {
        start = 2;
    }
    
    // Use sieve to find all primes up to end
    int* allPrimes = (int*)malloc(end * sizeof(int));
    int allPrimesCount = sieveOfEratosthenes(end, allPrimes, end);
    
    // Filter primes in the range [start, end]
    int count = 0;
    for (int i = 0; i < allPrimesCount && count < maxSize; i++) {
        if (allPrimes[i] >= start) {
            primes[count++] = allPrimes[i];
        }
    }
    
    free(allPrimes);
    return count;
}

/**
 * Simple prime check for a single number
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
bool isPrimeSimple(int n) {
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
 * Count prime numbers in a given range
 * Time Complexity: O(end log log end)
 * Space Complexity: O(end)
 */
int countPrimesInRange(int start, int end) {
    if (end < 2 || start > end) {
        return 0;
    }
    
    int* primes = (int*)malloc((end - start + 1) * sizeof(int));
    int count = primesInRange(start, end, primes, end - start + 1);
    free(primes);
    return count;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Abundant Number\n");
    printf("============================================================\n");
    
    // Test Case 1 - Abundant number 12
    int num1 = 12;
    bool result1 = isAbundantNumber(num1);
    int divisors1[20];
    int count1 = getProperDivisors(num1, divisors1, 20);
    int sum1 = sumOfProperDivisors(num1);
    printf("Number: %d\n", num1);
    printf("Proper divisors: ");
    for (int i = 0; i < count1; i++) {
        printf("%d ", divisors1[i]);
    }
    printf("\nSum of proper divisors: %d\n", sum1);
    printf("Is abundant: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Not abundant number
    int num2 = 10;
    bool result2 = isAbundantNumber(num2);
    int divisors2[20];
    int count2 = getProperDivisors(num2, divisors2, 20);
    int sum2 = sumOfProperDivisors(num2);
    printf("Number: %d\n", num2);
    printf("Proper divisors: ");
    for (int i = 0; i < count2; i++) {
        printf("%d ", divisors2[i]);
    }
    printf("\nSum of proper divisors: %d\n", sum2);
    printf("Is abundant: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Abundant number 18
    int num3 = 18;
    bool result3 = isAbundantNumber(num3);
    int sum3 = sumOfProperDivisors(num3);
    printf("Number: %d\n", num3);
    printf("Sum of proper divisors: %d\n", sum3);
    printf("Is abundant: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Perfect number (not abundant)
    int num4 = 6;
    bool result4 = isAbundantNumber(num4);
    int sum4 = sumOfProperDivisors(num4);
    printf("Number: %d\n", num4);
    printf("Sum of proper divisors: %d\n", sum4);
    printf("Is abundant: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Deficient number (not abundant)
    int num5 = 8;
    bool result5 = isAbundantNumber(num5);
    int sum5 = sumOfProperDivisors(num5);
    printf("Number: %d\n", num5);
    printf("Sum of proper divisors: %d\n", sum5);
    printf("Is abundant: %s\n\n", result5 ? "true" : "false");
    
    printf("============================================================\n");
    printf("Problem 2: Find All Prime Numbers in a Range\n");
    printf("============================================================\n");
    
    // Test Case 1 - Primes up to 30
    int n1 = 30;
    int primes1[100];
    int count1_primes = sieveOfEratosthenes(n1, primes1, 100);
    printf("Prime numbers up to %d:\n", n1);
    for (int i = 0; i < count1_primes; i++) {
        printf("%d ", primes1[i]);
    }
    printf("\nCount: %d\n\n", count1_primes);
    
    // Test Case 2 - Primes in range [10, 50]
    int start2 = 10;
    int end2 = 50;
    int primes2[100];
    int count2_primes = primesInRange(start2, end2, primes2, 100);
    printf("Prime numbers in range [%d, %d]:\n", start2, end2);
    for (int i = 0; i < count2_primes; i++) {
        printf("%d ", primes2[i]);
    }
    printf("\nCount: %d\n\n", count2_primes);
    
    // Test Case 3 - Primes in range [1, 20]
    int start3 = 1;
    int end3 = 20;
    int primes3[100];
    int count3_primes = primesInRange(start3, end3, primes3, 100);
    printf("Prime numbers in range [%d, %d]:\n", start3, end3);
    for (int i = 0; i < count3_primes; i++) {
        printf("%d ", primes3[i]);
    }
    printf("\nCount: %d\n\n", count3_primes);
    
    // Test Case 4 - Count primes in range
    int start4 = 2;
    int end4 = 100;
    int count4 = countPrimesInRange(start4, end4);
    printf("Number of primes in range [%d, %d]: %d\n\n", start4, end4, count4);
    
    // Test Case 5 - Primes up to 100
    int n5 = 100;
    int primes5[100];
    int count5_primes = sieveOfEratosthenes(n5, primes5, 100);
    printf("Prime numbers up to %d:\n", n5);
    for (int i = 0; i < count5_primes; i++) {
        printf("%d ", primes5[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\nCount: %d\n", count5_primes);
    
    return 0;
}
