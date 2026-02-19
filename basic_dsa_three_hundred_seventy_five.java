/**
 * Basic DSA Problems - Guess Number Higher or Lower II (LeetCode 375)
 * Min cost to guarantee win: pay guess value on wrong guess
 */
public class basic_dsa_three_hundred_seventy_five {

    // Problem: Pick in [1,n]. Pay k if guess k is wrong. Min cost to guarantee win.

    /**
     * DP: cost[i][j] = min cost for range [i,j]. Try each k as guess; worst-case branch.
     * Time O(n^3), Space O(n^2)
     */
    public static int getMoneyAmount(int n) {
        int[][] dp = new int[n + 2][n + 2];
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k <= j; k++)
                    dp[i][j] = Math.min(dp[i][j],
                            k + Math.max(dp[i][k - 1], dp[k + 1][j]));
            }
        }
        return dp[1][n];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Guess Number Higher or Lower II");
        System.out.println("=".repeat(60));

        System.out.println("n=10 -> " + getMoneyAmount(10));
        System.out.println("n=1 -> " + getMoneyAmount(1));
    }
}
