/**
 * Basic DSA Problems - Partition Equal Subset Sum (LeetCode 416)
 * Can array be split into two subsets with equal sum?
 */
public class basic_dsa_four_hundred_sixteen {

    // Problem: Partition nums into two subsets with equal sum.

    /**
     * Sum must be even. Subset sum problem for target = sum/2.
     * DP: dp[j] = can we make sum j. Time O(n*sum), Space O(sum)
     */
    public static boolean canPartition(int[] nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        for (int x : nums) {
            for (int j = target; j >= x; j--)
                if (dp[j - x]) dp[j] = true;
        }
        return dp[target];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Partition Equal Subset Sum");
        System.out.println("=".repeat(60));

        System.out.println("[1,5,11,5] -> " + canPartition(new int[]{1,5,11,5}));
        System.out.println("[1,2,3,5] -> " + canPartition(new int[]{1,2,3,5}));
    }
}
