import java.util.ArrayList;
import java.util.List;

/**
 * LeetCode 51 - N-Queens
 * Place n queens on an n×n chessboard so that no two queens attack each other.
 */
public class NQueens {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        int[] cols = new int[n]; // cols[row] = column of queen in row
        boolean[] colUsed = new boolean[n];
        boolean[] diag1 = new boolean[2 * n - 1]; // diagonal: row + col
        boolean[] diag2 = new boolean[2 * n - 1]; // anti-diagonal: row - col + n - 1
        backtrack(result, n, 0, cols, colUsed, diag1, diag2);
        return result;
    }

    private void backtrack(List<List<String>> result, int n, int row, int[] cols,
            boolean[] colUsed, boolean[] diag1, boolean[] diag2) {
        if (row == n) {
            result.add(boardToString(cols, n));
            return;
        }
        for (int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + n - 1;
            if (colUsed[col] || diag1[d1] || diag2[d2])
                continue;
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            cols[row] = col;
            backtrack(result, n, row + 1, cols, colUsed, diag1, diag2);
            colUsed[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    private List<String> boardToString(int[] cols, int n) {
        List<String> board = new ArrayList<>();
        for (int row = 0; row < n; row++) {
            StringBuilder sb = new StringBuilder();
            for (int c = 0; c < n; c++) {
                sb.append(c == cols[row] ? 'Q' : '.');
            }
            board.add(sb.toString());
        }
        return board;
    }

    // Run examples
    public static void main(String[] args) {
        NQueens sol = new NQueens();

        System.out.println("Example 1: n = 4");
        System.out.println(sol.solveNQueens(4));
        // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

        System.out.println("\nExample 2: n = 1");
        System.out.println(sol.solveNQueens(1));
        // [["Q"]]
    }
}
