/**
 * Basic DSA Problems - One Fundamental Matrix Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_fifty_seven {

    // Problem 1: Transpose Matrix
    // Given a 2D integer array matrix, return its transpose.
    // The transpose of a matrix is the matrix flipped over its main diagonal.
    //
    // Example:
    // matrix = [[1,2,3],[4,5,6]] -> [[1,4],[2,5],[3,6]]

    /**
     * Create transposed matrix with swapped dimensions
     * Time Complexity: O(m * n)
     * Space Complexity: O(m * n)
     */
    public static int[][] transpose(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0] == null) {
            return null;
        }

        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] result = new int[cols][rows];

        for (int i = 0; i < rows; i++) {
            if (matrix[i] == null || matrix[i].length != cols) {
                return null; // keep input handling simple for irregular matrices
            }
            for (int j = 0; j < cols; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }

    private static String matrixToString(int[][] matrix) {
        if (matrix == null) {
            return "null";
        }
        if (matrix.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < matrix.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append("[");
            for (int j = 0; j < matrix[i].length; j++) {
                if (j > 0) {
                    sb.append(", ");
                }
                sb.append(matrix[i][j]);
            }
            sb.append("]");
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Transpose Matrix");
        System.out.println("=".repeat(60));

        int[][] m1 = {{1, 2, 3}, {4, 5, 6}};
        System.out.println("matrix = [[1,2,3],[4,5,6]] -> " + matrixToString(transpose(m1)));

        int[][] m2 = {{1, 2}, {3, 4}, {5, 6}};
        System.out.println("matrix = [[1,2],[3,4],[5,6]] -> " + matrixToString(transpose(m2)));

        int[][] m3 = {{7}};
        System.out.println("matrix = [[7]] -> " + matrixToString(transpose(m3)));

        int[][] m4 = {};
        System.out.println("matrix = [] -> " + matrixToString(transpose(m4)));

        System.out.println("matrix = null -> " + matrixToString(transpose(null)));
    }
}
