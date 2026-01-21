/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_twenty_seven {
    
    // Problem 1: Check if a Number is Odious Number
    // An Odious number is a number that has an odd number of 1s in its binary representation
    // Example: 4 in binary is 100 (has 1 one, which is odd, so it's Odious)
    
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
     * Check if a number is Odious number (odd number of 1s in binary)
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isOdiousNumber(int n) {
        int onesCount = countOnesInBinary(Math.abs(n));
        return onesCount % 2 == 1;
    }
    
    /**
     * Check if a number is Odious number using bitwise operations
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isOdiousNumberBitwise(int n) {
        int num = Math.abs(n);
        int count = 0;
        
        while (num > 0) {
            count += num & 1; // Check if last bit is 1
            num >>= 1; // Right shift
        }
        
        return count % 2 == 1;
    }
    
    /**
     * Find all Odious numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Odious numbers
     */
    public static ArrayList<Integer> getOdiousNumbersInRange(int start, int end) {
        ArrayList<Integer> odiousNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isOdiousNumber(num)) {
                odiousNumbers.add(num);
            }
        }
        
        return odiousNumbers;
    }
    
    // Problem 2: Calculate Compound Interest
    // Compound Interest = Principal × (1 + Rate/100)^Time - Principal
    // Amount = Principal × (1 + Rate/100)^Time
    
    /**
     * Calculate compound interest
     * Compound Interest = Principal × (1 + Rate/100)^Time - Principal
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculateCompoundInterest(double principal, double rate, double time) {
        if (principal < 0 || rate < 0 || time < 0) {
            throw new IllegalArgumentException("Principal, rate, and time must be non-negative");
        }
        
        double amount = principal * Math.pow(1 + rate / 100.0, time);
        return amount - principal;
    }
    
    /**
     * Calculate total amount with compound interest
     * Amount = Principal × (1 + Rate/100)^Time
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculateAmountCompoundInterest(double principal, double rate, double time) {
        if (principal < 0 || rate < 0 || time < 0) {
            throw new IllegalArgumentException("Principal, rate, and time must be non-negative");
        }
        
        return principal * Math.pow(1 + rate / 100.0, time);
    }
    
    /**
     * Calculate compound interest compounded n times per year
     * Amount = Principal × (1 + Rate/(100×n))^(n×Time)
     * Returns array [interest, amount]
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double[] calculateCompoundInterestCompoundedNTimes(double principal, double rate, double time, int n) {
        if (principal < 0 || rate < 0 || time < 0 || n <= 0) {
            throw new IllegalArgumentException("Principal, rate, and time must be non-negative, n must be positive");
        }
        
        double amount = principal * Math.pow(1 + rate / (100.0 * n), n * time);
        double interest = amount - principal;
        return new double[]{interest, amount};
    }
    
    /**
     * Calculate principal from compound interest amount
     * Principal = Amount / (1 + Rate/100)^Time
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static double calculatePrincipalFromCompoundInterest(double amount, double rate, double time) {
        if (amount < 0 || rate < 0 || time < 0) {
            throw new IllegalArgumentException("Amount, rate, and time must be non-negative");
        }
        
        if (rate == 0) {
            return amount;
        }
        
        return amount / Math.pow(1 + rate / 100.0, time);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Odious Number");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Odious number 4
        int num1 = 4;
        boolean result1 = isOdiousNumber(num1);
        boolean result1_bitwise = isOdiousNumberBitwise(num1);
        String binary1 = Integer.toBinaryString(num1);
        int ones1 = countOnesInBinary(num1);
        System.out.println("Number: " + num1);
        System.out.println("Binary: " + binary1);
        System.out.println("Number of 1s: " + ones1);
        System.out.println("Is Odious number: " + result1);
        System.out.println("Is Odious number (bitwise): " + result1_bitwise);
        
        // Test Case 2 - Not Odious number 3
        int num2 = 3;
        boolean result2 = isOdiousNumber(num2);
        String binary2 = Integer.toBinaryString(num2);
        int ones2 = countOnesInBinary(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Binary: " + binary2);
        System.out.println("Number of 1s: " + ones2);
        System.out.println("Is Odious number: " + result2);
        
        // Test Case 3 - Odious number 7
        int num3 = 7;
        boolean result3 = isOdiousNumber(num3);
        String binary3 = Integer.toBinaryString(num3);
        int ones3 = countOnesInBinary(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Binary: " + binary3);
        System.out.println("Number of 1s: " + ones3);
        System.out.println("Is Odious number: " + result3);
        
        // Test Case 4 - Zero
        int num4 = 0;
        boolean result4 = isOdiousNumber(num4);
        String binary4 = Integer.toBinaryString(num4);
        int ones4 = countOnesInBinary(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Binary: " + binary4);
        System.out.println("Number of 1s: " + ones4);
        System.out.println("Is Odious number: " + result4);
        
        // Test Case 5 - Find Odious numbers in range
        int start = 1;
        int end = 20;
        ArrayList<Integer> odiousNums = getOdiousNumbersInRange(start, end);
        System.out.println("\nOdious numbers in range [" + start + ", " + end + "]:");
        System.out.println(odiousNums);
        System.out.println("Count: " + odiousNums.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Calculate Compound Interest");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Basic compound interest
        double principal1 = 10000;
        double rate1 = 5;
        double time1 = 2;
        double interest1 = calculateCompoundInterest(principal1, rate1, time1);
        double amount1 = calculateAmountCompoundInterest(principal1, rate1, time1);
        System.out.println("Principal: ₹" + principal1);
        System.out.println("Rate: " + rate1 + "% per annum");
        System.out.println("Time: " + time1 + " years");
        System.out.println("Compound Interest: ₹" + String.format("%.2f", interest1));
        System.out.println("Total Amount: ₹" + String.format("%.2f", amount1));
        
        // Test Case 2 - Different values
        double principal2 = 5000;
        double rate2 = 7.5;
        double time2 = 3;
        double interest2 = calculateCompoundInterest(principal2, rate2, time2);
        double amount2 = calculateAmountCompoundInterest(principal2, rate2, time2);
        System.out.println("\nPrincipal: ₹" + principal2);
        System.out.println("Rate: " + rate2 + "% per annum");
        System.out.println("Time: " + time2 + " years");
        System.out.println("Compound Interest: ₹" + String.format("%.2f", interest2));
        System.out.println("Total Amount: ₹" + String.format("%.2f", amount2));
        
        // Test Case 3 - Quarterly compounding
        double principal3_ci = 10000;
        double rate3_ci = 8;
        double time3_ci = 2;
        int n3_ci = 4; // Quarterly
        double[] result3_ci = calculateCompoundInterestCompoundedNTimes(principal3_ci, rate3_ci, time3_ci, n3_ci);
        System.out.println("\nPrincipal: ₹" + principal3_ci);
        System.out.println("Rate: " + rate3_ci + "% per annum");
        System.out.println("Time: " + time3_ci + " years");
        System.out.println("Compounding: " + n3_ci + " times per year (Quarterly)");
        System.out.println("Compound Interest: ₹" + String.format("%.2f", result3_ci[0]));
        System.out.println("Total Amount: ₹" + String.format("%.2f", result3_ci[1]));
        
        // Test Case 4 - Calculate principal from amount
        double amount4 = 11025;
        double rate4 = 5;
        double time4 = 2;
        double principal4 = calculatePrincipalFromCompoundInterest(amount4, rate4, time4);
        System.out.println("\nAmount: ₹" + amount4);
        System.out.println("Rate: " + rate4 + "% per annum");
        System.out.println("Time: " + time4 + " years");
        System.out.println("Principal: ₹" + String.format("%.2f", principal4));
        
        // Test Case 5 - Monthly compounding
        double principal5 = 10000;
        double rate5 = 6;
        double time5 = 1;
        int n5 = 12; // Monthly
        double[] result5 = calculateCompoundInterestCompoundedNTimes(principal5, rate5, time5, n5);
        System.out.println("\nPrincipal: ₹" + principal5);
        System.out.println("Rate: " + rate5 + "% per annum");
        System.out.println("Time: " + time5 + " year");
        System.out.println("Compounding: " + n5 + " times per year (Monthly)");
        System.out.println("Compound Interest: ₹" + String.format("%.2f", result5[0]));
        System.out.println("Total Amount: ₹" + String.format("%.2f", result5[1]));
    }
}
