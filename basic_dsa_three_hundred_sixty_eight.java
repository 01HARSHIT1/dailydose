/**
 * Basic DSA Problems - Largest Divisible Subset (LeetCode 368)
 * Largest subset where every pair (a,b) has a%b==0 or b%a==0
 */
public class basic_dsa_three_hundred_sixty_eight {

    // Problem: Distinct positive nums. Largest subset where each pair is divisible.

    /**
     * Sort ascending. dp[i] = longest chain ending at nums[i]. For each i, try j < i with nums[i]%nums[j]==0.
     * Time O(n^2), Space O(n)
     */
    public static java.util.List<Integer> largestDivisibleSubset(int[] nums) {
        java.util.Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        java.util.Arrays.fill(dp, 1);
        java.util.Arrays.fill(prev, -1);
        int maxLen = 1, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        java.util.List<Integer> out = new java.util.ArrayList<>();
        for (int i = maxIdx; i >= 0; i = prev[i]) out.add(0, nums[i]);
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Largest Divisible Subset");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3] -> " + largestDivisibleSubset(new int[]{1,2,3}));
        System.out.println("[1,2,4,8] -> " + largestDivisibleSubset(new int[]{1,2,4,8}));
    }
}
