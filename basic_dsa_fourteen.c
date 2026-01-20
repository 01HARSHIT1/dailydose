#include <stdio.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */

// Problem 1: Find Largest of Three Numbers
// Find the largest among three numbers

/**
 * Find largest of three numbers using if-else
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int findLargestThree(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

/**
 * Find largest of three numbers using ternary operator
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int findLargestThreeTernary(int a, int b, int c) {
    return (a >= b && a >= c) ? a : (b >= c ? b : c);
}

// Problem 2: Check if a Year is a Leap Year
// Determine whether a given year is a leap year

/**
 * Check if a year is a leap year
 * Leap year rules:
 * - Divisible by 4
 * - But not divisible by 100 (unless divisible by 400)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * Check if a year is a leap year (compact version)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool isLeapYearCompact(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Test cases
int main() {
    printf("============================================================\n");
    printf("Problem 1: Find Largest of Three Numbers\n");
    printf("============================================================\n");
    
    // Test Case 1
    int a1 = 10, b1 = 20, c1 = 15;
    int largest1 = findLargestThree(a1, b1, c1);
    int largest1b = findLargestThreeTernary(a1, b1, c1);
    printf("Numbers: %d, %d, %d\n", a1, b1, c1);
    printf("Largest (If-else): %d\n", largest1);
    printf("Largest (Ternary): %d\n\n", largest1b);
    
    // Test Case 2 - All same
    int a2 = 5, b2 = 5, c2 = 5;
    int largest2 = findLargestThree(a2, b2, c2);
    printf("Numbers: %d, %d, %d\n", a2, b2, c2);
    printf("Largest: %d\n\n", largest2);
    
    // Test Case 3 - First is largest
    int a3 = 30, b3 = 10, c3 = 20;
    int largest3 = findLargestThree(a3, b3, c3);
    printf("Numbers: %d, %d, %d\n", a3, b3, c3);
    printf("Largest: %d\n\n", largest3);
    
    // Test Case 4 - Second is largest
    int a4 = 10, b4 = 30, c4 = 20;
    int largest4 = findLargestThree(a4, b4, c4);
    printf("Numbers: %d, %d, %d\n", a4, b4, c4);
    printf("Largest: %d\n\n", largest4);
    
    // Test Case 5 - Negative numbers
    int a5 = -5, b5 = -10, c5 = -3;
    int largest5 = findLargestThree(a5, b5, c5);
    printf("Numbers: %d, %d, %d\n", a5, b5, c5);
    printf("Largest: %d\n\n", largest5);
    
    printf("============================================================\n");
    printf("Problem 2: Check if a Year is a Leap Year\n");
    printf("============================================================\n");
    
    // Test Case 1 - Regular leap year
    int year1 = 2020;
    bool result1 = isLeapYear(year1);
    bool result1b = isLeapYearCompact(year1);
    printf("Year: %d\n", year1);
    printf("Is Leap Year (Method 1): %s\n", result1 ? "true" : "false");
    printf("Is Leap Year (Compact): %s\n\n", result1b ? "true" : "false");
    
    // Test Case 2 - Not a leap year
    int year2 = 2021;
    bool result2 = isLeapYear(year2);
    bool result2b = isLeapYearCompact(year2);
    printf("Year: %d\n", year2);
    printf("Is Leap Year (Method 1): %s\n", result2 ? "true" : "false");
    printf("Is Leap Year (Compact): %s\n\n", result2b ? "true" : "false");
    
    // Test Case 3 - Century year (not leap)
    int year3 = 1900;
    bool result3 = isLeapYear(year3);
    bool result3b = isLeapYearCompact(year3);
    printf("Year: %d\n", year3);
    printf("Is Leap Year (Method 1): %s\n", result3 ? "true" : "false");
    printf("Is Leap Year (Compact): %s\n\n", result3b ? "true" : "false");
    
    // Test Case 4 - Century year (leap - divisible by 400)
    int year4 = 2000;
    bool result4 = isLeapYear(year4);
    bool result4b = isLeapYearCompact(year4);
    printf("Year: %d\n", year4);
    printf("Is Leap Year (Method 1): %s\n", result4 ? "true" : "false");
    printf("Is Leap Year (Compact): %s\n\n", result4b ? "true" : "false");
    
    // Test Case 5 - Another leap year
    int year5 = 2024;
    bool result5 = isLeapYear(year5);
    bool result5b = isLeapYearCompact(year5);
    printf("Year: %d\n", year5);
    printf("Is Leap Year (Method 1): %s\n", result5 ? "true" : "false");
    printf("Is Leap Year (Compact): %s\n\n", result5b ? "true" : "false");
    
    // Test Case 6 - Non-leap century
    int year6 = 2100;
    bool result6 = isLeapYear(year6);
    bool result6b = isLeapYearCompact(year6);
    printf("Year: %d\n", year6);
    printf("Is Leap Year (Method 1): %s\n", result6 ? "true" : "false");
    printf("Is Leap Year (Compact): %s\n\n", result6b ? "true" : "false");
    
    return 0;
}
