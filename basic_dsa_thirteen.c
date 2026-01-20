#include <stdio.h>
#include <stdbool.h>

/**
 * Basic DSA Problems - Two Fundamental Questions
 */

// Problem 1: Find Largest of Three Numbers
// Return the largest among a, b, c
/**
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int largestOfThree(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

// Problem 2: Check if a Year is a Leap Year
// Leap year rules:
// - divisible by 400 => leap
// - divisible by 100 => not leap
// - divisible by 4 => leap
/**
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return (year % 4 == 0);
}

int main() {
    printf("Problem 1 - Largest of Three Numbers:\n");
    printf("%d\n", largestOfThree(10, 20, 5));   // 20
    printf("%d\n", largestOfThree(-1, -5, -3));  // -1
    printf("%d\n", largestOfThree(7, 7, 2));     // 7

    printf("\nProblem 2 - Leap Year Check:\n");
    int years[] = {1900, 2000, 2024, 2023};
    int n = (int)(sizeof(years) / sizeof(years[0]));
    for (int i = 0; i < n; i++) {
        printf("%d => %s\n", years[i], isLeapYear(years[i]) ? "true" : "false");
    }

    return 0;
}

