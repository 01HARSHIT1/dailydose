/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_one {
    
    // Problem 1: Check if a Number is Automorphic
    // An automorphic number is a number whose square ends with the number itself
    // Example: 5² = 25 (ends with 5), 6² = 36 (ends with 6), 25² = 625 (ends with 25)
    
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
     * Check if a number is automorphic number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isAutomorphicNumber(int n) {
        if (n < 0) {
            return false;
        }
        
        long square = (long) n * n;
        int numDigits = countDigits(n);
        
        // Extract last numDigits from square
        long divisor = (long) Math.pow(10, numDigits);
        long lastDigits = square % divisor;
        
        return lastDigits == n;
    }
    
    /**
     * Find all automorphic numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of automorphic numbers
     */
    public static ArrayList<Integer> getAutomorphicNumbersInRange(int start, int end) {
        ArrayList<Integer> automorphicNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isAutomorphicNumber(num)) {
                automorphicNumbers.add(num);
            }
        }
        
        return automorphicNumbers;
    }
    
    // Problem 2: Convert Decimal to Hexadecimal
    // Convert a decimal number to its hexadecimal (base 16) representation
    
    /**
     * Convert decimal to hexadecimal using iteration
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static String decimalToHexadecimalIterative(int n) {
        if (n == 0) {
            return "0";
        }
        
        String hexDigits = "0123456789ABCDEF";
        StringBuilder hexadecimal = new StringBuilder();
        int num = Math.abs(n);
        
        while (num > 0) {
            hexadecimal.insert(0, hexDigits.charAt(num % 16));
            num /= 16;
        }
        
        return n >= 0 ? hexadecimal.toString() : "-" + hexadecimal.toString();
    }
    
    /**
     * Convert decimal to hexadecimal using recursion
     * Time Complexity: O(log n)
     * Space Complexity: O(log n) due to recursion stack
     */
    public static String decimalToHexadecimalRecursive(int n) {
        String hexDigits = "0123456789ABCDEF";
        
        if (n == 0) {
            return "0";
        }
        if (Math.abs(n) < 16) {
            String result = String.valueOf(hexDigits.charAt(Math.abs(n)));
            return n >= 0 ? result : "-" + result;
        }
        if (n < 0) {
            return "-" + decimalToHexadecimalRecursive(-n);
        }
        
        return decimalToHexadecimalRecursive(n / 16) + hexDigits.charAt(n % 16);
    }
    
    /**
     * Convert decimal to hexadecimal using built-in function
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static String decimalToHexadecimalBuiltin(int n) {
        return n >= 0 ? Integer.toHexString(n).toUpperCase() : "-" + Integer.toHexString(-n).toUpperCase();
    }
    
    /**
     * Convert decimal to hexadecimal and return as list of characters
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static ArrayList<Character> decimalToHexadecimalList(int n) {
        String hexDigits = "0123456789ABCDEF";
        ArrayList<Character> hexList = new ArrayList<>();
        
        if (n == 0) {
            hexList.add('0');
            return hexList;
        }
        
        int num = Math.abs(n);
        while (num > 0) {
            hexList.add(0, hexDigits.charAt(num % 16));
            num /= 16;
        }
        
        if (n < 0) {
            hexList.add(0, '-');
        }
        
        return hexList;
    }
    
    /**
     * Convert hexadecimal string back to decimal (helper function)
     * Time Complexity: O(n) where n is length of hex string
     * Space Complexity: O(1)
     */
    public static int hexadecimalToDecimal(String hexStr) {
        if (hexStr == null || hexStr.isEmpty() || hexStr.equals("0")) {
            return 0;
        }
        
        boolean isNegative = hexStr.charAt(0) == '-';
        int start = isNegative ? 1 : 0;
        
        int decimal = 0;
        int power = 0;
        String hexDigits = "0123456789ABCDEF";
        
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
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Automorphic");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Automorphic number 5
        int num1 = 5;
        boolean result1 = isAutomorphicNumber(num1);
        long square1 = (long) num1 * num1;
        System.out.println("Number: " + num1);
        System.out.println("Square: " + square1);
        System.out.println("Is automorphic: " + result1);
        
        // Test Case 2 - Automorphic number 6
        int num2 = 6;
        boolean result2 = isAutomorphicNumber(num2);
        long square2 = (long) num2 * num2;
        System.out.println("\nNumber: " + num2);
        System.out.println("Square: " + square2);
        System.out.println("Is automorphic: " + result2);
        
        // Test Case 3 - Automorphic number 25
        int num3 = 25;
        boolean result3 = isAutomorphicNumber(num3);
        long square3 = (long) num3 * num3;
        System.out.println("\nNumber: " + num3);
        System.out.println("Square: " + square3);
        System.out.println("Is automorphic: " + result3);
        
        // Test Case 4 - Not automorphic number
        int num4 = 7;
        boolean result4 = isAutomorphicNumber(num4);
        long square4 = (long) num4 * num4;
        System.out.println("\nNumber: " + num4);
        System.out.println("Square: " + square4);
        System.out.println("Is automorphic: " + result4);
        
        // Test Case 5 - Find automorphic numbers in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> automorphicNums = getAutomorphicNumbersInRange(start, end);
        System.out.println("\nAutomorphic numbers in range [" + start + ", " + end + "]:");
        System.out.println(automorphicNums);
        System.out.println("Count: " + automorphicNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Convert Decimal to Hexadecimal");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Positive number
        int num1_dec = 255;
        String result1_iter = decimalToHexadecimalIterative(num1_dec);
        String result1_rec = decimalToHexadecimalRecursive(num1_dec);
        String result1_builtin = decimalToHexadecimalBuiltin(num1_dec);
        ArrayList<Character> result1_list = decimalToHexadecimalList(num1_dec);
        System.out.println("Decimal: " + num1_dec);
        System.out.println("Hexadecimal (iterative): " + result1_iter);
        System.out.println("Hexadecimal (recursive): " + result1_rec);
        System.out.println("Hexadecimal (built-in): " + result1_builtin);
        System.out.print("Hexadecimal (list): ");
        for (char c : result1_list) {
            System.out.print(c);
        }
        System.out.println();
        // Verify conversion
        int decimalBack = hexadecimalToDecimal(result1_iter);
        System.out.println("Verification (hex to decimal): " + decimalBack);
        
        // Test Case 2 - Zero
        int num2_dec = 0;
        String result2_hex = decimalToHexadecimalIterative(num2_dec);
        System.out.println("\nDecimal: " + num2_dec);
        System.out.println("Hexadecimal: " + result2_hex);
        
        // Test Case 3 - Large number
        int num3_dec = 4095;
        String result3_hex = decimalToHexadecimalIterative(num3_dec);
        System.out.println("\nDecimal: " + num3_dec);
        System.out.println("Hexadecimal: " + result3_hex);
        System.out.println("Verification: " + hexadecimalToDecimal(result3_hex));
        
        // Test Case 4 - Number with letters
        int num4_dec = 10;
        String result4_hex = decimalToHexadecimalIterative(num4_dec);
        System.out.println("\nDecimal: " + num4_dec);
        System.out.println("Hexadecimal: " + result4_hex);
        
        // Test Case 5 - Negative number
        int num5_dec = -256;
        String result5_hex = decimalToHexadecimalIterative(num5_dec);
        System.out.println("\nDecimal: " + num5_dec);
        System.out.println("Hexadecimal: " + result5_hex);
        System.out.println("Verification: " + hexadecimalToDecimal(result5_hex));
    }
}
