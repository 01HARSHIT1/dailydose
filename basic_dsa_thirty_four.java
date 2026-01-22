/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_four {
    
    // Problem: Check if Two Numbers are Twin Primes
    // Twin primes are pairs of prime numbers that differ by 2
    // Example: (3, 5), (5, 7), (11, 13), (17, 19) are twin prime pairs
    
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
     * Check if two numbers are twin primes
     * Twin primes are pairs of primes that differ by exactly 2
     * Time Complexity: O(√a + √b)
     * Space Complexity: O(1)
     */
    public static boolean areTwinPrimes(int a, int b) {
        // Check if both are prime
        if (!isPrime(a) || !isPrime(b)) {
            return false;
        }
        
        // Check if they differ by 2
        return Math.abs(a - b) == 2;
    }
    
    /**
     * Find all twin prime pairs in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(k) where k is the number of twin prime pairs
     */
    public static ArrayList<int[]> getTwinPrimePairsInRange(int start, int end) {
        ArrayList<int[]> twinPairs = new ArrayList<>();
        
        for (int num = start; num < end; num++) {
            if (isPrime(num) && isPrime(num + 2) && (num + 2) <= end) {
                twinPairs.add(new int[]{num, num + 2});
            }
        }
        
        return twinPairs;
    }
    
    /**
     * Get all twin prime pairs up to n
     * Time Complexity: O(n * √n)
     * Space Complexity: O(k) where k is the number of twin prime pairs
     */
    public static ArrayList<int[]> getAllTwinPrimesUpTo(int n) {
        ArrayList<int[]> twinPairs = new ArrayList<>();
        
        // Start from 3 (first twin prime pair is (3, 5))
        for (int num = 3; num < n - 1; num++) {
            if (isPrime(num) && isPrime(num + 2)) {
                twinPairs.add(new int[]{num, num + 2});
            }
        }
        
        return twinPairs;
    }
    
    /**
     * Count number of twin prime pairs in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(1)
     */
    public static int countTwinPrimesInRange(int start, int end) {
        int count = 0;
        
        for (int num = start; num < end; num++) {
            if (isPrime(num) && isPrime(num + 2) && (num + 2) <= end) {
                count++;
            }
        }
        
        return count;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if Two Numbers are Twin Primes");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Twin primes (3, 5)
        int a1 = 3, b1 = 5;
        boolean result1 = areTwinPrimes(a1, b1);
        System.out.println("Numbers: (" + a1 + ", " + b1 + ")");
        System.out.println("Are twin primes: " + result1);
        
        // Test Case 2 - Twin primes (5, 7)
        int a2 = 5, b2 = 7;
        boolean result2 = areTwinPrimes(a2, b2);
        System.out.println("\nNumbers: (" + a2 + ", " + b2 + ")");
        System.out.println("Are twin primes: " + result2);
        
        // Test Case 3 - Not twin primes (3, 7)
        int a3 = 3, b3 = 7;
        boolean result3 = areTwinPrimes(a3, b3);
        System.out.println("\nNumbers: (" + a3 + ", " + b3 + ")");
        System.out.println("Are twin primes: " + result3);
        
        // Test Case 4 - Not twin primes (4, 6) - not primes
        int a4 = 4, b4 = 6;
        boolean result4 = areTwinPrimes(a4, b4);
        System.out.println("\nNumbers: (" + a4 + ", " + b4 + ")");
        System.out.println("Are twin primes: " + result4);
        
        // Test Case 5 - Twin primes (11, 13)
        int a5 = 11, b5 = 13;
        boolean result5 = areTwinPrimes(a5, b5);
        System.out.println("\nNumbers: (" + a5 + ", " + b5 + ")");
        System.out.println("Are twin primes: " + result5);
        
        // Test Case 6 - Find twin prime pairs in range
        int start = 1;
        int end = 50;
        ArrayList<int[]> twinPairs = getTwinPrimePairsInRange(start, end);
        System.out.println("\nTwin prime pairs in range [" + start + ", " + end + "]:");
        for (int[] pair : twinPairs) {
            System.out.print("(" + pair[0] + ", " + pair[1] + ") ");
        }
        System.out.println("\nCount: " + twinPairs.size());
        
        // Test Case 7 - All twin primes up to 100
        int n7 = 100;
        ArrayList<int[]> allTwinPairs = getAllTwinPrimesUpTo(n7);
        System.out.println("\nAll twin prime pairs up to " + n7 + ":");
        for (int i = 0; i < allTwinPairs.size(); i++) {
            int[] pair = allTwinPairs.get(i);
            System.out.print("(" + pair[0] + ", " + pair[1] + ") ");
            if ((i + 1) % 5 == 0) {
                System.out.println();
            }
        }
        System.out.println("\nTotal count: " + allTwinPairs.size());
    }
}
