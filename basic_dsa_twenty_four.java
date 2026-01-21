/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_four {
    
    // Problem 1: Check if a Number is Duck Number
    // A Duck number is a number that contains at least one zero, but should not start with zero
    // Example: 102, 1020 are Duck numbers, but 012, 0123 are not
    
    /**
     * Check if a number is Duck number
     * A Duck number contains at least one zero but doesn't start with zero
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isDuckNumber(int n) {
        if (n <= 0) {
            return false;
        }
        
        String numStr = String.valueOf(n);
        
        // Check if it starts with zero
        if (numStr.charAt(0) == '0') {
            return false;
        }
        
        // Check if it contains at least one zero
        return numStr.contains("0");
    }
    
    /**
     * Check if a number is Duck number using iterative approach
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isDuckNumberIterative(int n) {
        if (n <= 0) {
            return false;
        }
        
        boolean hasZero = false;
        
        while (n > 0) {
            int digit = n % 10;
            if (digit == 0) {
                hasZero = true;
            }
            n /= 10;
        }
        
        // For integers, they can't start with zero by definition
        // So we just check if there's a zero somewhere
        return hasZero;
    }
    
    /**
     * Find all Duck numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Duck numbers
     */
    public static ArrayList<Integer> getDuckNumbersInRange(int start, int end) {
        ArrayList<Integer> duckNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isDuckNumber(num)) {
                duckNumbers.add(num);
            }
        }
        
        return duckNumbers;
    }
    
    // Problem 2: Check if a Number is Neon Number
    // A Neon number is a number where the sum of digits of the square of the number equals the number itself
    // Example: 9² = 81, and 8 + 1 = 9, so 9 is a Neon number
    
    /**
     * Calculate sum of digits of a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int sumOfDigits(int n) {
        int total = 0;
        int num = Math.abs(n);
        
        while (num > 0) {
            total += num % 10;
            num /= 10;
        }
        
        return total;
    }
    
    /**
     * Check if a number is Neon number
     * Sum of digits of square equals the number itself
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isNeonNumber(int n) {
        if (n < 0) {
            return false;
        }
        
        long square = (long) n * n;
        int sumOfSquareDigits = sumOfDigits((int) square);
        
        return sumOfSquareDigits == n;
    }
    
    /**
     * Find all Neon numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Neon numbers
     */
    public static ArrayList<Integer> getNeonNumbersInRange(int start, int end) {
        ArrayList<Integer> neonNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isNeonNumber(num)) {
                neonNumbers.add(num);
            }
        }
        
        return neonNumbers;
    }
    
    /**
     * Get the sum of digits of square of a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int getSquareDigitsSum(int n) {
        long square = (long) n * n;
        return sumOfDigits((int) square);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Duck Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Duck number 102
        int num1 = 102;
        boolean result1 = isDuckNumber(num1);
        boolean result1_iter = isDuckNumberIterative(num1);
        System.out.println("Number: " + num1);
        System.out.println("Is Duck number: " + result1);
        System.out.println("Is Duck number (iterative): " + result1_iter);
        
        // Test Case 2 - Duck number 1020
        int num2 = 1020;
        boolean result2 = isDuckNumber(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Is Duck number: " + result2);
        
        // Test Case 3 - Not Duck number (no zero)
        int num3 = 123;
        boolean result3 = isDuckNumber(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Is Duck number: " + result3);
        
        // Test Case 4 - Single digit (not Duck as no zero)
        int num4 = 5;
        boolean result4 = isDuckNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Duck number: " + result4);
        
        // Test Case 5 - Find Duck numbers in range
        int start = 100;
        int end = 200;
        ArrayList<Integer> duckNums = getDuckNumbersInRange(start, end);
        System.out.println("\nDuck numbers in range [" + start + ", " + end + "] (first 15):");
        for (int i = 0; i < Math.min(15, duckNums.size()); i++) {
            System.out.print(duckNums.get(i) + " ");
        }
        System.out.println("\nTotal count: " + duckNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Number is Neon Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Neon number 9
        int num1_neon = 9;
        boolean result1_neon = isNeonNumber(num1_neon);
        long square1 = (long) num1_neon * num1_neon;
        int sum1 = getSquareDigitsSum(num1_neon);
        System.out.println("Number: " + num1_neon);
        System.out.println("Square: " + square1);
        System.out.println("Sum of digits of square: " + sum1);
        System.out.println("Is Neon number: " + result1_neon);
        
        // Test Case 2 - Not Neon number
        int num2_neon = 12;
        boolean result2_neon = isNeonNumber(num2_neon);
        long square2 = (long) num2_neon * num2_neon;
        int sum2 = getSquareDigitsSum(num2_neon);
        System.out.println("\nNumber: " + num2_neon);
        System.out.println("Square: " + square2);
        System.out.println("Sum of digits of square: " + sum2);
        System.out.println("Is Neon number: " + result2_neon);
        
        // Test Case 3 - Single digit Neon
        int num3_neon = 1;
        boolean result3_neon = isNeonNumber(num3_neon);
        long square3 = (long) num3_neon * num3_neon;
        int sum3 = getSquareDigitsSum(num3_neon);
        System.out.println("\nNumber: " + num3_neon);
        System.out.println("Square: " + square3);
        System.out.println("Sum of digits of square: " + sum3);
        System.out.println("Is Neon number: " + result3_neon);
        
        // Test Case 4 - Zero
        int num4_neon = 0;
        boolean result4_neon = isNeonNumber(num4_neon);
        System.out.println("\nNumber: " + num4_neon);
        System.out.println("Is Neon number: " + result4_neon);
        
        // Test Case 5 - Find Neon numbers in range
        int start_neon = 0;
        int end_neon = 1000;
        ArrayList<Integer> neonNums = getNeonNumbersInRange(start_neon, end_neon);
        System.out.println("\nNeon numbers in range [" + start_neon + ", " + end_neon + "]:");
        System.out.println(neonNums);
        System.out.println("Count: " + neonNums.size());
    }
}
