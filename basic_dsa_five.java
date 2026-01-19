/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_five {
    
    // Problem 1: Find Factorial of a Number
    // Calculate factorial using both iterative and recursive approaches
    
    /**
     * Iterative approach to find factorial
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Long factorialIterative(int n) {
        if (n < 0) {
            return null; // Factorial is not defined for negative numbers
        }
        
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
    
    /**
     * Recursive approach to find factorial
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static Long factorialRecursive(int n) {
        if (n < 0) {
            return null; // Factorial is not defined for negative numbers
        }
        if (n == 0 || n == 1) {
            return 1L;
        }
        return (long) n * factorialRecursive(n - 1);
    }
    
    // Problem 2: Check if a Number is Prime
    // Determine whether a number is prime or not
    
    /**
     * Check if a number is prime
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        
        // Check divisibility from 3 to √n
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Find Factorial of a Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int num1 = 5;
        Long factIter1 = factorialIterative(num1);
        Long factRec1 = factorialRecursive(num1);
        System.out.println("Number: " + num1);
        System.out.println("Factorial (Iterative): " + factIter1);
        System.out.println("Factorial (Recursive): " + factRec1);
        
        // Test Case 2
        int num2 = 0;
        Long factIter2 = factorialIterative(num2);
        Long factRec2 = factorialRecursive(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Factorial (Iterative): " + factIter2);
        System.out.println("Factorial (Recursive): " + factRec2);
        
        // Test Case 3
        int num3 = 1;
        Long factIter3 = factorialIterative(num3);
        Long factRec3 = factorialRecursive(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Factorial (Iterative): " + factIter3);
        System.out.println("Factorial (Recursive): " + factRec3);
        
        // Test Case 4
        int num4 = 7;
        Long factIter4 = factorialIterative(num4);
        Long factRec4 = factorialRecursive(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Factorial (Iterative): " + factIter4);
        System.out.println("Factorial (Recursive): " + factRec4);
        
        // Test Case 5 - Negative number
        int num5 = -5;
        Long factIter5 = factorialIterative(num5);
        Long factRec5 = factorialRecursive(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Factorial (Iterative): " + factIter5);
        System.out.println("Factorial (Recursive): " + factRec5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Number is Prime");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Prime number
        int num6 = 7;
        boolean result1 = isPrime(num6);
        System.out.println("Number: " + num6);
        System.out.println("Is Prime: " + result1);
        
        // Test Case 2 - Non-prime number
        int num7 = 10;
        boolean result2 = isPrime(num7);
        System.out.println("\nNumber: " + num7);
        System.out.println("Is Prime: " + result2);
        
        // Test Case 3 - Smallest prime
        int num8 = 2;
        boolean result3 = isPrime(num8);
        System.out.println("\nNumber: " + num8);
        System.out.println("Is Prime: " + result3);
        
        // Test Case 4 - Number less than 2
        int num9 = 1;
        boolean result4 = isPrime(num9);
        System.out.println("\nNumber: " + num9);
        System.out.println("Is Prime: " + result4);
        
        // Test Case 5 - Large prime
        int num10 = 17;
        boolean result5 = isPrime(num10);
        System.out.println("\nNumber: " + num10);
        System.out.println("Is Prime: " + result5);
        
        // Test Case 6 - Even number (except 2)
        int num11 = 4;
        boolean result6 = isPrime(num11);
        System.out.println("\nNumber: " + num11);
        System.out.println("Is Prime: " + result6);
        
        // Test Case 7 - Large non-prime
        int num12 = 100;
        boolean result7 = isPrime(num12);
        System.out.println("\nNumber: " + num12);
        System.out.println("Is Prime: " + result7);
        
        // Test Case 8 - Prime number
        int num13 = 13;
        boolean result8 = isPrime(num13);
        System.out.println("\nNumber: " + num13);
        System.out.println("Is Prime: " + result8);
    }
}
