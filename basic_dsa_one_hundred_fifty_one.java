/**
 * Basic DSA Problems - Binary Number with Alternating Bits
 * Check if binary representation has alternating 0s and 1s
 */
public class basic_dsa_one_hundred_fifty_one {

    // Problem: Given positive integer n, return true if its binary representation has alternating bits
    // (no two adjacent bits are the same). Example: 5 (101) -> true, 7 (111) -> false

    /**
     * Check: n ^ (n >> 1) should be all 1s (alternating gives ...111)
     * Then check (n ^ (n >> 1)) & ((n ^ (n >> 1)) + 1) == 0 for "all 1s"
     * Or: x = n ^ (n >> 1), then x & (x+1) == 0 (x is of form 111...)
     * Time O(1), Space O(1)
     */
    public static boolean hasAlternatingBits(int n) {
        int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Number with Alternating Bits");
        System.out.println("=".repeat(60));

        System.out.println("5 (101) -> " + hasAlternatingBits(5));
        System.out.println("7 (111) -> " + hasAlternatingBits(7));
        System.out.println("11 (1011) -> " + hasAlternatingBits(11));
        System.out.println("10 (1010) -> " + hasAlternatingBits(10));
    }
}
