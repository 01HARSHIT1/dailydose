/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventeen {
    
    // Problem 1: Convert Decimal to Binary
    // Convert a decimal number to its binary representation
    
    /**
     * Convert decimal to binary using iteration
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static String decimalToBinaryIterative(int n) {
        if (n == 0) {
            return "0";
        }
        
        StringBuilder binary = new StringBuilder();
        int num = Math.abs(n);
        
        while (num > 0) {
            binary.insert(0, num % 2);
            num /= 2;
        }
        
        return n >= 0 ? binary.toString() : "-" + binary.toString();
    }
    
    /**
     * Convert decimal to binary using recursion
     * Time Complexity: O(log n)
     * Space Complexity: O(log n) due to recursion stack
     */
    public static String decimalToBinaryRecursive(int n) {
        if (n == 0) {
            return "0";
        }
        if (n == 1) {
            return "1";
        }
        if (n < 0) {
            return "-" + decimalToBinaryRecursive(-n);
        }
        
        return decimalToBinaryRecursive(n / 2) + (n % 2);
    }
    
    /**
     * Convert decimal to binary using built-in function
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static String decimalToBinaryBuiltin(int n) {
        return n >= 0 ? Integer.toBinaryString(n) : "-" + Integer.toBinaryString(-n);
    }
    
    /**
     * Convert decimal to binary and return as list of digits
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static ArrayList<Integer> decimalToBinaryList(int n) {
        ArrayList<Integer> binaryList = new ArrayList<>();
        if (n == 0) {
            binaryList.add(0);
            return binaryList;
        }
        
        int num = Math.abs(n);
        while (num > 0) {
            binaryList.add(0, num % 2);
            num /= 2;
        }
        
        if (n < 0) {
            binaryList.add(0, -1);
        }
        
        return binaryList;
    }
    
    // Problem 2: Find Sum of Cubes of First N Natural Numbers
    // Calculate 1³ + 2³ + 3³ + ... + N³
    
    /**
     * Find sum of cubes using iteration
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long sumOfCubesIterative(int n) {
        if (n <= 0) {
            return 0;
        }
        
        long total = 0;
        for (int i = 1; i <= n; i++) {
            total += (long) i * i * i;
        }
        return total;
    }
    
    /**
     * Find sum of cubes using mathematical formula: [n(n+1)/2]²
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static long sumOfCubesFormula(int n) {
        if (n <= 0) {
            return 0;
        }
        long sum = (long) n * (n + 1) / 2;
        return sum * sum;
    }
    
    /**
     * Find sum of cubes using recursion
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static long sumOfCubesRecursive(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return (long) n * n * n + sumOfCubesRecursive(n - 1);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Convert Decimal to Binary");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Positive number
        int num1 = 10;
        String result1_iter = decimalToBinaryIterative(num1);
        String result1_rec = decimalToBinaryRecursive(num1);
        String result1_builtin = decimalToBinaryBuiltin(num1);
        ArrayList<Integer> result1_list = decimalToBinaryList(num1);
        System.out.println("Decimal: " + num1);
        System.out.println("Binary (iterative): " + result1_iter);
        System.out.println("Binary (recursive): " + result1_rec);
        System.out.println("Binary (built-in): " + result1_builtin);
        System.out.println("Binary (list): " + result1_list);
        
        // Test Case 2 - Zero
        int num2 = 0;
        String result2 = decimalToBinaryIterative(num2);
        System.out.println("\nDecimal: " + num2);
        System.out.println("Binary: " + result2);
        
        // Test Case 3 - Negative number
        int num3 = -15;
        String result3 = decimalToBinaryIterative(num3);
        System.out.println("\nDecimal: " + num3);
        System.out.println("Binary: " + result3);
        
        // Test Case 4 - Large number
        int num4 = 255;
        String result4 = decimalToBinaryIterative(num4);
        System.out.println("\nDecimal: " + num4);
        System.out.println("Binary: " + result4);
        
        // Test Case 5 - Single digit
        int num5 = 7;
        String result5 = decimalToBinaryIterative(num5);
        System.out.println("\nDecimal: " + num5);
        System.out.println("Binary: " + result5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find Sum of Cubes of First N Natural Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int n1 = 5;
        long result1_iter_cubes = sumOfCubesIterative(n1);
        long result1_formula_cubes = sumOfCubesFormula(n1);
        long result1_rec_cubes = sumOfCubesRecursive(n1);
        System.out.println("N = " + n1);
        System.out.println("1³ + 2³ + 3³ + 4³ + 5³ = " + result1_iter_cubes);
        System.out.println("Iterative method: " + result1_iter_cubes);
        System.out.println("Formula method: " + result1_formula_cubes);
        System.out.println("Recursive method: " + result1_rec_cubes);
        
        // Test Case 2
        int n2 = 10;
        long result2_cubes = sumOfCubesFormula(n2);
        System.out.println("\nN = " + n2);
        System.out.println("Sum of cubes: " + result2_cubes);
        
        // Test Case 3
        int n3 = 1;
        long result3_cubes = sumOfCubesFormula(n3);
        System.out.println("\nN = " + n3);
        System.out.println("Sum of cubes: " + result3_cubes);
        
        // Test Case 4
        int n4 = 7;
        long result4_cubes = sumOfCubesFormula(n4);
        System.out.println("\nN = " + n4);
        System.out.println("Sum of cubes: " + result4_cubes);
        
        // Test Case 5 - Larger number
        int n5 = 20;
        long result5_cubes = sumOfCubesFormula(n5);
        System.out.println("\nN = " + n5);
        System.out.println("Sum of cubes: " + result5_cubes);
        
        // Verification: Formula should equal sum of first n natural numbers squared
        long verification = (long) n5 * (n5 + 1) / 2;
        verification = verification * verification;
        System.out.println("\nVerification: (1+2+...+20)² = " + verification);
    }
}
