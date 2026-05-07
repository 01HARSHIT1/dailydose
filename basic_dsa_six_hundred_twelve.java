/**
 * Basic DSA Problems - One Fundamental Kadane / DP Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twelve {

    // Problem 1: Maximum Subarray
    // Contiguous subarray with largest sum (at least one element if non-empty array).

    /**
     * Kadane: end each position at either nums[i] alone or extend previous best suffix
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int best = nums[0];
        int suffix = nums[0];

        for (int i = 1; i < nums.length; i++) {
            suffix = Math.max(nums[i], suffix + nums[i]);
            best = Math.max(best, suffix);
        }

        return best;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Maximum Subarray");
        System.out.println("=".repeat(60));

        int[] a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("mixed -> " + maxSubArray(a));

        int[] b = {1};
        System.out.println("[1] -> " + maxSubArray(b));

        int[] c = {5, 4, -1, 7, 8};
        System.out.println("positive tail -> " + maxSubArray(c));

        System.out.println("empty -> " + maxSubArray(new int[0]));
        System.out.println("null -> " + maxSubArray(null));
    }
}
