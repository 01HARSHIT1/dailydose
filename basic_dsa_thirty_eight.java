/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_eight {
    
    // Problem: Check if a Number is Circular Prime
    // A Circular Prime is a prime number that remains prime when its digits are rotated
    // Example: 197 is circular prime because 197, 971, and 719 are all prime
    // Note: Single-digit primes (2, 3, 5, 7) are circular primes
    
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
     * Rotate a number by moving the last digit to the front
     * Example: 197 -> 719
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int rotateNumber(int n) {
        if (n < 10) {
            return n;
        }
        
        int lastDigit = n % 10;
        int remaining = n / 10;
        int numDigits = countDigits(n);
        
        // Move last digit to front
        int rotated = lastDigit * (int) Math.pow(10, numDigits - 1) + remaining;
        
        return rotated;
    }
    
    /**
     * Get all rotations of a number
     * Time Complexity: O(d * log n) where d is number of digits
     * Space Complexity: O(d)
     */
    public static ArrayList<Integer> getAllRotations(int n) {
        ArrayList<Integer> rotations = new ArrayList<>();
        int numDigits = countDigits(n);
        int current = n;
        
        for (int i = 0; i < numDigits; i++) {
            rotations.add(current);
            current = rotateNumber(current);
        }
        
        return rotations;
    }
    
    /**
     * Check if a number is Circular Prime
     * A Circular Prime remains prime when its digits are rotated
     * Time Complexity: O(d * √n) where d is number of digits
     * Space Complexity: O(d)
     */
    public static boolean isCircularPrime(int n) {
        if (n < 2) {
            return false;
        }
        
        // Get all rotations
        ArrayList<Integer> rotations = getAllRotations(n);
        
        // Check if all rotations are prime
        for (int rotation : rotations) {
            if (!isPrime(rotation)) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * Find all Circular Prime numbers in a given range
     * Time Complexity: O((end - start) * d * √n)
     * Space Complexity: O(k) where k is the number of Circular Primes
     */
    public static ArrayList<Integer> getCircularPrimesInRange(int start, int end) {
        ArrayList<Integer> circularPrimes = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isCircularPrime(num)) {
                circularPrimes.add(num);
            }
        }
        
        return circularPrimes;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Circular Prime");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Circular Prime 2
        int num1 = 2;
        boolean result1 = isCircularPrime(num1);
        ArrayList<Integer> rotations1 = getAllRotations(num1);
        System.out.println("Number: " + num1);
        System.out.println("Rotations: " + rotations1);
        System.out.println("Is Circular Prime: " + result1);
        
        // Test Case 2 - Circular Prime 197
        int num2 = 197;
        boolean result2 = isCircularPrime(num2);
        ArrayList<Integer> rotations2 = getAllRotations(num2);
        boolean allPrime2 = true;
        for (int r : rotations2) {
            if (!isPrime(r)) {
                allPrime2 = false;
                break;
            }
        }
        System.out.println("\nNumber: " + num2);
        System.out.println("Rotations: " + rotations2);
        System.out.println("All rotations prime: " + allPrime2);
        System.out.println("Is Circular Prime: " + result2);
        
        // Test Case 3 - Circular Prime 113
        int num3 = 113;
        boolean result3 = isCircularPrime(num3);
        ArrayList<Integer> rotations3 = getAllRotations(num3);
        boolean allPrime3 = true;
        for (int r : rotations3) {
            if (!isPrime(r)) {
                allPrime3 = false;
                break;
            }
        }
        System.out.println("\nNumber: " + num3);
        System.out.println("Rotations: " + rotations3);
        System.out.println("All rotations prime: " + allPrime3);
        System.out.println("Is Circular Prime: " + result3);
        
        // Test Case 4 - Not Circular Prime (19)
        int num4 = 19;
        boolean result4 = isCircularPrime(num4);
        ArrayList<Integer> rotations4 = getAllRotations(num4);
        boolean allPrime4 = true;
        for (int r : rotations4) {
            if (!isPrime(r)) {
                allPrime4 = false;
                break;
            }
        }
        System.out.println("\nNumber: " + num4);
        System.out.println("Rotations: " + rotations4);
        System.out.println("All rotations prime: " + allPrime4);
        System.out.println("Is Circular Prime: " + result4);
        
        // Test Case 5 - Single digit Circular Prime 7
        int num5 = 7;
        boolean result5 = isCircularPrime(num5);
        ArrayList<Integer> rotations5 = getAllRotations(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Rotations: " + rotations5);
        System.out.println("Is Circular Prime: " + result5);
        
        // Test Case 6 - Find Circular Primes in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> circularPrimes = getCircularPrimesInRange(start, end);
        System.out.println("\nCircular Prime numbers in range [" + start + ", " + end + "]:");
        System.out.println(circularPrimes);
        System.out.println("Count: " + circularPrimes.size());
        
        // Test Case 7 - Circular Prime 199
        int num7 = 199;
        boolean result7 = isCircularPrime(num7);
        ArrayList<Integer> rotations7 = getAllRotations(num7);
        boolean allPrime7 = true;
        for (int r : rotations7) {
            if (!isPrime(r)) {
                allPrime7 = false;
                break;
            }
        }
        System.out.println("\nNumber: " + num7);
        System.out.println("Rotations: " + rotations7);
        System.out.println("All rotations prime: " + allPrime7);
        System.out.println("Is Circular Prime: " + result7);
    }
}
