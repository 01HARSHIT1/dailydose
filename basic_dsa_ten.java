/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ten {
    
    // Problem 1: Calculate Power of a Number
    // Calculate a raised to the power b (a^b)
    
    /**
     * Calculate power using iterative approach
     * Time Complexity: O(exponent)
     * Space Complexity: O(1)
     */
    public static long powerIterative(int base, int exponent) {
        if (exponent < 0) {
            return -1; // Handle negative exponents separately
        }
        
        long result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
    
    /**
     * Calculate power using recursive approach
     * Time Complexity: O(exponent)
     * Space Complexity: O(exponent) due to recursion stack
     */
    public static long powerRecursive(int base, int exponent) {
        if (exponent < 0) {
            return -1; // Handle negative exponents separately
        }
        if (exponent == 0) {
            return 1;
        }
        return base * powerRecursive(base, exponent - 1);
    }
    
    /**
     * Calculate power using optimized approach (binary exponentiation)
     * Time Complexity: O(log exponent)
     * Space Complexity: O(log exponent) due to recursion
     */
    public static long powerOptimized(int base, int exponent) {
        if (exponent < 0) {
            return -1;
        }
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return base;
        }
        
        if (exponent % 2 == 0) {
            // If exponent is even: base^exponent = (base^2)^(exponent/2)
            return powerOptimized(base * base, exponent / 2);
        } else {
            // If exponent is odd: base^exponent = base * base^(exponent-1)
            return base * powerOptimized(base * base, (exponent - 1) / 2);
        }
    }
    
    // Problem 2: Find LCM (Least Common Multiple) of Two Numbers
    // Find the smallest positive integer that is divisible by both numbers
    
    /**
     * Calculate GCD using Euclidean algorithm
     */
    private static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    /**
     * Find LCM using formula: LCM(a, b) = (a * b) / GCD(a, b)
     * Time Complexity: O(log(min(a, b))) - due to GCD calculation
     * Space Complexity: O(1)
     */
    public static long findLCM(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        
        return Math.abs((long) a * b) / gcd(a, b);
    }
    
    /**
     * Find LCM using brute force approach
     * Time Complexity: O(a * b)
     * Space Complexity: O(1)
     */
    public static long findLCMBruteForce(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        if (a == 0 || b == 0) {
            return 0;
        }
        
        long maxNum = Math.max(a, b);
        while (true) {
            if (maxNum % a == 0 && maxNum % b == 0) {
                return maxNum;
            }
            maxNum++;
        }
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Calculate Power of a Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int base1 = 2, exp1 = 5;
        long powIter1 = powerIterative(base1, exp1);
        long powRec1 = powerRecursive(base1, exp1);
        long powOpt1 = powerOptimized(base1, exp1);
        System.out.println("Base: " + base1 + ", Exponent: " + exp1);
        System.out.println("Result (Iterative): " + powIter1);
        System.out.println("Result (Recursive): " + powRec1);
        System.out.println("Result (Optimized): " + powOpt1);
        
        // Test Case 2
        int base2 = 3, exp2 = 4;
        long powIter2 = powerIterative(base2, exp2);
        long powRec2 = powerRecursive(base2, exp2);
        long powOpt2 = powerOptimized(base2, exp2);
        System.out.println("\nBase: " + base2 + ", Exponent: " + exp2);
        System.out.println("Result (Iterative): " + powIter2);
        System.out.println("Result (Recursive): " + powRec2);
        System.out.println("Result (Optimized): " + powOpt2);
        
        // Test Case 3 - Power of 0
        int base3 = 5, exp3 = 0;
        long powIter3 = powerIterative(base3, exp3);
        long powRec3 = powerRecursive(base3, exp3);
        long powOpt3 = powerOptimized(base3, exp3);
        System.out.println("\nBase: " + base3 + ", Exponent: " + exp3);
        System.out.println("Result (Iterative): " + powIter3);
        System.out.println("Result (Recursive): " + powRec3);
        System.out.println("Result (Optimized): " + powOpt3);
        
        // Test Case 4 - Base is 0
        int base4 = 0, exp4 = 5;
        long powIter4 = powerIterative(base4, exp4);
        long powRec4 = powerRecursive(base4, exp4);
        long powOpt4 = powerOptimized(base4, exp4);
        System.out.println("\nBase: " + base4 + ", Exponent: " + exp4);
        System.out.println("Result (Iterative): " + powIter4);
        System.out.println("Result (Recursive): " + powRec4);
        System.out.println("Result (Optimized): " + powOpt4);
        
        // Test Case 5 - Large exponent
        int base5 = 2, exp5 = 10;
        long powIter5 = powerIterative(base5, exp5);
        long powRec5 = powerRecursive(base5, exp5);
        long powOpt5 = powerOptimized(base5, exp5);
        System.out.println("\nBase: " + base5 + ", Exponent: " + exp5);
        System.out.println("Result (Iterative): " + powIter5);
        System.out.println("Result (Recursive): " + powRec5);
        System.out.println("Result (Optimized): " + powOpt5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find LCM (Least Common Multiple) of Two Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int a1 = 12, b1 = 18;
        long lcm1 = findLCM(a1, b1);
        long lcmBf1 = findLCMBruteForce(a1, b1);
        System.out.println("Numbers: " + a1 + ", " + b1);
        System.out.println("LCM (Using GCD formula): " + lcm1);
        System.out.println("LCM (Brute Force): " + lcmBf1);
        
        // Test Case 2
        int a2 = 15, b2 = 25;
        long lcm2 = findLCM(a2, b2);
        long lcmBf2 = findLCMBruteForce(a2, b2);
        System.out.println("\nNumbers: " + a2 + ", " + b2);
        System.out.println("LCM (Using GCD formula): " + lcm2);
        System.out.println("LCM (Brute Force): " + lcmBf2);
        
        // Test Case 3 - Coprime numbers
        int a3 = 7, b3 = 13;
        long lcm3 = findLCM(a3, b3);
        long lcmBf3 = findLCMBruteForce(a3, b3);
        System.out.println("\nNumbers: " + a3 + ", " + b3);
        System.out.println("LCM (Using GCD formula): " + lcm3);
        System.out.println("LCM (Brute Force): " + lcmBf3);
        
        // Test Case 4 - Same numbers
        int a4 = 10, b4 = 10;
        long lcm4 = findLCM(a4, b4);
        long lcmBf4 = findLCMBruteForce(a4, b4);
        System.out.println("\nNumbers: " + a4 + ", " + b4);
        System.out.println("LCM (Using GCD formula): " + lcm4);
        System.out.println("LCM (Brute Force): " + lcmBf4);
        
        // Test Case 5 - One number is multiple of other
        int a5 = 5, b5 = 15;
        long lcm5 = findLCM(a5, b5);
        long lcmBf5 = findLCMBruteForce(a5, b5);
        System.out.println("\nNumbers: " + a5 + ", " + b5);
        System.out.println("LCM (Using GCD formula): " + lcm5);
        System.out.println("LCM (Brute Force): " + lcmBf5);
        
        // Test Case 6 - Large numbers
        int a6 = 48, b6 = 60;
        long lcm6 = findLCM(a6, b6);
        long lcmBf6 = findLCMBruteForce(a6, b6);
        System.out.println("\nNumbers: " + a6 + ", " + b6);
        System.out.println("LCM (Using GCD formula): " + lcm6);
        System.out.println("LCM (Brute Force): " + lcmBf6);
    }
}
