/**
 * Basic DSA Problems - Max Sum of Rectangle No Larger Than K (LeetCode 363)
 * Max submatrix sum <= k
 */
public class basic_dsa_three_hundred_sixty_three {

    // Problem: Matrix, int k. Return max sum of rectangle with sum <= k.

    /**
     * Enumerate column ranges [c1,c2]. For each, compute row prefix sums, then 1D problem:
     * max subarray sum <= k using TreeSet for prefix sums.
     * Time O(m^2 * n log n), Space O(n)
     */
    public static int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int max = Integer.MIN_VALUE;
        for (int c1 = 0; c1 < n; c1++) {
            int[] rowSum = new int[m];
            for (int c2 = c1; c2 < n; c2++) {
                for (int r = 0; r < m; r++) rowSum[r] += matrix[r][c2];
                java.util.TreeSet<Integer> set = new java.util.TreeSet<>();
                set.add(0);
                int pref = 0;
                for (int r = 0; r < m; r++) {
                    pref += rowSum[r];
                    Integer ceil = set.ceiling(pref - k);
                    if (ceil != null) max = Math.max(max, pref - ceil);
                    set.add(pref);
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Max Sum of Rectangle No Larger Than K");
        System.out.println("=".repeat(60));

        System.out.println("[[1,0,1],[0,-2,3]], k=2 -> " + maxSumSubmatrix(new int[][]{{1,0,1},{0,-2,3}}, 2));
        System.out.println("[[2,2,-1]], k=3 -> " + maxSumSubmatrix(new int[][]{{2,2,-1}}, 3));
    }
}
