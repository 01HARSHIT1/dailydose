/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty {
    
    // Problem 1: Check if a Number is Harshad/Niven Number
    // A Harshad number (or Niven number) is a number that is divisible by the sum of its digits
    // Example: 18 is Harshad because 1 + 8 = 9, and 18 is divisible by 9
    
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
     * Check if a number is Harshad/Niven number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isHarshadNumber(int n) {
        if (n <= 0) {
            return false;
        }
        
        int digitSum = sumOfDigits(n);
        return n % digitSum == 0;
    }
    
    /**
     * Find all Harshad numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Harshad numbers
     */
    public static ArrayList<Integer> getHarshadNumbersInRange(int start, int end) {
        ArrayList<Integer> harshadNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isHarshadNumber(num)) {
                harshadNumbers.add(num);
            }
        }
        
        return harshadNumbers;
    }
    
    // Problem 2: Convert Decimal to Octal
    // Convert a decimal number to its octal (base 8) representation
    
    /**
     * Convert decimal to octal using iteration
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static String decimalToOctalIterative(int n) {
        if (n == 0) {
            return "0";
        }
        
        StringBuilder octal = new StringBuilder();
        int num = Math.abs(n);
        
        while (num > 0) {
            octal.insert(0, num % 8);
            num /= 8;
        }
        
        return n >= 0 ? octal.toString() : "-" + octal.toString();
    }
    
    /**
     * Convert decimal to octal using recursion
     * Time Complexity: O(log n)
     * Space Complexity: O(log n) due to recursion stack
     */
    public static String decimalToOctalRecursive(int n) {
        if (n == 0) {
            return "0";
        }
        if (Math.abs(n) < 8) {
            return n >= 0 ? String.valueOf(n) : "-" + String.valueOf(-n);
        }
        if (n < 0) {
            return "-" + decimalToOctalRecursive(-n);
        }
        
        return decimalToOctalRecursive(n / 8) + (n % 8);
    }
    
    /**
     * Convert decimal to octal using built-in function
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static String decimalToOctalBuiltin(int n) {
        return n >= 0 ? Integer.toOctalString(n) : "-" + Integer.toOctalString(-n);
    }
    
    /**
     * Convert decimal to octal and return as list of digits
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static ArrayList<Integer> decimalToOctalList(int n) {
        ArrayList<Integer> octalList = new ArrayList<>();
        if (n == 0) {
            octalList.add(0);
            return octalList;
        }
        
        int num = Math.abs(n);
        while (num > 0) {
            octalList.add(0, num % 8);
            num /= 8;
        }
        
        if (n < 0) {
            octalList.add(0, -1);
        }
        
        return octalList;
    }
    
    /**
     * Convert octal string back to decimal (helper function)
     * Time Complexity: O(n) where n is length of octal string
     * Space Complexity: O(1)
     */
    public static int octalToDecimal(String octalStr) {
        if (octalStr == null || octalStr.isEmpty() || octalStr.equals("0")) {
            return 0;
        }
        
        boolean isNegative = octalStr.charAt(0) == '-';
        int start = isNegative ? 1 : 0;
        
        int decimal = 0;
        int power = 0;
        
        // Process from right to left
        for (int i = octalStr.length() - 1; i >= start; i--) {
            int digit = Character.getNumericValue(octalStr.charAt(i));
            if (digit < 0 || digit > 7) {
                throw new IllegalArgumentException("Invalid octal digit: " + digit);
            }
            decimal += digit * Math.pow(8, power);
            power++;
        }
        
        return isNegative ? -decimal : decimal;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Harshad/Niven Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Harshad number 18
        int num1 = 18;
        boolean result1 = isHarshadNumber(num1);
        int sum1 = sumOfDigits(num1);
        System.out.println("Number: " + num1);
        System.out.println("Sum of digits: " + sum1);
        System.out.println(num1 + " ÷ " + sum1 + " = " + (num1 / sum1));
        System.out.println("Is Harshad number: " + result1);
        
        // Test Case 2 - Harshad number 12
        int num2 = 12;
        boolean result2 = isHarshadNumber(num2);
        int sum2 = sumOfDigits(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Sum of digits: " + sum2);
        System.out.println(num2 + " ÷ " + sum2 + " = " + (num2 / sum2));
        System.out.println("Is Harshad number: " + result2);
        
        // Test Case 3 - Not Harshad number
        int num3 = 19;
        boolean result3 = isHarshadNumber(num3);
        int sum3 = sumOfDigits(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Sum of digits: " + sum3);
        System.out.println(num3 + " ÷ " + sum3 + " = " + ((double)num3 / sum3) + " (not divisible)");
        System.out.println("Is Harshad number: " + result3);
        
        // Test Case 4 - Harshad number 1
        int num4 = 1;
        boolean result4 = isHarshadNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Harshad number: " + result4);
        
        // Test Case 5 - Find Harshad numbers in range
        int start = 1;
        int end = 30;
        ArrayList<Integer> harshadNums = getHarshadNumbersInRange(start, end);
        System.out.println("\nHarshad numbers in range [" + start + ", " + end + "]:");
        System.out.println(harshadNums);
        System.out.println("Count: " + harshadNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Convert Decimal to Octal");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Positive number
        int num1_dec = 64;
        String result1_iter = decimalToOctalIterative(num1_dec);
        String result1_rec = decimalToOctalRecursive(num1_dec);
        String result1_builtin = decimalToOctalBuiltin(num1_dec);
        ArrayList<Integer> result1_list = decimalToOctalList(num1_dec);
        System.out.println("Decimal: " + num1_dec);
        System.out.println("Octal (iterative): " + result1_iter);
        System.out.println("Octal (recursive): " + result1_rec);
        System.out.println("Octal (built-in): " + result1_builtin);
        System.out.println("Octal (list): " + result1_list);
        // Verify conversion
        int decimalBack = octalToDecimal(result1_iter);
        System.out.println("Verification (octal to decimal): " + decimalBack);
        
        // Test Case 2 - Zero
        int num2_dec = 0;
        String result2_oct = decimalToOctalIterative(num2_dec);
        System.out.println("\nDecimal: " + num2_dec);
        System.out.println("Octal: " + result2_oct);
        
        // Test Case 3 - Large number
        int num3_dec = 255;
        String result3_oct = decimalToOctalIterative(num3_dec);
        System.out.println("\nDecimal: " + num3_dec);
        System.out.println("Octal: " + result3_oct);
        System.out.println("Verification: " + octalToDecimal(result3_oct));
        
        // Test Case 4 - Single digit
        int num4_dec = 7;
        String result4_oct = decimalToOctalIterative(num4_dec);
        System.out.println("\nDecimal: " + num4_dec);
        System.out.println("Octal: " + result4_oct);
        
        // Test Case 5 - Negative number
        int num5_dec = -100;
        String result5_oct = decimalToOctalIterative(num5_dec);
        System.out.println("\nDecimal: " + num5_dec);
        System.out.println("Octal: " + result5_oct);
        System.out.println("Verification: " + octalToDecimal(result5_oct));
    }
}
