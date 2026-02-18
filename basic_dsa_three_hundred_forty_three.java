/**
 * Basic DSA Problems - Integer Break (LeetCode 343)
 * Break n into sum of k>=2 positive integers, maximize product
 */
public class basic_dsa_three_hundred_forty_three {

    // Problem: n >= 2. Break into k>=2 positive integers. Maximize product.

    /**
     * DP: dp[i] = max product from breaking i. Try splitting at j: j * (i-j) or j * dp[i-j].
     * Time O(n^2), Space O(n)
     */
    public static int integerBreak(int n) {
        int[] dp = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++)
                dp[i] = Math.max(dp[i], Math.max(j * (i - j), j * dp[i - j]));
        }
        return dp[n];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Integer Break");
        System.out.println("=".repeat(60));

        System.out.println("2 -> " + integerBreak(2));
        System.out.println("10 -> " + integerBreak(10));
    }
}
