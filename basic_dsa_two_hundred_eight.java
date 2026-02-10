/**
 * Basic DSA Problems - Rotate Image (90 degrees clockwise)
 * Rotate n x n matrix in place
 */
public class basic_dsa_two_hundred_eight {

    // Problem: n x n matrix. Rotate 90 degrees clockwise in place.

    /**
     * Layer by layer: for each cell on top edge, swap with right, bottom, left in cycle (4-way swap).
     * Time O(n^2), Space O(1)
     */
    public static void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Rotate Image");
        System.out.println("=".repeat(60));

        int[][] m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        rotate(m);
        System.out.println("After 90° clockwise:");
        for (int[] row : m) System.out.println(java.util.Arrays.toString(row));
    }
}
