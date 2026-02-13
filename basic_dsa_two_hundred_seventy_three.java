/**
 * Basic DSA Problems - Reverse Bits
 * Reverse bits of 32-bit unsigned integer
 */
public class basic_dsa_two_hundred_seventy_three {

    // Problem: Reverse bits of 32-bit unsigned integer. Return reversed value.

    /**
     * Extract bits from right, shift result left and add. Repeat 32 times.
     * Time O(1), Space O(1)
     */
    public static int reverseBits(int n) {
        int out = 0;
        for (int i = 0; i < 32; i++) {
            out = (out << 1) | (n & 1);
            n >>>= 1;
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Bits");
        System.out.println("=".repeat(60));

        System.out.println("43261596 -> " + reverseBits(43261596));
        System.out.println("1 -> " + reverseBits(1));
    }
}
