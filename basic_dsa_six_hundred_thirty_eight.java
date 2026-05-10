/**
 * Basic DSA Problems - One Fundamental Matrix Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_eight {

    // Problem 1: Rotate Image
    // matrix is n x n. Rotate 90 degrees clockwise; return a new matrix (input unchanged).

    /**
     * Position (i, j) maps to (j, n - 1 - i)
     * Time Complexity: O(n^2)
     * Space Complexity: O(n^2) for output
     */
    public static int[][] rotate(int[][] matrix) {
        if (matrix == null) {
            return null;
        }
        int n = matrix.length;
        if (n == 0) {
            return new int[0][];
        }

        int[][] out = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out[j][n - 1 - i] = matrix[i][j];
            }
        }
        return out;
    }

    private static String matrixToString(int[][] m) {
        if (m == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < m.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append("[");
            for (int j = 0; j < m[i].length; j++) {
                if (j > 0) {
                    sb.append(", ");
                }
                sb.append(m[i][j]);
            }
            sb.append("]");
        }
        return sb.append("]").toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Rotate Image (90 clockwise)");
        System.out.println("=".repeat(60));

        int[][] a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        System.out.println("3x3 -> " + matrixToString(rotate(a)));
        System.out.println("original[0][0] still 1 -> " + (a[0][0] == 1));

        int[][] b = {{5, 1}, {2, 3}};
        System.out.println("2x2 -> " + matrixToString(rotate(b)));

        System.out.println("null -> " + matrixToString(rotate(null)));
    }
}
