/**
 * Basic DSA Problems - Power of Two
 * Check if integer n is a power of 2 using bit manipulation
 */
public class basic_dsa_two_hundred_thirty_three {

    // Problem: Given integer n, return true if it is a power of 2. Otherwise return false.
    // Power of 2: 1, 2, 4, 8, 16, ... (2^0, 2^1, 2^2, etc.)

    /**
     * Powers of 2 have exactly one bit set. n & (n-1) clears the lowest set bit.
     * If n is power of 2: n has one bit, n-1 has all lower bits set, so n & (n-1) == 0.
     * Must handle n <= 0.
     * Time O(1), Space O(1)
     */
    public static boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Power of Two");
        System.out.println("=".repeat(60));

        System.out.println("1 -> " + isPowerOfTwo(1));
        System.out.println("2 -> " + isPowerOfTwo(2));
        System.out.println("4 -> " + isPowerOfTwo(4));
        System.out.println("16 -> " + isPowerOfTwo(16));
        System.out.println("3 -> " + isPowerOfTwo(3));
        System.out.println("0 -> " + isPowerOfTwo(0));
        System.out.println("-4 -> " + isPowerOfTwo(-4));
    }
}
