/**
 * Basic DSA Problems - Combination Sum IV (LeetCode 377)
 * Number of combinations that add up to target (order matters)
 */
public class basic_dsa_three_hundred_seventy_seven {

    // Problem: Distinct nums, target. Return count of sequences that sum to target.

    /**
     * DP: dp[i] = count of ways to make sum i. dp[i] += dp[i-n] for each n in nums.
     * Time O(target * n), Space O(target)
     */
    public static int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int n : nums)
                if (i >= n) dp[i] += dp[i - n];
        return dp[target];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Combination Sum IV");
        System.out.println("=".repeat(60));

        System.out.println("nums=[1,2,3], target=4 -> " + combinationSum4(new int[]{1,2,3}, 4));
        System.out.println("nums=[9], target=3 -> " + combinationSum4(new int[]{9}, 3));
    }
}
