/**
 * Basic DSA Problems - Power of Four (LeetCode 342)
 * Check if integer is a power of 4
 */
public class basic_dsa_three_hundred_forty_two {

    // Problem: Return true if n is power of 4 (1, 4, 16, 64, ...).

    /**
     * Power of 4: exactly one bit set, and it's in even position (0,2,4,...).
     * Use 0xAAAAAAAA to mask odd bits; power of 4 & odd mask == 0.
     * Time O(1), Space O(1)
     */
    public static boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Power of Four");
        System.out.println("=".repeat(60));

        System.out.println("16 -> " + isPowerOfFour(16));
        System.out.println("5 -> " + isPowerOfFour(5));
        System.out.println("1 -> " + isPowerOfFour(1));
    }
}
