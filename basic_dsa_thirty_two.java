/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_two {
    
    // Problem: Check if a Number is Palindrome
    // A palindrome number is a number that remains the same when its digits are reversed
    // Example: 121, 1331, 12321 are palindromes
    
    /**
     * Reverse a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static long reverseNumber(int n) {
        long reversedNum = 0;
        int num = Math.abs(n);
        
        while (num > 0) {
            reversedNum = reversedNum * 10 + num % 10;
            num /= 10;
        }
        
        return n < 0 ? -reversedNum : reversedNum;
    }
    
    /**
     * Check if a number is palindrome using string conversion
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     */
    public static boolean isPalindromeNumberString(int n) {
        String numStr = String.valueOf(Math.abs(n));
        String reversed = new StringBuilder(numStr).reverse().toString();
        return numStr.equals(reversed);
    }
    
    /**
     * Check if a number is palindrome by reversing it
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isPalindromeNumberReverse(int n) {
        if (n < 0) {
            return false; // Negative numbers are not palindromes
        }
        
        int original = n;
        long reversedNum = reverseNumber(n);
        return original == reversedNum;
    }
    
    /**
     * Check if a number is palindrome using two-pointer approach
     * Time Complexity: O(log n)
     * Space Complexity: O(log n) for string conversion
     */
    public static boolean isPalindromeNumberTwoPointers(int n) {
        if (n < 0) {
            return false;
        }
        
        String numStr = String.valueOf(n);
        int left = 0;
        int right = numStr.length() - 1;
        
        while (left < right) {
            if (numStr.charAt(left) != numStr.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
    
    /**
     * Find all palindrome numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of palindrome numbers
     */
    public static ArrayList<Integer> getPalindromeNumbersInRange(int start, int end) {
        ArrayList<Integer> palindromeNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isPalindromeNumberReverse(num)) {
                palindromeNumbers.add(num);
            }
        }
        
        return palindromeNumbers;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Palindrome");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Palindrome number 121
        int num1 = 121;
        boolean result1_string = isPalindromeNumberString(num1);
        boolean result1_reverse = isPalindromeNumberReverse(num1);
        boolean result1_two_pointers = isPalindromeNumberTwoPointers(num1);
        long reversed1 = reverseNumber(num1);
        System.out.println("Number: " + num1);
        System.out.println("Reversed: " + reversed1);
        System.out.println("Is palindrome (string): " + result1_string);
        System.out.println("Is palindrome (reverse): " + result1_reverse);
        System.out.println("Is palindrome (two pointers): " + result1_two_pointers);
        
        // Test Case 2 - Palindrome number 1331
        int num2 = 1331;
        boolean result2 = isPalindromeNumberReverse(num2);
        long reversed2 = reverseNumber(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Reversed: " + reversed2);
        System.out.println("Is palindrome: " + result2);
        
        // Test Case 3 - Not palindrome
        int num3 = 123;
        boolean result3 = isPalindromeNumberReverse(num3);
        long reversed3 = reverseNumber(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Reversed: " + reversed3);
        System.out.println("Is palindrome: " + result3);
        
        // Test Case 4 - Single digit (always palindrome)
        int num4 = 7;
        boolean result4 = isPalindromeNumberReverse(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is palindrome: " + result4);
        
        // Test Case 5 - Palindrome number 12321
        int num5 = 12321;
        boolean result5 = isPalindromeNumberReverse(num5);
        long reversed5 = reverseNumber(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Reversed: " + reversed5);
        System.out.println("Is palindrome: " + result5);
        
        // Test Case 6 - Find palindrome numbers in range
        int start = 100;
        int end = 200;
        ArrayList<Integer> palindromeNums = getPalindromeNumbersInRange(start, end);
        System.out.println("\nPalindrome numbers in range [" + start + ", " + end + "]:");
        System.out.println(palindromeNums);
        System.out.println("Count: " + palindromeNums.size());
        
        // Test Case 7 - Zero
        int num7 = 0;
        boolean result7 = isPalindromeNumberReverse(num7);
        System.out.println("\nNumber: " + num7);
        System.out.println("Is palindrome: " + result7);
    }
}
