/**
 * Basic DSA Problems - Bomb Enemy (LeetCode 361)
 * Max enemies killed by one bomb; blast travels row/col until wall
 */
public class basic_dsa_three_hundred_sixty_one {

    // Problem: Grid with 'W','E','0'. Bomb kills E in same row/col until W. Return max.

    /**
     * For each '0', count E in row and col (scan until W). Optimize: precompute row/col counts.
     * Time O(m*n), Space O(n) for col counts
     */
    public static int maxKilledEnemies(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int m = grid.length, n = grid[0].length;
        int max = 0;
        int rowHits = 0;
        int[] colHits = new int[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowHits = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        if (grid[i][k] == 'E') rowHits++;
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colHits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        if (grid[k][j] == 'E') colHits[j]++;
                }
                if (grid[i][j] == '0')
                    max = Math.max(max, rowHits + colHits[j]);
            }
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Bomb Enemy");
        System.out.println("=".repeat(60));

        char[][] g = {{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
        System.out.println("[[0,E,0,0],[E,0,W,E],[0,E,0,0]] -> " + maxKilledEnemies(g));
    }
}
