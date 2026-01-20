/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_twelve {
    
    // Problem 1: Check if a Number is Even or Odd
    // Determine whether a number is even or odd
    
    /**
     * Check if a number is even or odd using modulo operator
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static String isEvenOrOdd(int n) {
        if (n % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }
    
    /**
     * Check if a number is even or odd using bitwise AND
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static String isEvenOrOddBitwise(int n) {
        if ((n & 1) == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }
    
    // Problem 2: Find Sum of First N Natural Numbers
    // Calculate the sum of first n natural numbers (1 + 2 + 3 + ... + n)
    
    /**
     * Find sum using iterative approach
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Long sumNaturalNumbersIterative(int n) {
        if (n < 0) {
            return null;
        }
        
        long total = 0;
        for (int i = 1; i <= n; i++) {
            total += i;
        }
        return total;
    }
    
    /**
     * Find sum using mathematical formula: n * (n + 1) / 2
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static Long sumNaturalNumbersFormula(int n) {
        if (n < 0) {
            return null;
        }
        return (long) n * (n + 1) / 2;
    }
    
    /**
     * Find sum using recursive approach
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static Long sumNaturalNumbersRecursive(int n) {
        if (n < 0) {
            return null;
        }
        if (n == 0) {
            return 0L;
        }
        return (long) n + sumNaturalNumbersRecursive(n - 1);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Even or Odd");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Even number
        int num1 = 10;
        String result1 = isEvenOrOdd(num1);
        String result1b = isEvenOrOddBitwise(num1);
        System.out.println("Number: " + num1);
        System.out.println("Result (Modulo): " + result1);
        System.out.println("Result (Bitwise): " + result1b);
        
        // Test Case 2 - Odd number
        int num2 = 15;
        String result2 = isEvenOrOdd(num2);
        String result2b = isEvenOrOddBitwise(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Result (Modulo): " + result2);
        System.out.println("Result (Bitwise): " + result2b);
        
        // Test Case 3 - Zero
        int num3 = 0;
        String result3 = isEvenOrOdd(num3);
        String result3b = isEvenOrOddBitwise(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Result (Modulo): " + result3);
        System.out.println("Result (Bitwise): " + result3b);
        
        // Test Case 4 - Negative even
        int num4 = -8;
        String result4 = isEvenOrOdd(num4);
        String result4b = isEvenOrOddBitwise(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Result (Modulo): " + result4);
        System.out.println("Result (Bitwise): " + result4b);
        
        // Test Case 5 - Negative odd
        int num5 = -7;
        String result5 = isEvenOrOdd(num5);
        String result5b = isEvenOrOddBitwise(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Result (Modulo): " + result5);
        System.out.println("Result (Bitwise): " + result5b);
        
        // Test Case 6 - Large even number
        int num6 = 1000;
        String result6 = isEvenOrOdd(num6);
        String result6b = isEvenOrOddBitwise(num6);
        System.out.println("\nNumber: " + num6);
        System.out.println("Result (Modulo): " + result6);
        System.out.println("Result (Bitwise): " + result6b);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find Sum of First N Natural Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int n1 = 5;
        Long sumIter1 = sumNaturalNumbersIterative(n1);
        Long sumFormula1 = sumNaturalNumbersFormula(n1);
        Long sumRec1 = sumNaturalNumbersRecursive(n1);
        System.out.println("N = " + n1);
        System.out.println("Sum (Iterative): " + sumIter1);
        System.out.println("Sum (Formula): " + sumFormula1);
        System.out.println("Sum (Recursive): " + sumRec1);
        System.out.println("Verification: 1+2+3+4+5 = " + sumIter1);
        
        // Test Case 2
        int n2 = 10;
        Long sumIter2 = sumNaturalNumbersIterative(n2);
        Long sumFormula2 = sumNaturalNumbersFormula(n2);
        Long sumRec2 = sumNaturalNumbersRecursive(n2);
        System.out.println("\nN = " + n2);
        System.out.println("Sum (Iterative): " + sumIter2);
        System.out.println("Sum (Formula): " + sumFormula2);
        System.out.println("Sum (Recursive): " + sumRec2);
        
        // Test Case 3 - Single number
        int n3 = 1;
        Long sumIter3 = sumNaturalNumbersIterative(n3);
        Long sumFormula3 = sumNaturalNumbersFormula(n3);
        Long sumRec3 = sumNaturalNumbersRecursive(n3);
        System.out.println("\nN = " + n3);
        System.out.println("Sum (Iterative): " + sumIter3);
        System.out.println("Sum (Formula): " + sumFormula3);
        System.out.println("Sum (Recursive): " + sumRec3);
        
        // Test Case 4 - Zero
        int n4 = 0;
        Long sumIter4 = sumNaturalNumbersIterative(n4);
        Long sumFormula4 = sumNaturalNumbersFormula(n4);
        Long sumRec4 = sumNaturalNumbersRecursive(n4);
        System.out.println("\nN = " + n4);
        System.out.println("Sum (Iterative): " + sumIter4);
        System.out.println("Sum (Formula): " + sumFormula4);
        System.out.println("Sum (Recursive): " + sumRec4);
        
        // Test Case 5 - Large number
        int n5 = 100;
        Long sumIter5 = sumNaturalNumbersIterative(n5);
        Long sumFormula5 = sumNaturalNumbersFormula(n5);
        Long sumRec5 = sumNaturalNumbersRecursive(n5);
        System.out.println("\nN = " + n5);
        System.out.println("Sum (Iterative): " + sumIter5);
        System.out.println("Sum (Formula): " + sumFormula5);
        System.out.println("Sum (Recursive): " + sumRec5);
        
        // Test Case 6 - Negative number
        int n6 = -5;
        Long sumIter6 = sumNaturalNumbersIterative(n6);
        Long sumFormula6 = sumNaturalNumbersFormula(n6);
        Long sumRec6 = sumNaturalNumbersRecursive(n6);
        System.out.println("\nN = " + n6);
        System.out.println("Sum (Iterative): " + (sumIter6 != null ? sumIter6 : "Invalid"));
        System.out.println("Sum (Formula): " + (sumFormula6 != null ? sumFormula6 : "Invalid"));
        System.out.println("Sum (Recursive): " + (sumRec6 != null ? sumRec6 : "Invalid"));
    }
}
