/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_fifteen {
    
    // Problem 1: Check if Number is Positive, Negative, or Zero
    // Determine whether a number is positive, negative, or zero
    
    /**
     * Check if number is positive, negative, or zero
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static String checkNumberSign(int n) {
        if (n > 0) {
            return "Positive";
        } else if (n < 0) {
            return "Negative";
        } else {
            return "Zero";
        }
    }
    
    // Problem 2: Print Multiplication Table
    // Print multiplication table for a given number
    
    /**
     * Print multiplication table for a number
     * Time Complexity: O(limit)
     * Space Complexity: O(1)
     */
    public static void printMultiplicationTable(int n, int limit) {
        System.out.println("Multiplication table of " + n + ":");
        for (int i = 1; i <= limit; i++) {
            System.out.println(n + " x " + i + " = " + (n * i));
        }
    }
    
    /**
     * Get multiplication table as an array of strings
     * Time Complexity: O(limit)
     * Space Complexity: O(limit)
     */
    public static String[] getMultiplicationTable(int n, int limit) {
        String[] table = new String[limit];
        for (int i = 1; i <= limit; i++) {
            table[i - 1] = n + " x " + i + " = " + (n * i);
        }
        return table;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if Number is Positive, Negative, or Zero");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Positive number
        int num1 = 15;
        String result1 = checkNumberSign(num1);
        System.out.println("Number: " + num1);
        System.out.println("Sign: " + result1);
        
        // Test Case 2 - Negative number
        int num2 = -10;
        String result2 = checkNumberSign(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Sign: " + result2);
        
        // Test Case 3 - Zero
        int num3 = 0;
        String result3 = checkNumberSign(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Sign: " + result3);
        
        // Test Case 4 - Large positive
        int num4 = 1000;
        String result4 = checkNumberSign(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Sign: " + result4);
        
        // Test Case 5 - Large negative
        int num5 = -500;
        String result5 = checkNumberSign(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Sign: " + result5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Print Multiplication Table");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int num6 = 5;
        printMultiplicationTable(num6, 10);
        
        // Test Case 2
        System.out.println();
        int num7 = 7;
        String[] table1 = getMultiplicationTable(num7, 12);
        System.out.println("Multiplication table of " + num7 + ":");
        for (String row : table1) {
            System.out.println(row);
        }
        
        // Test Case 3 - Zero
        System.out.println();
        int num8 = 0;
        printMultiplicationTable(num8, 5);
        
        // Test Case 4 - Negative number
        System.out.println();
        int num9 = -3;
        printMultiplicationTable(num9, 5);
        
        // Test Case 5 - Custom limit
        System.out.println();
        int num10 = 9;
        printMultiplicationTable(num10, 5);
    }
}
