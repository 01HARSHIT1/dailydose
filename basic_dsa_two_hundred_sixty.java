/**
 * Basic DSA Problems - Single Number III
 * Find two elements that appear once; all others appear twice
 */
public class basic_dsa_two_hundred_sixty {

    // Problem: nums has exactly two elements that appear once, rest appear twice.
    // Return the two elements. O(n) time, O(1) space.

    /**
     * XOR all -> xor = a^b. Any set bit in xor distinguishes a and b.
     * Split by rightmost set bit, XOR each group separately.
     * Time O(n), Space O(1)
     */
    public static int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int x : nums) xor ^= x;
        int mask = xor & (-xor);
        int a = 0, b = 0;
        for (int x : nums) {
            if ((x & mask) == 0) a ^= x;
            else b ^= x;
        }
        return new int[]{a, b};
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Single Number III");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,1,3,2,5] -> " + java.util.Arrays.toString(singleNumber(new int[]{1, 2, 1, 3, 2, 5})));
        System.out.println("[-1,0] -> " + java.util.Arrays.toString(singleNumber(new int[]{-1, 0})));
    }
}
