/**
 * Basic DSA Problems - Single Number
 * Find the element that appears once (others appear twice)
 */
public class basic_dsa_one_hundred_fifty_five {

    // Problem: Non-empty array; every element appears twice except one. Return that one.

    /**
     * XOR of a number with itself is 0; XOR with 0 is the number. So XOR all elements.
     * Time O(n), Space O(1)
     */
    public static int singleNumber(int[] nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        return x;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Single Number");
        System.out.println("=".repeat(60));

        System.out.println("[2,2,1] -> " + singleNumber(new int[]{2, 2, 1}));
        System.out.println("[4,1,2,1,2] -> " + singleNumber(new int[]{4, 1, 2, 1, 2}));
        System.out.println("[1] -> " + singleNumber(new int[]{1}));
    }
}
