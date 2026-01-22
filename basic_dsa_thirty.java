/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty {
    
    // Problem 1: Check if a Number is Ugly Number
    // An Ugly number is a number whose only prime factors are 2, 3, or 5
    // Example: 6 = 2 × 3 (ugly), 8 = 2 × 2 × 2 (ugly), 14 = 2 × 7 (not ugly, has factor 7)
    
    /**
     * Check if a number is Ugly number
     * An Ugly number has only prime factors 2, 3, or 5
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isUglyNumber(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true; // 1 is considered ugly
        }
        
        // Remove all factors of 2, 3, and 5
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        
        // If after removing 2, 3, 5 factors, we get 1, it's ugly
        return n == 1;
    }
    
    /**
     * Get prime factors of a number (only 2, 3, 5 if ugly)
     * Returns list of factors or null if has other factors
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static ArrayList<Integer> getUglyFactors(int n) {
        if (n <= 0) {
            return null;
        }
        
        ArrayList<Integer> factors = new ArrayList<>();
        int num = n;
        
        // Check factors of 2, 3, 5
        int[] primes = {2, 3, 5};
        for (int prime : primes) {
            while (num % prime == 0) {
                factors.add(prime);
                num /= prime;
            }
        }
        
        return num == 1 ? factors : null;
    }
    
    /**
     * Find all Ugly numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Ugly numbers
     */
    public static ArrayList<Integer> getUglyNumbersInRange(int start, int end) {
        ArrayList<Integer> uglyNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isUglyNumber(num)) {
                uglyNumbers.add(num);
            }
        }
        
        return uglyNumbers;
    }
    
    // Problem 2: Find Sum of First N Odd Numbers
    // Sum of first n odd numbers = n²
    // Example: 1 + 3 + 5 + 7 = 16 = 4²
    
    /**
     * Find sum of first n odd numbers using iteration
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long sumOfOddNumbersIterative(int n) {
        if (n <= 0) {
            return 0;
        }
        
        long total = 0;
        int odd = 1;
        
        for (int i = 0; i < n; i++) {
            total += odd;
            odd += 2;
        }
        
        return total;
    }
    
    /**
     * Find sum of first n odd numbers using formula
     * Sum = n²
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static long sumOfOddNumbersFormula(int n) {
        if (n <= 0) {
            return 0;
        }
        return (long) n * n;
    }
    
    /**
     * Find sum of first n odd numbers using recursion
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static long sumOfOddNumbersRecursive(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        // nth odd number = 2n - 1
        int nthOdd = 2 * n - 1;
        return nthOdd + sumOfOddNumbersRecursive(n - 1);
    }
    
    /**
     * Get list of first n odd numbers
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static ArrayList<Integer> getFirstNOddNumbers(int n) {
        ArrayList<Integer> oddNumbers = new ArrayList<>();
        if (n <= 0) {
            return oddNumbers;
        }
        
        int odd = 1;
        for (int i = 0; i < n; i++) {
            oddNumbers.add(odd);
            odd += 2;
        }
        
        return oddNumbers;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Ugly Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Ugly number 6
        int num1 = 6;
        boolean result1 = isUglyNumber(num1);
        ArrayList<Integer> factors1 = getUglyFactors(num1);
        System.out.println("Number: " + num1);
        if (factors1 != null) {
            System.out.println("Prime factors: " + factors1);
        }
        System.out.println("Is Ugly number: " + result1);
        
        // Test Case 2 - Ugly number 8
        int num2 = 8;
        boolean result2 = isUglyNumber(num2);
        ArrayList<Integer> factors2 = getUglyFactors(num2);
        System.out.println("\nNumber: " + num2);
        if (factors2 != null) {
            System.out.println("Prime factors: " + factors2);
        }
        System.out.println("Is Ugly number: " + result2);
        
        // Test Case 3 - Not Ugly number 14
        int num3 = 14;
        boolean result3 = isUglyNumber(num3);
        ArrayList<Integer> factors3 = getUglyFactors(num3);
        System.out.println("\nNumber: " + num3);
        if (factors3 != null) {
            System.out.println("Prime factors: " + factors3);
        } else {
            System.out.println("Has prime factors other than 2, 3, 5");
        }
        System.out.println("Is Ugly number: " + result3);
        
        // Test Case 4 - Ugly number 1
        int num4 = 1;
        boolean result4 = isUglyNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Ugly number: " + result4);
        
        // Test Case 5 - Find Ugly numbers in range
        int start = 1;
        int end = 30;
        ArrayList<Integer> uglyNums = getUglyNumbersInRange(start, end);
        System.out.println("\nUgly numbers in range [" + start + ", " + end + "]:");
        System.out.println(uglyNums);
        System.out.println("Count: " + uglyNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find Sum of First N Odd Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Sum of first 4 odd numbers
        int n1 = 4;
        long result1_sum = sumOfOddNumbersIterative(n1);
        long result1_formula = sumOfOddNumbersFormula(n1);
        long result1_rec = sumOfOddNumbersRecursive(n1);
        ArrayList<Integer> oddNums1 = getFirstNOddNumbers(n1);
        System.out.println("n = " + n1);
        System.out.println("First " + n1 + " odd numbers: " + oddNums1);
        System.out.println("Sum (iterative): " + result1_sum);
        System.out.println("Sum (formula): " + result1_formula);
        System.out.println("Sum (recursive): " + result1_rec);
        System.out.println("Verification: " + n1 + "² = " + (n1 * n1));
        
        // Test Case 2 - Sum of first 10 odd numbers
        int n2 = 10;
        long result2_sum = sumOfOddNumbersFormula(n2);
        ArrayList<Integer> oddNums2 = getFirstNOddNumbers(n2);
        System.out.println("\nn = " + n2);
        System.out.println("First " + n2 + " odd numbers: " + oddNums2);
        System.out.println("Sum: " + result2_sum);
        System.out.println("Verification: " + n2 + "² = " + (n2 * n2));
        
        // Test Case 3 - Sum of first 1 odd number
        int n3 = 1;
        long result3_sum = sumOfOddNumbersFormula(n3);
        System.out.println("\nn = " + n3);
        System.out.println("Sum: " + result3_sum);
        
        // Test Case 4 - Sum of first 5 odd numbers
        int n4 = 5;
        long result4_sum = sumOfOddNumbersFormula(n4);
        ArrayList<Integer> oddNums4 = getFirstNOddNumbers(n4);
        System.out.println("\nn = " + n4);
        System.out.println("First " + n4 + " odd numbers: " + oddNums4);
        System.out.println("Sum: " + result4_sum);
        
        // Test Case 5 - Large n
        int n5 = 20;
        long result5_sum = sumOfOddNumbersFormula(n5);
        System.out.println("\nn = " + n5);
        System.out.println("Sum of first " + n5 + " odd numbers: " + result5_sum);
        System.out.println("Verification: " + n5 + "² = " + ((long) n5 * n5));
    }
}
