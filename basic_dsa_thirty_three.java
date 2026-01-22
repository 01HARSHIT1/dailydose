/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_three {
    
    // Problem: Find nth Prime Number
    // Find the nth prime number in the sequence of prime numbers
    // Example: 1st prime = 2, 2nd prime = 3, 3rd prime = 5, 4th prime = 7, 5th prime = 11
    
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
     * Find nth prime number using brute force
     * Time Complexity: O(n * √n)
     * Space Complexity: O(1)
     */
    public static int nthPrimeBruteForce(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("n must be positive");
        }
        
        if (n == 1) {
            return 2;
        }
        
        int count = 1;
        int num = 3;
        
        while (count < n) {
            if (isPrime(num)) {
                count++;
                if (count == n) {
                    return num;
                }
            }
            num += 2; // Check only odd numbers (except 2)
        }
        
        return num - 2;
    }
    
    /**
     * Find nth prime number using optimized approach with Sieve of Eratosthenes
     * Time Complexity: O(n log log n) for sieve
     * Space Complexity: O(n)
     */
    public static int nthPrimeSieveOptimized(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("n must be positive");
        }
        
        if (n == 1) {
            return 2;
        }
        
        // Estimate upper bound: n * log(n) + n * log(log(n)) for n > 6
        if (n <= 6) {
            int[] primes = {2, 3, 5, 7, 11, 13};
            return primes[n - 1];
        }
        
        int upperBound = (int) (n * Math.log(n) + n * Math.log(Math.log(n)));
        if (upperBound < 20) {
            upperBound = 20;
        }
        
        // Sieve of Eratosthenes
        boolean[] isPrimeList = new boolean[upperBound + 1];
        Arrays.fill(isPrimeList, true);
        isPrimeList[0] = isPrimeList[1] = false;
        
        for (int i = 2; i * i <= upperBound; i++) {
            if (isPrimeList[i]) {
                for (int j = i * i; j <= upperBound; j += i) {
                    isPrimeList[j] = false;
                }
            }
        }
        
        // Collect primes
        int count = 0;
        for (int i = 2; i <= upperBound; i++) {
            if (isPrimeList[i]) {
                count++;
                if (count == n) {
                    return i;
                }
            }
        }
        
        // If not enough primes found, use brute force
        return nthPrimeBruteForce(n);
    }
    
    /**
     * Get list of first n prime numbers
     * Time Complexity: O(n * √n)
     * Space Complexity: O(n)
     */
    public static ArrayList<Integer> getFirstNPrimes(int n) {
        ArrayList<Integer> primes = new ArrayList<>();
        if (n <= 0) {
            return primes;
        }
        
        int num = 2;
        
        while (primes.size() < n) {
            if (isPrime(num)) {
                primes.add(num);
            }
            num++;
        }
        
        return primes;
    }
    
    /**
     * Get all prime numbers in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(k) where k is the number of primes
     */
    public static ArrayList<Integer> getPrimesInRange(int start, int end) {
        ArrayList<Integer> primes = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isPrime(num)) {
                primes.add(num);
            }
        }
        
        return primes;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find nth Prime Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - 1st prime
        int n1 = 1;
        int result1 = nthPrimeBruteForce(n1);
        System.out.println("n = " + n1);
        System.out.println(n1 + "st prime number: " + result1);
        
        // Test Case 2 - 5th prime
        int n2 = 5;
        int result2 = nthPrimeBruteForce(n2);
        int result2_sieve = nthPrimeSieveOptimized(n2);
        System.out.println("\nn = " + n2);
        System.out.println(n2 + "th prime number (brute force): " + result2);
        System.out.println(n2 + "th prime number (sieve): " + result2_sieve);
        
        // Test Case 3 - 10th prime
        int n3 = 10;
        int result3 = nthPrimeBruteForce(n3);
        int result3_sieve = nthPrimeSieveOptimized(n3);
        System.out.println("\nn = " + n3);
        System.out.println(n3 + "th prime number (brute force): " + result3);
        System.out.println(n3 + "th prime number (sieve): " + result3_sieve);
        
        // Test Case 4 - First 10 primes
        int n4 = 10;
        ArrayList<Integer> primesList = getFirstNPrimes(n4);
        System.out.println("\nFirst " + n4 + " prime numbers:");
        System.out.println(primesList);
        
        // Test Case 5 - 20th prime
        int n5 = 20;
        int result5 = nthPrimeBruteForce(n5);
        System.out.println("\nn = " + n5);
        System.out.println(n5 + "th prime number: " + result5);
        
        // Test Case 6 - Primes in range
        int start = 10;
        int end = 50;
        ArrayList<Integer> primesRange = getPrimesInRange(start, end);
        System.out.println("\nPrime numbers in range [" + start + ", " + end + "]:");
        System.out.println(primesRange);
        System.out.println("Count: " + primesRange.size());
        
        // Test Case 7 - 100th prime
        int n7 = 100;
        int result7 = nthPrimeSieveOptimized(n7);
        System.out.println("\nn = " + n7);
        System.out.println(n7 + "th prime number: " + result7);
    }
}
