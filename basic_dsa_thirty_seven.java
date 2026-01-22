/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_seven {
    
    // Problem: Check if a Number is Trimorphic
    // A Trimorphic number is a number whose cube ends with the number itself
    // Example: 4³ = 64 (ends with 4), 5³ = 125 (ends with 5), 25³ = 15625 (ends with 25)
    
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
     * Check if a number is Trimorphic number
     * A Trimorphic number's cube ends with the number itself
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isTrimorphicNumber(int n) {
        if (n < 0) {
            return false;
        }
        
        long cube = (long) n * n * n;
        int numDigits = countDigits(n);
        
        // Extract last numDigits from cube
        long divisor = (long) Math.pow(10, numDigits);
        long lastDigits = cube % divisor;
        
        return lastDigits == n;
    }
    
    /**
     * Find all Trimorphic numbers in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of Trimorphic numbers
     */
    public static ArrayList<Integer> getTrimorphicNumbersInRange(int start, int end) {
        ArrayList<Integer> trimorphicNumbers = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isTrimorphicNumber(num)) {
                trimorphicNumbers.add(num);
            }
        }
        
        return trimorphicNumbers;
    }
    
    /**
     * Get the last numDigits of cube of a number
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static long getCubeLastDigits(int n, int numDigits) {
        long cube = (long) n * n * n;
        long divisor = (long) Math.pow(10, numDigits);
        return cube % divisor;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Trimorphic");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Trimorphic number 4
        int num1 = 4;
        boolean result1 = isTrimorphicNumber(num1);
        long cube1 = (long) num1 * num1 * num1;
        long lastDigits1 = getCubeLastDigits(num1, countDigits(num1));
        System.out.println("Number: " + num1);
        System.out.println("Cube: " + cube1);
        System.out.println("Last digits of cube: " + lastDigits1);
        System.out.println("Is Trimorphic number: " + result1);
        
        // Test Case 2 - Trimorphic number 5
        int num2 = 5;
        boolean result2 = isTrimorphicNumber(num2);
        long cube2 = (long) num2 * num2 * num2;
        long lastDigits2 = getCubeLastDigits(num2, countDigits(num2));
        System.out.println("\nNumber: " + num2);
        System.out.println("Cube: " + cube2);
        System.out.println("Last digits of cube: " + lastDigits2);
        System.out.println("Is Trimorphic number: " + result2);
        
        // Test Case 3 - Trimorphic number 25
        int num3 = 25;
        boolean result3 = isTrimorphicNumber(num3);
        long cube3 = (long) num3 * num3 * num3;
        long lastDigits3 = getCubeLastDigits(num3, countDigits(num3));
        System.out.println("\nNumber: " + num3);
        System.out.println("Cube: " + cube3);
        System.out.println("Last digits of cube: " + lastDigits3);
        System.out.println("Is Trimorphic number: " + result3);
        
        // Test Case 4 - Not Trimorphic number
        int num4 = 6;
        boolean result4 = isTrimorphicNumber(num4);
        long cube4 = (long) num4 * num4 * num4;
        long lastDigits4 = getCubeLastDigits(num4, countDigits(num4));
        System.out.println("\nNumber: " + num4);
        System.out.println("Cube: " + cube4);
        System.out.println("Last digits of cube: " + lastDigits4);
        System.out.println("Is Trimorphic number: " + result4);
        
        // Test Case 5 - Single digit Trimorphic
        int num5 = 1;
        boolean result5 = isTrimorphicNumber(num5);
        long cube5 = (long) num5 * num5 * num5;
        System.out.println("\nNumber: " + num5);
        System.out.println("Cube: " + cube5);
        System.out.println("Is Trimorphic number: " + result5);
        
        // Test Case 6 - Find Trimorphic numbers in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> trimorphicNums = getTrimorphicNumbersInRange(start, end);
        System.out.println("\nTrimorphic numbers in range [" + start + ", " + end + "]:");
        System.out.println(trimorphicNums);
        System.out.println("Count: " + trimorphicNums.size());
        
        // Test Case 7 - Trimorphic number 49
        int num7 = 49;
        boolean result7 = isTrimorphicNumber(num7);
        long cube7 = (long) num7 * num7 * num7;
        long lastDigits7 = getCubeLastDigits(num7, countDigits(num7));
        System.out.println("\nNumber: " + num7);
        System.out.println("Cube: " + cube7);
        System.out.println("Last digits of cube: " + lastDigits7);
        System.out.println("Is Trimorphic number: " + result7);
    }
}
