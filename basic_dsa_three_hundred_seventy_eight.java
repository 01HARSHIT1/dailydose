/**
 * Basic DSA Problems - Kth Smallest Element in a Sorted Matrix (LeetCode 378)
 * Matrix sorted row/col, find kth smallest
 */
public class basic_dsa_three_hundred_seventy_eight {

    // Problem: n x n matrix sorted non-decreasing row & col. Return kth smallest.

    /**
     * Binary search on value. Count elements <= mid; if count >= k, answer <= mid.
     * Count by walking from top-right.
     * Time O(n * log(max-min)), Space O(1)
     */
    public static int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            int c = n - 1;
            for (int r = 0; r < n; r++) {
                while (c >= 0 && matrix[r][c] > mid) c--;
                count += c + 1;
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Kth Smallest Element in a Sorted Matrix");
        System.out.println("=".repeat(60));

        int[][] m = {{1,5,9},{10,11,13},{12,13,15}};
        System.out.println("[[1,5,9],[10,11,13],[12,13,15]], k=8 -> " + kthSmallest(m, 8));
    }
}
