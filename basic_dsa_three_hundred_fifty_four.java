/**
 * Basic DSA Problems - Russian Doll Envelopes (LeetCode 354)
 * Max envelopes you can Russian doll (one fits inside other)
 */
public class basic_dsa_three_hundred_fifty_four {

    // Problem: envelopes[i]=[w,h]. Fit inside = both w and h strictly smaller. Max chain.

    /**
     * Sort by w asc, h desc. Then LIS on h (avoids same-w in sequence).
     * Time O(n log n), Space O(n)
     */
    public static int maxEnvelopes(int[][] envelopes) {
        java.util.Arrays.sort(envelopes, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
        int[] dp = new int[envelopes.length];
        int len = 0;
        for (int[] e : envelopes) {
            int i = java.util.Arrays.binarySearch(dp, 0, len, e[1]);
            if (i < 0) i = -(i + 1);
            dp[i] = e[1];
            if (i == len) len++;
        }
        return len;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Russian Doll Envelopes");
        System.out.println("=".repeat(60));

        System.out.println("[[5,4],[6,4],[6,7],[2,3]] -> " + maxEnvelopes(new int[][]{{5,4},{6,4},{6,7},{2,3}}));
        System.out.println("[[1,1],[1,1],[1,1]] -> " + maxEnvelopes(new int[][]{{1,1},{1,1},{1,1}}));
    }
}
