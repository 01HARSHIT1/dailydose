/**
 * Basic DSA Problems - Number of Islands
 * Count connected components of '1' in 2D grid (4-directional)
 */
public class basic_dsa_one_hundred_seventy_six {

    // Problem: Grid of '1' and '0'. Return number of islands (connected 1s, 4-directional).

    static int rows, cols;

    public static int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        rows = grid.length;
        cols = grid[0].length;
        int count = 0;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
        return count;
    }

    static void dfs(char[][] grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') return;
        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Number of Islands");
        System.out.println("=".repeat(60));

        char[][] grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };
        System.out.println("Number of islands -> " + numIslands(grid));
    }
}
