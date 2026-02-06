/**
 * Basic DSA Problems - Maximum Subarray (Kadane's Algorithm)
 * Find the contiguous subarray with the largest sum
 */
public class basic_dsa_ninety_nine {

    // Problem: Given an integer array nums, find the subarray with the largest sum
    // and return that sum. At least one element must be present.

    /**
     * Kadane's algorithm: track current sum and max sum; reset current when it goes negative.
     * Time O(n), Space O(1)
     */
    public static int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }
        return maxSum;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum Subarray (Kadane's Algorithm)");
        System.out.println("=".repeat(60));

        System.out.println("[-2,1,-3,4,-1,2,1,-5,4] -> " + maxSubArray(new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
        System.out.println("[1] -> " + maxSubArray(new int[] { 1 }));
        System.out.println("[5,4,-1,7,8] -> " + maxSubArray(new int[] { 5, 4, -1, 7, 8 }));
        System.out.println("[-1] -> " + maxSubArray(new int[] { -1 }));
    }
}
