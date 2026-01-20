/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_seven {
    
    // Problem 1: Find GCD (Greatest Common Divisor) / HCF (Highest Common Factor)
    // Find the greatest common divisor of two numbers
    
    /**
     * Find GCD using iterative approach (Euclidean Algorithm)
     * Time Complexity: O(log(min(a, b)))
     * Space Complexity: O(1)
     */
    public static int gcdIterative(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    /**
     * Find GCD using recursive approach (Euclidean Algorithm)
     * Time Complexity: O(log(min(a, b)))
     * Space Complexity: O(log(min(a, b))) due to recursion stack
     */
    public static int gcdRecursive(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        if (b == 0) {
            return a;
        }
        return gcdRecursive(b, a % b);
    }
    
    // Problem 2: Check if a Number is Perfect Square
    // Determine whether a number is a perfect square
    
    /**
     * Check if a number is perfect square using Math.sqrt
     * Time Complexity: O(1) - depends on sqrt implementation
     * Space Complexity: O(1)
     */
    public static boolean isPerfectSquare(int n) {
        if (n < 0) {
            return false;
        }
        
        int sqrtN = (int) Math.sqrt(n);
        return sqrtN * sqrtN == n;
    }
    
    /**
     * Check if a number is perfect square without using Math library
     * Using binary search approach
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static boolean isPerfectSquareNoLibrary(int n) {
        if (n < 0) {
            return false;
        }
        if (n == 0 || n == 1) {
            return true;
        }
        
        long left = 1;
        long right = n / 2;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            
            if (square == n) {
                return true;
            } else if (square < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Find GCD (Greatest Common Divisor)");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int a1 = 48, b1 = 18;
        int gcdIter1 = gcdIterative(a1, b1);
        int gcdRec1 = gcdRecursive(a1, b1);
        System.out.println("Numbers: " + a1 + ", " + b1);
        System.out.println("GCD (Iterative): " + gcdIter1);
        System.out.println("GCD (Recursive): " + gcdRec1);
        
        // Test Case 2
        int a2 = 100, b2 = 25;
        int gcdIter2 = gcdIterative(a2, b2);
        int gcdRec2 = gcdRecursive(a2, b2);
        System.out.println("\nNumbers: " + a2 + ", " + b2);
        System.out.println("GCD (Iterative): " + gcdIter2);
        System.out.println("GCD (Recursive): " + gcdRec2);
        
        // Test Case 3 - Coprime numbers
        int a3 = 17, b3 = 13;
        int gcdIter3 = gcdIterative(a3, b3);
        int gcdRec3 = gcdRecursive(a3, b3);
        System.out.println("\nNumbers: " + a3 + ", " + b3);
        System.out.println("GCD (Iterative): " + gcdIter3);
        System.out.println("GCD (Recursive): " + gcdRec3);
        
        // Test Case 4 - Same numbers
        int a4 = 15, b4 = 15;
        int gcdIter4 = gcdIterative(a4, b4);
        int gcdRec4 = gcdRecursive(a4, b4);
        System.out.println("\nNumbers: " + a4 + ", " + b4);
        System.out.println("GCD (Iterative): " + gcdIter4);
        System.out.println("GCD (Recursive): " + gcdRec4);
        
        // Test Case 5 - One is zero
        int a5 = 0, b5 = 15;
        int gcdIter5 = gcdIterative(a5, b5);
        int gcdRec5 = gcdRecursive(a5, b5);
        System.out.println("\nNumbers: " + a5 + ", " + b5);
        System.out.println("GCD (Iterative): " + gcdIter5);
        System.out.println("GCD (Recursive): " + gcdRec5);
        
        // Test Case 6 - Large numbers
        int a6 = 252, b6 = 105;
        int gcdIter6 = gcdIterative(a6, b6);
        int gcdRec6 = gcdRecursive(a6, b6);
        System.out.println("\nNumbers: " + a6 + ", " + b6);
        System.out.println("GCD (Iterative): " + gcdIter6);
        System.out.println("GCD (Recursive): " + gcdRec6);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Check if a Number is Perfect Square");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Perfect square
        int num1 = 25;
        boolean result1 = isPerfectSquare(num1);
        boolean result1b = isPerfectSquareNoLibrary(num1);
        System.out.println("Number: " + num1);
        System.out.println("Is Perfect Square (with Math): " + result1);
        System.out.println("Is Perfect Square (binary search): " + result1b);
        
        // Test Case 2 - Not a perfect square
        int num2 = 26;
        boolean result2 = isPerfectSquare(num2);
        boolean result2b = isPerfectSquareNoLibrary(num2);
        System.out.println("\nNumber: " + num2);
        System.out.println("Is Perfect Square (with Math): " + result2);
        System.out.println("Is Perfect Square (binary search): " + result2b);
        
        // Test Case 3 - Zero
        int num3 = 0;
        boolean result3 = isPerfectSquare(num3);
        boolean result3b = isPerfectSquareNoLibrary(num3);
        System.out.println("\nNumber: " + num3);
        System.out.println("Is Perfect Square (with Math): " + result3);
        System.out.println("Is Perfect Square (binary search): " + result3b);
        
        // Test Case 4 - One
        int num4 = 1;
        boolean result4 = isPerfectSquare(num4);
        boolean result4b = isPerfectSquareNoLibrary(num4);
        System.out.println("\nNumber: " + num4);
        System.out.println("Is Perfect Square (with Math): " + result4);
        System.out.println("Is Perfect Square (binary search): " + result4b);
        
        // Test Case 5 - Large perfect square
        int num5 = 144;
        boolean result5 = isPerfectSquare(num5);
        boolean result5b = isPerfectSquareNoLibrary(num5);
        System.out.println("\nNumber: " + num5);
        System.out.println("Is Perfect Square (with Math): " + result5);
        System.out.println("Is Perfect Square (binary search): " + result5b);
        
        // Test Case 6 - Negative number
        int num6 = -16;
        boolean result6 = isPerfectSquare(num6);
        boolean result6b = isPerfectSquareNoLibrary(num6);
        System.out.println("\nNumber: " + num6);
        System.out.println("Is Perfect Square (with Math): " + result6);
        System.out.println("Is Perfect Square (binary search): " + result6b);
        
        // Test Case 7 - Not perfect square
        int num7 = 50;
        boolean result7 = isPerfectSquare(num7);
        boolean result7b = isPerfectSquareNoLibrary(num7);
        System.out.println("\nNumber: " + num7);
        System.out.println("Is Perfect Square (with Math): " + result7);
        System.out.println("Is Perfect Square (binary search): " + result7b);
    }
}
