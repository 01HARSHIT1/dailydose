/**
 * Basic DSA Problems - Android Unlock Patterns (LeetCode 351)
 * Count valid unlock patterns of length between m and n
 */
public class basic_dsa_three_hundred_fifty_one {

    // Problem: 3x3 grid, 1-9. Count patterns with length in [m,n]. Can't skip unvisited middle.

    // skip[i][j] = cell between i and j (1-indexed), 0 if none
    static int[][] skip = new int[10][10];
    static { skip[1][3] = skip[3][1] = 2; skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6; skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
    }

    public static int numberOfPatterns(int m, int n) {
        boolean[] vis = new boolean[10];
        int count = 0;
        count += 4 * dfs(1, 1, vis, m, n);  // 1,3,7,9 symmetric
        count += 4 * dfs(2, 1, vis, m, n);    // 2,4,6,8 symmetric
        count += dfs(5, 1, vis, m, n);        // 5
        return count;
    }

    private static int dfs(int cur, int len, boolean[] vis, int m, int n) {
        if (len > n) return 0;
        vis[cur] = true;
        int c = (len >= m ? 1 : 0);
        for (int next = 1; next <= 9; next++) {
            if (vis[next]) continue;
            int mid = skip[cur][next];
            if (mid == 0 || vis[mid]) c += dfs(next, len + 1, vis, m, n);
        }
        vis[cur] = false;
        return c;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Android Unlock Patterns");
        System.out.println("=".repeat(60));

        System.out.println("m=1, n=1 -> " + numberOfPatterns(1, 1));
        System.out.println("m=1, n=2 -> " + numberOfPatterns(1, 2));
    }
}
