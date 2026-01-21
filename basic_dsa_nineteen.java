/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_nineteen {
    
    // Problem 1: Check if a Number is Abundant Number
    // An abundant number is a number for which the sum of its proper divisors is greater than the number itself
    // Example: 12 has proper divisors 1, 2, 3, 4, 6, sum = 16 > 12, so 12 is abundant
    
    /**
     * Calculate sum of proper divisors of a number
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static int sumOfProperDivisors(int n) {
        if (n <= 1) {
            return 0;
        }
        
        int sumDivisors = 1; // 1 is always a divisor
        
        // Check divisors from 2 to √n
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sumDivisors += i;
                // Add the corresponding divisor (avoid adding square twice)
                if (i != n / i) {
                    sumDivisors += n / i;
                }
            }
        }
        
        return sumDivisors;
    }
    
    /**
     * Check if a number is abundant number
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isAbundantNumber(int n) {
        if (n <= 0) {
            return false;
        }
        return sumOfProperDivisors(n) > n;
    }
    
    /**
     * Get all proper divisors of a number
     * Time Complexity: O(√n)
     * Space Complexity: O(√n)
     */
    public static ArrayList<Integer> getProperDivisors(int n) {
        ArrayList<Integer> divisors = new ArrayList<>();
        if (n <= 1) {
            return divisors;
        }
        
        divisors.add(1);
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i) {
                    divisors.add(n / i);
                }
            }
        }
        
        Collections.sort(divisors);
        return divisors;
    }
    
    // Problem 2: Find All Prime Numbers in a Range
    // Find all prime numbers between two given numbers using Sieve of Eratosthenes
    
    /**
     * Find all prime numbers up to n using Sieve of Eratosthenes
     * Time Complexity: O(n log log n)
     * Space Complexity: O(n)
     */
    public static ArrayList<Integer> sieveOfEratosthenes(int n) {
        if (n < 2) {
            return new ArrayList<>();
        }
        
        // Create boolean array, initially all true
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        
        // Mark multiples of primes as false
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i as non-prime
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Collect all prime numbers
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }
        
        return primes;
    }
    
    /**
     * Find all prime numbers in a given range [start, end]
     * Time Complexity: O(end log log end) for sieve + O(end - start) for filtering
     * Space Complexity: O(end)
     */
    public static ArrayList<Integer> primesInRange(int start, int end) {
        if (end < 2 || start > end) {
            return new ArrayList<>();
        }
        
        // Adjust start to be at least 2
        start = Math.max(2, start);
        
        // Use sieve to find all primes up to end
        ArrayList<Integer> allPrimes = sieveOfEratosthenes(end);
        
        // Filter primes in the range [start, end]
        ArrayList<Integer> primesInRangeList = new ArrayList<>();
        for (int prime : allPrimes) {
            if (prime >= start) {
                primesInRangeList.add(prime);
            }
        }
        
        return primesInRangeList;
    }
    
    /**
     * Simple prime check for a single number
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isPrimeSimple(int n) {
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
     * Count prime numbers in a given range
     * Time Complexity: O(end log log end)
     * Space Complexity: O(end)
     */
    public static int countPrimesInRange(int start, int end) {
        ArrayList<Integer> primes = primesInRange(start, end);
        return primes.size();
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Abundant Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Abundant number 12
        int num1 = 12;
        boolean result1 = isAbundantNumber(num1);
        ArrayList<Integer> divisors1 = getProperDivisors(num1);
        int sum1 = divisors1.stream().mapToInt(Integer::intValue).sum();
        System.out.println("Number: " + num1);
        System.out.println("Proper divisors: " + divisors1);
        System.out.println("Sum of proper divisors: " + sum1);
        System.out.println("Is abundant: " + result1);
        
        // Test Case 2 - Not abundant number
        int num2 = 10;
        boolean result2 = isAbundantNumber(num2);
        ArrayList<Integer> divisors2 = getProperDivisors(num2);
        int sum2 = divisors2.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num2);
        System.out.println("Proper divisors: " + divisors2);
        System.out.println("Sum of proper divisors: " + sum2);
        System.out.println("Is abundant: " + result2);
        
        // Test Case 3 - Abundant number 18
        int num3 = 18;
        boolean result3 = isAbundantNumber(num3);
        ArrayList<Integer> divisors3 = getProperDivisors(num3);
        int sum3 = divisors3.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num3);
        System.out.println("Proper divisors: " + divisors3);
        System.out.println("Sum of proper divisors: " + sum3);
        System.out.println("Is abundant: " + result3);
        
        // Test Case 4 - Perfect number (not abundant)
        int num4 = 6;
        boolean result4 = isAbundantNumber(num4);
        ArrayList<Integer> divisors4 = getProperDivisors(num4);
        int sum4 = divisors4.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num4);
        System.out.println("Proper divisors: " + divisors4);
        System.out.println("Sum of proper divisors: " + sum4);
        System.out.println("Is abundant: " + result4);
        
        // Test Case 5 - Deficient number (not abundant)
        int num5 = 8;
        boolean result5 = isAbundantNumber(num5);
        ArrayList<Integer> divisors5 = getProperDivisors(num5);
        int sum5 = divisors5.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num5);
        System.out.println("Proper divisors: " + divisors5);
        System.out.println("Sum of proper divisors: " + sum5);
        System.out.println("Is abundant: " + result5);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find All Prime Numbers in a Range");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Primes up to 30
        int n1 = 30;
        ArrayList<Integer> primes1 = sieveOfEratosthenes(n1);
        System.out.println("Prime numbers up to " + n1 + ":");
        System.out.println(primes1);
        System.out.println("Count: " + primes1.size());
        
        // Test Case 2 - Primes in range [10, 50]
        int start2 = 10;
        int end2 = 50;
        ArrayList<Integer> primes2 = primesInRange(start2, end2);
        System.out.println("\nPrime numbers in range [" + start2 + ", " + end2 + "]:");
        System.out.println(primes2);
        System.out.println("Count: " + primes2.size());
        
        // Test Case 3 - Primes in range [1, 20]
        int start3 = 1;
        int end3 = 20;
        ArrayList<Integer> primes3 = primesInRange(start3, end3);
        System.out.println("\nPrime numbers in range [" + start3 + ", " + end3 + "]:");
        System.out.println(primes3);
        System.out.println("Count: " + primes3.size());
        
        // Test Case 4 - Count primes in range
        int start4 = 2;
        int end4 = 100;
        int count4 = countPrimesInRange(start4, end4);
        System.out.println("\nNumber of primes in range [" + start4 + ", " + end4 + "]: " + count4);
        
        // Test Case 5 - Primes up to 100
        int n5 = 100;
        ArrayList<Integer> primes5 = sieveOfEratosthenes(n5);
        System.out.println("\nPrime numbers up to " + n5 + ":");
        System.out.println(primes5);
        System.out.println("Count: " + primes5.size());
    }
}
