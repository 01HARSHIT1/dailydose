/**
 * Basic DSA Problems - Battleships in a Board (LeetCode 419)
 * Count battleships placed horizontally or vertically, no adjacent ships
 */
public class basic_dsa_four_hundred_nineteen {

    // Problem: Count ships. Ships are 1xk or kx1. One pass, O(1) extra space.

    /**
     * Count only top-left cell of each ship (no X above or left).
     * Time O(m*n), Space O(1)
     */
    public static int countBattleships(char[][] board) {
        int m = board.length, n = board[0].length, count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
                    count++;
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Battleships in a Board");
        System.out.println("=".repeat(60));

        char[][] b1 = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
        System.out.println("3x4 board -> " + countBattleships(b1));

        char[][] b2 = {{'.'}};
        System.out.println("1x1 empty -> " + countBattleships(b2));

        char[][] b3 = {{'X','.','.'},{'X','.','.'},{'.','.','X'}};
        System.out.println("3 ships -> " + countBattleships(b3));
    }
}
