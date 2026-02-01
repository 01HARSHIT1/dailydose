/**
 * Basic DSA Problems - Power of Three
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_sixty_two {

    // Problem: Check if a Number is Power of Three
    // A number is power of 3 if it can be written as 3^k for some non-negative integer k.
    // Examples: 1, 3, 9, 27, 81... (3^0, 3^1, 3^2, 3^3...)

    /**
     * Check using loop - repeatedly divide by 3
     * Time Complexity: O(log n base 3)
     */
    public static boolean isPowerOfThreeLoop(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }

    /**
     * Check using math: largest power of 3 in int is 3^19 = 1162261467
     * n is power of 3 iff n > 0 and 1162261467 % n == 0
     * Time Complexity: O(1)
     */
    public static boolean isPowerOfThreeMath(int n) {
        return n > 0 && 1162261467 % n == 0;
    }

    /**
     * Get exponent k if n = 3^k, else -1
     */
    public static int getPowerOfThreeExponent(int n) {
        if (!isPowerOfThreeLoop(n)) return -1;
        int k = 0;
        while (n > 1) {
            n /= 3;
            k++;
        }
        return k;
    }

    /**
     * Get powers of 3 in a range
     */
    public static java.util.ArrayList<Integer> getPowersOfThreeInRange(int start, int end) {
        java.util.ArrayList<Integer> list = new java.util.ArrayList<>();
        for (int p = 0; ; p++) {
            long val = (long) Math.pow(3, p);
            if (val > end) break;
            if (val >= start && val <= Integer.MAX_VALUE) list.add((int) val);
        }
        return list;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Power of Three");
        System.out.println("=".repeat(60));

        // Test 1: 9
        int n1 = 9;
        System.out.println("Number: " + n1 + " -> Is Power of 3: " + isPowerOfThreeLoop(n1) + " (3^2)");

        // Test 2: 27
        int n2 = 27;
        System.out.println("\nNumber: " + n2 + " -> Is Power of 3: " + isPowerOfThreeLoop(n2));

        // Test 3: 10 (not)
        int n3 = 10;
        System.out.println("\nNumber: " + n3 + " -> Is Power of 3: " + isPowerOfThreeLoop(n3));

        // Test 4: 1
        int n4 = 1;
        System.out.println("\nNumber: " + n4 + " (3^0) -> Is Power of 3: " + isPowerOfThreeLoop(n4));

        // Test 5: Math vs Loop
        int n5 = 81;
        System.out.println("\nNumber: " + n5 + " -> Loop: " + isPowerOfThreeLoop(n5) + ", Math: " + isPowerOfThreeMath(n5));

        // Test 6: Powers of 3 in range
        java.util.ArrayList<Integer> powers = getPowersOfThreeInRange(1, 100);
        System.out.println("\nPowers of 3 in [1, 100]: " + powers);
    }
}
