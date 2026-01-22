/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_nine {
    
    // Problem 1: Check if a Number is Happy Number
    // A happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
    // Example: 19 is happy: 1² + 9² = 82, 8² + 2² = 68, 6² + 8² = 100, 1² + 0² + 0² = 1
    
    /**
     * Calculate sum of squares of digits
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int sumOfSquaresOfDigits(int n) {
        int total = 0;
        int num = Math.abs(n);
        
        while (num > 0) {
            int digit = num % 10;
            total += digit * digit;
            num /= 10;
        }
        
        return total;
    }
    
    /**
     * Check if a number is Happy number
     * Time Complexity: O(k) where k is the cycle length
     * Space Complexity: O(k)
     */
    public static boolean isHappyNumber(int n) {
        if (n <= 0) {
            return false;
        }
        
        Set<Integer> seen = new HashSet<>();
        int current = n;
        
        while (current != 1 && !seen.contains(current)) {
            seen.add(current);
            current = sumOfSquaresOfDigits(current);
        }
        
        return current == 1;
    }
    
    /**
     * Get the sequence of numbers until it reaches 1 or detects a cycle
     * Time Complexity: O(k) where k is the length of sequence
     * Space Complexity: O(k)
     */
    public static ArrayList<Integer> getHappySequence(int n) {
        ArrayList<Integer> sequence = new ArrayList<>();
        if (n <= 0) {
            return sequence;
        }
        
        Set<Integer> seen = new HashSet<>();
        int current = n;
        
        while (current != 1 && !seen.contains(current)) {
            sequence.add(current);
            seen.add(current);
            current = sumOfSquaresOfDigits(current);
        }
        sequence.add(current);
        
        return sequence;
    }
    
    /**
     * Find all Happy numbers in a given range
     * Time Complexity: O((end - start) * k)
     * Space Complexity: O(m) where m is the number of Happy numbers
     */
    public static ArrayList<Integer> getHappyNumbersInRange(int start, int end) {
        ArrayList<Integer> happyNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isHappyNumber(num)) {
                happyNumbers.add(num);
            }
        }
        
        return happyNumbers;
    }
    
    // Problem 2: Find nth Fibonacci Number
    // Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
    // F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
    
    /**
     * Find nth Fibonacci number using iteration
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long nthFibonacciIterative(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        if (n <= 1) {
            return n;
        }
        
        long a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            long temp = a + b;
            a = b;
            b = temp;
        }
        
        return b;
    }
    
    /**
     * Find nth Fibonacci number using recursion
     * Time Complexity: O(2^n) - exponential
     * Space Complexity: O(n) due to recursion stack
     */
    public static long nthFibonacciRecursive(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        if (n <= 1) {
            return n;
        }
        
        return nthFibonacciRecursive(n - 1) + nthFibonacciRecursive(n - 2);
    }
    
    /**
     * Find nth Fibonacci number using memoization (top-down DP)
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static long nthFibonacciMemoization(int n, Map<Integer, Long> memo) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        if (n <= 1) {
            return n;
        }
        
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        
        long result = nthFibonacciMemoization(n - 1, memo) + nthFibonacciMemoization(n - 2, memo);
        memo.put(n, result);
        return result;
    }
    
    public static long nthFibonacciMemoization(int n) {
        return nthFibonacciMemoization(n, new HashMap<>());
    }
    
    /**
     * Find nth Fibonacci number using Binet's formula
     * Time Complexity: O(1) (but limited by floating point precision)
     * Space Complexity: O(1)
     */
    public static long nthFibonacciFormula(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        if (n <= 1) {
            return n;
        }
        
        double sqrt5 = Math.sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        
        return Math.round((Math.pow(phi, n) - Math.pow(psi, n)) / sqrt5);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Happy Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Happy number 19
        int num1 = 19;
        boolean result1 = isHappyNumber(num1);
        ArrayList<Integer> sequence1 = getHappySequence(num1);
        System.out.println("Number: " + num1);
        System.out.println("Sequence: " + sequence1);
        System.out.println("Is Happy number: " + result1);
        
        // Test Case 2 - Happy number 7
        int num2 = 7;
        boolean result2 = isHappyNumber(num2);
        ArrayList<Integer> sequence2 = getHappySequence(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Sequence: " + sequence2);
        System.out.println("Is Happy number: " + result2);
        
        // Test Case 3 - Not Happy number 4
        int num3 = 4;
        boolean result3 = isHappyNumber(num3);
        ArrayList<Integer> sequence3 = getHappySequence(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Sequence: " + sequence3);
        System.out.println("Is Happy number: " + result3);
        
        // Test Case 4 - Single digit happy
        int num4 = 1;
        boolean result4 = isHappyNumber(num4);
        ArrayList<Integer> sequence4 = getHappySequence(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Sequence: " + sequence4);
        System.out.println("Is Happy number: " + result4);
        
        // Test Case 5 - Find Happy numbers in range
        int start = 1;
        int end = 50;
        ArrayList<Integer> happyNums = getHappyNumbersInRange(start, end);
        System.out.println("\nHappy numbers in range [" + start + ", " + end + "]:");
        System.out.println(happyNums);
        System.out.println("Count: " + happyNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find nth Fibonacci Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - 10th Fibonacci number
        int n1 = 10;
        long result1_fib = nthFibonacciIterative(n1);
        long result1_memo = nthFibonacciMemoization(n1);
        long result1_formula = nthFibonacciFormula(n1);
        System.out.println("n = " + n1);
        System.out.println("Fibonacci (iterative): " + result1_fib);
        System.out.println("Fibonacci (memoization): " + result1_memo);
        System.out.println("Fibonacci (formula): " + result1_formula);
        
        // Test Case 2 - 5th Fibonacci number
        int n2 = 5;
        long result2_iter = nthFibonacciIterative(n2);
        long result2_rec = nthFibonacciRecursive(n2);
        System.out.println("\nn = " + n2);
        System.out.println("Fibonacci (iterative): " + result2_iter);
        System.out.println("Fibonacci (recursive): " + result2_rec);
        
        // Test Case 3 - 0th Fibonacci number
        int n3_fib = 0;
        long result3_fib = nthFibonacciIterative(n3_fib);
        System.out.println("\nn = " + n3_fib);
        System.out.println("Fibonacci: " + result3_fib);
        
        // Test Case 4 - 1st Fibonacci number
        int n4 = 1;
        long result4_fib = nthFibonacciIterative(n4);
        System.out.println("\nn = " + n4);
        System.out.println("Fibonacci: " + result4_fib);
        
        // Test Case 5 - Larger Fibonacci number
        int n5 = 20;
        long result5_iter = nthFibonacciIterative(n5);
        long result5_memo = nthFibonacciMemoization(n5);
        System.out.println("\nn = " + n5);
        System.out.println("Fibonacci (iterative): " + result5_iter);
        System.out.println("Fibonacci (memoization): " + result5_memo);
    }
}
