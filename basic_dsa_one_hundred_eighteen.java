/**
 * Basic DSA Problems - Reshape the Matrix
 * Reshape matrix to new dimensions (row-major order)
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_eighteen {

    // Problem: Given 2D matrix mat and r, c, reshape to r x c (row-major). If impossible, return original.

    /**
     * Flatten index: mat[i][j] -> flat index i*cols+j; new [i][j] = flat index i*c+j.
     * Time O(m*n), Space O(1) excluding result
     */
    public static int[][] matrixReshape(int[][] mat, int r, int c) {
        if (mat == null || mat.length == 0) return mat;
        int m = mat.length, n = mat[0].length;
        if (m * n != r * c) return mat;

        int[][] out = new int[r][c];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int flat = i * n + j;
                out[flat / c][flat % c] = mat[i][j];
            }
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reshape the Matrix");
        System.out.println("=".repeat(60));

        int[][] a = { { 1, 2 }, { 3, 4 } };
        int[][] r1 = matrixReshape(a, 1, 4);
        System.out.println("[[1,2],[3,4]] -> 1x4: " + Arrays.deepToString(r1));

        int[][] b = { { 1, 2 }, { 3, 4 } };
        int[][] r2 = matrixReshape(b, 2, 4);
        System.out.println("[[1,2],[3,4]] -> 2x4 (invalid): " + Arrays.deepToString(r2));
    }
}
