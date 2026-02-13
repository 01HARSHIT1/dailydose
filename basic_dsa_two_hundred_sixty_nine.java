/**
 * Basic DSA Problems - Maximum Subarray
 * Find contiguous subarray with largest sum (Kadane's Algorithm)
 */
public class basic_dsa_two_hundred_sixty_nine {

    // Problem: Find contiguous subarray with maximum sum. Return that sum.
    // Example: [-2,1,-3,4,-1,2,1,-5,4] -> 6 (subarray [4,-1,2,1])

    /**
     * Kadane: at each i, either extend prev best or start new. maxEndHere = max(maxEndHere+x, x).
     * Time O(n), Space O(1)
     */
    public static int maxSubArray(int[] nums) {
        int maxHere = nums[0], maxSoFar = nums[0];
        for (int i = 1; i < nums.length; i++) {
            maxHere = Math.max(maxHere + nums[i], nums[i]);
            maxSoFar = Math.max(maxSoFar, maxHere);
        }
        return maxSoFar;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum Subarray");
        System.out.println("=".repeat(60));

        System.out.println("[-2,1,-3,4,-1,2,1,-5,4] -> " + maxSubArray(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4}));
        System.out.println("[1] -> " + maxSubArray(new int[]{1}));
        System.out.println("[-1] -> " + maxSubArray(new int[]{-1}));
    }
}
