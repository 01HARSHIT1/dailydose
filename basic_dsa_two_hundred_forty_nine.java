/**
 * Basic DSA Problems - Island Perimeter
 * Calculate perimeter of island in 2D grid
 */
public class basic_dsa_two_hundred_forty_nine {

    // Problem: grid has 0=water, 1=land. One island (connected 1's). Return perimeter.
    // Each edge shared with water adds 1 to perimeter.

    /**
     * For each land cell, add 4 edges. Subtract 2 for each adjacent land (shared edge).
     * Time O(rc), Space O(1)
     */
    public static int islandPerimeter(int[][] grid) {
        int perimeter = 0;
        int rows = grid.length, cols = grid[0].length;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    if (r > 0 && grid[r - 1][c] == 1) perimeter -= 2;
                    if (c > 0 && grid[r][c - 1] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Island Perimeter");
        System.out.println("=".repeat(60));

        int[][] g = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
        System.out.println("4x4 grid -> " + islandPerimeter(g));

        System.out.println("[[1]] -> " + islandPerimeter(new int[][]{{1}}));
    }
}
