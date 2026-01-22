/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_six {
    
    // Problem: Check if a Number is Emirp
    // An Emirp is a prime number that when reversed is also a prime number (and different from the original)
    // Example: 13 is Emirp because 13 is prime and 31 (reversed) is also prime
    // Note: Palindromic primes like 11, 131 are NOT Emirp because reversed number is same
    
    /**
     * Check if a number is prime
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * Reverse a number
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int reverseNumber(int n) {
        long reversedNum = 0;
        int num = Math.abs(n);
        
        while (num > 0) {
            reversedNum = reversedNum * 10 + num % 10;
            num /= 10;
        }
        
        return (int) (n < 0 ? -reversedNum : reversedNum);
    }
    
    /**
     * Check if a number is Emirp
     * An Emirp is a prime that when reversed is also prime and different from original
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isEmirp(int n) {
        if (n < 2) {
            return false;
        }
        
        // Check if number is prime
        if (!isPrime(n)) {
            return false;
        }
        
        // Reverse the number
        int reversedN = reverseNumber(n);
        
        // Check if reversed number is different and also prime
        if (reversedN == n) {
            return false; // Palindromic primes are not Emirp
        }
        
        return isPrime(reversedN);
    }
    
    /**
     * Find all Emirp numbers in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(k) where k is the number of Emirp numbers
     */
    public static ArrayList<Integer> getEmirpNumbersInRange(int start, int end) {
        ArrayList<Integer> emirpNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isEmirp(num)) {
                emirpNumbers.add(num);
            }
        }
        
        return emirpNumbers;
    }
    
    /**
     * Get the Emirp pair (original, reversed) if number is Emirp
     * Returns array [n, reversed_n] if Emirp, null otherwise
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static int[] getEmirpPair(int n) {
        if (!isEmirp(n)) {
            return null;
        }
        
        int reversedN = reverseNumber(n);
        return new int[]{n, reversedN};
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Emirp");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Emirp number 13
        int num1 = 13;
        boolean result1 = isEmirp(num1);
        int reversed1 = reverseNumber(num1);
        int[] pair1 = getEmirpPair(num1);
        System.out.println("Number: " + num1);
        System.out.println("Reversed: " + reversed1);
        System.out.println("Is Emirp: " + result1);
        if (pair1 != null) {
            System.out.println("Emirp pair: (" + pair1[0] + ", " + pair1[1] + ")");
        }
        
        // Test Case 2 - Emirp number 17
        int num2 = 17;
        boolean result2 = isEmirp(num2);
        int reversed2 = reverseNumber(num2);
        int[] pair2 = getEmirpPair(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Reversed: " + reversed2);
        System.out.println("Is Emirp: " + result2);
        if (pair2 != null) {
            System.out.println("Emirp pair: (" + pair2[0] + ", " + pair2[1] + ")");
        }
        
        // Test Case 3 - Not Emirp (palindromic prime 11)
        int num3 = 11;
        boolean result3 = isEmirp(num3);
        int reversed3 = reverseNumber(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Reversed: " + reversed3);
        System.out.println("Is Emirp: " + result3 + " (palindromic prime, not Emirp)");
        
        // Test Case 4 - Not Emirp (not prime)
        int num4 = 15;
        boolean result4 = isEmirp(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Emirp: " + result4 + " (not prime)");
        
        // Test Case 5 - Emirp number 37
        int num5 = 37;
        boolean result5 = isEmirp(num5);
        int reversed5 = reverseNumber(num5);
        int[] pair5 = getEmirpPair(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Reversed: " + reversed5);
        System.out.println("Is Emirp: " + result5);
        if (pair5 != null) {
            System.out.println("Emirp pair: (" + pair5[0] + ", " + pair5[1] + ")");
        }
        
        // Test Case 6 - Find Emirp numbers in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> emirpNums = getEmirpNumbersInRange(start, end);
        System.out.println("\nEmirp numbers in range [" + start + ", " + end + "]:");
        System.out.println(emirpNums);
        System.out.println("Count: " + emirpNums.size());
        
        // Test Case 7 - Emirp number 79
        int num7 = 79;
        boolean result7 = isEmirp(num7);
        int reversed7 = reverseNumber(num7);
        int[] pair7 = getEmirpPair(num7);
        System.out.println("\nNumber: " + num7);
        System.out.println("Reversed: " + reversed7);
        System.out.println("Is Emirp: " + result7);
        if (pair7 != null) {
            System.out.println("Emirp pair: (" + pair7[0] + ", " + pair7[1] + ")");
        }
    }
}
