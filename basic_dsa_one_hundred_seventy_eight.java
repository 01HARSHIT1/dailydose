/**
 * Basic DSA Problems - Pacific Atlantic Water Flow
 * Find cells from which water can flow to both Pacific and Atlantic oceans
 */
import java.util.*;

public class basic_dsa_one_hundred_seventy_eight {

    // Problem: Matrix heights. Water flows from cell to adjacent cell with same or lower height.
    // Pacific = top/left edges, Atlantic = bottom/right. Return all cells that can reach both.

    static int R, C;
    static int[][] h;
    static int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};

    public static List<List<Integer>> pacificAtlantic(int[][] heights) {
        if (heights == null || heights.length == 0) return new ArrayList<>();
        h = heights;
        R = h.length;
        C = h[0].length;
        boolean[][] pac = new boolean[R][C];
        boolean[][] atl = new boolean[R][C];
        for (int c = 0; c < C; c++) {
            dfs(0, c, pac);
            dfs(R - 1, c, atl);
        }
        for (int r = 0; r < R; r++) {
            dfs(r, 0, pac);
            dfs(r, C - 1, atl);
        }
        List<List<Integer>> out = new ArrayList<>();
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (pac[r][c] && atl[r][c])
                    out.add(Arrays.asList(r, c));
        return out;
    }

    static void dfs(int r, int c, boolean[][] seen) {
        seen[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !seen[nr][nc] && h[nr][nc] >= h[r][c])
                dfs(nr, nc, seen);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Pacific Atlantic Water Flow");
        System.out.println("=".repeat(60));

        int[][] heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
        System.out.println("Result -> " + pacificAtlantic(heights));
    }
}
