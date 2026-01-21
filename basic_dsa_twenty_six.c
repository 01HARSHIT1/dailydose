#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Evil Number
// An Evil number is a number that has an even number of 1s in its binary representation
// Example: 3 in binary is 11 (has 2 ones, which is even), so 3 is Evil

/**
 * Count number of 1s in binary representation
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int countOnesInBinary(int n) {
    int count = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }
    
    return count;
}

/**
 * Check if a number is Evil number (even number of 1s in binary)
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isEvilNumber(int n) {
    int onesCount = countOnesInBinary(n < 0 ? -n : n);
    return onesCount % 2 == 0;
}

/**
 * Check if a number is Evil number using bitwise operations
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isEvilNumberBitwise(int n) {
    int num = n < 0 ? -n : n;
    int count = 0;
    
    while (num > 0) {
        count += num & 1; // Check if last bit is 1
        num >>= 1; // Right shift
    }
    
    return count % 2 == 0;
}

/**
 * Find all Evil numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Evil numbers
 */
int getEvilNumbersInRange(int start, int end, int* evilNumbers, int maxSize) {
    if (evilNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isEvilNumber(num)) {
            evilNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Calculate Simple Interest
// Simple Interest = (Principal × Rate × Time) / 100

/**
 * Calculate simple interest
 * Simple Interest = (Principal × Rate × Time) / 100
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculateSimpleInterest(double principal, double rate, double time) {
    if (principal < 0 || rate < 0 || time < 0) {
        printf("Error: Principal, rate, and time must be non-negative\n");
        return -1;
    }
    
    return (principal * rate * time) / 100.0;
}

/**
 * Calculate total amount with simple interest
 * Amount = Principal + Simple Interest
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculateAmountSimpleInterest(double principal, double rate, double time) {
    double interest = calculateSimpleInterest(principal, rate, time);
    return principal + interest;
}

/**
 * Calculate principal from simple interest
 * Principal = (Interest × 100) / (Rate × Time)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculatePrincipalFromInterest(double interest, double rate, double time) {
    if (rate == 0 || time == 0) {
        printf("Error: Rate and time cannot be zero\n");
        return -1;
    }
    
    if (interest < 0 || rate < 0 || time < 0) {
        printf("Error: Interest, rate, and time must be non-negative\n");
        return -1;
    }
    
    return (interest * 100.0) / (rate * time);
}

/**
 * Calculate time from simple interest
 * Time = (Interest × 100) / (Principal × Rate)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculateTimeFromInterest(double principal, double interest, double rate) {
    if (principal == 0 || rate == 0) {
        printf("Error: Principal and rate cannot be zero\n");
        return -1;
    }
    
    if (principal < 0 || interest < 0 || rate < 0) {
        printf("Error: Principal, interest, and rate must be non-negative\n");
        return -1;
    }
    
    return (interest * 100.0) / (principal * rate);
}

// Helper function to convert integer to binary string
void intToBinary(int n, char* binary) {
    if (n == 0) {
        strcpy(binary, "0");
        return;
    }
    
    char temp[33];
    int temp_index = 0;
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        temp[temp_index++] = (num % 2) + '0';
        num /= 2;
    }
    
    int index = 0;
    for (int i = temp_index - 1; i >= 0; i--) {
        binary[index++] = temp[i];
    }
    binary[index] = '\0';
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Check if a Number is Evil Number\n");
    printf("============================================================\n");
    
    char binary[34];
    
    // Test Case 1 - Evil number 3
    int num1 = 3;
    bool result1 = isEvilNumber(num1);
    bool result1_bitwise = isEvilNumberBitwise(num1);
    intToBinary(num1, binary);
    int ones1 = countOnesInBinary(num1);
    printf("Number: %d\n", num1);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones1);
    printf("Is Evil number: %s\n", result1 ? "true" : "false");
    printf("Is Evil number (bitwise): %s\n\n", result1_bitwise ? "true" : "false");
    
    // Test Case 2 - Not Evil number 5
    int num2 = 5;
    bool result2 = isEvilNumber(num2);
    intToBinary(num2, binary);
    int ones2 = countOnesInBinary(num2);
    printf("Number: %d\n", num2);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones2);
    printf("Is Evil number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Evil number 9
    int num3 = 9;
    bool result3 = isEvilNumber(num3);
    intToBinary(num3, binary);
    int ones3 = countOnesInBinary(num3);
    printf("Number: %d\n", num3);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones3);
    printf("Is Evil number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Zero
    int num4 = 0;
    bool result4 = isEvilNumber(num4);
    intToBinary(num4, binary);
    int ones4 = countOnesInBinary(num4);
    printf("Number: %d\n", num4);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones4);
    printf("Is Evil number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Evil numbers in range
    int start = 1;
    int end = 20;
    int evilNums[50];
    int count = getEvilNumbersInRange(start, end, evilNums, 50);
    printf("Evil numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", evilNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Calculate Simple Interest\n");
    printf("============================================================\n");
    
    // Test Case 1 - Basic simple interest
    double principal1 = 10000;
    double rate1 = 5;
    double time1 = 2;
    double interest1 = calculateSimpleInterest(principal1, rate1, time1);
    double amount1 = calculateAmountSimpleInterest(principal1, rate1, time1);
    printf("Principal: ₹%.2f\n", principal1);
    printf("Rate: %.2f%% per annum\n", rate1);
    printf("Time: %.2f years\n", time1);
    printf("Simple Interest: ₹%.2f\n", interest1);
    printf("Total Amount: ₹%.2f\n\n", amount1);
    
    // Test Case 2 - Different values
    double principal2 = 5000;
    double rate2 = 7.5;
    double time2 = 3;
    double interest2 = calculateSimpleInterest(principal2, rate2, time2);
    double amount2 = calculateAmountSimpleInterest(principal2, rate2, time2);
    printf("Principal: ₹%.2f\n", principal2);
    printf("Rate: %.2f%% per annum\n", rate2);
    printf("Time: %.2f years\n", time2);
    printf("Simple Interest: ₹%.2f\n", interest2);
    printf("Total Amount: ₹%.2f\n\n", amount2);
    
    // Test Case 3 - Calculate principal from interest
    double interest3 = 500;
    double rate3 = 5;
    double time3 = 2;
    double principal3 = calculatePrincipalFromInterest(interest3, rate3, time3);
    printf("Interest: ₹%.2f\n", interest3);
    printf("Rate: %.2f%% per annum\n", rate3);
    printf("Time: %.2f years\n", time3);
    printf("Principal: ₹%.2f\n\n", principal3);
    
    // Test Case 4 - Calculate time from interest
    double principal4 = 10000;
    double interest4 = 1500;
    double rate4 = 5;
    double time4 = calculateTimeFromInterest(principal4, interest4, rate4);
    printf("Principal: ₹%.2f\n", principal4);
    printf("Interest: ₹%.2f\n", interest4);
    printf("Rate: %.2f%% per annum\n", rate4);
    printf("Time: %.2f years\n\n", time4);
    
    // Test Case 5 - Zero interest
    double principal5 = 10000;
    double rate5 = 0;
    double time5 = 5;
    double interest5 = calculateSimpleInterest(principal5, rate5, time5);
    printf("Principal: ₹%.2f\n", principal5);
    printf("Rate: %.2f%% per annum\n", rate5);
    printf("Time: %.2f years\n", time5);
    printf("Simple Interest: ₹%.2f\n", interest5);
    
    return 0;
}
