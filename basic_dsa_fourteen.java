/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_fourteen {
    
    // Problem 1: Find Largest of Three Numbers
    // Find the largest among three numbers
    
    /**
     * Find largest of three numbers using if-else
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static int findLargestThree(int a, int b, int c) {
        if (a >= b && a >= c) {
            return a;
        } else if (b >= a && b >= c) {
            return b;
        } else {
            return c;
        }
    }
    
    /**
     * Find largest of three numbers using Math.max
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static int findLargestThreeMax(int a, int b, int c) {
        return Math.max(Math.max(a, b), c);
    }
    
    /**
     * Find largest of three numbers using ternary operator
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static int findLargestThreeTernary(int a, int b, int c) {
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
    public static boolean isLeapYear(int year) {
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
    public static boolean isLeapYearCompact(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Find Largest of Three Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int a1 = 10, b1 = 20, c1 = 15;
        int largest1 = findLargestThree(a1, b1, c1);
        int largest1b = findLargestThreeMax(a1, b1, c1);
        int largest1c = findLargestThreeTernary(a1, b1, c1);
        System.out.println("Numbers: " + a1 + ", " + b1 + ", " + c1);
        System.out.println("Largest (If-else): " + largest1);
        System.out.println("Largest (Math.max): " + largest1b);
        System.out.println("Largest (Ternary): " + largest1c);
        
        // Test Case 2 - All same
        int a2 = 5, b2 = 5, c2 = 5;
        int largest2 = findLargestThree(a2, b2, c2);
        System.out.println("\nNumbers: " + a2 + ", " + b2 + ", " + c2);
        System.out.println("Largest: " + largest2);
        
        // Test Case 3 - First is largest
        int a3 = 30, b3 = 10, c3 = 20;
        int largest3 = findLargestThree(a3, b3, c3);
        System.out.println("\nNumbers: " + a3 + ", " + b3 + ", " + c3);
        System.out.println("Largest: " + largest3);
        
        // Test Case 4 - Second is largest
        int a4 = 10, b4 = 30, c4 = 20;
        int largest4 = findLargestThree(a4, b4, c4);
        System.out.println("\nNumbers: " + a4 + ", " + b4 + ", " + c4);
        System.out.println("Largest: " + largest4);
        
        // Test Case 5 - Negative numbers
        int a5 = -5, b5 = -10, c5 = -3;
        int largest5 = findLargestThree(a5, b5, c5);
        System.out.println("\nNumbers: " + a5 + ", " + b5 + ", " + c5);
        System.out.println("Largest: " + largest5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Year is a Leap Year");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Regular leap year
        int year1 = 2020;
        boolean result1 = isLeapYear(year1);
        boolean result1b = isLeapYearCompact(year1);
        System.out.println("Year: " + year1);
        System.out.println("Is Leap Year (Method 1): " + result1);
        System.out.println("Is Leap Year (Compact): " + result1b);
        
        // Test Case 2 - Not a leap year
        int year2 = 2021;
        boolean result2 = isLeapYear(year2);
        boolean result2b = isLeapYearCompact(year2);
        System.out.println("\nYear: " + year2);
        System.out.println("Is Leap Year (Method 1): " + result2);
        System.out.println("Is Leap Year (Compact): " + result2b);
        
        // Test Case 3 - Century year (not leap)
        int year3 = 1900;
        boolean result3 = isLeapYear(year3);
        boolean result3b = isLeapYearCompact(year3);
        System.out.println("\nYear: " + year3);
        System.out.println("Is Leap Year (Method 1): " + result3);
        System.out.println("Is Leap Year (Compact): " + result3b);
        
        // Test Case 4 - Century year (leap - divisible by 400)
        int year4 = 2000;
        boolean result4 = isLeapYear(year4);
        boolean result4b = isLeapYearCompact(year4);
        System.out.println("\nYear: " + year4);
        System.out.println("Is Leap Year (Method 1): " + result4);
        System.out.println("Is Leap Year (Compact): " + result4b);
        
        // Test Case 5 - Another leap year
        int year5 = 2024;
        boolean result5 = isLeapYear(year5);
        boolean result5b = isLeapYearCompact(year5);
        System.out.println("\nYear: " + year5);
        System.out.println("Is Leap Year (Method 1): " + result5);
        System.out.println("Is Leap Year (Compact): " + result5b);
        
        // Test Case 6 - Non-leap century
        int year6 = 2100;
        boolean result6 = isLeapYear(year6);
        boolean result6b = isLeapYearCompact(year6);
        System.out.println("\nYear: " + year6);
        System.out.println("Is Leap Year (Method 1): " + result6);
        System.out.println("Is Leap Year (Compact): " + result6b);
    }
}
