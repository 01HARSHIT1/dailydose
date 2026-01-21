#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Check if a Number is Odious Number
// An Odious number is a number that has an odd number of 1s in its binary representation
// Example: 4 in binary is 100 (has 1 one, which is odd, so it's Odious)

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
 * Check if a number is Odious number (odd number of 1s in binary)
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isOdiousNumber(int n) {
    int onesCount = countOnesInBinary(n < 0 ? -n : n);
    return onesCount % 2 == 1;
}

/**
 * Check if a number is Odious number using bitwise operations
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool isOdiousNumberBitwise(int n) {
    int num = n < 0 ? -n : n;
    int count = 0;
    
    while (num > 0) {
        count += num & 1; // Check if last bit is 1
        num >>= 1; // Right shift
    }
    
    return count % 2 == 1;
}

/**
 * Find all Odious numbers in a given range
 * Stores results in array and returns count
 * Time Complexity: O((end - start) * log n)
 * Space Complexity: O(k) where k is the number of Odious numbers
 */
int getOdiousNumbersInRange(int start, int end, int* odiousNumbers, int maxSize) {
    if (odiousNumbers == NULL || maxSize == 0) {
        return 0;
    }
    
    int count = 0;
    for (int num = start; num <= end && count < maxSize; num++) {
        if (isOdiousNumber(num)) {
            odiousNumbers[count++] = num;
        }
    }
    
    return count;
}

// Problem 2: Calculate Compound Interest
// Compound Interest = Principal × (1 + Rate/100)^Time - Principal
// Amount = Principal × (1 + Rate/100)^Time

/**
 * Calculate compound interest
 * Compound Interest = Principal × (1 + Rate/100)^Time - Principal
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculateCompoundInterest(double principal, double rate, double time) {
    if (principal < 0 || rate < 0 || time < 0) {
        printf("Error: Principal, rate, and time must be non-negative\n");
        return -1;
    }
    
    double amount = principal * pow(1 + rate / 100.0, time);
    return amount - principal;
}

/**
 * Calculate total amount with compound interest
 * Amount = Principal × (1 + Rate/100)^Time
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculateAmountCompoundInterest(double principal, double rate, double time) {
    if (principal < 0 || rate < 0 || time < 0) {
        printf("Error: Principal, rate, and time must be non-negative\n");
        return -1;
    }
    
    return principal * pow(1 + rate / 100.0, time);
}

/**
 * Calculate compound interest compounded n times per year
 * Amount = Principal × (1 + Rate/(100×n))^(n×Time)
 * Stores results in result array [interest, amount]
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void calculateCompoundInterestCompoundedNTimes(double principal, double rate, double time, int n, double* result) {
    if (principal < 0 || rate < 0 || time < 0 || n <= 0) {
        printf("Error: Principal, rate, and time must be non-negative, n must be positive\n");
        result[0] = result[1] = -1;
        return;
    }
    
    double amount = principal * pow(1 + rate / (100.0 * n), n * time);
    double interest = amount - principal;
    result[0] = interest;
    result[1] = amount;
}

/**
 * Calculate principal from compound interest amount
 * Principal = Amount / (1 + Rate/100)^Time
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double calculatePrincipalFromCompoundInterest(double amount, double rate, double time) {
    if (amount < 0 || rate < 0 || time < 0) {
        printf("Error: Amount, rate, and time must be non-negative\n");
        return -1;
    }
    
    if (rate == 0) {
        return amount;
    }
    
    return amount / pow(1 + rate / 100.0, time);
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
    printf("Problem 1: Check if a Number is Odious Number\n");
    printf("============================================================\n");
    
    char binary[34];
    
    // Test Case 1 - Odious number 4
    int num1 = 4;
    bool result1 = isOdiousNumber(num1);
    bool result1_bitwise = isOdiousNumberBitwise(num1);
    intToBinary(num1, binary);
    int ones1 = countOnesInBinary(num1);
    printf("Number: %d\n", num1);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones1);
    printf("Is Odious number: %s\n", result1 ? "true" : "false");
    printf("Is Odious number (bitwise): %s\n\n", result1_bitwise ? "true" : "false");
    
    // Test Case 2 - Not Odious number 3
    int num2 = 3;
    bool result2 = isOdiousNumber(num2);
    intToBinary(num2, binary);
    int ones2 = countOnesInBinary(num2);
    printf("Number: %d\n", num2);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones2);
    printf("Is Odious number: %s\n\n", result2 ? "true" : "false");
    
    // Test Case 3 - Odious number 7
    int num3 = 7;
    bool result3 = isOdiousNumber(num3);
    intToBinary(num3, binary);
    int ones3 = countOnesInBinary(num3);
    printf("Number: %d\n", num3);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones3);
    printf("Is Odious number: %s\n\n", result3 ? "true" : "false");
    
    // Test Case 4 - Zero
    int num4 = 0;
    bool result4 = isOdiousNumber(num4);
    intToBinary(num4, binary);
    int ones4 = countOnesInBinary(num4);
    printf("Number: %d\n", num4);
    printf("Binary: %s\n", binary);
    printf("Number of 1s: %d\n", ones4);
    printf("Is Odious number: %s\n\n", result4 ? "true" : "false");
    
    // Test Case 5 - Find Odious numbers in range
    int start = 1;
    int end = 20;
    int odiousNums[50];
    int count = getOdiousNumbersInRange(start, end, odiousNums, 50);
    printf("Odious numbers in range [%d, %d]:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", odiousNums[i]);
    }
    printf("\nCount: %d\n\n", count);
    
    printf("============================================================\n");
    printf("Problem 2: Calculate Compound Interest\n");
    printf("============================================================\n");
    
    // Test Case 1 - Basic compound interest
    double principal1 = 10000;
    double rate1 = 5;
    double time1 = 2;
    double interest1 = calculateCompoundInterest(principal1, rate1, time1);
    double amount1 = calculateAmountCompoundInterest(principal1, rate1, time1);
    printf("Principal: ₹%.2f\n", principal1);
    printf("Rate: %.2f%% per annum\n", rate1);
    printf("Time: %.2f years\n", time1);
    printf("Compound Interest: ₹%.2f\n", interest1);
    printf("Total Amount: ₹%.2f\n\n", amount1);
    
    // Test Case 2 - Different values
    double principal2 = 5000;
    double rate2 = 7.5;
    double time2 = 3;
    double interest2 = calculateCompoundInterest(principal2, rate2, time2);
    double amount2 = calculateAmountCompoundInterest(principal2, rate2, time2);
    printf("Principal: ₹%.2f\n", principal2);
    printf("Rate: %.2f%% per annum\n", rate2);
    printf("Time: %.2f years\n", time2);
    printf("Compound Interest: ₹%.2f\n", interest2);
    printf("Total Amount: ₹%.2f\n\n", amount2);
    
    // Test Case 3 - Quarterly compounding
    double principal3 = 10000;
    double rate3 = 8;
    double time3 = 2;
    int n3 = 4; // Quarterly
    double result3[2];
    calculateCompoundInterestCompoundedNTimes(principal3, rate3, time3, n3, result3);
    printf("Principal: ₹%.2f\n", principal3);
    printf("Rate: %.2f%% per annum\n", rate3);
    printf("Time: %.2f years\n", time3);
    printf("Compounding: %d times per year (Quarterly)\n", n3);
    printf("Compound Interest: ₹%.2f\n", result3[0]);
    printf("Total Amount: ₹%.2f\n\n", result3[1]);
    
    // Test Case 4 - Calculate principal from amount
    double amount4 = 11025;
    double rate4 = 5;
    double time4 = 2;
    double principal4 = calculatePrincipalFromCompoundInterest(amount4, rate4, time4);
    printf("Amount: ₹%.2f\n", amount4);
    printf("Rate: %.2f%% per annum\n", rate4);
    printf("Time: %.2f years\n", time4);
    printf("Principal: ₹%.2f\n\n", principal4);
    
    // Test Case 5 - Monthly compounding
    double principal5 = 10000;
    double rate5 = 6;
    double time5 = 1;
    int n5 = 12; // Monthly
    double result5[2];
    calculateCompoundInterestCompoundedNTimes(principal5, rate5, time5, n5, result5);
    printf("Principal: ₹%.2f\n", principal5);
    printf("Rate: %.2f%% per annum\n", rate5);
    printf("Time: %.2f year\n", time5);
    printf("Compounding: %d times per year (Monthly)\n", n5);
    printf("Compound Interest: ₹%.2f\n", result5[0]);
    printf("Total Amount: ₹%.2f\n", result5[1]);
    
    return 0;
}
