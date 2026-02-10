/**
 * Basic DSA Problems - Valid Sudoku
 * Check if 9x9 board is valid (no duplicate in row, column, or 3x3 box)
 */
import java.util.HashSet;
import java.util.Set;

public class basic_dsa_two_hundred_five {

    // Problem: 9x9 board. '.' is empty. Check: no duplicate 1-9 in row, col, or 3x3 box.

    /**
     * For each cell with digit, add "r(i)d", "c(j)d", "b(box)d" to set. Duplicate => invalid.
     * Time O(81), Space O(81)
     */
    public static boolean isValidSudoku(char[][] board) {
        Set<String> seen = new HashSet<>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                int box = (i / 3) * 3 + (j / 3);
                String r = "r" + i + c, col = "c" + j + c, b = "b" + box + c;
                if (!seen.add(r) || !seen.add(col) || !seen.add(b)) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Sudoku");
        System.out.println("=".repeat(60));

        char[][] board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        System.out.println("Valid -> " + isValidSudoku(board));
    }
}
