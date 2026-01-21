/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_eight {
    
    // Problem 1: Check if a Number is Kaprekar Number
    // A Kaprekar number is a number whose square, when split into two parts and added, gives the original number
    // Example: 45² = 2025, split as 20 and 25, 20 + 25 = 45
    
    /**
     * Count number of digits in a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int countDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int count = 0;
        int num = Math.abs(n);
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }
    
    /**
     * Check if a number is Kaprekar number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isKaprekarNumber(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true; // 1² = 1, 0 + 1 = 1
        }
        
        long square = (long) n * n;
        int numDigits = countDigits((int) square);
        
        // Try splitting at different positions
        for (int splitPos = 1; splitPos < numDigits; splitPos++) {
            long divisor = (long) Math.pow(10, splitPos);
            
            // Split the square into two parts
            long rightPart = square % divisor;
            long leftPart = square / divisor;
            
            // Check if sum equals original number
            if (leftPart + rightPart == n && rightPart > 0) {
                return true;
            }
        }
        
        return false;
    }
    
    /**
     * Get the split of square that makes it Kaprekar number
     * Returns array [left_part, right_part] if Kaprekar, null otherwise
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static long[] getKaprekarSplit(int n) {
        if (n <= 0) {
            return null;
        }
        if (n == 1) {
            return new long[]{0, 1};
        }
        
        long square = (long) n * n;
        int numDigits = countDigits((int) square);
        
        for (int splitPos = 1; splitPos < numDigits; splitPos++) {
            long divisor = (long) Math.pow(10, splitPos);
            
            long rightPart = square % divisor;
            long leftPart = square / divisor;
            
            if (leftPart + rightPart == n && rightPart > 0) {
                return new long[]{leftPart, rightPart};
            }
        }
        
        return null;
    }
    
    /**
     * Find all Kaprekar numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Kaprekar numbers
     */
    public static ArrayList<Integer> getKaprekarNumbersInRange(int start, int end) {
        ArrayList<Integer> kaprekarNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isKaprekarNumber(num)) {
                kaprekarNumbers.add(num);
            }
        }
        
        return kaprekarNumbers;
    }
    
    // Problem 2: Find nth Triangular Number
    // A triangular number is the number of dots that can be arranged in an equilateral triangle
    // Formula: T(n) = n(n+1)/2
    // Example: T(4) = 1 + 2 + 3 + 4 = 10
    
    /**
     * Find nth triangular number using formula
     * T(n) = n(n+1)/2
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static long nthTriangularNumberFormula(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        return (long) n * (n + 1) / 2;
    }
    
    /**
     * Find nth triangular number using iteration
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long nthTriangularNumberIterative(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        
        long total = 0;
        for (int i = 1; i <= n; i++) {
            total += i;
        }
        return total;
    }
    
    /**
     * Find nth triangular number using recursion
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static long nthTriangularNumberRecursive(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n must be non-negative");
        }
        if (n == 0) {
            return 0;
        }
        return n + nthTriangularNumberRecursive(n - 1);
    }
    
    /**
     * Find all triangular numbers in a given range
     * Time Complexity: O(end - start)
     * Space Complexity: O(k) where k is the number of triangular numbers
     */
    public static ArrayList<Integer> getTriangularNumbersInRange(int start, int end) {
        ArrayList<Integer> triangularNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            // Check if number is triangular by solving n(n+1)/2 = num
            // This gives us a quadratic equation: n² + n - 2*num = 0
            // n = (-1 + sqrt(1 + 8*num)) / 2
            double discriminant = 1 + 8 * (long) num;
            if (discriminant >= 0) {
                double n = (-1 + Math.sqrt(discriminant)) / 2;
                if (n >= 0 && Math.abs(n - Math.round(n)) < 1e-9) {
                    triangularNumbers.add(num);
                }
            }
        }
        
        return triangularNumbers;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Kaprekar Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Kaprekar number 9
        int num1 = 9;
        boolean result1 = isKaprekarNumber(num1);
        long[] split1 = getKaprekarSplit(num1);
        long square1 = (long) num1 * num1;
        System.out.println("Number: " + num1);
        System.out.println("Square: " + square1);
        if (split1 != null) {
            System.out.println("Split: " + split1[0] + " + " + split1[1] + " = " + (split1[0] + split1[1]));
        }
        System.out.println("Is Kaprekar number: " + result1);
        
        // Test Case 2 - Kaprekar number 45
        int num2 = 45;
        boolean result2 = isKaprekarNumber(num2);
        long[] split2 = getKaprekarSplit(num2);
        long square2 = (long) num2 * num2;
        System.out.println("\nNumber: " + num2);
        System.out.println("Square: " + square2);
        if (split2 != null) {
            System.out.println("Split: " + split2[0] + " + " + split2[1] + " = " + (split2[0] + split2[1]));
        }
        System.out.println("Is Kaprekar number: " + result2);
        
        // Test Case 3 - Kaprekar number 55
        int num3 = 55;
        boolean result3 = isKaprekarNumber(num3);
        long[] split3 = getKaprekarSplit(num3);
        long square3 = (long) num3 * num3;
        System.out.println("\nNumber: " + num3);
        System.out.println("Square: " + square3);
        if (split3 != null) {
            System.out.println("Split: " + split3[0] + " + " + split3[1] + " = " + (split3[0] + split3[1]));
        }
        System.out.println("Is Kaprekar number: " + result3);
        
        // Test Case 4 - Not Kaprekar number
        int num4 = 10;
        boolean result4 = isKaprekarNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Kaprekar number: " + result4);
        
        // Test Case 5 - Find Kaprekar numbers in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> kaprekarNums = getKaprekarNumbersInRange(start, end);
        System.out.println("\nKaprekar numbers in range [" + start + ", " + end + "]:");
        System.out.println(kaprekarNums);
        System.out.println("Count: " + kaprekarNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find nth Triangular Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - 4th triangular number
        int n1 = 4;
        long result1_tri = nthTriangularNumberFormula(n1);
        long result1_iter = nthTriangularNumberIterative(n1);
        long result1_rec = nthTriangularNumberRecursive(n1);
        System.out.println("n = " + n1);
        System.out.println("Triangular number (formula): " + result1_tri);
        System.out.println("Triangular number (iterative): " + result1_iter);
        System.out.println("Triangular number (recursive): " + result1_rec);
        System.out.println("Pattern: 1 + 2 + 3 + 4 = " + result1_tri);
        
        // Test Case 2 - 10th triangular number
        int n2 = 10;
        long result2_tri = nthTriangularNumberFormula(n2);
        System.out.println("\nn = " + n2);
        System.out.println("10th triangular number: " + result2_tri);
        
        // Test Case 3 - 0th triangular number
        int n3 = 0;
        long result3_tri = nthTriangularNumberFormula(n3);
        System.out.println("\nn = " + n3);
        System.out.println("0th triangular number: " + result3_tri);
        
        // Test Case 4 - Large triangular number
        int n4 = 100;
        long result4_tri = nthTriangularNumberFormula(n4);
        System.out.println("\nn = " + n4);
        System.out.println("100th triangular number: " + result4_tri);
        
        // Test Case 5 - Find triangular numbers in range
        int start_tri = 1;
        int end_tri = 50;
        ArrayList<Integer> triangularNums = getTriangularNumbersInRange(start_tri, end_tri);
        System.out.println("\nTriangular numbers in range [" + start_tri + ", " + end_tri + "]:");
        System.out.println(triangularNums);
        System.out.println("Count: " + triangularNums.size());
    }
}
