import java.util.*;

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_six {
    
    // Problem 1: Fibonacci Sequence
    // Generate Fibonacci sequence using both iterative and recursive approaches
    
    /**
     * Generate first n Fibonacci numbers using iterative approach
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static List<Integer> fibonacciIterative(int n) {
        List<Integer> fib = new ArrayList<>();
        if (n <= 0) {
            return fib;
        }
        if (n == 1) {
            fib.add(0);
            return fib;
        }
        if (n == 2) {
            fib.add(0);
            fib.add(1);
            return fib;
        }
        
        fib.add(0);
        fib.add(1);
        for (int i = 2; i < n; i++) {
            fib.add(fib.get(i - 1) + fib.get(i - 2));
        }
        
        return fib;
    }
    
    /**
     * Get nth Fibonacci number using recursive approach
     * Time Complexity: O(2^n) - exponential
     * Space Complexity: O(n) due to recursion stack
     */
    public static Integer fibonacciRecursive(int n) {
        if (n <= 0) {
            return null;
        }
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
    
    /**
     * Get nth Fibonacci number using iterative approach (optimized)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer fibonacciNthIterative(int n) {
        if (n <= 0) {
            return null;
        }
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        
        int a = 0, b = 1;
        for (int i = 2; i < n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        
        return b;
    }
    
    // Problem 2: Check if a Number is Palindrome
    // Determine whether a number reads the same forwards and backwards
    
    /**
     * Check if a number is palindrome
     * Time Complexity: O(log n) where log is base 10
     * Space Complexity: O(1)
     */
    public static boolean isPalindromeNumber(int n) {
        if (n < 0) {
            return false; // Negative numbers are not palindromes
        }
        if (n < 10) {
            return true; // Single digit numbers are palindromes
        }
        
        int original = n;
        int reversedNum = 0;
        
        while (n > 0) {
            reversedNum = reversedNum * 10 + n % 10;
            n /= 10;
        }
        
        return original == reversedNum;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Fibonacci Sequence");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - First 10 Fibonacci numbers
        int n1 = 10;
        List<Integer> fib1 = fibonacciIterative(n1);
        System.out.println("First " + n1 + " Fibonacci numbers (Iterative): " + fib1);
        
        // Test Case 2 - First 5 Fibonacci numbers
        int n2 = 5;
        List<Integer> fib2 = fibonacciIterative(n2);
        System.out.println("\nFirst " + n2 + " Fibonacci numbers (Iterative): " + fib2);
        
        // Test Case 3 - 7th Fibonacci number (iterative optimized)
        int n3 = 7;
        Integer fibNth1 = fibonacciNthIterative(n3);
        System.out.println("\n" + n3 + "th Fibonacci number (Iterative): " + fibNth1);
        
        // Test Case 4 - 7th Fibonacci number (recursive)
        Integer fibNth2 = fibonacciRecursive(n3);
        System.out.println(n3 + "th Fibonacci number (Recursive): " + fibNth2);
        
        // Test Case 5 - Edge cases
        System.out.println("\n1st Fibonacci number: " + fibonacciNthIterative(1));
        System.out.println("2nd Fibonacci number: " + fibonacciNthIterative(2));
        System.out.println("3rd Fibonacci number: " + fibonacciNthIterative(3));
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Number is Palindrome");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Palindrome number
        int num1 = 121;
        boolean result1 = isPalindromeNumber(num1);
        System.out.println("Number: " + num1);
        System.out.println("Is Palindrome: " + result1);
        
        // Test Case 2 - Non-palindrome number
        int num2 = 123;
        boolean result2 = isPalindromeNumber(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Is Palindrome: " + result2);
        
        // Test Case 3 - Single digit
        int num3 = 5;
        boolean result3 = isPalindromeNumber(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Is Palindrome: " + result3);
        
        // Test Case 4 - Palindrome with even digits
        int num4 = 1221;
        boolean result4 = isPalindromeNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Palindrome: " + result4);
        
        // Test Case 5 - Large palindrome
        int num5 = 12321;
        boolean result5 = isPalindromeNumber(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Is Palindrome: " + result5);
        
        // Test Case 6 - Negative number
        int num6 = -121;
        boolean result6 = isPalindromeNumber(num6);
        System.out.println("\nNumber: " + num6);
        System.out.println("Is Palindrome: " + result6);
        
        // Test Case 7 - Number with zeros
        int num7 = 1001;
        boolean result7 = isPalindromeNumber(num7);
        System.out.println("\nNumber: " + num7);
        System.out.println("Is Palindrome: " + result7);
        
        // Test Case 8 - Non-palindrome
        int num8 = 12345;
        boolean result8 = isPalindromeNumber(num8);
        System.out.println("\nNumber: " + num8);
        System.out.println("Is Palindrome: " + result8);
    }
}
