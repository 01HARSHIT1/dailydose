/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_six {
    
    // Problem 1: Check if a Number is Evil Number
    // An Evil number is a number that has an even number of 1s in its binary representation
    // Example: 3 in binary is 11 (has 2 ones, which is even), so 3 is Evil
    
    /**
     * Count number of 1s in binary representation
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int countOnesInBinary(int n) {
        int count = 0;
        int num = Math.abs(n);
        
        while (num > 0) {
            if (num % 2 == 1) {
                count++;
            }
            num /= 2;
        }
        
        return count;
    }
    
    /**
     * Check if a number is Evil number (even number of 1s in binary)
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isEvilNumber(int n) {
        int onesCount = countOnesInBinary(Math.abs(n));
        return onesCount % 2 == 0;
    }
    
    /**
     * Check if a number is Evil number using bitwise operations
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isEvilNumberBitwise(int n) {
        int num = Math.abs(n);
        int count = 0;
        
        while (num > 0) {
            count += num & 1; // Check if last bit is 1
            num >>= 1; // Right shift
        }
        
        return count % 2 == 0;
    }
    
    /**
     * Find all Evil numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Evil numbers
     */
    public static ArrayList<Integer> getEvilNumbersInRange(int start, int end) {
        ArrayList<Integer> evilNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isEvilNumber(num)) {
                evilNumbers.add(num);
            }
        }
        
        return evilNumbers;
    }
    
    // Problem 2: Calculate Simple Interest
    // Simple Interest = (Principal × Rate × Time) / 100
    
    /**
     * Calculate simple interest
     * Simple Interest = (Principal × Rate × Time) / 100
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculateSimpleInterest(double principal, double rate, double time) {
        if (principal < 0 || rate < 0 || time < 0) {
            throw new IllegalArgumentException("Principal, rate, and time must be non-negative");
        }
        
        return (principal * rate * time) / 100.0;
    }
    
    /**
     * Calculate total amount with simple interest
     * Amount = Principal + Simple Interest
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculateAmountSimpleInterest(double principal, double rate, double time) {
        double interest = calculateSimpleInterest(principal, rate, time);
        return principal + interest;
    }
    
    /**
     * Calculate principal from simple interest
     * Principal = (Interest × 100) / (Rate × Time)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculatePrincipalFromInterest(double interest, double rate, double time) {
        if (rate == 0 || time == 0) {
            throw new IllegalArgumentException("Rate and time cannot be zero");
        }
        
        if (interest < 0 || rate < 0 || time < 0) {
            throw new IllegalArgumentException("Interest, rate, and time must be non-negative");
        }
        
        return (interest * 100.0) / (rate * time);
    }
    
    /**
     * Calculate time from simple interest
     * Time = (Interest × 100) / (Principal × Rate)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculateTimeFromInterest(double principal, double interest, double rate) {
        if (principal == 0 || rate == 0) {
            throw new IllegalArgumentException("Principal and rate cannot be zero");
        }
        
        if (principal < 0 || interest < 0 || rate < 0) {
            throw new IllegalArgumentException("Principal, interest, and rate must be non-negative");
        }
        
        return (interest * 100.0) / (principal * rate);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Evil Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Evil number 3
        int num1 = 3;
        boolean result1 = isEvilNumber(num1);
        boolean result1_bitwise = isEvilNumberBitwise(num1);
        String binary1 = Integer.toBinaryString(num1);
        int ones1 = countOnesInBinary(num1);
        System.out.println("Number: " + num1);
        System.out.println("Binary: " + binary1);
        System.out.println("Number of 1s: " + ones1);
        System.out.println("Is Evil number: " + result1);
        System.out.println("Is Evil number (bitwise): " + result1_bitwise);
        
        // Test Case 2 - Not Evil number 5
        int num2 = 5;
        boolean result2 = isEvilNumber(num2);
        String binary2 = Integer.toBinaryString(num2);
        int ones2 = countOnesInBinary(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Binary: " + binary2);
        System.out.println("Number of 1s: " + ones2);
        System.out.println("Is Evil number: " + result2);
        
        // Test Case 3 - Evil number 9
        int num3 = 9;
        boolean result3 = isEvilNumber(num3);
        String binary3 = Integer.toBinaryString(num3);
        int ones3 = countOnesInBinary(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Binary: " + binary3);
        System.out.println("Number of 1s: " + ones3);
        System.out.println("Is Evil number: " + result3);
        
        // Test Case 4 - Zero
        int num4 = 0;
        boolean result4 = isEvilNumber(num4);
        String binary4 = Integer.toBinaryString(num4);
        int ones4 = countOnesInBinary(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Binary: " + binary4);
        System.out.println("Number of 1s: " + ones4);
        System.out.println("Is Evil number: " + result4);
        
        // Test Case 5 - Find Evil numbers in range
        int start = 1;
        int end = 20;
        ArrayList<Integer> evilNums = getEvilNumbersInRange(start, end);
        System.out.println("\nEvil numbers in range [" + start + ", " + end + "]:");
        System.out.println(evilNums);
        System.out.println("Count: " + evilNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Calculate Simple Interest");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Basic simple interest
        double principal1 = 10000;
        double rate1 = 5;
        double time1 = 2;
        double interest1 = calculateSimpleInterest(principal1, rate1, time1);
        double amount1 = calculateAmountSimpleInterest(principal1, rate1, time1);
        System.out.println("Principal: ₹" + principal1);
        System.out.println("Rate: " + rate1 + "% per annum");
        System.out.println("Time: " + time1 + " years");
        System.out.println("Simple Interest: ₹" + interest1);
        System.out.println("Total Amount: ₹" + amount1);
        
        // Test Case 2 - Different values
        double principal2 = 5000;
        double rate2 = 7.5;
        double time2 = 3;
        double interest2 = calculateSimpleInterest(principal2, rate2, time2);
        double amount2 = calculateAmountSimpleInterest(principal2, rate2, time2);
        System.out.println("\nPrincipal: ₹" + principal2);
        System.out.println("Rate: " + rate2 + "% per annum");
        System.out.println("Time: " + time2 + " years");
        System.out.println("Simple Interest: ₹" + interest2);
        System.out.println("Total Amount: ₹" + amount2);
        
        // Test Case 3 - Calculate principal from interest
        double interest3 = 500;
        double rate3 = 5;
        double time3 = 2;
        double principal3 = calculatePrincipalFromInterest(interest3, rate3, time3);
        System.out.println("\nInterest: ₹" + interest3);
        System.out.println("Rate: " + rate3 + "% per annum");
        System.out.println("Time: " + time3 + " years");
        System.out.println("Principal: ₹" + principal3);
        
        // Test Case 4 - Calculate time from interest
        double principal4 = 10000;
        double interest4 = 1500;
        double rate4 = 5;
        double time4 = calculateTimeFromInterest(principal4, interest4, rate4);
        System.out.println("\nPrincipal: ₹" + principal4);
        System.out.println("Interest: ₹" + interest4);
        System.out.println("Rate: " + rate4 + "% per annum");
        System.out.println("Time: " + time4 + " years");
        
        // Test Case 5 - Zero interest
        double principal5 = 10000;
        double rate5 = 0;
        double time5 = 5;
        double interest5 = calculateSimpleInterest(principal5, rate5, time5);
        System.out.println("\nPrincipal: ₹" + principal5);
        System.out.println("Rate: " + rate5 + "% per annum");
        System.out.println("Time: " + time5 + " years");
        System.out.println("Simple Interest: ₹" + interest5);
    }
}
