/**
 * Basic DSA Problems - Search a 2D Matrix II
 * Search in sorted matrix (rows and cols non-decreasing)
 */
public class basic_dsa_two_hundred_eighty_eight {

    // Problem: Matrix: each row sorted ascending, each col sorted ascending.
    // Return true if target exists.

    /**
     * Start top-right. If target > cell, go down. If target < cell, go left.
     * Time O(m+n), Space O(1)
     */
    public static boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) return false;
        int r = 0, c = matrix[0].length - 1;
        while (r < matrix.length && c >= 0) {
            int v = matrix[r][c];
            if (v == target) return true;
            if (v < target) r++;
            else c--;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Search a 2D Matrix II");
        System.out.println("=".repeat(60));

        int[][] m = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        System.out.println("target=5 -> " + searchMatrix(m, 5));
        System.out.println("target=10 -> " + searchMatrix(m, 10));
    }
}
