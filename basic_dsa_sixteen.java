/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_sixteen {
    
    // Problem 1: Check if a Number is Perfect Number
    // A perfect number is a positive integer that is equal to the sum of its proper divisors
    // Example: 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14
    
    /**
     * Check if a number is perfect number
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isPerfectNumber(int n) {
        if (n <= 1) {
            return false;
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
        
        return sumDivisors == n;
    }
    
    /**
     * Get all proper divisors of a number (excluding the number itself)
     * Time Complexity: O(√n)
     * Space Complexity: O(√n)
     */
    public static ArrayList<Integer> getProperDivisors(int n) {
        ArrayList<Integer> divisors = new ArrayList<>();
        if (n <= 1) {
            return divisors;
        }
        
        divisors.add(1);
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i) {
                    divisors.add(n / i);
                }
            }
        }
        
        Collections.sort(divisors);
        return divisors;
    }
    
    // Problem 2: Find Sum of Squares of First N Natural Numbers
    // Calculate 1² + 2² + 3² + ... + N²
    
    /**
     * Find sum of squares using iteration
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long sumOfSquaresIterative(int n) {
        if (n <= 0) {
            return 0;
        }
        
        long total = 0;
        for (int i = 1; i <= n; i++) {
            total += i * i;
        }
        return total;
    }
    
    /**
     * Find sum of squares using mathematical formula: n(n+1)(2n+1)/6
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static long sumOfSquaresFormula(int n) {
        if (n <= 0) {
            return 0;
        }
        return (long) n * (n + 1) * (2 * n + 1) / 6;
    }
    
    /**
     * Find sum of squares using recursion
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static long sumOfSquaresRecursive(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return (long) n * n + sumOfSquaresRecursive(n - 1);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Perfect Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Perfect number 6
        int num1 = 6;
        boolean result1 = isPerfectNumber(num1);
        ArrayList<Integer> divisors1 = getProperDivisors(num1);
        int sum1 = divisors1.stream().mapToInt(Integer::intValue).sum();
        System.out.println("Number: " + num1);
        System.out.println("Proper divisors: " + divisors1);
        System.out.println("Sum of divisors: " + sum1);
        System.out.println("Is perfect number: " + result1);
        
        // Test Case 2 - Perfect number 28
        int num2 = 28;
        boolean result2 = isPerfectNumber(num2);
        ArrayList<Integer> divisors2 = getProperDivisors(num2);
        int sum2 = divisors2.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num2);
        System.out.println("Proper divisors: " + divisors2);
        System.out.println("Sum of divisors: " + sum2);
        System.out.println("Is perfect number: " + result2);
        
        // Test Case 3 - Not perfect number
        int num3 = 10;
        boolean result3 = isPerfectNumber(num3);
        ArrayList<Integer> divisors3 = getProperDivisors(num3);
        int sum3 = divisors3.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num3);
        System.out.println("Proper divisors: " + divisors3);
        System.out.println("Sum of divisors: " + sum3);
        System.out.println("Is perfect number: " + result3);
        
        // Test Case 4 - Perfect number 496
        int num4 = 496;
        boolean result4 = isPerfectNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is perfect number: " + result4);
        
        // Test Case 5 - Not perfect number
        int num5 = 1;
        boolean result5 = isPerfectNumber(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Is perfect number: " + result5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find Sum of Squares of First N Natural Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int n1 = 5;
        long result1_iter = sumOfSquaresIterative(n1);
        long result1_formula = sumOfSquaresFormula(n1);
        long result1_rec = sumOfSquaresRecursive(n1);
        System.out.println("N = " + n1);
        System.out.println("1² + 2² + 3² + 4² + 5² = " + result1_iter);
        System.out.println("Iterative method: " + result1_iter);
        System.out.println("Formula method: " + result1_formula);
        System.out.println("Recursive method: " + result1_rec);
        
        // Test Case 2
        int n2 = 10;
        long result2_sq = sumOfSquaresFormula(n2);
        System.out.println("\nN = " + n2);
        System.out.println("Sum of squares: " + result2_sq);
        
        // Test Case 3
        int n3 = 1;
        long result3_sq = sumOfSquaresFormula(n3);
        System.out.println("\nN = " + n3);
        System.out.println("Sum of squares: " + result3_sq);
        
        // Test Case 4
        int n4 = 20;
        long result4_sq = sumOfSquaresFormula(n4);
        System.out.println("\nN = " + n4);
        System.out.println("Sum of squares: " + result4_sq);
        
        // Test Case 5 - Large number
        int n5 = 100;
        long result5_sq = sumOfSquaresFormula(n5);
        System.out.println("\nN = " + n5);
        System.out.println("Sum of squares: " + result5_sq);
    }
}
