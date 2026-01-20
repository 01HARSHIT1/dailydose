import java.util.*;

/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_nine {
    
    // Problem 1: Count Digits in a Number
    // Count the number of digits in a number
    
    /**
     * Count digits using iterative approach
     * Time Complexity: O(log n) where log is base 10
     * Space Complexity: O(1)
     */
    public static int countDigits(int n) {
        if (n == 0) {
            return 1;
        }
        
        n = Math.abs(n); // Handle negative numbers
        int count = 0;
        
        while (n > 0) {
            count++;
            n /= 10;
        }
        
        return count;
    }
    
    /**
     * Count digits using recursive approach
     * Time Complexity: O(log n)
     * Space Complexity: O(log n) due to recursion stack
     */
    public static int countDigitsRecursive(int n) {
        n = Math.abs(n); // Handle negative numbers
        if (n < 10) {
            return 1;
        }
        return 1 + countDigitsRecursive(n / 10);
    }
    
    /**
     * Count digits using logarithmic approach
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static int countDigitsLog(int n) {
        if (n == 0) {
            return 1;
        }
        return (int) Math.log10(Math.abs(n)) + 1;
    }
    
    // Problem 2: Check if a Number is Armstrong Number
    // An Armstrong number is a number that is equal to the sum of its own digits
    // each raised to the power of the number of digits
    
    /**
     * Check if a number is Armstrong number
     * Time Complexity: O(d) where d is number of digits
     * Space Complexity: O(1)
     */
    public static boolean isArmstrong(int n) {
        if (n < 0) {
            return false;
        }
        
        int original = n;
        int numDigits = countDigits(n);
        int sumPower = 0;
        
        while (n > 0) {
            int digit = n % 10;
            sumPower += Math.pow(digit, numDigits);
            n /= 10;
        }
        
        return original == sumPower;
    }
    
    /**
     * Find all Armstrong numbers in a given range
     * Time Complexity: O(n * d) where n is range size, d is average digits
     * Space Complexity: O(1) excluding output
     */
    public static List<Integer> findArmstrongNumbersInRange(int start, int end) {
        List<Integer> armstrongNums = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isArmstrong(num)) {
                armstrongNums.add(num);
            }
        }
        
        return armstrongNums;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Count Digits in a Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int num1 = 12345;
        int count1 = countDigits(num1);
        int countRec1 = countDigitsRecursive(num1);
        int countLog1 = countDigitsLog(num1);
        System.out.println("Number: " + num1);
        System.out.println("Number of digits (Iterative): " + count1);
        System.out.println("Number of digits (Recursive): " + countRec1);
        System.out.println("Number of digits (Logarithmic): " + countLog1);
        
        // Test Case 2
        int num2 = 9876;
        int count2 = countDigits(num2);
        int countRec2 = countDigitsRecursive(num2);
        int countLog2 = countDigitsLog(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Number of digits (Iterative): " + count2);
        System.out.println("Number of digits (Recursive): " + countRec2);
        System.out.println("Number of digits (Logarithmic): " + countLog2);
        
        // Test Case 3 - Single digit
        int num3 = 5;
        int count3 = countDigits(num3);
        int countRec3 = countDigitsRecursive(num3);
        int countLog3 = countDigitsLog(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Number of digits (Iterative): " + count3);
        System.out.println("Number of digits (Recursive): " + countRec3);
        System.out.println("Number of digits (Logarithmic): " + countLog3);
        
        // Test Case 4 - Zero
        int num4 = 0;
        int count4 = countDigits(num4);
        int countRec4 = countDigitsRecursive(num4);
        int countLog4 = countDigitsLog(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Number of digits (Iterative): " + count4);
        System.out.println("Number of digits (Recursive): " + countRec4);
        System.out.println("Number of digits (Logarithmic): " + countLog4);
        
        // Test Case 5 - Negative number
        int num5 = -123;
        int count5 = countDigits(num5);
        int countRec5 = countDigitsRecursive(num5);
        int countLog5 = countDigitsLog(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Number of digits (Iterative): " + count5);
        System.out.println("Number of digits (Recursive): " + countRec5);
        System.out.println("Number of digits (Logarithmic): " + countLog5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Number is Armstrong Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Armstrong number (153: 1^3 + 5^3 + 3^3 = 153)
        int num7 = 153;
        boolean result1 = isArmstrong(num7);
        System.out.println("Number: " + num7);
        System.out.println("Is Armstrong: " + result1);
        if (result1) {
            System.out.println("Verification: 1³ + 5³ + 3³ = " + 
                (int)Math.pow(1, 3) + " + " + (int)Math.pow(5, 3) + " + " + 
                (int)Math.pow(3, 3) + " = " + 
                ((int)Math.pow(1, 3) + (int)Math.pow(5, 3) + (int)Math.pow(3, 3)) + 
                " = " + num7);
        }
        
        // Test Case 2 - Not Armstrong
        int num8 = 123;
        boolean result2 = isArmstrong(num8);
        System.out.println("\nNumber: " + num8);
        System.out.println("Is Armstrong: " + result2);
        
        // Test Case 3 - Armstrong number (371: 3^3 + 7^3 + 1^3 = 371)
        int num9 = 371;
        boolean result3 = isArmstrong(num9);
        System.out.println("\nNumber: " + num9);
        System.out.println("Is Armstrong: " + result3);
        
        // Test Case 4 - Armstrong number (407: 4^3 + 0^3 + 7^3 = 407)
        int num10 = 407;
        boolean result4 = isArmstrong(num10);
        System.out.println("\nNumber: " + num10);
        System.out.println("Is Armstrong: " + result4);
        
        // Test Case 5 - Single digit (all single digits are Armstrong)
        int num11 = 5;
        boolean result5 = isArmstrong(num11);
        System.out.println("\nNumber: " + num11);
        System.out.println("Is Armstrong: " + result5);
        
        // Test Case 6 - 4-digit Armstrong (1634: 1^4 + 6^4 + 3^4 + 4^4 = 1634)
        int num12 = 1634;
        boolean result6 = isArmstrong(num12);
        System.out.println("\nNumber: " + num12);
        System.out.println("Is Armstrong: " + result6);
        
        // Test Case 7 - Find Armstrong numbers in range
        System.out.println("\nArmstrong numbers between 100 and 500: " + 
            findArmstrongNumbersInRange(100, 500));
    }
}
