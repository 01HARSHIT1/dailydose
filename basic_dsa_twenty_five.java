/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_five {
    
    // Problem 1: Check if a Number is Pronic/Heteromecic Number
    // A Pronic number (also called Heteromecic number) is a number that is the product of two consecutive integers
    // Example: 6 = 2 × 3, 12 = 3 × 4, 20 = 4 × 5
    
    /**
     * Check if a number is Pronic/Heteromecic number
     * A Pronic number is the product of two consecutive integers
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isPronicNumber(int n) {
        if (n < 0) {
            return false;
        }
        
        // Check if there exists an integer i such that i * (i + 1) == n
        for (int i = 0; i * (i + 1) <= n; i++) {
            if (i * (i + 1) == n) {
                return true;
            }
        }
        
        return false;
    }
    
    /**
     * Get the two consecutive factors if number is Pronic
     * Returns array [i, i+1] if Pronic, null otherwise
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static int[] getPronicFactors(int n) {
        if (n < 0) {
            return null;
        }
        
        for (int i = 0; i * (i + 1) <= n; i++) {
            if (i * (i + 1) == n) {
                return new int[]{i, i + 1};
            }
        }
        
        return null;
    }
    
    /**
     * Find all Pronic numbers in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(k) where k is the number of Pronic numbers
     */
    public static ArrayList<Integer> getPronicNumbersInRange(int start, int end) {
        ArrayList<Integer> pronicNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isPronicNumber(num)) {
                pronicNumbers.add(num);
            }
        }
        
        return pronicNumbers;
    }
    
    // Problem 2: Check if a Number is Deficient Number
    // A Deficient number is a number for which the sum of its proper divisors is less than the number itself
    // Example: 8 has proper divisors 1, 2, 4, sum = 7 < 8, so 8 is deficient
    
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
     * Check if a number is deficient number
     * Sum of proper divisors is less than the number itself
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     */
    public static boolean isDeficientNumber(int n) {
        if (n <= 0) {
            return false;
        }
        return sumOfProperDivisors(n) < n;
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
    
    /**
     * Find all Deficient numbers in a given range
     * Time Complexity: O((end - start) * √n)
     * Space Complexity: O(k) where k is the number of Deficient numbers
     */
    public static ArrayList<Integer> getDeficientNumbersInRange(int start, int end) {
        ArrayList<Integer> deficientNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isDeficientNumber(num)) {
                deficientNumbers.add(num);
            }
        }
        
        return deficientNumbers;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Pronic/Heteromecic Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Pronic number 6
        int num1 = 6;
        boolean result1 = isPronicNumber(num1);
        int[] factors1 = getPronicFactors(num1);
        System.out.println("Number: " + num1);
        if (factors1 != null) {
            System.out.println("Factors: " + factors1[0] + " × " + factors1[1] + " = " + num1);
        }
        System.out.println("Is Pronic number: " + result1);
        
        // Test Case 2 - Pronic number 12
        int num2 = 12;
        boolean result2 = isPronicNumber(num2);
        int[] factors2 = getPronicFactors(num2);
        System.out.println("\nNumber: " + num2);
        if (factors2 != null) {
            System.out.println("Factors: " + factors2[0] + " × " + factors2[1] + " = " + num2);
        }
        System.out.println("Is Pronic number: " + result2);
        
        // Test Case 3 - Not Pronic number
        int num3 = 10;
        boolean result3 = isPronicNumber(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Is Pronic number: " + result3);
        
        // Test Case 4 - Pronic number 0
        int num4 = 0;
        boolean result4 = isPronicNumber(num4);
        int[] factors4 = getPronicFactors(num4);
        System.out.println("\nNumber: " + num4);
        if (factors4 != null) {
            System.out.println("Factors: " + factors4[0] + " × " + factors4[1] + " = " + num4);
        }
        System.out.println("Is Pronic number: " + result4);
        
        // Test Case 5 - Find Pronic numbers in range
        int start = 0;
        int end = 50;
        ArrayList<Integer> pronicNums = getPronicNumbersInRange(start, end);
        System.out.println("\nPronic numbers in range [" + start + ", " + end + "]:");
        System.out.println(pronicNums);
        System.out.println("Count: " + pronicNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Number is Deficient Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Deficient number 8
        int num1_def = 8;
        boolean result1_def = isDeficientNumber(num1_def);
        ArrayList<Integer> divisors1 = getProperDivisors(num1_def);
        int sum1 = divisors1.stream().mapToInt(Integer::intValue).sum();
        System.out.println("Number: " + num1_def);
        System.out.println("Proper divisors: " + divisors1);
        System.out.println("Sum of proper divisors: " + sum1);
        System.out.println("Is deficient: " + result1_def);
        
        // Test Case 2 - Not deficient (perfect number 6)
        int num2_def = 6;
        boolean result2_def = isDeficientNumber(num2_def);
        ArrayList<Integer> divisors2 = getProperDivisors(num2_def);
        int sum2 = divisors2.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num2_def);
        System.out.println("Proper divisors: " + divisors2);
        System.out.println("Sum of proper divisors: " + sum2);
        System.out.println("Is deficient: " + result2_def);
        
        // Test Case 3 - Deficient number 10
        int num3_def = 10;
        boolean result3_def = isDeficientNumber(num3_def);
        ArrayList<Integer> divisors3 = getProperDivisors(num3_def);
        int sum3 = divisors3.stream().mapToInt(Integer::intValue).sum();
        System.out.println("\nNumber: " + num3_def);
        System.out.println("Proper divisors: " + divisors3);
        System.out.println("Sum of proper divisors: " + sum3);
        System.out.println("Is deficient: " + result3_def);
        
        // Test Case 4 - Deficient number 1
        int num4_def = 1;
        boolean result4_def = isDeficientNumber(num4_def);
        System.out.println("\nNumber: " + num4_def);
        System.out.println("Is deficient: " + result4_def);
        
        // Test Case 5 - Find Deficient numbers in range
        int start_def = 1;
        int end_def = 30;
        ArrayList<Integer> deficientNums = getDeficientNumbersInRange(start_def, end_def);
        System.out.println("\nDeficient numbers in range [" + start_def + ", " + end_def + "]:");
        System.out.println(deficientNums);
        System.out.println("Count: " + deficientNums.size());
    }
}
