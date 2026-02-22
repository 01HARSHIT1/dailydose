/**
 * Basic DSA Problems - Arithmetic Slices (LeetCode 413)
 * Count contiguous subarrays of length >= 3 with constant difference
 */
public class basic_dsa_four_hundred_thirteen {

    // Problem: Count arithmetic subarrays (len>=3, same diff between consecutive).

    /**
     * Extend arithmetic run; add (len-2) new slices when run grows.
     * Time O(n), Space O(1)
     */
    public static int numberOfArithmeticSlices(int[] nums) {
        if (nums.length < 3) return 0;
        int total = 0, run = 0;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                run++;
                total += run;
            } else run = 0;
        }
        return total;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Arithmetic Slices");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,4] -> " + numberOfArithmeticSlices(new int[]{1,2,3,4}));
        System.out.println("[1,2,3,8,9,10] -> " + numberOfArithmeticSlices(new int[]{1,2,3,8,9,10}));
    }
}
