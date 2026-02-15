/**
 * Basic DSA Problems - Single Number
 * Find the element that appears exactly once
 */
public class basic_dsa_three_hundred_ten {

    // Problem: Non-empty array where every element appears twice except one. Return that one.

    /**
     * XOR: a ^ a = 0, a ^ 0 = a. XOR all elements to cancel pairs, leave the single.
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
