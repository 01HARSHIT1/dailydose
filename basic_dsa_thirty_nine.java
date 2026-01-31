/**
 * Basic DSA Problems - Sunny Number
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_nine {
    
    // Problem: Check if a Number is Sunny Number
    // A Sunny number is a number n such that n+1 is a perfect square
    // Example: 8 is sunny because 8+1=9=3^2; 3 is sunny because 3+1=4=2^2
    
    /**
     * Check if a number is a perfect square
     * Time Complexity: O(1) using sqrt
     * Space Complexity: O(1)
     */
    public static boolean isPerfectSquare(long n) {
        if (n < 0) {
            return false;
        }
        long sqrt = (long) Math.sqrt(n);
        return sqrt * sqrt == n;
    }
    
    /**
     * Check if a number is Sunny number
     * A number n is sunny if n+1 is a perfect square
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isSunnyNumber(int n) {
        if (n < 0) {
            return false;
        }
        return isPerfectSquare((long) n + 1);
    }
    
    /**
     * Get the square root value for sunny number (the number whose square is n+1)
     * Returns -1 if not a sunny number
     */
    public static int getSunnySquareRoot(int n) {
        if (!isSunnyNumber(n)) {
            return -1;
        }
        return (int) Math.sqrt((long) n + 1);
    }
    
    /**
     * Find all Sunny numbers in a given range
     * Time Complexity: O(end - start)
     * Space Complexity: O(k) where k is the number of Sunny numbers
     */
    public static ArrayList<Integer> getSunnyNumbersInRange(int start, int end) {
        ArrayList<Integer> sunnyNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isSunnyNumber(num)) {
                sunnyNumbers.add(num);
            }
        }
        
        return sunnyNumbers;
    }
    
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Sunny Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Sunny number 8 (8+1=9=3^2)
        int num1 = 8;
        boolean result1 = isSunnyNumber(num1);
        int sqrt1 = getSunnySquareRoot(num1);
        System.out.println("Number: " + num1);
        System.out.println("n+1 = " + (num1 + 1) + ", sqrt = " + sqrt1);
        System.out.println("Is Sunny number: " + result1);
        
        // Test Case 2 - Sunny number 3 (3+1=4=2^2)
        int num2 = 3;
        boolean result2 = isSunnyNumber(num2);
        int sqrt2 = getSunnySquareRoot(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("n+1 = " + (num2 + 1) + ", sqrt = " + sqrt2);
        System.out.println("Is Sunny number: " + result2);
        
        // Test Case 3 - Sunny number 15 (15+1=16=4^2)
        int num3 = 15;
        boolean result3 = isSunnyNumber(num3);
        int sqrt3 = getSunnySquareRoot(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("n+1 = " + (num3 + 1) + ", sqrt = " + sqrt3);
        System.out.println("Is Sunny number: " + result3);
        
        // Test Case 4 - Not Sunny number (5: 5+1=6, not a perfect square)
        int num4 = 5;
        boolean result4 = isSunnyNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("n+1 = " + (num4 + 1) + " (not a perfect square)");
        System.out.println("Is Sunny number: " + result4);
        
        // Test Case 5 - Sunny number 0 (0+1=1=1^2)
        int num5 = 0;
        boolean result5 = isSunnyNumber(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("n+1 = 1, sqrt = 1");
        System.out.println("Is Sunny number: " + result5);
        
        // Test Case 6 - Find Sunny numbers in range
        int start = 1;
        int end = 50;
        ArrayList<Integer> sunnyNums = getSunnyNumbersInRange(start, end);
        System.out.println("\nSunny numbers in range [" + start + ", " + end + "]:");
        System.out.println(sunnyNums);
        System.out.println("Count: " + sunnyNums.size());
        
        // Test Case 7 - Sunny number 24 (24+1=25=5^2)
        int num7 = 24;
        boolean result7 = isSunnyNumber(num7);
        System.out.println("\nNumber: " + num7);
        System.out.println("n+1 = " + (num7 + 1) + " = 5^2");
        System.out.println("Is Sunny number: " + result7);
    }
}
