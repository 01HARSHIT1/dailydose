import java.util.Arrays;

/**
 * Basic DSA Problems - One Fundamental Matrix Simulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_nine {

    // Problem 1: Spiral Matrix
    // Return all elements of matrix in clockwise spiral order.

    /**
     * Layer bounds top/bottom/left/right; four edge passes until exhausted
     * Time Complexity: O(m * n)
     * Space Complexity: O(m * n) for the result array
     */
    public static int[] spiralOrder(int[][] matrix) {
        if (matrix == null) {
            return null;
        }
        int m = matrix.length;
        if (m == 0) {
            return new int[0];
        }
        int n = matrix[0].length;
        if (n == 0) {
            return new int[0];
        }

        int[] out = new int[m * n];
        int t = 0;
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                out[t++] = matrix[top][j];
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                out[t++] = matrix[i][right];
            }
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    out[t++] = matrix[bottom][j];
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    out[t++] = matrix[i][left];
                }
                left++;
            }
        }

        return out;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Spiral Matrix");
        System.out.println("=".repeat(60));

        int[][] a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        System.out.println("3x3 -> " + Arrays.toString(spiralOrder(a)));

        int[][] b = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        System.out.println("3x4 -> " + Arrays.toString(spiralOrder(b)));

        System.out.println("empty -> " + Arrays.toString(spiralOrder(new int[0][])));
        int[] z = spiralOrder(null);
        System.out.println("null -> " + (z == null ? "null" : Arrays.toString(z)));
    }
}
