/**
 * Basic DSA Problems - One Fundamental Bit Manipulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_two {

    // Problem 1: Reverse Bits
    // Treat n as an unsigned 32-bit value; reverse bit order and return the result as int.

    /**
     * Build answer left-to-right from bits of n right-to-left (unsigned shift)
     * Time Complexity: O(32) = O(1)
     * Space Complexity: O(1)
     */
    public static int reverseBits(int n) {
        int result = 0;
        int x = n;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (x & 1);
            x >>>= 1;
        }
        return result;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse Bits");
        System.out.println("=".repeat(60));

        int sample = 43261596; // LeetCode example
        System.out.println("43261596 -> " + reverseBits(sample));

        int allOnesLow8 = 0b11111111;
        System.out.println("low 8 ones -> " + reverseBits(allOnesLow8));

        System.out.println("0 -> " + reverseBits(0));
        System.out.println("-1 -> " + reverseBits(-1));
    }
}
