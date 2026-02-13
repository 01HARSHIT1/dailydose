/**
 * Basic DSA Problems - Number of 1 Bits
 * Count set bits (Hamming weight)
 */
public class basic_dsa_two_hundred_seventy_four {

    // Problem: Return number of 1 bits in 32-bit unsigned integer.

    /**
     * n & (n-1) clears lowest set bit. Repeat until 0.
     * Time O(k) where k = number of set bits, Space O(1)
     */
    public static int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n &= n - 1;
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Number of 1 Bits");
        System.out.println("=".repeat(60));

        System.out.println("11 (binary 1011) -> " + hammingWeight(11));
        System.out.println("128 (binary 10000000) -> " + hammingWeight(128));
    }
}
