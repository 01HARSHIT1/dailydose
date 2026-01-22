/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_thirty_one {
    
    // Problem 1: Check if a Number is Perfect Cube
    // A perfect cube is a number that can be expressed as the cube of an integer
    // Example: 8 = 2³, 27 = 3³, 64 = 4³
    
    /**
     * Check if a number is perfect cube using math library
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isPerfectCubeMath(int n) {
        int num = Math.abs(n);
        int cubeRoot = (int) Math.round(Math.pow(num, 1.0 / 3));
        return cubeRoot * cubeRoot * cubeRoot == num;
    }
    
    /**
     * Check if a number is perfect cube using binary search
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isPerfectCubeBinarySearch(int n) {
        int num = Math.abs(n);
        if (num == 0 || num == 1) {
            return true;
        }
        
        long left = 1, right = num;
        
        while (left <= right) {
            long mid = (left + right) / 2;
            long cube = mid * mid * mid;
            
            if (cube == num) {
                return true;
            } else if (cube < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
    
    /**
     * Get the cube root if number is perfect cube
     * Returns cube root if perfect cube, -1 otherwise
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static long getCubeRoot(int n) {
        int num = Math.abs(n);
        boolean isNegative = n < 0;
        
        if (num == 0) {
            return 0;
        }
        if (num == 1) {
            return isNegative ? -1 : 1;
        }
        
        long left = 1, right = num;
        
        while (left <= right) {
            long mid = (left + right) / 2;
            long cube = mid * mid * mid;
            
            if (cube == num) {
                return isNegative ? -mid : mid;
            } else if (cube < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1; // Not a perfect cube
    }
    
    /**
     * Find all perfect cubes in a given range
     * Time Complexity: O((end - start) * log n)
     * Space Complexity: O(k) where k is the number of perfect cubes
     */
    public static ArrayList<Integer> getPerfectCubesInRange(int start, int end) {
        ArrayList<Integer> perfectCubes = new ArrayList<>();
        
        for (int num = start; num <= end; num++) {
            if (isPerfectCubeBinarySearch(num)) {
                perfectCubes.add(num);
            }
        }
        
        return perfectCubes;
    }
    
    // Problem 2: Find Sum of First N Even Numbers
    // Sum of first n even numbers = n(n+1)
    // Example: 2 + 4 + 6 + 8 = 20 = 4 × 5
    
    /**
     * Find sum of first n even numbers using iteration
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long sumOfEvenNumbersIterative(int n) {
        if (n <= 0) {
            return 0;
        }
        
        long total = 0;
        int even = 2;
        
        for (int i = 0; i < n; i++) {
            total += even;
            even += 2;
        }
        
        return total;
    }
    
    /**
     * Find sum of first n even numbers using formula
     * Sum = n(n+1)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static long sumOfEvenNumbersFormula(int n) {
        if (n <= 0) {
            return 0;
        }
        return (long) n * (n + 1);
    }
    
    /**
     * Find sum of first n even numbers using recursion
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static long sumOfEvenNumbersRecursive(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 2;
        }
        
        // nth even number = 2n
        int nthEven = 2 * n;
        return nthEven + sumOfEvenNumbersRecursive(n - 1);
    }
    
    /**
     * Get list of first n even numbers
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static ArrayList<Integer> getFirstNEvenNumbers(int n) {
        ArrayList<Integer> evenNumbers = new ArrayList<>();
        if (n <= 0) {
            return evenNumbers;
        }
        
        int even = 2;
        for (int i = 0; i < n; i++) {
            evenNumbers.add(even);
            even += 2;
        }
        
        return evenNumbers;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Check if a Number is Perfect Cube");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Perfect cube 8
        int num1 = 8;
        boolean result1_math = isPerfectCubeMath(num1);
        boolean result1_bs = isPerfectCubeBinarySearch(num1);
        long cubeRoot1 = getCubeRoot(num1);
        System.out.println("Number: " + num1);
        System.out.println("Is perfect cube (math): " + result1_math);
        System.out.println("Is perfect cube (binary search): " + result1_bs);
        if (cubeRoot1 != -1) {
            System.out.println("Cube root: " + cubeRoot1);
        }
        
        // Test Case 2 - Perfect cube 27
        int num2 = 27;
        boolean result2 = isPerfectCubeBinarySearch(num2);
        long cubeRoot2 = getCubeRoot(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Is perfect cube: " + result2);
        if (cubeRoot2 != -1) {
            System.out.println("Cube root: " + cubeRoot2);
        }
        
        // Test Case 3 - Not perfect cube
        int num3 = 25;
        boolean result3 = isPerfectCubeBinarySearch(num3);
        long cubeRoot3 = getCubeRoot(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Is perfect cube: " + result3);
        if (cubeRoot3 == -1) {
            System.out.println("Not a perfect cube");
        }
        
        // Test Case 4 - Perfect cube 1
        int num4 = 1;
        boolean result4 = isPerfectCubeBinarySearch(num4);
        long cubeRoot4 = getCubeRoot(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is perfect cube: " + result4);
        if (cubeRoot4 != -1) {
            System.out.println("Cube root: " + cubeRoot4);
        }
        
        // Test Case 5 - Find perfect cubes in range
        int start = 1;
        int end = 100;
        ArrayList<Integer> perfectCubes = getPerfectCubesInRange(start, end);
        System.out.println("\nPerfect cubes in range [" + start + ", " + end + "]:");
        System.out.println(perfectCubes);
        System.out.println("Count: " + perfectCubes.size());
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find Sum of First N Even Numbers");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Sum of first 4 even numbers
        int n1 = 4;
        long result1_iter = sumOfEvenNumbersIterative(n1);
        long result1_formula = sumOfEvenNumbersFormula(n1);
        long result1_rec = sumOfEvenNumbersRecursive(n1);
        ArrayList<Integer> evenNums1 = getFirstNEvenNumbers(n1);
        System.out.println("n = " + n1);
        System.out.println("First " + n1 + " even numbers: " + evenNums1);
        System.out.println("Sum (iterative): " + result1_iter);
        System.out.println("Sum (formula): " + result1_formula);
        System.out.println("Sum (recursive): " + result1_rec);
        System.out.println("Verification: " + n1 + " × (" + n1 + " + 1) = " + (n1 * (n1 + 1)));
        
        // Test Case 2 - Sum of first 10 even numbers
        int n2 = 10;
        long result2_sum = sumOfEvenNumbersFormula(n2);
        ArrayList<Integer> evenNums2 = getFirstNEvenNumbers(n2);
        System.out.println("\nn = " + n2);
        System.out.println("First " + n2 + " even numbers: " + evenNums2);
        System.out.println("Sum: " + result2_sum);
        System.out.println("Verification: " + n2 + " × (" + n2 + " + 1) = " + (n2 * (n2 + 1)));
        
        // Test Case 3 - Sum of first 1 even number
        int n3 = 1;
        long result3_sum = sumOfEvenNumbersFormula(n3);
        System.out.println("\nn = " + n3);
        System.out.println("Sum: " + result3_sum);
        
        // Test Case 4 - Sum of first 5 even numbers
        int n4 = 5;
        long result4_sum = sumOfEvenNumbersFormula(n4);
        ArrayList<Integer> evenNums4 = getFirstNEvenNumbers(n4);
        System.out.println("\nn = " + n4);
        System.out.println("First " + n4 + " even numbers: " + evenNums4);
        System.out.println("Sum: " + result4_sum);
        
        // Test Case 5 - Large n
        int n5 = 20;
        long result5_sum = sumOfEvenNumbersFormula(n5);
        System.out.println("\nn = " + n5);
        System.out.println("Sum of first " + n5 + " even numbers: " + result5_sum);
        System.out.println("Verification: " + n5 + " × (" + n5 + " + 1) = " + ((long) n5 * (n5 + 1)));
    }
}
