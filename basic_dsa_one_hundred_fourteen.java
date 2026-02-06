/**
 * Basic DSA Problems - Single Number
 * Find the element that appears once (others appear twice)
 */
public class basic_dsa_one_hundred_fourteen {

    // Problem: Given non-empty array where every element appears twice except one,
    // find that single one. Linear time and O(1) extra space.

    /**
     * XOR all elements: a ^ a = 0, so pairs cancel; result is the single number.
     * Time O(n), Space O(1)
     */
    public static int singleNumber(int[] nums) {
        if (nums == null || nums.length == 0) return -1;
        int x = 0;
        for (int n : nums) x ^= n;
        return x;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Single Number");
        System.out.println("=".repeat(60));

        System.out.println("[2,2,1] -> " + singleNumber(new int[] { 2, 2, 1 }));
        System.out.println("[4,1,2,1,2] -> " + singleNumber(new int[] { 4, 1, 2, 1, 2 }));
        System.out.println("[1] -> " + singleNumber(new int[] { 1 }));
    }
}
