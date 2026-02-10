/**
 * Basic DSA Problems - Set Matrix Zeroes
 * If an element is 0, set its entire row and column to 0 (in place)
 */
public class basic_dsa_two_hundred_seven {

    // Problem: If matrix[i][j] == 0, set all of row i and column j to 0. O(1) space.

    /**
     * Use first row and first column as markers. Handle (0,0) overlap with a single extra variable.
     * Time O(m*n), Space O(1)
     */
    public static void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean col0 = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = true;
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0) matrix[i][0] = 0;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Set Matrix Zeroes");
        System.out.println("=".repeat(60));

        int[][] m = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        setZeroes(m);
        System.out.println("After setZeroes:");
        for (int[] row : m) System.out.println(java.util.Arrays.toString(row));
    }
}
