/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_three {
    
    // Problem 1: Check if a Number is Spy Number
    // A Spy number is a number where the sum of its digits equals the product of its digits
    // Example: 1124 = 1+1+2+4 = 8 and 1*1*2*4 = 8, so 1124 is a Spy number
    
    /**
     * Calculate sum of digits of a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int sumOfDigits(int n) {
        int total = 0;
        int num = Math.abs(n);
        
        while (num > 0) {
            total += num % 10;
            num /= 10;
        }
        
        return total;
    }
    
    /**
     * Calculate product of digits of a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int productOfDigits(int n) {
        int product = 1;
        int num = Math.abs(n);
        
        while (num > 0) {
            int digit = num % 10;
            product *= digit;
            num /= 10;
        }
        
        return product;
    }
    
    /**
     * Check if a number is Spy number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isSpyNumber(int n) {
        if (n <= 0) {
            return false;
        }
        
        return sumOfDigits(n) == productOfDigits(n);
    }
    
    /**
     * Find all Spy numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Spy numbers
     */
    public static ArrayList<Integer> getSpyNumbersInRange(int start, int end) {
        ArrayList<Integer> spyNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isSpyNumber(num)) {
                spyNumbers.add(num);
            }
        }
        
        return spyNumbers;
    }
    
    // Problem 2: Convert Hexadecimal to Decimal
    // Convert a hexadecimal (base 16) number to its decimal representation
    
    /**
     * Convert hexadecimal string to decimal using iteration
     * Time Complexity: O(n) where n is length of hex string
     * Space Complexity: O(1)
     */
    public static int hexadecimalToDecimalIterative(String hexStr) {
        if (hexStr == null || hexStr.isEmpty() || hexStr.equals("0")) {
            return 0;
        }
        
        String hexDigits = "0123456789ABCDEF";
        boolean isNegative = hexStr.charAt(0) == '-';
        int start = isNegative ? 1 : 0;
        
        int decimal = 0;
        int power = 0;
        
        // Process from right to left
        for (int i = hexStr.length() - 1; i >= start; i--) {
            char ch = Character.toUpperCase(hexStr.charAt(i));
            int digitValue = hexDigits.indexOf(ch);
            if (digitValue == -1) {
                throw new IllegalArgumentException("Invalid hexadecimal digit: " + ch);
            }
            decimal += digitValue * Math.pow(16, power);
            power++;
        }
        
        return isNegative ? -decimal : decimal;
    }
    
    /**
     * Convert hexadecimal string to decimal using recursion
     * Time Complexity: O(n) where n is length of hex string
     * Space Complexity: O(n) due to recursion stack
     */
    public static int hexadecimalToDecimalRecursive(String hexStr) {
        if (hexStr == null || hexStr.isEmpty() || hexStr.equals("0")) {
            return 0;
        }
        
        boolean isNegative = hexStr.charAt(0) == '-';
        String hex = isNegative ? hexStr.substring(1) : hexStr;
        
        int result = helper(hex, hex.length() - 1, 0);
        return isNegative ? -result : result;
    }
    
    private static int helper(String hex, int index, int power) {
        String hexDigits = "0123456789ABCDEF";
        if (index < 0) {
            return 0;
        }
        char ch = Character.toUpperCase(hex.charAt(index));
        int digitValue = hexDigits.indexOf(ch);
        if (digitValue == -1) {
            throw new IllegalArgumentException("Invalid hexadecimal digit: " + ch);
        }
        return digitValue * (int) Math.pow(16, power) + helper(hex, index - 1, power + 1);
    }
    
    /**
     * Convert hexadecimal string to decimal using built-in function
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int hexadecimalToDecimalBuiltin(String hexStr) {
        if (hexStr == null || hexStr.isEmpty()) {
            return 0;
        }
        
        boolean isNegative = hexStr.charAt(0) == '-';
        String hex = isNegative ? hexStr.substring(1) : hexStr;
        
        int decimal = Integer.parseInt(hex, 16);
        return isNegative ? -decimal : decimal;
    }
    
    /**
     * Convert hexadecimal array (list of characters) to decimal
     * Time Complexity: O(n) where n is length of array
     * Space Complexity: O(1)
     */
    public static int hexadecimalArrayToDecimal(char[] hexArray) {
        if (hexArray == null || hexArray.length == 0) {
            return 0;
        }
        
        String hexDigits = "0123456789ABCDEF";
        int decimal = 0;
        int power = hexArray.length - 1;
        
        for (char ch : hexArray) {
            char chUpper = Character.toUpperCase(ch);
            int digitValue = hexDigits.indexOf(chUpper);
            if (digitValue == -1) {
                throw new IllegalArgumentException("Invalid hexadecimal digit: " + ch);
            }
            decimal += digitValue * Math.pow(16, power);
            power--;
        }
        
        return decimal;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Spy Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Spy number 1124
        int num1 = 1124;
        boolean result1 = isSpyNumber(num1);
        int sum1 = sumOfDigits(num1);
        int product1 = productOfDigits(num1);
        System.out.println("Number: " + num1);
        System.out.println("Sum of digits: " + sum1);
        System.out.println("Product of digits: " + product1);
        System.out.println("Is Spy number: " + result1);
        
        // Test Case 2 - Spy number 22
        int num2 = 22;
        boolean result2 = isSpyNumber(num2);
        int sum2 = sumOfDigits(num2);
        int product2 = productOfDigits(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Sum of digits: " + sum2);
        System.out.println("Product of digits: " + product2);
        System.out.println("Is Spy number: " + result2);
        
        // Test Case 3 - Not Spy number
        int num3 = 123;
        boolean result3 = isSpyNumber(num3);
        int sum3 = sumOfDigits(num3);
        int product3 = productOfDigits(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Sum of digits: " + sum3);
        System.out.println("Product of digits: " + product3);
        System.out.println("Is Spy number: " + result3);
        
        // Test Case 4 - Single digit (always Spy)
        int num4 = 1;
        boolean result4 = isSpyNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Spy number: " + result4);
        
        // Test Case 5 - Find Spy numbers in range
        int start = 1;
        int end = 2000;
        ArrayList<Integer> spyNums = getSpyNumbersInRange(start, end);
        System.out.println("\nSpy numbers in range [" + start + ", " + end + "] (first 20):");
        for (int i = 0; i < Math.min(20, spyNums.size()); i++) {
            System.out.print(spyNums.get(i) + " ");
        }
        System.out.println("\nTotal count: " + spyNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Convert Hexadecimal to Decimal");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Basic hexadecimal
        String hex1 = "FF";
        int result1_dec = hexadecimalToDecimalIterative(hex1);
        int result1_rec = hexadecimalToDecimalRecursive(hex1);
        int result1_builtin = hexadecimalToDecimalBuiltin(hex1);
        System.out.println("Hexadecimal: " + hex1);
        System.out.println("Decimal (iterative): " + result1_dec);
        System.out.println("Decimal (recursive): " + result1_rec);
        System.out.println("Decimal (built-in): " + result1_builtin);
        
        // Test Case 2 - Zero
        String hex2 = "0";
        int result2_dec = hexadecimalToDecimalIterative(hex2);
        System.out.println("\nHexadecimal: " + hex2);
        System.out.println("Decimal: " + result2_dec);
        
        // Test Case 3 - Large hexadecimal
        String hex3 = "ABCD";
        int result3_dec = hexadecimalToDecimalIterative(hex3);
        System.out.println("\nHexadecimal: " + hex3);
        System.out.println("Decimal: " + result3_dec);
        
        // Test Case 4 - Hexadecimal array
        char[] hex4 = {'1', 'A', 'F'};
        int result4_dec = hexadecimalArrayToDecimal(hex4);
        System.out.println("\nHexadecimal (array): " + new String(hex4));
        System.out.println("Decimal: " + result4_dec);
        
        // Test Case 5 - Lowercase hexadecimal
        String hex5 = "abc";
        int result5_dec = hexadecimalToDecimalIterative(hex5);
        System.out.println("\nHexadecimal: " + hex5);
        System.out.println("Decimal: " + result5_dec);
    }
}
