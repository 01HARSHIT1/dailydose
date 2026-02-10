/**
 * Basic DSA Problems - Search a 2D Matrix
 * Search in sorted matrix (each row sorted, first of row > last of previous)
 */
public class basic_dsa_one_hundred_eighty_one {

    // Problem: Matrix where each row is sorted and row[i][0] > row[i-1][last]. Find target.

    /**
     * Treat as 1D sorted array: index mid maps to [mid/cols][mid%cols]. Binary search.
     * Time O(log(m*n)), Space O(1)
     */
    public static boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        int rows = matrix.length, cols = matrix[0].length;
        int lo = 0, hi = rows * cols - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = mid / cols, c = mid % cols;
            int v = matrix[r][c];
            if (v == target) return true;
            if (v < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Search a 2D Matrix");
        System.out.println("=".repeat(60));

        int[][] matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        System.out.println("target 3 -> " + searchMatrix(matrix, 3));
        System.out.println("target 13 -> " + searchMatrix(matrix, 13));
    }
}
