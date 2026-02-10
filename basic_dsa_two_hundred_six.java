/**
 * Basic DSA Problems - Spiral Matrix
 * Return elements of matrix in spiral order (right, down, left, up)
 */
import java.util.ArrayList;
import java.util.List;

public class basic_dsa_two_hundred_six {

    // Problem: m x n matrix. Return all elements in spiral order.

    /**
     * Four boundaries: top, bottom, left, right. Traverse and shrink.
     * Time O(m*n), Space O(1) excluding output
     */
    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> out = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return out;
        int top = 0, bottom = matrix.length - 1, left = 0, right = matrix[0].length - 1;
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; c++) out.add(matrix[top][c]);
            top++;
            if (top > bottom) break;
            for (int r = top; r <= bottom; r++) out.add(matrix[r][right]);
            right--;
            if (left > right) break;
            for (int c = right; c >= left; c--) out.add(matrix[bottom][c]);
            bottom--;
            if (top > bottom) break;
            for (int r = bottom; r >= top; r--) out.add(matrix[r][left]);
            left++;
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Spiral Matrix");
        System.out.println("=".repeat(60));

        int[][] m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        System.out.println("Spiral -> " + spiralOrder(m));
    }
}
