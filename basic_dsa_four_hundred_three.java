/**
 * Basic DSA Problems - Frog Jump (LeetCode 403)
 * Can frog reach last stone? From pos with jump k, next jump k-1/k/k+1.
 */
public class basic_dsa_four_hundred_three {

    // Problem: stones positions. Start 0, first jump 1. Jump k -> next k-1,k,k+1.

    /**
     * DP: at stone i with lastJump k. Try jump to stone at pos+k-1, pos+k, pos+k+1.
     * Time O(n^2), Space O(n^2)
     */
    public static boolean canCross(int[] stones) {
        int n = stones.length;
        java.util.Map<Integer, Integer> pos = new java.util.HashMap<>();
        for (int i = 0; i < n; i++) pos.put(stones[i], i);
        boolean[][] dp = new boolean[n][n + 1];
        dp[0][1] = true;

        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= n; k++) {
                if (!dp[i][k]) continue;
                int p = stones[i];
                for (int d = -1; d <= 1; d++) {
                    int nk = k + d;
                    if (nk <= 0) continue;
                    Integer j = pos.get(p + nk);
                    if (j != null) dp[j][nk] = true;
                }
            }
        }
        for (int k = 1; k <= n; k++)
            if (dp[n - 1][k]) return true;
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Frog Jump");
        System.out.println("=".repeat(60));

        System.out.println("[0,1,3,5,6,8,12,17] -> " + canCross(new int[]{0,1,3,5,6,8,12,17}));
        System.out.println("[0,1,2,3,4,8,9,11] -> " + canCross(new int[]{0,1,2,3,4,8,9,11}));
    }
}
