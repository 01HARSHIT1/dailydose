/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_five {
    
    // Problem: Check if a Number is Smith Number
    // A Smith number is a composite number whose sum of digits equals the sum of digits of its prime factors
    // Example: 4 = 2 × 2, sum of digits of 4 = 4, sum of digits of prime factors (2+2) = 4, so 4 is Smith
    
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
     * Get all prime factors of a number (with repetition)
     * Time Complexity: O(√n)
     * Space Complexity: O(log n)
     */
    public static ArrayList<Integer> getPrimeFactors(int n) {
        ArrayList<Integer> factors = new ArrayList<>();
        if (n < 2) {
            return factors;
        }
        
        int num = Math.abs(n);
        
        // Check for factor 2
        while (num % 2 == 0) {
            factors.add(2);
            num /= 2;
        }
        
        // Check for odd factors
        for (int i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                factors.add(i);
                num /= i;
            }
        }
        
        // If remaining number is prime
        if (num > 1) {
            factors.add(num);
        }
        
        return factors;
    }
    
    /**
     * Calculate sum of digits of all factors
     * Time Complexity: O(k * log m) where k is number of factors, m is max factor
     * Space Complexity: O(1)
     */
    public static int sumOfDigitsOfFactors(ArrayList<Integer> factors) {
        int total = 0;
        for (int factor : factors) {
            total += sumOfDigits(factor);
        }
        return total;
    }
    
    /**
     * Check if a number is Smith number
     * A Smith number is composite and sum of digits equals sum of digits of prime factors
     * Time Complexity: O(√n)
     * Space Complexity: O(log n)
     */
    public static boolean isSmithNumber(int n) {
        if (n < 4) {
            return false; // No composite numbers below 4
        }
        
        // Smith numbers must be composite
        if (isPrime(n)) {
            return false;
        }
        
        // Get prime factors
        ArrayList<Integer> factors = getPrimeFactors(n);
        
        // Calculate sum of digits of number
        int sumDigitsNum = sumOfDigits(n);
        
        // Calculate sum of digits of prime factors
        int sumDigitsFactors = sumOfDigitsOfFactors(factors);
        
        return sumDigitsNum == sumDigitsFactors;
    }
    
    /**
     * Find all Smith numbers in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(k) where k is the number of Smith numbers
     */
    public static ArrayList<Integer> getSmithNumbersInRange(int start, int end) {
        ArrayList<Integer> smithNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isSmithNumber(num)) {
                smithNumbers.add(num);
            }
        }
        
        return smithNumbers;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Smith Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Smith number 4
        int num1 = 4;
        boolean result1 = isSmithNumber(num1);
        ArrayList<Integer> factors1 = getPrimeFactors(num1);
        int sumDigits1 = sumOfDigits(num1);
        int sumFactors1 = sumOfDigitsOfFactors(factors1);
        System.out.println("Number: " + num1);
        System.out.println("Prime factors: " + factors1);
        System.out.println("Sum of digits of number: " + sumDigits1);
        System.out.println("Sum of digits of factors: " + sumFactors1);
        System.out.println("Is Smith number: " + result1);
        
        // Test Case 2 - Smith number 22
        int num2 = 22;
        boolean result2 = isSmithNumber(num2);
        ArrayList<Integer> factors2 = getPrimeFactors(num2);
        int sumDigits2 = sumOfDigits(num2);
        int sumFactors2 = sumOfDigitsOfFactors(factors2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Prime factors: " + factors2);
        System.out.println("Sum of digits of number: " + sumDigits2);
        System.out.println("Sum of digits of factors: " + sumFactors2);
        System.out.println("Is Smith number: " + result2);
        
        // Test Case 3 - Smith number 27
        int num3 = 27;
        boolean result3 = isSmithNumber(num3);
        ArrayList<Integer> factors3 = getPrimeFactors(num3);
        int sumDigits3 = sumOfDigits(num3);
        int sumFactors3 = sumOfDigitsOfFactors(factors3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Prime factors: " + factors3);
        System.out.println("Sum of digits of number: " + sumDigits3);
        System.out.println("Sum of digits of factors: " + sumFactors3);
        System.out.println("Is Smith number: " + result3);
        
        // Test Case 4 - Not Smith number (prime)
        int num4 = 7;
        boolean result4 = isSmithNumber(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Smith number: " + result4 + " (prime numbers are not Smith)");
        
        // Test Case 5 - Not Smith number (composite but not Smith)
        int num5 = 8;
        boolean result5 = isSmithNumber(num5);
        ArrayList<Integer> factors5 = getPrimeFactors(num5);
        int sumDigits5 = sumOfDigits(num5);
        int sumFactors5 = sumOfDigitsOfFactors(factors5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Prime factors: " + factors5);
        System.out.println("Sum of digits of number: " + sumDigits5);
        System.out.println("Sum of digits of factors: " + sumFactors5);
        System.out.println("Is Smith number: " + result5);
        
        // Test Case 6 - Find Smith numbers in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> smithNums = getSmithNumbersInRange(start, end);
        System.out.println("\nSmith numbers in range [" + start + ", " + end + "]:");
        System.out.println(smithNums);
        System.out.println("Count: " + smithNums.size());
        
        // Test Case 7 - Smith number 666
        int num7 = 666;
        boolean result7 = isSmithNumber(num7);
        ArrayList<Integer> factors7 = getPrimeFactors(num7);
        int sumDigits7 = sumOfDigits(num7);
        int sumFactors7 = sumOfDigitsOfFactors(factors7);
        System.out.println("\nNumber: " + num7);
        System.out.println("Prime factors: " + factors7);
        System.out.println("Sum of digits of number: " + sumDigits7);
        System.out.println("Sum of digits of factors: " + sumFactors7);
        System.out.println("Is Smith number: " + result7);
    }
}
