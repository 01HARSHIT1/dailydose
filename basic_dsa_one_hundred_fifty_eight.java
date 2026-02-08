/**
 * Basic DSA Problems - Maximum Subarray (Kadane's Algorithm)
 * Find contiguous subarray with the largest sum
 */
public class basic_dsa_one_hundred_fifty_eight {

    // Problem: Given integer array nums, find contiguous subarray with largest sum. Return the sum.

    /**
     * Kadane: at each index, either extend current subarray or start fresh. Track max sum.
     * Time O(n), Space O(1)
     */
    public static int maxSubArray(int[] nums) {
        int cur = nums[0], max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            cur = Math.max(nums[i], cur + nums[i]);
            max = Math.max(max, cur);
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum Subarray");
        System.out.println("=".repeat(60));

        System.out.println("[-2,1,-3,4,-1,2,1,-5,4] -> " + maxSubArray(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4}));
        System.out.println("[1] -> " + maxSubArray(new int[]{1}));
        System.out.println("[5,4,-1,7,8] -> " + maxSubArray(new int[]{5, 4, -1, 7, 8}));
    }
}
