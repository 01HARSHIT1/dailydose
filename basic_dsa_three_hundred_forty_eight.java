/**
 * Basic DSA Problems - Design Tic-Tac-Toe (LeetCode 348)
 * Track row/col/diag sums for O(1) win detection on n x n board
 */
public class basic_dsa_three_hundred_forty_eight {

    // Problem: n x n board. move(row,col,player) returns player id if win, else 0.

    static class TicTacToe {
        int n;
        int[] rows, cols;
        int diag, antiDiag;

        TicTacToe(int n) {
            this.n = n;
            rows = new int[n];
            cols = new int[n];
        }

        public int move(int row, int col, int player) {
            int v = player == 1 ? 1 : -1;
            rows[row] += v;
            cols[col] += v;
            if (row == col) diag += v;
            if (row + col == n - 1) antiDiag += v;
            if (Math.abs(rows[row]) == n || Math.abs(cols[col]) == n
                    || Math.abs(diag) == n || Math.abs(antiDiag) == n)
                return player;
            return 0;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Design Tic-Tac-Toe");
        System.out.println("=".repeat(60));

        TicTacToe g = new TicTacToe(3);
        System.out.println("move(0,0,1)=" + g.move(0, 0, 1) + ", move(0,2,2)=" + g.move(0, 2, 2)
                + ", move(2,2,1)=" + g.move(2, 2, 1) + ", move(1,1,2)=" + g.move(1, 1, 2)
                + ", move(2,0,1)=" + g.move(2, 0, 1) + ", move(1,0,2)=" + g.move(1, 0, 2)
                + ", move(2,1,1)=" + g.move(2, 1, 1));
    }
}
