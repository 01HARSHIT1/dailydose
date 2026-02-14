/**
 * Basic DSA Problems - Maximum Subarray (Kadane's Algorithm)
 * Find contiguous subarray with largest sum
 */
public class basic_dsa_three_hundred_seven {

    // Problem: Integer array nums. Return largest sum of any contiguous subarray.

    /**
     * Kadane's algo: track current sum, reset when negative; keep max.
     * Time O(n), Space O(1)
     */
    public static int maxSubArray(int[] nums) {
        int max = nums[0], cur = 0;
        for (int n : nums) {
            cur = Math.max(0, cur) + n;
            max = Math.max(max, cur);
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum Subarray (Kadane's Algorithm)");
        System.out.println("=".repeat(60));

        System.out.println("[-2,1,-3,4,-1,2,1,-5,4] -> " + maxSubArray(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4}));
        System.out.println("[1] -> " + maxSubArray(new int[]{1}));
        System.out.println("[5,4,-1,7,8] -> " + maxSubArray(new int[]{5, 4, -1, 7, 8}));
    }
}
