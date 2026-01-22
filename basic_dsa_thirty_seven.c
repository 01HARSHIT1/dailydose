#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

// Problem: Check if a Number is Trimorphic
// A Trimorphic number is a number whose cube ends with the number itself
// Example: 4³ = 64 (ends with 4), 5³ = 125 (ends with 5), 25³ = 15625 (ends with 25)

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
 * Check if a number is Trimorphic number
 * A Trimorphic number's cube ends with the number itself
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isTrimorphicNumber(int n) {
    if (n < 0) {
        return false;
    }
    
    long long cube = (long long) n * n * n;
    int numDigits = countDigits(n);
    
    // Extract last numDigits from cube
    long long divisor = (long long) pow(10, numDigits);
    long long lastDigits = cube % divisor;
    
    return lastDigits == n;
}

/**
 * Find all Trimorphic numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Trimorphic numbers
 */
int getTrimorphicNumbersInRange(int start, int end, int* trimorphicNumbers, int maxSize) {
    if (trimorphicNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isTrimorphicNumber(num)) {
            trimorphicNumbers[count++] = num;
        }
    }
    
    return count;
}

/**
 * Get the last numDigits of cube of a number
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
long long getCubeLastDigits(int n, int numDigits) {
    long long cube = (long long) n * n * n;
    long long divisor = (long long) pow(10, numDigits);
    return cube % divisor;
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem: Check if a Number is Trimorphic\n");
    printf("============================================================\n");
    
    // Test Case 1 - Trimorphic number 4
    int num1 = 4;
    bool result1 = isTrimorphicNumber(num1);
    long long cube1 = (long long) num1 * num1 * num1;
    long long lastDigits1 = getCubeLastDigits(num1, countDigits(num1));
    printf("Number: %d\n", num1);
    printf("Cube: %lld\n", cube1);
    printf("Last digits of cube: %lld\n", lastDigits1);
    printf("Is Trimorphic number: %s\n\n", result1 ? "true" : "false");
    
    // Test Case 2 - Trimorphic number 5
    int num2 = 5;
    bool result2 = isTrimorphicNumber(num2);
    long long cube2 = (long long) num2 * num2 * num2;
    long long lastDigits2 = getCubeLastDigits(num2, countDigits(num2));
    printf("Number: %d\n", num2);
    printf("Cube: %lld\n", cube2);
    printf("Last digits of cube: %lld\n", lastDigits2);
    printf("Is Trimorphic number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Trimorphic number 25
    int num3 = 25;
    bool result3 = isTrimorphicNumber(num3);
    long long cube3 = (long long) num3 * num3 * num3;
    long long lastDigits3 = getCubeLastDigits(num3, countDigits(num3));
    printf("Number: %d\n", num3);
    printf("Cube: %lld\n", cube3);
    printf("Last digits of cube: %lld\n", lastDigits3);
    printf("Is Trimorphic number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Not Trimorphic number
    int num4 = 6;
    bool result4 = isTrimorphicNumber(num4);
    long long cube4 = (long long) num4 * num4 * num4;
    long long lastDigits4 = getCubeLastDigits(num4, countDigits(num4));
    printf("Number: %d\n", num4);
    printf("Cube: %lld\n", cube4);
    printf("Last digits of cube: %lld\n", lastDigits4);
    printf("Is Trimorphic number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Single digit Trimorphic
    int num5 = 1;
    bool result5 = isTrimorphicNumber(num5);
    long long cube5 = (long long) num5 * num5 * num5;
    printf("Number: %d\n", num5);
    printf("Cube: %lld\n", cube5);
    printf("Is Trimorphic number: %s\n\n", result5 ? "true" : "false");
    
    // Test Case 6 - Find Trimorphic numbers in range
    int start = 1;
    int end = 100;
    int trimorphicNums[20];
    int count = getTrimorphicNumbersInRange(start, end, trimorphicNums, 20);
    printf("Trimorphic numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", trimorphicNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    // Test Case 7 - Trimorphic number 49
    int num7 = 49;
    bool result7 = isTrimorphicNumber(num7);
    long long cube7 = (long long) num7 * num7 * num7;
    long long lastDigits7 = getCubeLastDigits(num7, countDigits(num7));
    printf("Number: %d\n", num7);
    printf("Cube: %lld\n", cube7);
    printf("Last digits of cube: %lld\n", lastDigits7);
    printf("Is Trimorphic number: %s\n", result7 ? "true" : "false");
    
    return 0;
}
