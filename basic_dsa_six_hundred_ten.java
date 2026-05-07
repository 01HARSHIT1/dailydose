/**
 * Basic DSA Problems - One Fundamental Dynamic Programming Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_ten {

    // Problem 1: Unique Paths
    // An m x n grid: start top-left, end bottom-right; move only right or down.
    // Return how many distinct paths exist.

    /**
     * Row-by-row DP: ways[i][j] = ways[i-1][j] + ways[i][j-1]; one array suffices
     * Time Complexity: O(m * n)
     * Space Complexity: O(n)
     */
    public static int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        int[] dp = new int[n];
        for (int j = 0; j < n; j++) {
            dp[j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Unique Paths");
        System.out.println("=".repeat(60));

        System.out.println("3x7 -> " + uniquePaths(3, 7));
        System.out.println("3x2 -> " + uniquePaths(3, 2));
        System.out.println("1x1 -> " + uniquePaths(1, 1));
        System.out.println("0x5 -> " + uniquePaths(0, 5));
    }
}
