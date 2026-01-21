/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_two {
    
    // Problem 1: Check if a Number is Disarium Number
    // A Disarium number is a number where the sum of its digits raised to their respective positions equals the number itself
    // Example: 135 = 1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135
    
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
     * Check if a number is Disarium number
     * Time Complexity: O(d * log n) where d is number of digits
     * Space Complexity: O(1)
     */
    public static boolean isDisariumNumber(int n) {
        if (n <= 0) {
            return false;
        }
        
        int original = n;
        int numDigits = countDigits(n);
        long sumPowers = 0;
        
        // Process digits from right to left
        int position = numDigits;
        while (n > 0) {
            int digit = n % 10;
            sumPowers += (long) Math.pow(digit, position);
            position--;
            n /= 10;
        }
        
        return sumPowers == original;
    }
    
    /**
     * Find all Disarium numbers in a given range
     * Time Complexity: O((end - start) * d * log n)
     * Space Complexity: O(k) where k is the number of Disarium numbers
     */
    public static ArrayList<Integer> getDisariumNumbersInRange(int start, int end) {
        ArrayList<Integer> disariumNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isDisariumNumber(num)) {
                disariumNumbers.add(num);
            }
        }
        
        return disariumNumbers;
    }
    
    /**
     * Get the sum of digits raised to their positions
     * Time Complexity: O(d * log n) where d is number of digits
     * Space Complexity: O(1)
     */
    public static long getDigitPowersSum(int n) {
        if (n <= 0) {
            return 0;
        }
        
        int numDigits = countDigits(n);
        long sumPowers = 0;
        int position = numDigits;
        int temp = n;
        
        while (temp > 0) {
            int digit = temp % 10;
            sumPowers += (long) Math.pow(digit, position);
            position--;
            temp /= 10;
        }
        
        return sumPowers;
    }
    
    // Problem 2: Convert Octal to Decimal
    // Convert an octal (base 8) number to its decimal representation
    
    /**
     * Convert octal string to decimal using iteration
     * Time Complexity: O(n) where n is length of octal string
     * Space Complexity: O(1)
     */
    public static int octalToDecimalIterative(String octalStr) {
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
    
    /**
     * Convert octal string to decimal using recursion
     * Time Complexity: O(n) where n is length of octal string
     * Space Complexity: O(n) due to recursion stack
     */
    public static int octalToDecimalRecursive(String octalStr) {
        if (octalStr == null || octalStr.isEmpty() || octalStr.equals("0")) {
            return 0;
        }
        
        boolean isNegative = octalStr.charAt(0) == '-';
        String octal = isNegative ? octalStr.substring(1) : octalStr;
        
        int result = helper(octal, octal.length() - 1, 0);
        return isNegative ? -result : result;
    }
    
    private static int helper(String octal, int index, int power) {
        if (index < 0) {
            return 0;
        }
        int digit = Character.getNumericValue(octal.charAt(index));
        if (digit < 0 || digit > 7) {
            throw new IllegalArgumentException("Invalid octal digit: " + digit);
        }
        return digit * (int) Math.pow(8, power) + helper(octal, index - 1, power + 1);
    }
    
    /**
     * Convert octal string to decimal using built-in function
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int octalToDecimalBuiltin(String octalStr) {
        if (octalStr == null || octalStr.isEmpty()) {
            return 0;
        }
        
        boolean isNegative = octalStr.charAt(0) == '-';
        String octal = isNegative ? octalStr.substring(1) : octalStr;
        
        int decimal = Integer.parseInt(octal, 8);
        return isNegative ? -decimal : decimal;
    }
    
    /**
     * Convert octal array to decimal
     * Time Complexity: O(n) where n is length of array
     * Space Complexity: O(1)
     */
    public static int octalArrayToDecimal(int[] octalArray) {
        if (octalArray == null || octalArray.length == 0) {
            return 0;
        }
        
        int decimal = 0;
        int power = octalArray.length - 1;
        
        for (int digit : octalArray) {
            if (digit < 0 || digit > 7) {
                throw new IllegalArgumentException("Invalid octal digit: " + digit);
            }
            decimal += digit * Math.pow(8, power);
            power--;
        }
        
        return decimal;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Disarium Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Disarium number 135
        int num1 = 135;
        boolean result1 = isDisariumNumber(num1);
        long sum1 = getDigitPowersSum(num1);
        System.out.println("Number: " + num1);
        System.out.println("Sum of digits raised to positions: " + sum1);
        System.out.println("Is Disarium number: " + result1);
        
        // Test Case 2 - Disarium number 89
        int num2 = 89;
        boolean result2 = isDisariumNumber(num2);
        long sum2 = getDigitPowersSum(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Sum of digits raised to positions: " + sum2);
        System.out.println("Is Disarium number: " + result2);
        
        // Test Case 3 - Not Disarium number
        int num3 = 123;
        boolean result3 = isDisariumNumber(num3);
        long sum3 = getDigitPowersSum(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Sum of digits raised to positions: " + sum3);
        System.out.println("Is Disarium number: " + result3);
        
        // Test Case 4 - Single digit Disarium
        int num4 = 1;
        boolean result4 = isDisariumNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Disarium number: " + result4);
        
        // Test Case 5 - Find Disarium numbers in range
        int start = 1;
        int end = 200;
        ArrayList<Integer> disariumNums = getDisariumNumbersInRange(start, end);
        System.out.println("\nDisarium numbers in range [" + start + ", " + end + "]:");
        System.out.println(disariumNums);
        System.out.println("Count: " + disariumNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Convert Octal to Decimal");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Basic octal
        String octal1 = "123";
        int result1_dec = octalToDecimalIterative(octal1);
        int result1_rec = octalToDecimalRecursive(octal1);
        int result1_builtin = octalToDecimalBuiltin(octal1);
        System.out.println("Octal: " + octal1);
        System.out.println("Decimal (iterative): " + result1_dec);
        System.out.println("Decimal (recursive): " + result1_rec);
        System.out.println("Decimal (built-in): " + result1_builtin);
        
        // Test Case 2 - Zero
        String octal2 = "0";
        int result2_dec = octalToDecimalIterative(octal2);
        System.out.println("\nOctal: " + octal2);
        System.out.println("Decimal: " + result2_dec);
        
        // Test Case 3 - Large octal
        String octal3 = "377";
        int result3_dec = octalToDecimalIterative(octal3);
        System.out.println("\nOctal: " + octal3);
        System.out.println("Decimal: " + result3_dec);
        
        // Test Case 4 - Octal array
        int[] octal4 = {1, 2, 7};
        int result4_dec = octalArrayToDecimal(octal4);
        System.out.println("\nOctal (array): " + Arrays.toString(octal4));
        System.out.println("Decimal: " + result4_dec);
        
        // Test Case 5 - Single digit
        String octal5 = "7";
        int result5_dec = octalToDecimalIterative(octal5);
        System.out.println("\nOctal: " + octal5);
        System.out.println("Decimal: " + result5_dec);
    }
}
